// problem 123
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <map>

using namespace std;

int main() {
	char line[1000];
	map<string, int> ignore;
	map<string, vector<string> > sentences;

	while(gets(line)) {
		char* p = line;

		while(*p != 0) {
			*p = tolower(*p);
			p++;
		}

		if(line[0] == ':' && line[1] == ':' && line[2] == 0) {
			break;
		}

		ignore[string(line)] = 1;
	}

	while(gets(line)) {
		int s = 0;
		int e = 0;

		while(true) {
			char* p = line;

			while(*p != 0) {
				*p = tolower(*p);
				p++;
			}

			while(line[e] != ' ' && line[e] != 0) {
				e++;
			}

			string word(line + s, e - s);

			if(ignore.count(word) == 0) {
				for(int c = s;c < e;c++) {
					line[c] = toupper(line[c]);
				}

				sentences[word].push_back(string(line));
			}

			if(line[e] == 0) { break; }

			s = e + 1;
			e = s;
		}
	}

	for(map<string, vector<string> >::iterator it = sentences.begin();it != sentences.end();it++) {
		for(vector<string>::iterator vit = it->second.begin();vit != it->second.end();vit++) {
			printf("%s\n", vit->c_str());
		}
	}

	return 0;
}