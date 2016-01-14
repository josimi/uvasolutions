// problem 408
// Jonathon Simister

#include <cstdio>

using namespace std;

int gcd(int a, int b) {
	int c;

	while(a != 0) {
		c = b%a;
		b = a;
		a = c;
	}

	return b;
}

int main() {
	int step, mod;
	
	while(scanf("%d %d", &step, &mod) == 2) {
		printf("% 10d% 10d    ", step, mod);

		if(gcd(step, mod) == 1) {
			puts("Good Choice");
		} else {
			puts("Bad Choice");
		}

		putchar('\n');
	}

	return 0;
}