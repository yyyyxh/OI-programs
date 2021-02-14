/*
	author:yyyyxh
	exam:CF7C
	date:2020.10.18
	status:
	difficult:Green
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=5e+18;
ll gcd(ll a,ll b){
	if (!b) return a;
	return gcd(b,a%b);
}
ll exgcd(ll a,ll b,ll &x,ll &y){
	if (!b) {
		x=1; y=0;
		return a;
	}
	ll d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;
	return d;
}
void divs(ll &a,ll &b,ll &c){
	ll t=gcd(a,b); t=gcd(t,c);
	a/=t; b/=t; c/=t;
}
void solve(ll a,ll b,ll c){
	divs(a,b,c);
	ll x,y;
	ll s=exgcd(a,b,x,y);
	if (c%s!=0){
		puts("-1");
		return ;
	}
	printf("%lld %lld\n",c/s*x,c/s*y);
}
int main(){
	ll A,B,C;
	scanf("%lld %lld %lld",&A,&B,&C);
	solve(A,B,-C);
	return 0;
}

