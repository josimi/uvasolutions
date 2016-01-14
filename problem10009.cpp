// problem 10009
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>

using namespace std;

int main() {
	int ntests;
	bool am[26][26];
	int d[26];
	int p[26];

	scanf("%d", &ntests);

	while(ntests--) {
		int nroads, nqueries;

		memset(am, false, sizeof(am));

		scanf("%d %d", &nroads, &nqueries);

		for(int c = 0;c < nroads;c++) {
			char s1[100];
			char s2[100];

			scanf("%s %s", s1, s2);

			am[s1[0] - 'A'][s2[0] - 'A'] = true;
			am[s2[0] - 'A'][s1[0] - 'A'] = true;
		}

		for(int c = 0;c < nqueries;c++) {
			char s1[100];
			char s2[100];
			queue<int> q;

			memset(d, 0x3f, sizeof(d));

			scanf("%s %s", s1, s2);

			d[s1[0] - 'A'] = true;
			q.push(s1[0] - 'A');

			while(!q.empty()) {
				int t = q.front();
				q.pop();

				for(int x = 0;x < 26;x++) {
					if(am[t][x] && d[x] >(d[t] + 1)) {
						d[x] = d[t] + 1;
						p[x] = t;
						q.push(x);
					}
				}
			}

			stack<int> st;

			st.push(s2[0] - 'A');

			while(st.top() != (s1[0] - 'A')) {
				st.push(p[st.top()]);
			}

			while(!st.empty()) {
				putchar(st.top() + 'A');
				st.pop();
			}

			putchar('\n');
		}

		if(ntests > 0) {
			putchar('\n');
		}
	}

	return 0;
}