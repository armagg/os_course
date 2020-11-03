#include <stdio.h>
#include <unistd.h>
#include <math.h>


struct dot
{
   int y;
   int x;
   float dis;
};

void nearest_dot(struct dot center, struct dot dots[], int m){
    float distant[m];
    //cal distances
    for(int i = 0; i< m; i++){
        distant[i] = ((center.x - dots[i].x)*(center.x - dots[i].x)) + ((center.y - dots[i].y) * (center.y - dots[i].y));
        dots[i].dis = distant[i];
    }

    //find min
    float min = 2000000000;
    for (size_t i = 0; i < m; i++)
    {
        if(distant[i] < min){
            min = distant[i];
        }
    }

    //print answer
    for (size_t i = 0; i < m; i++)
    {
        if(min == dots[i].dis){
            printf("%d %d: %d %d\n", center.x, center.y, dots[i].x, dots[i].y);
        }
    }
    
     
}

int main(void){
    //get n and m
    int n,m;
    scanf("%d %d", &n, &m);

    //make structs
    struct dot centers[n];
    struct dot dots[m];

    //get centers and dots
    for (int i = 0; i < n; i++){
        int a,b;
        scanf("%d %d",&a, &b);
        centers[i].x = a;
        centers[i].y = b;
    }
    for (int i = 0; i < m; i++){
            int a,b;
            scanf("%d %d",&a, &b);
            dots[i].x = a;
            dots[i].y = b;
    }
    
    int witch_center = 0;

    //make processes
    for(int i=0; i < n; i++){
        witch_center = i;
        int pid = fork();
        if (!pid)
            break;
        if (i == n - 1)
            witch_center = -1;
    }

    if (witch_center != -1)
    {
        struct dot center = centers[witch_center];
        nearest_dot(center, dots, m);
    }

}