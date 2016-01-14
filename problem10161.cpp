// problem 10161
// Jonathon Simister

#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
	int n;

	while(scanf("%d", &n) == 1) {
		if(n == 0) { break; }

		int o = (int)floor(sqrt((double)n));
		
		int dx, dy;
		int x, y;
		int xb, yb;

		if((o & 1) == 1) {
			x = 1;
			y = o;
			dx = 0;
			dy = 1;
		} else {
			x = o;
			y = 1;
			dx = 1;
			dy = 0;
		}

		int p = o*o;

restart:
		if(p < n) {
			if(dy == 1) {
				p += 1;
				y += 1;
				dy = 0;
				dx = 1;
				xb = o + 1;
				yb = 0;
			} else {
				p += 1;
				x += 1;
				dy = 1;
				dx = 0;
				xb = 0;
				yb = o + 1;
			}
		}

		while(p < n) {
			p += 1;
			x += dx;
			y += dy;

			if(y == yb) {
				dx = -1;
				dy = 0;
				xb = 1;
				yb = 0;
			} else if(x == xb) {
				dx = 0;
				dy = -1;
				yb = 1;
				xb = 0;
			}
		}

		printf("%d %d\n", x, y);
	}

	return 0;
}