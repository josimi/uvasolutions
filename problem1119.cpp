// problem 1119
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <queue>
#include <functional>

using namespace std;

int main() {
	int ntests;

	scanf("%d", &ntests);

	while(ntests--) {
		int ntasks, nrules;
		bool dm[105][105];
		int dc[105];
		priority_queue<int,vector<int>,greater<int> > q;

		scanf("%d %d", &ntasks, &nrules);
	
		memset(dm, false, sizeof(dm));
		memset(dc, 0, sizeof(dc));

		for(int cr = 0;cr < nrules;cr++) {
			int task, k;
			scanf("%d %d", &task,&k);

			for(int c = 0;c < k;c++) {
				int i;

				scanf("%d", &i);

				dm[task][i] = true;
				dc[task]++;
			}
		}

		for(int ct = 1;ct <= ntasks;ct++) {
			if(dc[ct] == 0) {
				q.push(ct);
			}
		}

		bool pr = false;

		while(!q.empty()) {
			int i = q.top();
			q.pop();

			if(pr) { putchar(' '); }

			printf("%d", i);
			pr = true;

			for(int x = 1;x <= ntasks;x++) {
				if(dm[x][i]) {
					dm[x][i] = false;
					dc[x]--;

					if(dc[x] == 0) {
						q.push(x);
					}
				}
			}
		}

		putchar('\n');

		if(ntests > 0) {
			putchar('\n');
		}
	}

	return 0;
}