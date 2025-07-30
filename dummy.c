#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <fs.h>


// Meta info
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Harshit Modi");
MODULE_DESCRIPTION("DummyFS Kernel Module");


extern struct file_system_type dummyFS_type;

/**
 * @brief This func is called when module is loaded into kernel therefore fs registered into kernel
 */
static int __init ModuleInit(void){
    register_filesystem(&dummyFS_type);
    printk("FS Registered\n");
    return 0;
}


/**
 * @brief This func is called when module is unloaded from kernel therefore fs unregistered from kernel
 */
static void __exit ModuleExit(void){
    unregister_filesystem(&dummyFS_type);
    printk("FS removed\n");
}


module_init(ModuleInit);
module_exit(ModuleExit);