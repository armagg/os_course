#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/time.h>

MODULE_LICENSE("GPL");

static int __init show_time(void) {
    long int offset = 12600;//tehran time is +3:30
    printk("module show time and date started\n");
    struct tm date_time;
    time64_to_tm(get_seconds(), offset, &date_time);
    
    printk("(%04d-%02d-%02d %02d:%02d:%02d)\n", (int)date_time.tm_year + 1900, (int)date_time.tm_mon + 1,(int) date_time.tm_mday,(int) date_time.tm_hour,(int) date_time.tm_min,(int) date_time.tm_sec);

    return 0;
}

static void __exit show_time_exit(void) {
    printk("module show time and date deleted!");
}

module_init(show_time);
module_exit(show_time_exit);
