#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>


// Meta info
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Harshit Modi");
MODULE_DESCRIPTION("DummyFS Kernel Module");

/**
 * @brief This func is called when module is loaded into kernel therefore fs registered into kernel
 */
static int __init ModuleInit(void){
     printk("Hello World\n");
     return 0;
}


/**
 * @brief This func is called when module is unloaded from kernel therefore fs unregistered from kernel
 */
static void __exit ModuleExit(void){
    printk("Bye World\n");
}


module_init(ModuleInit);
module_exit(ModuleExit);