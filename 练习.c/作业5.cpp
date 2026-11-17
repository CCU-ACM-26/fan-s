#include<stdio.h>
int main()
{
    int num;
    printf("请输入一个三位数：");
    scanf("%d",&num);
    int hundreds = num / 100;       
    int tens = num /10 %10;          
    int units = num %10;             
    printf("百位：%d，十位：%d，个位：%d\n",hundreds,tens,units);
    return 0;
}

