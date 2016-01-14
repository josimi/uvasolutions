// problem 644
// Jonathon Simister

#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
	int ct = 0;
	char line[2000];
	vector<string> al;

	while(gets(line)) {
		ct++;
		al.clear();
		bool imm = true;

		do {
			if(line[0] == '9') { break; }

			for(int x = 0;x < al.size();x++) {
				bool same = true;

				for(int y = 0;y < min(al[x].length(), strlen(line));y++) {
					if(al[x][y] != line[y]) {
						same = false;
						break;
					}
				}

				if(same) {
					imm = false;
				}
			}

			al.push_back(string(line));
		} while(gets(line));

		if(imm) {
			printf("Set %d is immediately decodable\n",ct);
		} else {
			printf("Set %d is not immediately decodable\n", ct);
		}
	}

	return 0;
}