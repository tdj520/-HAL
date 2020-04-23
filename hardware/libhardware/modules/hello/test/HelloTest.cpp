#include <hardware/hardware.h>
#include <hardware/hello.h>
#include <log/log.h>
#define TAG "HelloHal"
int main(){
    hello_device_t* hello_device = NULL;

    const hello_module_t * module = NULL;

    int ret = hw_get_module(HELLO_HARDWARE_MODULE_ID,(const struct hw_module_t**)&module);

    if (!ret) {
        ret = _hello_open((const struct hw_module_t*)module,&hello_device);
    }

   
    if (ret < 0) {
          ALOGD("get hello-hal failed.......");
          return -1;
    }

    int total = 0;
    hello_device->additionTest(hello_device,3,5,&total);
    ALOGD("success start hello-hal....total = %d",total);
    return 0;
}
