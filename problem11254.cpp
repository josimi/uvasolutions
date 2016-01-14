// problem 11254
// Jonathon Simister

#include <cstdio>
#include <cmath>

using namespace std;

int main() {
	int n;

	while(scanf("%d", &n) == 1) {
		if(n == -1) { break; }

		if(n == 0) {
			puts("0 = 0 + ... + 0");
			continue;
		}

		int k = sqrt(n) + 1;
		
		double x;

		do {
			k--;
			x = ((double)n / (double)k) - 0.5*k - 0.5;
		} while(x != floor(x));

		int i = x;

		printf("%d = %d + ... + %d\n", n, i + 1, i + k);
	}

	return 0;
}