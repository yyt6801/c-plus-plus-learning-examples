#include<stdio.h>
#include<stdlib.h>
int main(){
    int ASC_FL_OS=16;
    int ASC_FL_DS=47;
    ASC_FL_OS++;ASC_FL_DS--;
    printf("%d;%d\n",ASC_FL_OS,ASC_FL_DS);
    float Xi[ASC_FL_DS - ASC_FL_OS];
    for(int xii=0;xii<=ASC_FL_DS - ASC_FL_OS;xii++) {
        Xi[xii] = (2 * xii / float(ASC_FL_DS - ASC_FL_OS)) - 1;
        printf( "xii的值为%d, Xi的值为%f\n",xii,Xi[xii]);
    }

}