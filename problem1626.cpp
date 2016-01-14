// problem 1626
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

class parsenode {
public:
	parsenode(char c) {
		ch = c;
	}

private:
	char ch;
};

int main() {
	char line[1000];
	int ntests;
	parsenode* tree;
	int len;

	gets(line);

	sscanf(line, "%d", &ntests);

	while(ntests--) {
		gets(line);
		gets(line);

		len = strlen(line);

		tree = new parsenode(0);

		tree->parse(line, 0, len - 1);
	}

	return 0;
}