// problem 10327
// Jonathon Simister

#include <cstdio>

using namespace std;

int main() {
	int n;
	int a[1000];
	int inv;

	while(scanf("%d", &n) == 1) {
		for(int c = 0;c < n;c++) {
			scanf("%d", a + c);
		}

		inv = 0;

		for(int x = 0;x < n;x++) {
			for(int y = x + 1;y < n;y++) {
				if(a[y] < a[x]) {
					inv++;
				}
			}
		}

		printf("Minimum exchange operations : %d\n", inv);
	}

	return 0;
}