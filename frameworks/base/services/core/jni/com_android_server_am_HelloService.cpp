#include <jni.h>
#include <nativehelper/JNIHelp.h>
#include <binder/IServiceManager.h>
#include <android/hardware/hello_hidl/1.0/IHello.h>
#include <log/log.h>

using android::sp;
using android::hardware::hello_hidl::V1_0::IHello;

namespace android {

sp<IHello> hw_device;

static jint android_server_am_HelloService_nativeAdd(JNIEnv* env, jobject /* clazz */,jint a,jint b) {
      ALOGW("dongjiao...JNI nativeAdd.....before");
      uint32_t total = hw_device->addition_hidl(a,b);
      ALOGW("dongjiao...dongjiao...JNI nativeAdd nativeAdd.....end total = :%d",total);
    	return reinterpret_cast<jint>((int)total);
}

static void android_server_am_HelloService_nativeInit(JNIEnv* /* env */,jobject /* clazz */) {
      ALOGW("dongjiao...JNI nativeInit.....");
      hw_device = IHello::getService();
        if (hw_device == nullptr) {
              ALOGW("dongjiao...failed to get IHello service");
              return;
     }
     ALOGW("dongjiao...success to get HIDL IHello service");
}

/*
 * JNI registration.
 */
static const JNINativeMethod gMethods[] = {
    { "nativeAdd", "(II)I", (void*) android_server_am_HelloService_nativeAdd },
    { "nativeInit", "()V", (void*) android_server_am_HelloService_nativeInit },
};

int register_android_server_am_HelloService(JNIEnv* env)
{
    return jniRegisterNativeMethods(env, "com/android/server/am/HelloService",
            gMethods, NELEM(gMethods));
}

}; // namespace android

