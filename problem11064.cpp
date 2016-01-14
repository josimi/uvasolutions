// problem 11064
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#include <cmath>

using namespace std;

#define limit 65536

int tot(int prime, int exp) {
	if(exp == 1) { return prime - 1; }

	return pow(prime, exp - 1) * (prime - 1);
}

bool* era;
vector<int> primes;

int main() {
	int n;

	era = new bool[limit];

	memset(era, true, sizeof(era));

	era[0] = false;
	era[1] = false;

	for(unsigned int x = 2;x < limit;x++) {
		if(era[x]) {
			primes.push_back(x);

			for(unsigned int y = x*x;y < limit;y += x) {
				era[y] = false;
			}
		}
	}

	while(scanf("%d", &n) == 1) {
		long long k = n;
		map<int, int> factors;

		for(int c = 0;c < primes.size() && k > 0;c++) {
			while((k % primes[c]) == 0) {
				factors[primes[c]]++;
				k = k / primes[c];
			}
		}

		if(k > 1) {
			factors[k]++;
		}

		long long r = 1;
		long long ndiv = 1;

		for(map<int, int>::iterator it = factors.begin();it != factors.end();it++) {
			//printf("%d ^ %d\n", it->first, it->second);
			r *= tot(it->first, it->second);
			ndiv *= (it->second + 1);
		}

		ndiv -= 1;

		printf("%lld\n", n - r - ndiv);
	}

	return 0;
}