#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>


static int __init show_time(void) {

}

static int __exit show_time_exit(void){

}

module_init(show_time);
module_exit(show_time_exit);
