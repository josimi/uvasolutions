// problem 10302
// Jonathon Simister

#include <cstdio>

using namespace std;

int main() {
	long long ll;

	while(scanf("%lld", &ll) == 1) {
		long long sum = (ll * (ll + (long long)1)) / (long long)2;

		printf("%lld\n", sum*sum);
	}

	return 0;
}