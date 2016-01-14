// problem 988
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int nevents;
	vector<vector<int> > al;
	vector<int> inedges;
	vector<int> inpaths;
	queue<int> q;
	int totalpaths;
	bool pr = false;

	while(scanf("%d", &nevents) == 1) {
		al.assign(nevents, vector<int>());
		inedges.assign(nevents, 0);

		for(int y = 0;y < nevents;y++) {
			int ne;

			scanf("%d", &ne);

			for(int x = 0;x < ne;x++) {
				int e;

				scanf("%d", &e);

				al[y].push_back(e);
				inedges[e]++;
			}
		}

		totalpaths = 0;
		inpaths.assign(nevents, 0);
		inpaths[0] = 1;

		q.push(0);

		while(!q.empty()) {
			int t = q.front();
			q.pop();

			if(al[t].size() == 0) {
				totalpaths += inpaths[t];
			} else {
				for(vector<int>::iterator it = al[t].begin();it != al[t].end();it++) {
					inpaths[*it] += inpaths[t];
					inedges[*it]--;

					if(inedges[*it] == 0) {
						q.push(*it);
					}
				}
			}
		}

		if(pr) {
			putchar('\n');
		}

		printf("%d\n", totalpaths);

		pr = true;
	}

	return 0;
}