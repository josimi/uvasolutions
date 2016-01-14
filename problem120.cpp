// problem 120
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	char line[2000];

	while(gets(line)) {
		char* tok = strtok(line, " ");
		int a[40];
		int n = 0;
		vector<int> v;
		int largest = -1;
		int smallest = 1000000;

		do {
			sscanf(tok, "%d", a + n);

			largest = max(largest, a[n]);
			smallest = min(smallest, a[n]);

			n++;

			tok = strtok(NULL, " ");
		} while(tok != NULL);

		for(int x = 0;x < n;x++) {
			if(x > 0) { putchar(' '); }
			printf("%d", a[x]);
		}
		putchar('\n');

		int p = n;

		while(p > 0) {
			int li = 0;

			if(is_sorted(a, a + n)) { break; }

			for(int x = 0;x < p;x++) {
				if(a[x] > a[li]) { li = x; }
			}

			if(li != 0) {

				reverse(a, a + li + 1);

				v.push_back((n - li));

				/*for(int x = 0;x < n;x++) {
					printf("%d ", a[x]);
				}
				putchar('\n');*/
			}

			if(is_sorted(a, a + n)) { break; }

			reverse(a, a + p);

			v.push_back((n - p) + 1);

			/*for(int x = 0;x < n;x++) {
				printf("%d ", a[x]);
			}
			putchar('\n');*/

			p--;
		}

		for(int x = 0;x < v.size();x++) {
			printf("%d ", v[x]);
		}

		puts("0");
	}

	return 0;
}