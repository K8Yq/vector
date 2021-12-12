
#include "vector.h"
#include <stdio.h>
#include <time.h>


#define Vector_2D_PRINT(v) printf("%s: {%lf %lf}\n", #v, v.x, v.y);

double func(double i){
    return i + 11;
}

void main(){

    Vector_2D v1 = {1.0, 2.0};
    Vector_2D v2 = {0.0, 4.0};
    Vector_2D v3 = {5.0, 0.0};
    Vector_2D v4 = {0.0, 5.0};

    /*tests*/

    kpnt_t res1 = Vector_2D_Distance(v1, v2);
    angle res2 = Vector_2D_Angle_Between(v3, v4);
    kpnt_t res3 = Vector_2D_Scalar(v1, v2);
    Vector_2D res4 = Vector_2D_Rotate_right(v4);
    Vector_2D res5 = Vector_2D_Div(v2, 0.0);
    Vector_2D res6 = Vector_2D_Apply_Func(v1, func);

    printf("%lf\n%lf\n%lf\n", res1, res2, res3);
    
    Vector_2D_PRINT(res4);
    Vector_2D_PRINT(res5);
    Vector_2D_PRINT(res6);

    printf("%d %d\n\n", sizeof(Vector_2D), sizeof(kpnt_t));



    clock_t start = clock(), diff;

    v1 = Vector_2D_Add(v1, v1);
    
    diff = clock() - start;


    int msec = diff * 1000 / CLOCKS_PER_SEC;
    printf("Time taken %d seconds %d milliseconds", msec/1000, msec%1000);

}
