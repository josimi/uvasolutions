// problem 10050
// Jonathon Simister

#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int ntests;
	int a[4000];
	int ndays;
	int nparties;
	int h;

	scanf("%d", &ntests);

	while(ntests--) {
		memset(a, 0, sizeof(a));

		scanf("%d", &ndays);
		scanf("%d", &nparties);

		for(int p = 0;p < nparties;p++) {
			scanf("%d", &h);

			for(int x = h - 1;x < 4000;x += h) {
				a[x] += 1;
			}
		}

		int missed = 0;

		for(int x = 0;x < ndays;x++) {
			if((x % 7) == 5 || (x % 7) == 6) { continue; }

			if(a[x] != 0) {
				missed++;
			}
		}

		printf("%d\n", missed);
	}

	return 0;
}