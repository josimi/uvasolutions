// problem 924
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <map>

using namespace std;

int nemployees;
int ft[2550];
vector<int> al[2550];

int main() {
	int ntests;
	queue<int> q;
	map<int, int> m;

	scanf("%d", &nemployees);

	for(int y = 0;y < nemployees;y++) {
		int nf;
		int f;

		scanf("%d", &nf);

		for(int x = 0;x < nf;x++) {
			scanf("%d", &f);

			al[y].push_back(f);
		}
	}

	scanf("%d", &ntests);

	for(int ct = 0;ct < ntests;ct++) {
		int start;

		scanf("%d", &start);

		memset(ft, 0, sizeof(ft));
		q.push(start);

		while(!q.empty()) {
			int t = q.front();
			q.pop();

			for(vector<int>::iterator it = al[t].begin();it != al[t].end();it++) {
				if(ft[*it] == 0 && *it != start) {
					ft[*it] = ft[t] + 1;
					q.push(*it);
				}
			}
		}

		m.clear();

		for(int c = 0;c < nemployees;c++) {
			if(ft[c] != 0) {
				m[ft[c]]++;
			}
		}

		int boomsize = 0;
		int firstboom = 0;

		for(map<int, int>::iterator it = m.begin();it != m.end();it++) {
			if(it->second > boomsize) {
				boomsize = it->second;
				firstboom = it->first;
			}
		}

		if(boomsize == 0) {
			puts("0");
		} else {
			printf("%d %d\n",boomsize,firstboom);
		}
	}

	return 0;
}