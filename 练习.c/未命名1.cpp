#include<stdio.h>
#include<math.h>
int main(){
int a=3;
    int b=4;
    int c=5;

    scanf("%d %d %d\n",&a,&b,&c);
    double p=(a+b+c)/2;
   double area=sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%lf\n",area);



    return 0;
}
