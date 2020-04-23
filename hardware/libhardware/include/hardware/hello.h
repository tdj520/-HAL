#include <sys/cdefs.h>
#include <sys/types.h>
#include <hardware/hardware.h>


#define HELLO_HARDWARE_MODULE_ID "hello"
#define HELLO_MODULE_API_VERSION_1_0 HARDWARE_MODULE_API_VERSION(0, 1)

#define HARDWARE_HELLO "hello"

typedef struct hello_module {
    struct hw_module_t common;
} hello_module_t;

typedef struct hello_device {
    struct hw_device_t common;
   
    int (*additionTest)(const struct hello_device *dev,int a,int b,int* total);
} hello_device_t;


static inline int _hello_open(const struct hw_module_t *module,
        hello_device_t **device) {
    return module->methods->open(module, HARDWARE_HELLO,
            (struct hw_device_t **) device);
}



