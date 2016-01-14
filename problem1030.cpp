// problem 1030
// Jonathon Simister

#include <cstdio>
#include <cstring>

using namespace std;

int n;
char m[6][10][12];
char maxmass[10][10][10];

void lookat(int f, int v) {
	for(int j = 0;j < n;j++) {
		for(int k = 0;k < n;k++) {
			if(m[f][j][k] == '.') {
				if(v == 1) {
					for(int z = 0;z < n;z++) {
						maxmass[k][j][z] = 0;
					}
				} else if(v == 2) {
					for(int x = 0;x < n;x++) {
						maxmass[x][j][k] = 0;
					}
				} else if(v == 3) {
					for(int y = 0;y < n;y++) {
						maxmass[k][y][j] = 0;
					}
				}
			}
		}
	}
}

int main() {
	while(scanf("%d", &n) == 1) {
		if(n == 0) { break; }

		for(int y = 0;y < n;y++) {
			scanf("%s %s %s %s %s %s", m[0][y], m[1][y], m[2][y], m[3][y], m[4][y], m[5][y]);
		}

		memset(maxmass, 1, sizeof(maxmass));

		lookat(0, 1);
		lookat(1, 2);
		lookat(4, 3);

		int mass = 0;

		for(int z = 0;z < n;z++) {
			for(int y = 0;y < n;y++) {
				for(int x = 0;x < n;x++) {
					mass += maxmass[x][y][z];
				}
			}
		}

		printf("Maximum weight: %d gram(s)\n", mass);
	}

	return 0;
}