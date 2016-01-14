// problem 10578
// Jonathon Simister

#include <cstdio>
#include <cstring>

using namespace std;

char dp[5*5*5*5*5*5];

int f(int x) {
	if(dp[x] != 0) {
		return dp[x];
	}
	
	int n[6];
	
	int y = x;
	int moves = 0;
	int pile = 0;
	int ret;

	for(int i = 0;i < 6;i++) {
		n[i] = y % 5;
		pile += n[i] * (i + 1);
		moves += n[i];
		y = (y - n[i]) / 5;
	}

	if(pile > 31) {
		if((moves % 2) == 0) { // B is the winner
			ret = -1;
			goto end;
		} else {
			ret = 1;
			goto end;
		}
	}

	int desired;

	if((moves % 2) == 0) {
		desired = 1;
	} else {
		desired = -1;
	}

	int base = 1;

	for(int i = 0;i < 6;i++) {
		if(n[i] < 4) {
			int k = x + base;

			if(f(k) == desired) {
				ret = desired;
				goto end;
			}
		}

		base *= 5;
	}

	printf("no winning moves from %d (%d,%d,%d,%d,%d,%d) for %d\n", pile, n[0],n[1],n[2],n[3],n[4],n[5], desired);

	ret = -desired;

end:
	dp[x] = ret;

	return ret;
}

int main() {
	char s[100];

	memset(dp, 0, sizeof(dp));

	while(scanf("%s", s) == 1) {
		int n[6];

		memset(n, 0, sizeof(n));

		for(int i = 0;s[i] != 0;i++) {
			n[s[i] - '1']++;
		}

		int k = 0;
		int base = 1;
		for(int i = 0;i < 6;i++) {
			k += n[i] * base;

			base *= 5;
		}

		if(f(k) == 1) {
			printf("%s A\n", s);
		} else {
			printf("%s B\n", s);
		}
	}

	return 0;
}