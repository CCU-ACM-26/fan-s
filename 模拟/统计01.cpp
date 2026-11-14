#include<bits/stdc++.h>
using namespace std;
int n,x;
int cnt,nailong;
int main(){
    cin>>n;
    string s1,s2;
    cin>>s1>>s2;
    
    for(int i=0;i<n;i++){
       
        if(s1[i]=='0')cnt++;
        else nailong++;
        
        if(s2[i]=='0')cnt++;
        else nailong++;
    }
       
    cout<<cnt<<" "<<nailong;
    
    return 0;
}