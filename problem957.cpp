// problem 957
// Jonathon Simister

#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int main() {
	int Y, p;
	int* e = (int*)malloc(1001000);

	while(scanf("%d", &Y) == 1) {
		scanf("%d", &p);

		int l = 0;
		e[0] = 0;

		for(int x = 0;x < p;x++) {
			int i;

			scanf("%d", &i);

			for(int y = l + 1;y <= i;y++) {
				e[y] = e[l];
			}

			e[i]++;

			l = i;
		}

		int maxpopes = 0;
		int maxyear = 0;

		for(int x = Y;x <= l;x++) {
			if((e[x] - e[x - Y]) > maxpopes) {
				maxpopes = e[x] - e[x - Y];
				maxyear = x;
			}
		}

		printf("%d %d %d\n", maxpopes, maxyear-(Y-1), maxyear);
	}

	return 0;
}