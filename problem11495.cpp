// problem 11495
// Jonathon Simister

#include <cstdio>
#include <algorithm>

using namespace std;

int a[100000];

long long inversions(int* a,int s, int e) {
	if((e - s) <= 1) { return 0; }

	int mid = (s + e) / 2;

	long long ret = inversions(a, s, mid) + inversions(a, mid, e);

	int index1 = 0;
	int index2 = 0;

	while((s + index1) < mid) {
		if((mid + index2) == e || a[s + index1] < a[mid + index2]) {
			ret += index2;
			index1++;
		} else {
			index2++;
		}
	}

	sort(a + s, a + e);

	return ret;
}


int main() {
	int n;
	
	while(scanf("%d", &n) == 1) {
		if(n == 0) { break; }

		for(int i = 0;i < n;i++) {
			scanf("%d", a + i);
		}

		if(inversions(a, 0, n) & 1) {
			puts("Marcelo");
		} else {
			puts("Carlos");
		}
	}

	return 0;
}