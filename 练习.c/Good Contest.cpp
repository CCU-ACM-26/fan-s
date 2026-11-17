#include<iostream>
#include<algorithm>
using namespace std;
int t;	
int n;
int a[3005];
bool cmp(int x,int y){
	return x<y; 
} 
int main(){

	cin>>t;
	for(int i=1;i<=t;i++){
	
		
		cin>>n>>a[i];
		sort(a+1,a+n+1,cmp);
		cout<<a[n]-a[1]<<"\n";
	} 
	
	
	return 0;
}
