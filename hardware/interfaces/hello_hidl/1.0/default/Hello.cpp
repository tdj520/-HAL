// FIXME: your file license if you have one

#include "Hello.h"
#include <log/log.h>
#include <hardware/hardware.h>
#include <hardware/hello.h>
namespace android {
namespace hardware {
namespace hello_hidl {
namespace V1_0 {
namespace implementation {
hello_device_t* hello_device = NULL;
// Methods from ::android::hardware::hello_hidl::V1_0::IHello follow.
Return<uint32_t> Hello::addition_hidl(uint32_t a, uint32_t b) {
    // TODO implement
    uint32_t total = 0;
    ALOGD("dongjiao...HIDL addition_hidl...");
    hello_device->additionTest(hello_device,(int)a,(int)b,(int *)&total);
    return total;
}


// Methods from ::android::hidl::base::V1_0::IBase follow.

IHello* HIDL_FETCH_IHello(const char* /* name */) {

    const hello_module_t * module = NULL;

    int ret = hw_get_module(HELLO_HARDWARE_MODULE_ID,(const struct hw_module_t**)&module);

    if (!ret) {
        ret = _hello_open((const struct hw_module_t*)module,&hello_device);
    }
    if (ret < 0) {
          ALOGD("dongjiao HIDL get HAL service failed.......");
          return NULL;
    }
    ALOGE("dongjiao HIDL get HAL service surccess....");
    return new Hello();
}
//
}  // namespace implementation
}  // namespace V1_0
}  // namespace hello_hidl
}  // namespace hardware
}  // namespace android
