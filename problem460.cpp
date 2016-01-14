// problem 460
// Jonathon Simister

#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	int ntests;

	scanf("%d", &ntests);

	while(ntests--) {
		int lx1, ly1, rx1, ry1;
		int lx2, ly2, rx2, ry2;

		scanf("%d %d %d %d", &lx1, &ly1, &rx1, &ry1);
		scanf("%d %d %d %d", &lx2, &ly2, &rx2, &ry2);

		if(lx1 > lx2 && rx1 < rx2) {
			printf("%d %d %d %d\n", lx1, max(ly1, ly2), rx1, min(ry1, ry2));
		}
	}
}