// problem 10238
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int faces;

long long dp[4001][51];

long long f(int sum, int throws) {
	if(sum < 1) { return 0; }

	if(throws == 1) {
		return sum <= faces ? 1 : 0;
	}

	if(dp[sum][throws] != -1) {
		return dp[sum][throws];
	}

	dp[sum][throws] = 0;

	for(int i = 1;i <= min(faces,sum);i++) {
		dp[sum][throws] += f(sum - i, throws - 1);
	}

	return dp[sum][throws];
}

long long powi(long long x, int y) {
	long long ret = 1;

	for(int i = 0;i < y;i++) {
		ret *= x;
	}

	return ret;
}

int main() {
	int throws;
	int sum;

	while(scanf("%d %d %d", &faces, &throws, &sum) == 3) {
		memset(dp, -1, sizeof(dp));

		printf("%lld/%lld\n", f(sum, throws), powi(faces,throws));
	}

	return 0;
}