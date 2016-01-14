// problem 11003
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1005][3005];
int weight[1005];
int cap[1005];
int nboxes;

int height(int i, int wcap) {
	int ret;

	if(i == nboxes) { return  0; }

	if(wcap < 3005) {
		if(dp[i][wcap] != -1) {
			return dp[i][wcap];
		}
	}
	
	if(wcap < weight[i]) {
		ret = height(i + 1, wcap);
	} else {
		ret = max(height(i + 1, wcap), 1 + height(i + 1, min(wcap - weight[i], cap[i])));
	}

	if(wcap < 3005) {
		dp[i][wcap] = ret;
	}

	return ret;
}

int main() {
	while(scanf("%d", &nboxes) == 1) {
		if(nboxes == 0) { break; }

		memset(dp, -1, sizeof(dp));

		for(int c = 0;c < nboxes;c++) {
			scanf("%d %d", weight + c, cap + c);
		}

		printf("%d\n", height(0, 10000));
	}

	return 0;
}