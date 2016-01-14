// problem 11479
// Jonathon Simister

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int ntests;
	long long a, b, c;

	scanf("%d", &ntests);

	for(int ct = 1;ct <= ntests;ct++) {
		scanf("%lld %lld %lld", &a, &b, &c);

		printf("Case %d: ", ct);

		if(a <= 0 || b <= 0 || c <= 0) {
			puts("Invalid");
		} else if(a == b && c == b) {
			puts("Equilateral");
		} else if(abs(a-b) >= c || abs(b-c) >= a || abs(a-c) >= b) {
			puts("Invalid");
		} else if(a + b <= c || a + c <= b || c + b <= a) {
			puts("Invalid");
		} else if(a == b || c == b || a == c) {
			puts("Isosceles");
		} else {
			puts("Scalene");
		}
	}

	return 0;
}