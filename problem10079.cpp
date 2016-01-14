// problem 10079
// Jonathon Simister

#include <cstdio>

using namespace std;

int main() {
	long long n;
	long long s;

	while(scanf("%lld", &n) == 1) {
		if(n < 0) { break; }

		s = (((n - 1) * n) / 2) + 1 + n;

		printf("%lld\n", s);
	}

	return 0;
}