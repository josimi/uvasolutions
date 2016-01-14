// problem 11228
// Jonathon Simister

#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int root[1005];
double cx[1005];
double cy[1005];
vector<pair<double, pair<int, int> > > edges;

int unionfind(int v) {
	if(root[v] == v) {
		return v;
	} else {
		return root[v] = unionfind(root[v]);
	}
}

void makeunion(int v, int u) {
	root[unionfind(v)] = unionfind(u);
}

int main() {
	int ntests;
	
	scanf("%d", &ntests);

	for(int ct = 1;ct <= ntests;ct++) {
		int ncities;
		double threshold;
		double roadlength = 0;
		double raillength = 0;
		int nstates = 1;

		scanf("%d %lf", &ncities, &threshold);

		for(int c = 0;c < ncities;c++) {
			scanf("%lf %lf", cx + c, cy + c);
			root[c] = c;
		}

		edges.clear();

		for(int x = 0;x < ncities;x++) {
			for(int y = 0;y < ncities;y++) {
				double dx = cx[y] - cx[x];
				double dy = cy[y] - cy[x];

				edges.push_back(pair<double, pair<int, int> >(sqrt(dx*dx + dy*dy), pair<int, int>(x, y)));
			}
		}

		sort(edges.begin(), edges.end());

		for(int c = 0;c < edges.size();c++) {
			if(unionfind(edges[c].second.first) != unionfind(edges[c].second.second)) {
				if(edges[c].first <= threshold) {
					roadlength += edges[c].first;
				} else {
					raillength += edges[c].first;
					nstates++;
				}

				makeunion(edges[c].second.first, edges[c].second.second);
			}
		}

		printf("Case #%d: %d %.0lf %.0lf\n", ct, nstates, roadlength, raillength);
	}

	return 0;
}