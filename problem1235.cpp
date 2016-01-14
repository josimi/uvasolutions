// problem 1235
// Jonathon Simister

#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int root[550];

int unionfind(int v) {
	if(root[v] == v) {
		return v;
	} else {
		return root[v] = unionfind(root[v]);
	}
}

void makeunion(int u, int v) {
	root[unionfind(u)] = unionfind(v);
}

int p(int n, int place) {
	return (n / place) % 10;
}

int rolldist(int a, int b) {
	//printf("rolldist(%d,%d) = ", a, b);

	int ia, ib;

	ia = p(a, 1);
	ib = p(b, 1);
	int d1 = abs(ia - ib);
	d1 = min(min(d1, 10 - ia + ib),10 - ib + ia);

	ia = p(a, 10);
	ib = p(b, 10);
	int d10 = abs(ia - ib);
	d10 = min(min(d10, 10 - ia + ib), 10 - ib + ia);

	ia = p(a, 100);
	ib = p(b, 100);
	int d100 = abs(ia - ib);
	d100 = min(min(d100, 10 - ia + ib), 10 - ib + ia);

	ia = p(a, 1000);
	ib = p(b, 1000);
	int d1000 = abs(ia - ib);
	d1000 = min(min(d1000, 10 - ia + ib), 10 - ib + ia);

	//printf("%d %d %d %d\n", d1, d10, d100, d1000);

	return d1 + d10 + d100 + d1000;
}

int main() {
	int ntests;

	scanf("%d", &ntests);

	//printf("%d\n", rolldist(5678, 9090));

	while(ntests--) {
		int n;
		vector<int> v;
		vector<pair<int, pair<int, int> > > edges;
		int mst = 0;
		bool has0 = false;

		scanf("%d", &n);

		for(int c = 0;c < n;c++) {
			int i;

			scanf("%d", &i);

			if(i == 0) { has0 = true; }

			v.push_back(i);
			root[c] = c;
		}

		for(int x = 0;x < v.size();x++) {
			for(int y = 0;y < v.size();y++) {
				if(x == y) { continue; }

				edges.push_back(pair<int, pair<int, int> >(rolldist(v[x],v[y]), pair<int, int>(x, y)));
			}
		}

		sort(edges.begin(), edges.end());

		for(int c = 0;c < edges.size();c++) {
			if(unionfind(edges[c].second.first) != unionfind(edges[c].second.second)) {
				//printf("edge between %d and %d size %d\n", v[edges[c].second.first], v[edges[c].second.second], edges[c].first);

				mst += edges[c].first;
				makeunion(edges[c].second.first, edges[c].second.second);
			}
		}

		if(!has0) {
			int mindist = INT_MAX;

			for(int c = 0;c < v.size();c++) {
				mindist = min(mindist, rolldist(0, v[c]));
			}

			mst += mindist;
		}

		printf("%d\n", mst);
	}

	return 0;
}