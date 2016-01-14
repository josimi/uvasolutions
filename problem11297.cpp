// problem 11297
// Jonathon Simister

#include <cstdio>
#include <cstring>

using namespace std;

int bit[500 * 500];
int bitsize;

void increase(int i, int d) {
	for(;i < bitsize;i |= i + 1) {
		bit[i] += d;
	}
}

int main() {
	int n, q;

	while(scanf("%d %d", &n, &q) == 2) {
		memset(bit, 0, sizeof(bit));

		bitsize = n * n;

		for(int y = 0;y < n;y++) {
			for(int x = 0;x < n;x++) {
				int i;

				scanf("%d", &i);

				increase((y*n) + x, i);
			}
		}

		for(int i = 0;i < q;i++) {
			char s[10];

			scanf("%s", s);

			if(s[0] == 'c') {
				int x, y, d;
				scanf("%d %d %d", &x, &y, &d);
				increase((y*n) + x, d);
			}
		}
	}

	return 0;
}