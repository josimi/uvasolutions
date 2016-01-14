// problem 10677
// Jonathon Simister

#include <cstdio>

using namespace std;

int main() {
	int ntests;
	int b1, b2, r1, r2;
	int a1, a2;

	scanf("%d", &ntests);
	
	while(ntests--) {
		scanf("%d %d %d %d", &b1, &b2, &r1, &r2);

		for(int c = r2 - 1;c > r1;c--) {
			bool e = true;
			int m = -1;
			a1 = c;
			a2 = c;

			while(a1 > 0 || a2 > 0) {
				if((a1 % b1) == 0) {
					if((b2 % b2) != 0) {
						e = false;
						break;
					}
				} else if((a2 % b2) == 0) {
					e = false;
					break;
				} else if(m == -1) {
					m = (a1 % b1) / (a2 % b2);
				} else if(((a1 % b1) / (a2 % b2)) != m) {
					e = false;
					break;
				}

				a1 = a1 / b1;
				a2 = a2 / b2;
			}

			if(e && a1 == 0 && a2 == 0) {
				printf("%d - %d\n", c, m);
				break;
			}
		}
	}

	return 0;
}