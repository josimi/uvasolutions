// problem 12376
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	int ntests;
	int nnodes, nedges;
	int nv[101];
	int nt[101];
	vector<int> e[101];
	queue<int> q;
	int maxl;
	int maxn;

	scanf("%d", &ntests);

	for(int ct = 1;ct <= ntests;ct++) {
		scanf("%d %d", &nnodes, &nedges);

		for(int c = 0;c < nnodes;c++) {
			scanf("%d", nv + c);
			e[c].clear();
		}

		memset(nt, 0, sizeof(nt));

		for(int c = 0;c < nedges;c++) {
			int u, v;

			scanf("%d %d", &u, &v);

			e[u].push_back(v);
		}

		q.push(0);
		maxl = 0;
		maxn = 0;

		while(!q.empty()) {
			int t = q.front();
			q.pop();

			int w = -1;
			int nn = 0;

			for(vector<int>::iterator it = e[t].begin();it != e[t].end();it++) {
				if(nv[*it] > w) {
					w = nv[*it];
					nn = *it;
				}
			}

			if(nn != 0) {
			nt[nn] = nv[nn] + nt[t];
			q.push(nn);
		}

			if(maxl < nt[nn]) {
				maxl = nt[nn];
				maxn = nn;
			}
		}

		printf("Case %d: %d %d\n", ct, maxl, maxn);
	}

	return 0;
}