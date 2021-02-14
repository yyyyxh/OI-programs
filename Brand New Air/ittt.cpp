#include <bits/stdc++.h>
using namespace std;
const int N=10003;
int n,m,ans,a[N];
int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		a[i]<<=1;
	}
	for(int i=1; i<=m; i++){
		int x,y,z;
		cin>>x>>y>>z;
		a[x]+=z; a[y]+=z;
	}
	sort(a+1,a+1+n);
	for (int i=1; i<n; i+=2){
		ans+=a[i+1]-a[i];
	}
	cout<<(ans>>1)<<endl;
	return 0;
}
