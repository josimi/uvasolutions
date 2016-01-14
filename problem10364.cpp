// problem 10364
// Jonathon Simister

#include <cstdio>
#include <cstring>

using namespace std;

int s[25];
int nsides;
int tlen;
int dp[3][2 << 20];

int setlen(int set) {
	int len = 0;
	
	for(int c = 0;c < nsides;c++) {
		int b = 2 << c;

		if((set & b) == b) {
			len += s[c];
		}
	}

	return len;
}

bool square(int side, int set) {
	if(dp[side][set] != -1) {
		return dp[side][set] == 1;
	}

	bool ret;

	int elen = tlen*(side + 1);
	int slen = setlen(set);

	if(slen > elen) {
		ret = false;
		goto fend;
	}

	if(slen == elen) {
		if(side == 2) {
			ret = true;
			goto fend;
		} else {
			ret = square(side + 1, set);
			goto fend;
		}
	}

	if(slen < elen) {
		for(int c = 0;c < nsides;c++) {
			int b = 2 << c;

			if((set | b) != set) {
				if(square(side, set|b)) {
					ret = true;
					goto fend;
				}
			}
		}

		ret = false;
		goto fend;
	}

fend:
	if(ret) {
		dp[side][set] = 1;
	} else {
		dp[side][set] = 0;
	}

	return ret;
}

int main() {
	int ntests;

	scanf("%d", &ntests);

	while(ntests--) {
		scanf("%d", &nsides);

		int len = 0;

		for(int c = 0;c < nsides;c++) {
			scanf("%d", s + c);
			len += s[c];
		}

		if((len % 4) != 0) {
			puts("no");
			continue;
		}

		tlen = len / 4;

		memset(dp, -1, sizeof(dp));

		if(square(0, 0)) {
			puts("yes");
		} else {
			puts("no");
		}
	}

	return 0;
}