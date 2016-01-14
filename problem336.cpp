// problem 336
// Jonathon Simister

#include <cstdio>
#include <map>
#include <queue>
#include <cstring>

using namespace std;

map<int, int> nodemap;

int nodeid(int name) {
	if(nodemap.count(name) == 0) {
		nodemap[name] = nodemap.size();
	}

	return nodemap[name];
}

int main() {
	int nc;
	bool am[40][40];
	unsigned int dist[40];
	int ct = 0;

	while(scanf("%d", &nc) == 1) {
		if(nc == 0) { break; }

		memset(am, false, sizeof(am));
		nodemap.clear();

		for(int c = 0;c < nc;c++) {
			int a, b;

			scanf("%d %d", &a, &b);

			am[nodeid(a)][nodeid(b)] = true;
			am[nodeid(b)][nodeid(a)] = true;
		}


		int start, ttl;

		while(scanf("%d %d", &start, &ttl) == 2) {
			if(start == 0 && ttl == 0) { break; }

			queue<int> q;

			memset(dist, 0x3F, sizeof(dist));

			dist[nodeid(start)] = 0;

			q.push(nodeid(start));

			while(!q.empty()) {
				int t = q.front();
				q.pop();

				if(dist[t] < ttl) {
					for(int x = 0;x < 40;x++) {
						if(am[t][x] && dist[x] >(dist[t] + 1)) {
							dist[x] = dist[t] + 1;
							q.push(x);
						}
					}
				}
			}

			int count = 0;

			for(map<int, int>::iterator it = nodemap.begin();it != nodemap.end();it++) {
				if(dist[it->second] == 0x3F3F3F3F) {
					count++;
				}
			}

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++ct, count, start, ttl);
		}
	}

	return 0;
}