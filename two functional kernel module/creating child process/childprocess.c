// making a fork and then a fork again! 

#include<unistd.h>
#include<stdio.h>

int main(){
    int child = -1, grand_child = -1;

    while (child < 0){
        child = fork();
        if (child > 0){
            printf("father pid: %d\n", getpid());
            wait(child);
            return(0);
        }
    }
    sleep(1);
    


    while (grand_child < 0){
        grand_child = fork();
        if (grand_child > 0){
            printf("child pid: %d\n", getpid());
            wait(grand_child);
            return(0);
        }
    }
    sleep(1);

    printf("grandchilds pid:%d \n", getpid());
    return(0);

}