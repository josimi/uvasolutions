// problem 514
// Jonathon Simister

#include <cstdio>
#include <stack>

using namespace std;

int main() {
	int n;
	int a[1000];

	while(scanf("%d", &n) == 1) {
		if(n == 0) { break; }

		while(true) {
			stack<int> st;

			for(int c = 0;c < n;c++) {
				scanf("%d", a + c);

				if(a[c] == 0) { goto doneSet; }
			}

			int x = 1;

			for(int y = 0;y < n;y++) {
				while(x <= n && (st.empty() || st.top() != a[y])) {
					st.push(x++);
				}

				if(st.top() == a[y]) {
					st.pop();
				} else {
					break;
				}
			}

			if(st.empty()) {
				puts("Yes");
			} else {
				puts("No");
			}
		}

	doneSet:
		putchar('\n');
	}

	return 0;
}