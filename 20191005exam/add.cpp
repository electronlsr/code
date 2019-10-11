#include<bits/stdc++.h>
using namespace std;
int a[300007],b[300007];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	for(register int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(register int i=31;i>=0;--i){
		int now=0;
		for(register int j=1;j<=n;++j){
			if(a[j]&(1<<i)){
				b[++now]=a[j];
			}
		}
		if(now>=2){
			for(register int j=1;j<=now;++j){
				a[j]=b[j];
			}
			n=now;
		}
	}
	cout<<(a[1]&a[n])<<endl;
	fclose(stdin);
	fclose(stdout);
}
