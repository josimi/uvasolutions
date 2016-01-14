// problem 11389
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main() {
	int n, d, r;
	int mo[120];
	int ev[120];
	int ot;

	while(scanf("%d %d %d", &n, &d, &r) == 3) {
		if(n == 0 && d == 0 && r == 0) { break; }

		for(int c = 0;c < n;c++) {
			scanf("%d", mo + c);
		}

		for(int c = 0;c < n;c++) {
			scanf("%d", ev + c);
		}

		sort(mo, mo + n);
		sort(ev, ev + n, greater<int>());

		ot = 0;

		for(int c = 0;c < n;c++) {
			if((mo[c] + ev[c]) > d) {
				ot += (mo[c] + ev[c]) - d;
			}
		}

		printf("%d\n", ot * r);
	}

	return 0;
}