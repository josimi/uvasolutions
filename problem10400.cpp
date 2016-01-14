// problem 10400
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <stack>

using namespace std;

int a[101];
int n;
int target;
char dp[64002][100];

bool possible(int r, int p, int pi) {
	if(p == n) {
		if(r == target) {
			dp[r + 32000][p] = pi;
			return true;
		} else {
			dp[r + 32000][p] = 0;
			return false;
		}
	}

	if(dp[r + 32000][p] != -1) {
		return dp[r + 32000][p] > 0;
	}

	bool ret = false;

	for(int i = 1;i <= 4;i++) {
		int tr;

		switch(i) {
		case 1:
			tr = r + a[p];
			break;
		case 2:
			tr = r - a[p];
			break;
		case 3:
			tr = r * a[p];
			break;
		case 4:
			if((r % a[p]) != 0) { continue; }
			tr = r / a[p];
			break;
		}

		if(tr <= -32000 || tr >= 32000) {
			continue;
		}

		if(possible(tr, p + 1, i)) {
			ret = true;
			goto endf;
		}
	}

endf:
	if(ret) {
		dp[r + 32000][p] = pi;
	} else {
		dp[r + 32000][p] = 0;
	}

	return ret;
}

int main() {
	int ntests;

	scanf("%d", &ntests);

	while(ntests--) {
		scanf("%d", &n);
		
		for(int i = 0;i < n;i++) {
			scanf("%d", a + i);
		}

		scanf("%d", &target);

		memset(dp, -1, sizeof(dp));

		if(!possible(a[0], 1, 0)) {
			puts("NO EXPRESSION");
		} else {
			stack<char> st;

			int ct = target;

			for(int i = n;i > 1;i--) {
				char o = dp[ct + 32000][i];

				st.push(o);

				switch(o) {
				case 1:
					ct = ct - a[i - 1];
					break;
				case 2:
					ct = ct + a[i - 1];
					break;
				case 3:
					ct = ct / a[i - 1];
					break;
				case 4:
					ct = ct * a[i - 1];
					break;
				}
			}

			int i = 0;

			while(!st.empty()) {
				printf("%d", a[i++]);

				switch(st.top()) {
				case 1:
					putchar('+');
					break;
				case 2:
					putchar('-');
					break;
				case 3:
					putchar('*');
					break;
				case 4:
					putchar('/');
					break;
				default:
					break;
				}

				st.pop();
			}

			printf("%d=%d\n", a[i], target);
		}
	}

	return 0;
}