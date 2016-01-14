// problem 264
// Jonathon Simister

#include <cstdio>
#include <cmath>
#include <map>

using namespace std;

int main() {
	int sum = 0;
	map<int, int> ordsum;

	ordsum[1] = 1;

	for(int x = 2;sum < 10001000;x += 2) {
		sum = (x*(x + 1)) / 2;

		ordsum[sum] = x;
	}

	int n;

	while(scanf("%d", &n) == 1) {
		map<int,int>::iterator it = ordsum.lower_bound(n);
		
		int num = it->second;
		int den = 1;
		int p = it->first;
		int d = -1;

		while(p > n) {
			if(d == -1) {
				if(num == 1) {
					d = 1;
					den--;
					p--;
				} else {
					num--;
					den++;
					p--;
				}
			} else {
				num++;
				den--;
				p--;
			}
		}

		printf("TERM %d IS %d/%d\n", n, num, den);
	}

	return 0;
}