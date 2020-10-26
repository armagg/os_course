
// calculating some simple functions in kernel mods 

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


MODULE_LICENSE("GPL");

MODULE_AUTHOR("omid Mesgarha");
MODULE_DESCRIPTION("calculating some simple functions in kernel mods ");
MODULE_VERSION("1.00");

static int ta_1, ta_2;

module_param(ta_1, int, 0);
module_param(ta_2, int, 0);


static int __init age_calculator_init(void) {
    printk("module age_calculator started.\n");
    printk("%d, %d recieved\n", TA1, TA2);
    return 0;
}

static int age_calculator_differece(void){
    int temp = ta_1 - ta_2;
    if(temp >= 0) {
        return temp;
    }else{
        return -temp;
    }
}

static float age_calculator_average(void){
    return (float) (ta_1 + ta_2) / 2 ;
}

static void __exit age_calculator_exit(viod){
     printk("module age_calculator ended.\n");
}

EXPORT_SYMBOL(age_calculator_differece);
EXPORT_SYMBOL(age_calculator_average);

module_init(age_calculator_init);
module_exit(age_calculator_exit);

