// problem 412
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <cmath>

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
	int n;
	vector<int> v;
	int rp;
	int tp;

	while(scanf("%d", &n) == 1) {
		if(n == 0) { break; }

		v.clear();

		for(int c = 0;c < n;c++) {
			int i;

			scanf("%d", &i);

			v.push_back(i);
		}

		rp = 0;
		tp = ((v.size())*(v.size() - 1)) / 2;

		for(int x = 0;x < n;x++) {
			for(int y = x + 1;y < n;y++) {
				if(gcd(v[x], v[y]) == 1) {
					rp++;
				}
			}
		}

		double x;

		if(rp == 0) {
			puts("No estimate for this data set.");
		} else {
			x = sqrt(6 * ((double)tp / (double)rp));
			printf("%.6lf\n", x);
		}
	}

	return 0;
}