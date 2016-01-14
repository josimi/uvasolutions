// problem 400
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	int n;
	char buf[100];

	while(scanf("%d", &n) == 1) {
		int maxlen = 0;
		vector<string> filenames;

		for(int c = 0;c < n;c++) {
			scanf("%s", buf);

			filenames.push_back(string(buf));

			maxlen = max(maxlen, (int)strlen(buf));
		}

		sort(filenames.begin(), filenames.end());

		int cols = 60 / (maxlen + 2);

		if(cols == 0) { cols = 1; }

		printf("------------------------------------------------------------\n");

		int rows = n / cols;

		if((n % cols) != 0) {
			rows++;
		}

		for(int y = 0;y < rows;y++) {
			for(int x = 0;x < cols && (y + (x * rows)) < n;x++) {
				int i = (x * rows) + y;

				printf("%s", filenames[i].c_str());

				for(int c = 0;c < (maxlen - filenames[i].length());c++) {
					putchar(' ');
				}

				if(x < (cols - 1)) {
					printf("  ");
				}
			}

			printf("\n");
		}
	}

	return 0;
}