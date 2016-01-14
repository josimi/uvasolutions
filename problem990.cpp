// problem 990
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int dp[32][1005];
int t, w;
int n;
int val[32];
int d[32];

int main() {
	bool pr = false;

	while(scanf("%d %d", &t, &w) == 2) {
		if(pr) { putchar('\n'); }

		pr = true;

		scanf("%d", &n);

		memset(dp, 0, sizeof(dp));

		for(int c = 1;c <= n;c++) {
			scanf("%d %d", d+c, val+c);
			d[c] *= w*3;
		}

		int maxval = 0;
		int maxy;

		for(int x = 1;x <= n;x++) {
			for(int y = 0;y <= t;y++) {
				if(d[x] <= y) {
					dp[x][y] = max(dp[x - 1][y - d[x]] + val[x], dp[x - 1][y]);

					if(dp[x][y] > maxval) {
						maxval = dp[x][y];
						maxy = y;
					}
				} else {
					dp[x][y] = dp[x - 1][y];
				}
			}
		}

		printf("%d\n", maxval);

		vector<int> v;

		int vt = maxval;
		int ct = maxy;

		for(int x = n;x > 0;x--) {
			if(dp[x][ct] == vt && dp[x-1][ct-d[x]] == vt - val[x]) {
				v.push_back(x);

				vt -= val[x];
				ct -= d[x];
			}
		}

		printf("%d\n", (int)v.size());

		sort(v.begin(), v.end());

		for(vector<int>::iterator it = v.begin();it != v.end();it++) {
			printf("%d %d\n", d[*it] / (3 * w), val[*it]);
		}
	}

	return 0;
}