#include <bits/stdc++.h> 
using namespace std;
const int N=100006,INF=2147483627;
int n,b,cur,tmp;
int h(int x){
	return x+n;
}
int l[N*2],r[N*2],s[N],ans;
int mn,mx;
int main(){
	cin>>n>>b;
	mn=INF; mx=-INF;
	for (int i=1; i<=n; i++){
		int a;
		cin>>a;
		if (a<b) s[i]=-1;
		if (a>b) s[i]=1;
		if (a==b) tmp=i;
	}
	cur=0; l[h(0)]=1;
	for (int i=tmp-1; i; i--){
		cur+=s[i];
		mx=max(cur,mx);
		mn=min(cur,mn);
		l[h(cur)]++;
	}
	cur=0; r[h(0)]=1;
	for (int i=tmp+1; i<=n; i++){
		cur+=s[i];
		mx=max(cur,mx);
		mn=min(cur,mn);
		r[h(cur)]++;
	}
	int ans=0;
	for (int i=mn; i<=mx; i++){
		ans+=l[h(i)]*r[h(-i)];
	}
	cout<<ans<<endl;
}