// problem 725
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

inline int hamweight(int n) {
	int ret = 0;
	
	while(n > 0) {
		ret += (n & 1);
		n = n / 2;
	}

	return ret;
}

int main() {
	int n;
	char s[6];
	char sk[6];
	int kb;
	bool pr = false;

	memset(s, 0, sizeof(s));

	while(scanf("%d", &n) == 1) {
		vector<pair<int, int> > out;

		if(n == 0) { break; }

		if(pr) {
			putchar('\n');
		}

		for(int b = 0;b < 1023;b++) {
			if(hamweight(b) == 5) {
				int c = 0;

				for(int x = 0;x < 10;x++) {
					if((b & (1 << x)) == (1 << x)) {
						s[c++] = x + '0';
					}
				}

				do {
					int i = ((s[0] - '0') * 10000) + ((s[1] - '0') * 1000) + ((s[2] - '0') * 100) + ((s[3] - '0') * 10) + (s[4] - '0');

					//printf("s = %s\n", s);

					int k = i * n;

					if(k < 99999 && k >= 1234) {
						sprintf(sk, "%05d", k);

						kb = 0;

						for(int x = 0;x < 5;x++) {
							kb = kb | (1 << (sk[x] - '0'));
						}

						if((kb | b) == 1023) {
							out.push_back({ k, i });
						}
					}
				} while(next_permutation(s, s + 5));
			}
		}

		sort(out.begin(), out.end());



		if(out.size() == 0) {
			printf("There are no solutions for %d.\n", n);
		} else {
			for(vector<pair<int, int> >::iterator it = out.begin();it != out.end();it++) {
				printf("%05d / %05d = %d\n",it->first,it->second,n);
			}
		}

		pr = true;
	}

	return 0;
}