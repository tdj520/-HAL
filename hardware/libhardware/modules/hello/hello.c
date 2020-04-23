#define LOG_TAG "HelloHal"

#include <malloc.h>
#include <stdint.h>
#include <string.h>

#include <log/log.h>

#include <hardware/hello.h>
#include <hardware/hardware.h>

static int additionTest(const struct hello_device *dev,int a,int b,int *total)
{
	if(!dev){
		return -1;
	}
    *total = a + b;
    ALOGE("dongjiao....HAL additionTest() total = :%d",*total);
    return 0;
}

static int hello_close(hw_device_t *dev)
{
    if (dev) {
        free(dev);
        return 0;
    } else {
        return -1;
    }
}

static int hello_open(const hw_module_t* module,const char __unused *id,
                            hw_device_t** device)
{
    if (device == NULL) {
        ALOGE("NULL device on open11111");
        return -1;
    }

    hello_device_t *dev = malloc(sizeof(hello_device_t));
    memset(dev, 0, sizeof(hello_device_t));

    dev->common.tag = HARDWARE_DEVICE_TAG;
    dev->common.version = HELLO_MODULE_API_VERSION_1_0;
    dev->common.module = (struct hw_module_t*) module;
    dev->common.close = hello_close;
    dev->additionTest = additionTest;

    *device = &(dev->common);
    ALOGE("dongjiao....HAL hello_open()...");
    return 0;
}

static struct hw_module_methods_t hello_module_methods = {
    .open = hello_open,
};

hello_module_t  HAL_MODULE_INFO_SYM = {
    .common = {
        .tag                = HARDWARE_MODULE_TAG,
        .module_api_version = HELLO_MODULE_API_VERSION_1_0,
        .hal_api_version    = HARDWARE_HAL_API_VERSION,
        .id                 = HELLO_HARDWARE_MODULE_ID,
        .name               = "Demo Hello HAL",
        .author             = "dongjiao.tang@tcl.com",
        .methods            = &hello_module_methods,
    },
};

