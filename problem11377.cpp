// problem 11377
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int ntests;

	scanf("%d", &ntests);

	bool** am;

	am = new bool*[2000];

	for(int c = 0;c < 2000;c++) {
		am[c] = new bool[2000];
	}

	for(int ct = 1;ct <= ntests;ct++) {
		int ncities, nroutes, nairports;
		bool hasairport[2000];
		int dist[2000];

		scanf("%d %d %d", &ncities, &nroutes, &nairports);

		memset(hasairport, false, sizeof(hasairport));

		for(int c = 0;c < 2000;c++) {
			memset(am[c], false, 2000 * sizeof(bool));
		}

		for(int c = 0;c < nairports;c++) {
			int i;
			scanf("%d", &i);
			hasairport[i - 1] = true;
		}

		for(int c = 0;c < nroutes;c++) {
			int a, b;

			scanf("%d %d", &a, &b);

			am[a - 1][b - 1] = true;
			am[b - 1][a - 1] = true;
		}

		int nqueries;

		if(ct > 1) {
			putchar('\n');
		}

		printf("Case %d:\n", ct);

		scanf("%d", &nqueries);

		for(int c = 0;c < nqueries;c++) {
			int start, dest;
			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;

			scanf("%d %d", &start, &dest);

			start--;
			dest--;

			memset(dist, 0x3F, sizeof(dist));

			dist[start] = 0;

			q.push(pair<int, int>(0, start));

			while(!q.empty()) {
				pair<int, int> t = q.top();
				q.pop();

				for(int x = 0;x < ncities;x++) {
					if(am[t.second][x]) {
						int cost = 0;

						if(hasairport[t.second] == false && t.second == start) { cost++; }
						if(hasairport[x] == false) { cost++; }

						if((dist[t.second] + cost) < dist[x]) {
							dist[x] = dist[t.second] + cost;
							q.push(pair<int, int>(dist[x], x));
						}
					}
				}
			}
		
			if(dist[dest] == 0x3f3f3f3f) {
				puts("-1");
			} else {
				printf("%d\n", dist[dest]);
			}
		}
	}

	return 0;
}