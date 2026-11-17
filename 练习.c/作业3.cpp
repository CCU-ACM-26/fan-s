#include <stdio.h>
int main()
{
   char ch;
   printf("请输入一个大写字母:");
   scanf("%c",&ch);
   ch=ch+32;
   printf("对应的小写字母为:%c\n",ch);
   return 0;
}
