#include <bits/stdc++.h>
using namespace std;
const int N=10000003;
int t[N],c[N],d[N],ctot,id[N],co[N],w[N];
int n,m;
bool v[N],s[N];
int mht(int l,int r){
	if (id[l]<=id[r]) return id[r]-id[l];
	return co[w[l]]-id[l]+id[r];
}
void circle(int x){
	int cur=x,cnt=0;
	ctot++;
	do{
		d[cur]=0;
		c[cur]=cur;
		id[cur]=++cnt;
		w[cur]=ctot;
	//	cout<<cur<<" ";
		cur=t[cur];
	}while (cur!=x);
//	cout<<endl;
	co[ctot]=cnt;
}
void getc(int x){
	if (v[x]){
		circle(x);
		return ;
	}
	if (s[x]){
		return ;
	}
	s[x]=1;
	v[x]=1;
	getc(t[x]);
	v[x]=0;
}
void gets(int x){
	if (w[x]||s[x]){
		return ;
	}
	gets(t[x]);
	s[x]=1;
	d[x]=d[t[x]]+1;
	c[x]=c[t[x]];
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1; i<=n; i++) scanf("%d",t+i);
	for (int i=1; i<=n; i++){
		if (!s[i]){
			getc(i);
		}
	}
	memset(s,0,sizeof(s));
	for (int i=1; i<=n; i++){
		if (!s[i]){
			gets(i);
		}
	}
//	for (int i=1; i<=n; i++){
//		printf("c:%d d:%d id:%d\n",c[i],d[i],i);
//	}
	for (int i=1; i<=m; i++){
		int u,v;
		scanf("%d%d",&u,&v);
		printf("%d\n",mht(c[u],c[v])+d[u]-d[v]);
	}
	return 0;
}
