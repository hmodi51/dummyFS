#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <fs.h>
#include <stdio.h>



struct file_system_type dummyFS_type = {
    .name = "dummyFS",
    .owner = THIS_MODULE,
    .mount = dummy_mount,
    .kill_sb = dummyFS_kill,    // unimplemented
    .next = NULL
};


/* 
implementation for mounting the file system
*/
struct dentry *dummy_mount(struct file_system_type *fs_type , int flags , const char *dev_name , void *data){
   return mount_nodev(fs_type , flags , data , dummy_fill_super);
}

void dummyFS_kill(struct super_block *sb){
    // implementation for unmounting the file system
}


struct super_operations dummyfs_super_ops = {
    // have to fill struct of super operations
    .put_super = dummy_put_super,        // unimplemented
    .statfs = dummy_stat_fs,             // unimplemented
    .alloc_inode = dummy_alloc_inode,    // unimplemented
    .drop_inode = generic_delete_inode,  // already there in kernel files
    .free_inode = dummy_free_inode
};

/*
implementation for filling the superblock object
*/
static int dummy_fill_super(struct super_block *sb , void *data , int silent){
    sb->smagic = DUMMY_MAGIC;
    sb->s_blocksize = BLOCKSIZE;
    SB->s_blocksize_bits = BLOCKSIZEBITS;
    sb->s_op = &dummyfs_super_ops;
}

