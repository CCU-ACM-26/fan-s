#include<iostream>
#include<cstring>
using namespace std;
int cnt[10];
bool check(int x,int y,int z){
	if(y>999||z>999)return false;
	memset(cnt,0,sizeof(cnt));
	int num[3]={x,y,z};
	for(int t=0;t<3;t++){
		int v=num[t];
		while(v>0){
			cnt[v%10]++;
			v/=10;
		}
	}
	for(int d=1;d<=9;d++){
		if(cnt[d]!=1)return false;
	}
	return cnt[0]==0;
}
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	if(a==0){
		cout<<"No!!!\n";return 0;
	}
	bool found=false;
	for(int x=123;x<=987;x++){
		if(x%a!=0)continue;
		int y=x*b/a;
		int z=x*c/a;
		if(check(x,y,z))
		{
			cout<<x<<" "<<y<<" "<<z<<"\n";
			found=true;
		}
	}
	if(!found)cout<<"No!!!\n";
	
    return 0;

} 
