// problem 11094
// Jonathon Simister

#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <map>

using namespace std;

int main() {
	int rows, cols;
	char line[100];
	char m[30][30];
	int r[30][30];
	queue<pair<int, int> > q;
	map<int, int> rs;
	char chr;

	while(gets(line)) {
		sscanf(line, "%d %d", &rows, &cols);

		memset(r, 0, sizeof(r));
		rs.clear();

		for(int y = 0;y < rows;y++) {
			gets(m[y]);
		}

		{
			int x, y;

			gets(line);

			sscanf(line, "%d %d", &y, &x);

			q.push(pair<int, int>(x, y));

			chr = m[y][x];

		}
		
		gets(line);

		while(!q.empty()) {
			int x = q.front().first % cols;
			int y = q.front().second;
			q.pop();

			if(x >= 0 && x < cols && y >= 0 && y < rows) {
				if(m[y][x] == chr && r[y][x] == 0) {
					r[y][x] = -1;
					q.push(pair<int, int>(x + (cols - 1), y));
					q.push(pair<int, int>(x + 1, y));
					q.push(pair<int, int>(x, y - 1));
					q.push(pair<int, int>(x, y + 1));
				}
			}
		}

		int cr = 0;

		for(int sy = 0;sy < rows;sy++) {
			for(int sx = 0;sx < cols;sx++) {
				if(m[sy][sx] == chr && r[sy][sx] == 0) {
					cr++;

					q.push(pair<int, int>(sx, sy));

					while(!q.empty()) {
						int x = q.front().first % cols;
						int y = q.front().second;

						q.pop();

						if(x >= 0 && x < cols && y >= 0 && y < rows) {
							if(m[y][x] == chr && r[y][x] == 0) {
								r[y][x] = cr;
								rs[cr]++;
								q.push(pair<int, int>(x + (cols - 1), y));
								q.push(pair<int, int>(x + 1, y));
								q.push(pair<int, int>(x, y - 1));
								q.push(pair<int, int>(x, y + 1));
							}
						}
					}
				}
			}
		}

		int maxsize = 0;

		for(map<int, int>::iterator it = rs.begin();it != rs.end();it++) {
			maxsize = max(maxsize, it->second);
		}

		printf("%d\n", maxsize);
	}

	return 0;
}