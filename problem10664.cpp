// problem 10664
// Jonathon Simister

#include <cstdio>
#include <cstring>

using namespace std;

char line[1000];

int a[21];
char dp[21][210];
int n;

bool possible(int k, int w) {
	if(dp[k][w] != -1) {
		return dp[k][w] == 1;
	}

	if(w == 0) { return true; }
	if(w < 0) { return false; }
	if(k == n) { return false; }

	bool ret = possible(k + 1, w - a[k]) || possible(k + 1, w);

	if(ret) {
		dp[k][w] = 1;
		return true;
	} else {
		dp[k][w] = 0;
		return false;
	}
}

int main() {
	int ntests;
	char* tok;

	gets(line);
	sscanf(line, "%d", &ntests);

	while(ntests--) {
		gets(line);

		tok = strtok(line, " ");
		n = 0;
		int wsum = 0;

		memset(dp, -1, sizeof(dp));

		do {
			sscanf(tok, "%d", a + n);
			wsum += a[n];
			n++;
			tok = strtok(NULL, " ");
		} while(tok != NULL);

		if(wsum & 1) {
			puts("NO");
		} else {
			if(possible(0, wsum / 2)) {
				puts("YES");
			} else {
				puts("NO");
			}
		}
	}

	return 0;
}