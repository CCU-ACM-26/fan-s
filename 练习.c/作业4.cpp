#include<stdio.h>
#define PI 3.1415926
int main()
{
    float r,h;
    printf("请输入半径r和圆柱高h：");
    scanf("%f%f",&r,&h);
    float circleL = 2*PI*r;
    float circleS = PI*r*r;
    float ballS = 4*PI*r*r;
    float ballV = (4.0/3)*PI*r*r*r;
    float cylinderV = PI*r*r*h;
    printf("圆周长 = %.2f\n",circleL);
    printf("圆面积 = %.2f\n",circleS);
    printf("圆球表面积 = %.2f\n",ballS);
    printf("圆球体积 = %.2f\n",ballV);
    printf("圆柱体积 = %.2f\n",cylinderV);
    return 0;
}

