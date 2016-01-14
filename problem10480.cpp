// problem 10480
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int capacity[52][52];
int parent[52];

int main() {
	int ncities, nconn;

	while(scanf("%d %d", &ncities, &nconn) == 2) {
		if(ncities == 0 && nconn == 0) { break; }

		memset(capacity, 0, sizeof(capacity));
	}

	return 0;
}