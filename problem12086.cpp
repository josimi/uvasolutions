// problem 12086
// Jonathon Simister

#include <cstdio>
#include <cstring>

using namespace std;

int n;
int bit[200000];
int a[200000];

void increase(int i, int d) {
	for(;i < n;i |= i + 1) {
		bit[i] += d;
	}
}

int sum(int i) {
	int sum = 0;

	while(i >= 0) {
		sum += bit[i];
		i &= i + 1;
		i--;
	}

	return sum;
}

int getsum(int l, int r) {
	return sum(r) - sum(l - 1);
}

int main() {
	int ct = 0;
	char cmd[10];

	while(scanf("%d", &n) == 1) {
		if(n == 0) { break; }

		if(ct > 0) { printf("\n"); }

		ct++;

		memset(bit, 0, sizeof(bit));
		
		for(int i = 0;i < n;i++) {
			int k;

			scanf("%d", &k);
			
			increase(i, k);
			a[i] = k;
		}

		printf("Case %d:\n", ct);

		while(scanf("%s", cmd) == 1) {
			if(strcmp(cmd, "END") == 0) {
				break;
			}

			int j, k;

			scanf("%d %d", &j, &k);

			if(cmd[0] == 'M') {
				printf("%d\n", getsum(j - 1, k - 1));
			}

			if(cmd[0] == 'S') {
				int delta = k - a[j - 1];
				increase(j - 1, delta);
				a[j - 1] = k;
			}
		}
	}

	return 0;
}