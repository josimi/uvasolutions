// problem 10622
// Jonathon Simister

#include <cstdio>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;

long long powlong(long long x, int y) {
	long long ret = 1;

	for(int i = 0;i < y;i++) {
		ret *= x;
	}

	return ret;
}

int main() {
	map<long long, int> m;
	map<long long, int> n;

	for(long long x = 2;x <= 65536;x++) {
		int y = 2;

		while(true) {
			long long b = powlong(x, y);

			if(b < INT_MAX) {
				if(m.count(b) == 0) {
					m[b] = y;
				}
				if((y & 1) == 1 && n.count(b) == 0) {
					n[b] = y;
				}
			} else {
				break;
			}

			y++;
		}
	}

	long long i;

	while(scanf("%lld", &i)) {
		bool neg = i < 0;

		if(i == -2147483648) {
			puts("31");
			continue;
		}

		i = abs(i);

		if(i == 0) { break; }

		if(neg && n.count(i) == 1) {
			printf("%d\n", n[i]);
		} else if(!neg && m.count(i) == 1) {
			printf("%d\n", m[i]);
		} else {
			puts("1");
		}
	}

	return 0;
}