// problem 1137
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

#define lim 100000

bool* era;
vector<int> primes;

bool factorize(int i, map<int, int>& factors) {
	for(int c = 0;c < primes.size();c++) {
		if(i % primes[c] == 0) {
			factors[primes[c]]++;
			i = i / primes[c];
		}

		if(i % primes[c] == 0) {
			return false;
		}

		if(i == 1) {
			return true;
		}
	}

	factors[i]++;

	return true;
}

int main() {
	era = new bool[lim];

	memset(era, true, sizeof(era));

	for(unsigned int x = 2;x < lim;x++) {
		if(era[x]) {
			primes.push_back(x);

			for(unsigned int y = x*x;y < lim;y += x) {
				era[y] = false;
			}
		}
	}
	
	int a, b;
	int ct = 0;

	while(scanf("%d %d", &a, &b) == 2) {
		int np = 0;

		if(ct > 0) {
			putchar('\n');
		}

		for(int c = a;c <= b;c++) {
			map<int, int> factors;

			factors.clear();

			if(factorize(c, factors)) {
				bool div = false;

				if(factors.size() > 2) {
					div = true;

					for(map<int, int>::iterator it = factors.begin();it != factors.end();it++) {
						if((c - 1) % (it->first - 1) != 0) {
							div = false;
						}
					}
				}

				if(div) {
					printf("%d\n", c);
					np++;
				}
			}
		}

		if(np == 0) {
			puts("none");
		}

		ct++;
	}

	return 0;
}