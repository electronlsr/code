#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,c,k,cnt[57];
double dp[57][107],sum[57],ans;
int main() {
	freopen("elephant.in","r",stdin);
	freopen("elephant.out","w",stdout);
	cin>>T;
	for(register int ttt=1; ttt<=T; ++ttt) {
		memset(cnt,0,sizeof(cnt));
		cin>>n>>c>>k;
		for(register int i=1; i<=k; i++) {
			int l,r;
			cin>>l>>r;
			for(register int j=l; j<=r; j++)
				++cnt[j];
		}
		memset(dp,0,sizeof(dp));
		memset(sum,0,sizeof(sum));
		dp[0][1]=1;
		for(register int i=0; i<=k; i++)
			for(register int j=0; j<c; j++) {
				dp[i+1][j]+=dp[i][j]/2;
				for(register int x=0; x<c; x++)
					dp[i+1][j*x%c]+=dp[i][j]/2/c;
			}
		for(register int i=0; i<=k; i++)
			for(register int j=0; j<c; j++)
				sum[i]+=dp[i][j]*j;
		ans=0;
		for(int i=1; i<=n; i++)
			ans+=sum[cnt[i]];
		printf("%.9lf\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
}

