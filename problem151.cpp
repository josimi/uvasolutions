// problem 151
// Jonathon Simister

#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int i;
	int r;
	bool a[100];
	int c;
	int s;
	int k;

	while(scanf("%d", &i) == 1) {
		if(i == 0) { break; }

		for(k = 1;true;k++) {
			memset(a, true, sizeof(a));

			a[0] = false;
			c = 0;
			r = i - 1;

			while(r > 1) {
				s = k;

				while(s > 0) {
					c = (c + 1) % i;
					if(a[c]) {
						s--;
					}
				}

				a[c] = false;
				r--;
			}

			if(a[12]) {
				break;
			}
		}

		printf("%d\n", k);
	}

	return 0;
}