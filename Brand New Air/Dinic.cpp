#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=203,M=10003;
const ll INF=1e+18;
int head[N],to[M],next[M],d[N],now[M],n,m,s,t,tot=1;
ll c[M];
queue<int> q;
void add(int u,int v,ll w){
	tot++;
	next[tot]=head[u];
	head[u]=tot;
	c[tot]=w;
	to[tot]=v;
}
bool bfs(){
	memset(d,0,sizeof(d));
	q.push(s); d[s]=1; now[s]=head[s];
	while (!q.empty()){
		int x=q.front(); q.pop();
		for (int i=head[x]; i; i=next[i]){
			int y=to[i];
			if (c[i]&&!d[y]){
				q.push(y);
				now[y]=head[y];
				d[y]=d[x]+1;
			}
		}
	}
	return d[t];
}
ll dinic(int x,ll flow){
	if (x==t) return flow;
	ll rest=flow,i;
	for (i=now[x]; i&&rest; i=next[i]){
		int y=to[i];
		if (c[i]&&d[y]==d[x]+1){
			ll k=dinic(y,min(rest,c[i]));
			if (!k) d[y]=0;
			c[i]-=k;
			c[i^1]+=k;
			rest-=k;
		}
	}
	now[x]=i;
	return flow-rest;
}
int main(){
//	freopen("P3376_9.in","r",stdin);
//	freopen("P3376_9.ans","w",stdout);
	scanf("%d %d %d %d",&n,&m,&s,&t);
	for (int i=1; i<=m; i++){
		int u,v;
		ll w;
		scanf("%d %d %lld",&u,&v,&w);
		add(u,v,w);
		add(v,u,0);
	}
	ll ans=0;
	while (bfs())
		ans+=dinic(s,INF);
	cout<<ans<<endl;
	return 0;
}
