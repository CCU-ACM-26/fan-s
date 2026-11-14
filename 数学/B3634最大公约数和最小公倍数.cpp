//B3634 最大公约数和最小公倍数
#include<iostream>
using namespace std;
long long a,b;
long long gcd(long long x,long long y){
    while(y!=0){
        long long t=x%y;
        x=y;
        y=t;
    }
    return x;
}

int main(){
    
    cin>>a>>b;
    long long t=gcd(a,b);
     if(t == 0){          
        cout << "0 0\n"; 
        return 0;
    }

    
    long long lcm=a/t*b;
    cout<<t<<" "<<lcm<<endl;
}