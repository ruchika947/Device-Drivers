#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("DD");

static dev_t devnum;
static struct cdev _cdev;

static int sample_open(struct inode *inodep,struct file *filep)
{
    printk("sample open function\n");
    return 0;
}

static int sample_close(struct inode *inodep,struct file *filep)
{
    printk("sample close function\n");
    return 0;
}

struct file_operations fops={
    .open =sample_open,
    .release =sample_close,
};

static int __init sample_init(void)
{
    int ret;
    devnum =MKDEV(42,0);
    ret =register_chrdev_region(devnum,1,"sample_dev");
    
    if(ret)
    {
    printk("kernel didnt grant us device number\n");
    return ret;
    }

    cdev_init(&_cdev,&fops);

    ret =cdev_add(&_cdev,devnum,1);
    if(ret)
    {
        printk("unable to add cdev to kernel\n");
        unregister_chrdev_region(devnum,1);
        return ret;
    }
    printk("done init\n");
    return 0;
}

static void __exit sample_exit(void)
{
    cdev_del(&_cdev);
    unregister_chrdev_region(devnum,1);
    printk("ok tata bye bye\n");
}


module_init(sample_init);
module_exit(sample_exit);