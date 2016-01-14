// problem 10926
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int main() {
	int ntasks;
	bool dep[100][100];
	bool idp[100][100];
	int nd[100];
	int nidp[100];
	int x, y;
	queue<int> q;

	while(scanf("%d", &ntasks) == 1) {
		if(ntasks == 0) { break; }

		memset(dep, false, sizeof(dep));
		memset(nd, 0, sizeof(nd));
		memset(idp, false, sizeof(idp));
		memset(nidp, 0, sizeof(nidp));

		int n;

		for(y = 0;y < ntasks;y++) {
			scanf("%d", &n);
		
			for(int x = 0;x < n;x++) {
				int i;
				
				scanf("%d", &i);

				dep[y][i - 1] = true; // y depends on i - 1
				idp[y][i - 1] = true;
				nd[y]++;
			}
		}

		for(int y = 0;y < ntasks;y++) {
			if(nd[y] == 0) {
				q.push(y);
			}
		}

		while(!q.empty()) {
			int i = q.front();
			q.pop();

			for(int x = 0;x < ntasks;x++) {
				if(dep[x][i]) {
					for(int z = 0;z < ntasks;z++) {
						if(idp[i][z]) {
							idp[x][z] = true;
						}
					}
					

					nd[x]--;

					if(nd[x] == 0) {
						q.push(x);
					}
				}
			}
		}
		
		for(int y = 0;y < ntasks;y++) {
			for(int x = 0;x < ntasks;x++) {
				if(idp[y][x]) {
					nidp[y]++;
				}
			}
		}

		int mi = 0;

		for(int y = 0;y < ntasks;y++) {
			if(nidp[y] > nidp[mi]) {
				mi = y;
			}
		}

		printf("%d\n", mi + 1);
	}

	return 0;
}