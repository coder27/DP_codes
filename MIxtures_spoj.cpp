#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int colors[102][102];

int dp[102][102];


int n;

void init() {

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			dp[i][j]=-1;
		}
		dp[i][i]=0;
	}
}

int main(){
    
	while(scanf("%d",&n)!=EOF) {
		
		init();
		for(int i=1;i<=n;i++) {
			scanf("%d",&colors[i][i]);
		}
		
		for(int i=1;i<=n;i++) {
			for(int j=i+1;j<=n;j++) {
				colors[i][j] = (colors[i][j-1]+colors[j][j])%100;
			}
		}

		 for (int L=2;L<=n;L++) {
			for(int i=1;i<=n-L+1;i++) {
				int j = i+L-1;
					int &ret = dp[i][j];

					for(int k=i+1;k<=j;k++) {
						int aux = dp[i][k-1]+dp[k][j]+colors[i][k-1]*colors[k][j];

						if((ret==-1) || (aux<ret)) {
							ret = aux;
						}
					}
			}
		}
		cout<<dp[1][n]<<endl;

	}

	
    return 0;
}
