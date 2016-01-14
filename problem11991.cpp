// problem 11991
// Jonathon Simister

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n, m;

	while(scanf("%d %d", &n, &m) == 2) {
		int* cnt = (int*)calloc(1000, 1001 * sizeof(int));
		map<pair<int, int>, int> p;

		for(int c = 1;c <= n;c++) {
			int i;

			scanf("%d", &i);

			p[pair<int, int>(i, ++cnt[i])] = c;
		}

		for(int c = 0;c < m;c++) {
			int k, v;

			scanf("%d %d", &k, &v);
		
			printf("%d\n", p[pair<int, int>(v, k)]);
		}
	}

	return 0;
}