// problem 12050
// Jonathon Simister

#include <cstdio>
#include <cstring>

using namespace std;

int pow(int b, int e) {
	int ret = 1;
	
	while(e--) {
		ret *= b;
	}

	return ret;
} 

int main() {
	int n;

	while(scanf("%d", &n) == 1) {
		if(n == 0) { break; }

		int k = n;

		int d;

		for(d = 1;true;d++) {
			int ds = 18 * pow(10, d - 1);

			if(k > ds) {
				k -= ds;
			} else {
				break;
			}
		}

		bool sh = false;

		if(k > (9 * pow(10, d - 1))) {
			sh = true;
			k -= (9 * pow(10, d - 1));
		}

		int b = pow(10, d - 1) - 1;

		char pal[30];

		memset(pal, 0, sizeof(pal));

		sprintf(pal, "%d", b + k);

		char* sp = pal + d - 1;

		if(!sh) {
			sp--;
		}

		char* dp = pal + d;

		while(sp >= pal) {
			*dp = *sp;
			dp++;
			sp--;
		}

		printf("%s\n", pal);
	}

	return 0;
}