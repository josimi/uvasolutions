// problem 911
// Jonathon Simister

#include <cstdio>

using namespace std;

int choose(int n, int k) {
	if(k > (n - k)) {
		return choose(n, n - k);
	}

	if(k == 0) { return 1; }
	if(k > n) { return 0; }
	if(n < 1) { return 0; }
	if(k == n) { return 1; }
	if(k == 1) { return n; }

	return choose(n - 1, k - 1) + choose(n - 1, k);
}

int main() {
	int n, k;
	int a[101];
	int t;
	
	while(scanf("%d", &n) == 1) {
		scanf("%d", &k);

		for(int c = 0;c < k;c++) {
			scanf("%d", a + c);
		}

		t = 1;

		for(int c = 0;c < k && n > 0;c++) {
			t *= choose(n, a[c]);
			n -= a[c];
		}

		printf("%d\n", t);
	}

	return 0;
}