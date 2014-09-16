#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp [43][43][43];
bool opening[43];

int t,n,ki;

void init() {

	for(int i=0;i<=2*n;i++) {
		opening[i]=false;
		for(int j=0;j<=2*n;j++) {
			for(int k=0;k<=2*n;k++) {
				dp[i][j][k]=-1;
			}
		}
	}
}

int solve(int idx,int count1, int count2) {

	//cout<<idx<<endl;
	//cout<<idx<<" "<<count1<<" "<<count2<<" ";
	if(count1==n) {
		bool chck = false;
		for(int h=idx; h<=2*n;h++) {
			chck|= opening[h];
		}
		if(chck) return 0;
		return 1;
	}
	if(count1>n) return 0;

	if(count2>count1) return 0;

	//if(count1==n) return 0;

	int &ret = dp[idx][count1][count2];

	if(ret==-1) {
		if(!opening[idx]){
			ret = solve(idx+1,count1+1,count2)+solve(idx+1,count1,count2+1);
		} else {
			ret = solve(idx+1,count1+1,count2);
		}
	}
	//cout<<ret<<endl;
	return ret;
}

int main(){
    
	scanf("%d",&t);
	while(t--) {
		scanf("%d %d",&n,&ki);

		init();
		int temp;
		for(int i=0;i<ki;i++) {
			scanf("%d",&temp);
			opening[temp] = true;
		}

		int ans = solve(1,0,0);
		cout<<ans<<endl;
	}

	
    return 0;
}
