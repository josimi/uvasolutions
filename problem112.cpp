// problem 112
// Jonathon Simister

#include <cstdio>
#include <stack>
#include <cctype>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
	int n;

	while(scanf("%d", &n) == 1) {
		int sum = 0;
		stack<pair<int,int> > st;
		bool found = false;
		bool pfirst = false;
		int r;
		char ch;
		bool nl = false;
		bool vr = false;
		bool neg = false;
		bool hd = false;

		while(!pfirst || st.size() > 0) {
			ch = getchar();

			if(!isdigit(ch) && nl) {
				if(neg) { r = 0 - r; }

				if(!hd) {
					st.top().second++;
				}

				st.push({ r, 0 });
				sum += r;
				nl = false;
				pfirst = true;
			}

			if(ch == '(') {
				nl = true;
				r = 0;
				vr = false;
				hd = true;

				if(st.size() > 0) {
					st.top().second = true;
				}
				neg = false;
			} else if(ch == '-') {
				neg = true;
			} else if(isdigit(ch)) {
				r = r * 10;
				r += (ch - '0');

				hd = true;
			} else if(ch == ')') {
				int k = st.top().first;
				st.pop();

				if(sum == n && st.size() > 1 && st.top().second == 2) {
					found = true;
				}

				sum -= k;
			}
		}

		if(found) {
			puts("yes");
		} else {
			puts("no");
		}
	}

	return 0;
}