// problem 11296
// Jonathon Simister

#include <cstdio>

using namespace std;

long long g(int n) {
	return (n / 2) + 1;
}

long long f(int n) {
	long long ret = 0;
	
	for(int i = 0;i <= (n / 2);i++) {
		ret += g(n - (2 * i));
	}

	return ret;
}

int main() {
	int n;
	
	while(scanf("%d", &n) == 1) {
		printf("%lld\n", f(n));
	}

	return 0;
}