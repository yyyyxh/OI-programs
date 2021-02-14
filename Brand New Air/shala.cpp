/*
	author:yyyyxh
	exam:P2155
	date:2020.10.18
	status:AC
	difficult:Purple
*/
#include <bits/stdc++.h>
using namespace std;
const int N=10000003;
int inv[N+3],fact[N+3],finv[N+3],r,p[N+3],v[N+3],pre[N+3];
vector<int> prime;
typedef long long ll;
void gpri(){
	for (int i=2; i<=N; i++){
		if (!v[i]){
			v[i]=i;
			prime.push_back(i);
		}
		for (int j=0; j<prime.size(); j++){
			if (prime[j]>v[i]||prime[j]>N/i) break;
			v[i*prime[j]]=prime[j];
		}
	}
	for (int i=2; i<=N; i++){
		p[i]=p[i-1];
		if (v[i]==i) p[i]++;
	}
}
void ginv(){
	inv[1]=1;
	for (int i=2; i<=N; i++){
		inv[i]=(ll)(r-r/i)*inv[r%i]%r;
	}
}
void gfac(){
	pre[0]=fact[0]=finv[0]=1;
	for (int i=0; i<prime.size(); i++){
		if (prime[i]==r) finv[i+1]=finv[i];
		else finv[i+1]=(ll)finv[i]*inv[prime[i]%r]%r;
		fact[i+1]=(ll)fact[i]*(prime[i]-1)%r;
	}
	for (int i=1; i<=N; i++){
		if (i==r) pre[i]=pre[i-1];
		else pre[i]=(ll)pre[i-1]*i%r;
	}
}
void prev(){
	gpri();
	ginv();
	gfac();
}
int main(){
	int n,t,m;
	cin>>t>>r;
	prev();
	while (t--){
		cin>>n>>m;
		if (n>=r&&m<r) puts("0");
		else cout<<(ll)pre[n]*fact[p[m]]%r*finv[p[m]]%r<<endl;
	}
	return 0;
}

