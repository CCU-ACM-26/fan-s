#include<iostream>
#include<string>
using namespace std;
string s;

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>s;
		int n=s.size();
		int k=1;
		for(int i=1;i<=n;i++){
			if(s[i]!=s[i-1])k++;
		}
		bool p=false,m=true;
		for(int i=1;i<n-1;i++){
			if(s[i]!=s[i-1]&&s[i]!=s[i+1])p=true;
			if(s[i]==s[i-1]&&s[i]==s[i+1])m=true;
		}
		cout<<k+p+m<<endl;
	}
	return 0;
}
