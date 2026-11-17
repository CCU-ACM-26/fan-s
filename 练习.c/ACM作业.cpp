#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	int k=0;
	while(t--){
		int n;
		string s;
		cin>>n>>s;
		int count=0;
		int L=-1;int R=-1;
	for(int i=0;i<n;i++){
		if(s[i]=='1'){
			k++;
		if(L==-1) L=i+1;
		R=i+1;
		}
	
	}
	int ans=0;
	if(k==1)ans=0;
	if(k==2)ans=1;
	else ans=R-L;
	cout<<ans<<endl; 
		
	}

	
	
	return 0;
}
