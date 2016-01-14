// problem 926
// Jonathon Simister

#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

long long inpaths[32][32];
bool blocked[32][32][32][32];

long long paths(int x, int y) {
	long long ret = 0;

	if(x < 0 || y < 0) { return 0; }
	
	if(inpaths[x][y] != -1) { return inpaths[x][y]; }

	if(x > 0) {
		if(!blocked[x - 1][y][x][y]) {
			ret += paths(x - 1, y);
		}
	}

	if(y > 0) {
		if(!blocked[x][y - 1][x][y]) {
			ret += paths(x, y - 1);
		}
	}
	
	inpaths[x][y] = ret;

	return ret;
}

int main() {
	int ntests;
	int n;
	int sx, sy;
	int ex, ey;

	scanf("%d", &ntests);

	for(int ct = 0;ct < ntests;ct++) {
		scanf("%d", &n);
		scanf("%d %d", &sx, &sy);
		sx--;
		sy--;
		scanf("%d %d", &ex, &ey);
		ex--;
		ey--;

		memset(inpaths, -1, sizeof(inpaths));
		memset(blocked, false, sizeof(blocked));

		for(int y = 0;y < sy;y++) {
			for(int x = 0;x < n;x++) {
				inpaths[x][y] = 0;
			}
		}

		for(int y = 0;y < n;y++) {
			for(int x = 0;x < sx;x++) {
				inpaths[x][y] = 0;
			}
		}

		inpaths[sx][sy] = 1;

		int nblocks;

		scanf("%d", &nblocks);

		for(int c = 0;c < nblocks;c++) {
			int x, y;
			char s[40];
			scanf("%d %d %s", &x, &y, s);
			
			x--;
			y--;

			switch(s[0]) {
			case 'N':
				blocked[x][y][x][y+1] = true;
				break;
			case 'E':
				blocked[x][y][x+1][y] = true;
				break;
			case 'S':
				blocked[x][y-1][x][y] = true;
				break;
			case 'W':
				blocked[x-1][y][x][y] = true;
				break;
			}
		}

		printf("%lld\n", paths(ex,ey));

		/*for(int y = n - 1;y >= 0;y--) {
			for(int x = 0;x < n;x++) {
				printf("%lld ", inpaths[x][y]);
			}

			putchar('\n');
		}*/
	}

	return 0;
}