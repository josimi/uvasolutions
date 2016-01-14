// problem 344
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>

using namespace std;

char* r[100];

char* numeral(int i) {
	char* buf = (char*)calloc(100, 1);
	int m = i % 10;

	strcpy(buf, r[i - m]);
	strcat(buf, r[m]);

	return buf;
}

int main() {
	r[0] = "";
	r[1] = "i";
	r[2] = "ii";
	r[3] = "iii";
	r[4] = "iv";
	r[5] = "v";
	r[6] = "vi";
	r[7] = "vii";
	r[8] = "viii";
	r[9] = "ix";
	r[10] = "x";
	r[20] = "xx";
	r[30] = "xxx";
	r[40] = "xl";
	r[50] = "l";
	r[60] = "lx";
	r[70] = "lxx";
	r[80] = "lxxx";
	r[90] = "xc";
	r[100] = "c";

	int d;
	map<char, int> m;

	while(scanf("%d", &d) == 1) {
		if(d == 0) { break; }

		m.clear();

		for(int k = 1;k <= d;k++) {
			char* buf = numeral(k);
			char* p = buf;

			while(*p != 0) {
				m[*p]++;
				p++;
			}
		}

		printf("%d: %d i, %d v, %d x, %d l, %d c\n", d, m['i'], m['v'], m['x'], m['l'], m['c']);
	}

	return 0;
}