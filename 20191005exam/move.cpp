#include<bits/stdc++.h>
using namespace std;
struct egde{
	int v,w,nxt;
}mp[100007];
struct jntql{
	int u,d,f;
	bool operator<(const jntql a)const{
		return d>a.d;
	}
	jntql(int uu=0,int dd=0,int ff=0):u(uu),d(dd),f(ff){}
};
priority_queue<jntql> q;
int n,m,k,s,t,ans=0x7fffffff,cnt,h[10007],d[10007][11];
bool pd[10007][11];
void add(int u,int v,int w){
	mp[++cnt].v=v;
	mp[cnt].w=w;
	mp[cnt].nxt=h[u];
	h[u]=cnt;
}
void diji(){
	memset(d,0x3f,sizeof(d));
	d[s][0]=0;
	q.push(jntql(s,0,0));
	while(!q.empty()){
		int  u=q.top().u,f=q.top().f;
		q.pop();
		if(pd[u][f])
		continue;
		pd[u][f]=true;
		for(register int i=h[u];i;i=mp[i].nxt){
			if(d[mp[i].v][f]>d[u][f]+mp[i].w){
				d[mp[i].v][f]=d[u][f]+mp[i].w;
				q.push(jntql(mp[i].v,d[mp[i].v][f],f));
			}
			if(f<k){
				if(d[mp[i].v][f+1]>d[u][f]){
					d[mp[i].v][f+1]=d[u][f];
					q.push(jntql(mp[i].v,d[mp[i].v][f+1],f+1));
				}
			}
		}
	}
}
int main(){
	freopen("move.in","r",stdin);
	freopen("move.out","w",stdout);
	cin>>n>>m>>k>>s>>t;
	for(register int i=1;i<=m;++i){
		int a,b,c;
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	diji();
	cout<<d[t][k]<<endl;
	fclose(stdin);
	fclose(stdout);
}
