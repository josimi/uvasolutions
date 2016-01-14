// problem 11111
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <stack>
#include <cstring>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main() {
	char* line = (char*)malloc(1000000);

	while(gets(line)) {
		vector<int> v;
		int i;
		char* tok;
		stack<pair<int,int> > st;
		bool p = true;

		tok = strtok(line, " ");
		sscanf(tok, "%d", &i);
		v.push_back(i);

		while(true) {
			tok = strtok(NULL, " ");
			
			if(tok == NULL) { break; }

			sscanf(tok, "%d", &i);
			v.push_back(i);
		}

		for(int c = 0;c < v.size();c++) {
			if(v[c] < 0) {
				if(!st.empty()) {
					if(abs(v[c]) > abs(st.top().first)) {
						p = false;
						break;
					}
					if(abs(v[c]) >= st.top().second) {
						p = false;
						break;
					}

					st.top().second -= abs(v[c]);
				}
				st.push({ v[c], abs(v[c]) });
			} else if(v[c] > 0) {
				if(st.empty()) {
					p = false;
					break;
				} else if((st.top().first + v[c]) == 0) {
					st.pop();
				} else {
					p = false;
					break;
				}
			}
		}

		if(p) {
			puts(":-) Matrioshka!");
		} else {
			puts(":-( Try again.");
		}
	}

	return 0;
}