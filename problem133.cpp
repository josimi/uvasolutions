// problem 133
// Jonathon Simister

#include <cstdio>
#include <deque>

using namespace std;

int main() {
	int N, k, m;
	deque<int> d;
	int ki, mi;
	int mv, kv;

	while(scanf("%d %d %d", &N, &k, &m) == 3) {
		if(N == 0 && k == 0 && m == 0) { break; }

		d.clear();

		for(int c = 1;c <= N;c++) {
			d.push_back(c);
		}

		ki = 0;
		mi = N-1;

		while(d.size() > 0) {
			for(int c = 0;c < k;c++) {
				ki = (ki + 1) % d.size();
			}

			ki = (ki + d.size() - 1) % d.size();

			for(int c = 0;c < m;c++) {
				mi = (mi + (d.size()-1)) % d.size();
			}

			mi = (mi + d.size() - 1) % d.size();

			mv = d[mi];
			kv = d[ki];

			for(int c = 0;c < d.size();c++) {
				if(d[c] == mv) {
					d.erase(d.begin() + c);
					break;
				}
			}

			for(int c = 0;c < d.size();c++) {
				if(d[c] == kv) {
					d.erase(d.begin() + c);
					break;
				}
			}

			if(mv != kv) {
				printf("  %d", kv);
				printf("  %d", mv);
			} else {
				printf("  %d", kv);
			}

			if(d.size() > 0) {
				putchar(',');
			}
		}

		putchar('\n');
	}

	return 0;
}