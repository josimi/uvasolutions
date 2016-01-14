// problem 10397
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int root[800];
vector<pair<double, pair<int, int> > > edges;
int posx[800];
int posy[800];

int unionfind(int u) {
	if(root[u] != u) {
		return root[u] = unionfind(root[u]);
	} else {
		return u;
	}
}

void makeunion(int v, int u) {
	root[unionfind(v)] = unionfind(u);
}

double len(int a, int b) {
	double dx = posx[a] - posx[b];
	double dy = posy[a] - posy[b];

	return sqrt(dx*dx + dy*dy);
}

int main() {
	int n;

	while(scanf("%d", &n) == 1) {
		edges.clear();

		for(int c = 0;c < n;c++) {
			scanf("%d %d", posx+c, posy+c);

			root[c] = c;
		}

		int ncables;
		scanf("%d", &ncables);

		for(int c = 0;c < ncables;c++) {
			int a, b;
			scanf("%d %d", &a, &b);

			makeunion(a - 1, b - 1);
		}

		for(int x = 0;x < n;x++) {
			for(int y = 0;y < n;y++) {
				edges.push_back(pair<double, pair<int, int> >(len(x,y), pair<int, int>(x, y)));
			}
		}

		sort(edges.begin(), edges.end());

		double cost = 0;

		for(int c = 0;c < edges.size();c++) {
			if(unionfind(edges[c].second.first) != unionfind(edges[c].second.second)) {
				makeunion(edges[c].second.first, edges[c].second.second);
				cost += edges[c].first;
			}
		}
		
		printf("%.2lf\n", cost);
	}

	return 0;
}