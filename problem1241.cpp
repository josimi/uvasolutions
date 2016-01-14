// problem 1241
// Jonathon Simister

#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int ntests;
	bool* p = new bool[1024];

	scanf("%d", &ntests);

	while(ntests--) {
		int n, m;

		scanf("%d %d", &n, &m);

		memset(p, true, 1024);

		for(int i = 0;i < m;i++) {
			int k;
			scanf("%d", &k);

			p[k - 1] = false;
		}

		int walks = 0;

		for(int t = 1;t <= n;t++) {
			for(int i = 0;i < (1 << n);i += (1 << t)) {
				int j = 0;

				if(p[i]) { j++; }
				if(p[i + (1 << (t - 1))]) { j++; }

				if(j == 1) {
					walks++;
				}

				p[i] = j > 0;
			}
		}

		printf("%d\n", walks);
	}

	return 0;
}