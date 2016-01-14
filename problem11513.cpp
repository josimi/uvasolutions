// problem 11513
// Jonathon Simister

#include <cstdio>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
#include <cstring>
#include <vector>
#include <functional>

using namespace std;

class state {
public:
	state() {
		memset(a, 0, sizeof(a));
	}

	state(int* a_) {
		for(int c = 0;c < 9;c++) {
			a[c] = a_[c];
		}
	}

	bool operator<(const state& r) const {
		for(int c = 0;c < 9;c++) {
			if(a[c] > r.a[c]) { return false; }
			if(a[c] < r.a[c]) { return true; }
		}

		return false;
	}

	bool operator==(const state& r) const {
		for(int c = 0;c < 9;c++) {
			if(a[c] != r.a[c]) { return false; }
		}

		return true;
	}

	bool operator!=(const state &r) const {
		return !(*this == r);
	}

	state shift(int s) {
		int r[3];
		state ret = state(*this);
		
		if(s < 3) {
			r[1] = a[0 + (3 * s)];
			r[2] = a[1 + (3 * s)];
			r[0] = a[2 + (3 * s)];

			ret.a[0 + (3 * s)] = r[0];
			ret.a[1 + (3 * s)] = r[1];
			ret.a[2 + (3 * s)] = r[2];
		} else if(s < 6) {
			r[0] = a[0 + (s - 3)];
			r[1] = a[3 + (s - 3)];
			r[2] = a[6 + (s - 3)];

			ret.a[0 + (s - 3)] = r[1];
			ret.a[3 + (s - 3)] = r[2];
			ret.a[6 + (s - 3)] = r[0];
		}

		return ret;
	}

	int dist() {
		int d = 0;

		for(int c = 0;c < 9;c++) {
			if(a[c] != c + 1) {
				d++;
			}
		}

		return d;
	}

	void print() {
		printf("%d %d %d\n%d %d %d\n%d %d %d\n", a[0], a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8]);
	}

private:
	int a[9];
};

int main() {
	int a[9];
	int g[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	state goal(g);

	while(scanf("%d %d %d %d %d %d %d %d %d", a + 0, a + 1, a + 2, a + 3, a + 4, a + 5, a + 6, a + 7, a + 8) == 9) {
		map<state, pair<pair<int,int>,state> > m;
		queue<state> q;
		stack<int> st;
		int goaldist = -1;

		m[state(a)] = pair<pair<int,int>,state>(pair<int,int>(0,-1),state(a));
		q.push(state(a));

		while(!q.empty()) {
			state t = q.front();
			q.pop();

			if(t == goal) {
				goaldist = m[t].first.first;

				state cs = t;

				while(cs != state(a)) {
					st.push(m[cs].first.second);
					
					cs = m[cs].second;
				}

				break;
			}

			int d = m[t].first.first;

			for(int c = 0;c < 6;c++) {
				state n = t.shift(c);

				if(m.count(n) == 0) {
					m[n] = pair<pair<int,int>, state>(pair<int,int>(d + 1,c), t);
					q.push(n);
				} else if(m[n].first.first > (d + 1)) {
					m[n] = pair<pair<int,int>, state>(pair<int,int>(d + 1,c), t);
					q.push(n);
				}
			}
		}

		if(goaldist == -1) {
			puts("Not solvable");
		} else {
			printf("%d ", goaldist);

			while(!st.empty()) {
				if(st.top() < 3) {
					printf("H%d", st.top() + 1);
				} else {
					printf("V%d", st.top() - 2);
				}

				st.pop();
			}

			putchar('\n');
		}
	}


	return 0;
}