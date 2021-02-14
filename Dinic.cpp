#include <bits/stdc++.h>
using namespace std;
const int N=1003,M=20003;
const long long INF=1e18;
int n,m,s,t;
int cur[N],dis[N];
queue<int> q;
long long val[M];
int nxt[M],hd[N],tot=1,ver[M];
inline void adds(int u,int v,long long w){
	tot++; nxt[tot]=hd[u]; hd[u]=tot; ver[tot]=v; val[tot]+=w;
	tot++; nxt[tot]=hd[v]; hd[v]=tot; ver[tot]=u; val[tot]+=0; 
}
long long dinic(int u,long long nf){
	long long tf=0;
	if (!nf||u==t) return nf;
	for (register int i=cur[u]; i&&nf; i=nxt[i]){
		cur[u]=i;
		int v=ver[i]; long long w=val[i];
		if (!w||dis[u]+1!=dis[v]) continue;
		long long sf=dinic(v,min(nf,w));
		val[i]-=sf;
		val[i^1]+=sf;
		tf+=sf;
		nf-=sf;
	}
	if (!tf) dis[u]=-1;
	return tf;
}
bool bfs(){
	memset(dis,-1,sizeof dis);
	dis[s]=1;
	q.push(s);
	while (!q.empty()){
		int u=q.front(); q.pop();
		cur[u]=hd[u];
		for (register int i=hd[u]; i; i=nxt[i]){
			int v=ver[i]; long long w=val[i];
			if (!w||dis[v]>0) continue;
			dis[v]=dis[u]+1; 
			q.push(v);
		}
	}
	return dis[t]!=-1;
}
long long Dinic(){
	long long flow=0,ans=0;
	while (bfs())
		while (flow=dinic(s,INF))
			ans+=flow;
	return ans;
}
int ctd(char c){
	if (c>='A'&&c<='Z') return c-'A'+1;
	else return c-'a'+27;
}
int main(){
	n=52; cin>>m; s=1; t=26;
	for (register int i=1; i<=m; i++){
		char u,v; long long w;
		cin>>u>>v>>w;
		adds(ctd(u),ctd(v),w);
	}
	printf("%lld\n",Dinic());
	return 0;
}
