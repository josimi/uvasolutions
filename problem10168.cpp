// problem 10168
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

#define limit 10000001

int dp[limit][4];
bool* era;
vector<int> primes;

bool poss(int n, int p) {
	if(n <= 0) { return false; }
	if(p == 0) {
		if(era[n]) {
			dp[n][0] = (n << 1) | 1;
			return true;
		} else {
			dp[n][0] = 0;
			return false;
		}
	}
	
	if(dp[n][p] != -1) {
		return (dp[n][p] & 1) == 1;
	}

	for(int c = 0;c < primes.size();c++) {
		if(poss(n - primes[c], p-1)) {
			dp[n][p] = (primes[c] << 1) | 1;
			return true;
		}
	}

	dp[n][p] = 0;

	return false;
}

int main() {
	int n;

	era = new bool[limit];

	memset(era, true, limit);
	
	era[0] = false;
	era[1] = false;

	memset(dp, -1, sizeof(dp));

	for(unsigned int x = 2;x < limit;x++) {
		if(era[x]) {
			primes.push_back(x);

			if(x < 10000) {
				for(unsigned int y = x*x;y < limit;y += x) {
					era[y] = false;
				}
			}
		}
	}

	while(scanf("%d", &n) == 1) {
		if(poss(n, 3)) {
			int i = n;
			
			for(int c = 3;c >= 0;c--) {
				if(c < 3) { putchar(' '); }

				printf("%d", (dp[i][c] >> 1));
				i = i - (dp[i][c] >> 1);
			}

			putchar('\n');
		} else {
			puts("Impossible.");
		}
	}

	return 0;
}