#include<iostream>
using namespace std;
int gcd(int da,int xiao){
    int temp;
    while(xiao!=0){
        temp=da%xiao;
        da=xiao;
        xiao=temp;
    }
    return da;
}
int main(){
    int a,b;
    cin>>a>>b;
    int lcm=a*gcd(a,b)/b;
    cout<<lcm;


    return 0;
}
