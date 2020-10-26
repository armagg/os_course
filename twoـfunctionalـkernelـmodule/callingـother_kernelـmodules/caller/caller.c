// a caller for other modle 


#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


MODULE_LICENSE("GPL");

MODULE_AUTHOR("omid Mesgarha");
MODULE_DESCRIPTION("tsting calculation some simple functions in kernel mods ");
MODULE_VERSION("1.00");

extern int age_calculator_difference(void);
extern int age_calculator_average(void);

static int __init caller_init(void) {
    printk("init module age calculator caller.\n");
    printk("diff is: %d\n", age_calculator_difference());
    printk("avg is: %d\n", age_calculator_average()); 
    return 0;
}


static void __exit caller_exit(void) {
    printk("exit module age_calculator.\n");

}

module_init(caller_init);
module_exit(caller_exit);
