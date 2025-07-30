#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <fs.h>
#include <stdio.h>



struct file_system_type dummyFS_type {
    .name = "dummyFS",
    .owner = THIS_MODULE,
    .mount = dummy_mount,
    .kill_sb = dummyFS_kill,
    .next = NULL
};


struct dentry *mount(struct file_system_type *fs_type , int flags , const char *dev_name , void *data){
    mount_nodev(fs_type , flags , data , dummy_fill_super);
}


static int dummy_fill_super(struct super_block *sb , void *data , int silent){
    sb->smagic = DUMMY_MAGIC;
}