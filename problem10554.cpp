// problem 10554
// Jonathon Simister

#include <cstdio>

using namespace std;

int main() {
	char line[1000];

	while(gets(line)) {
		do {
			int fat;
			char tfat;
			int pro;
			char tpro;
			int sug;
			char tsug;
			int str;
			char tstr;
			int alc;
			char talc;

			int psum = 0;
			int asum = 0;

			sscanf(line, "%d%c %d%c %d%c %d%c %d%c", &fat, &tfat, &pro, &tpro, &sug, &tsug, &str, &tstr, &alc, &talc);

			if(tfat == '%') { psum += fat; }
			if(tpro == '%') { psum += pro; }

			gets(line);
		} while(!(line[0] == '-' && line[1] == 0))
	}

	return 0;
}