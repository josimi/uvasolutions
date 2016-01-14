// problem 10264
// Jonathon Simister

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int n;
	int* a = new int[32768];
	int* sum = new int[32768];

	while(scanf("%d", &n) == 1) {
		for(int i = 0;i < (1 << n);i++) {
			scanf("%d", a + i);
		}

		for(int i = 0;i < (1 << n);i++) {
			sum[i] = a[i];

			for(int x = 1;x < (1 << n);x = x << 1) {
				sum[i] += a[i ^ x];
			}
 		}

		int maxP = 0;

		for(int i = 0;i < (1 << n);i++) {
			for(int x = 1;x < (1 << n);x = x << 1) {
				int p = sum[i] + sum[i ^ x] - a[i] - a[i ^ x];

				maxP = max(maxP, p);
			}
		}

		printf("%d\n", maxP);
	}

	return 0;
}