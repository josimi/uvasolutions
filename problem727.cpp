// problem 727
// Jonathon Simister

#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <cctype>

using namespace std;

class token {
public:
	token(char ch) {
		t = ch;
	}

	bool isvalue() {
		return isdigit(t);
	}

	bool isop() {
		return (t == '+' || t == '-' || t == '/' || t == '*');
	}

	bool prec(token& r) {
		if((t == '*' || t == '/') && (r.t == '+' || r.t == '-')) {
			return true;
		} else if((t == '*' || t == '/') && (r.t == '*' || r.t == '/')) {
			return true;
		} else if((t == '+' || t == '-') && (r.t == '+' || r.t == '-')) {
			return true;
		} else if((t == '+' || t == '-') && (r.t == '*' || r.t == '/')) {
			return false;
		}
	}

	char t;
};

void tokenize(const char* input, vector<token>& out) {
	const char* p = input;

	while(*p != 0) {
		out.push_back(token(*p));
		p++;
	}
}

void infixtopost(vector<token>& in, vector<token>& out) {
	stack<token> st;

	for(vector<token>::iterator it = in.begin();it != in.end();it++) {
		if(it->isvalue()) {
			out.push_back(*it);
		} else if(it->isop()) {
			while(!st.empty() && st.top().isop() && st.top().prec(*it)) {
				out.push_back(st.top());
				st.pop();
			}

			st.push(*it);
		} else if(it->t == '(') {
			st.push(*it);
		} else if(it->t == ')') {
			while(st.top().t != '(') {
				out.push_back(st.top());
				st.pop();
			}
			st.pop();
		}
	}

	while(!st.empty()) {
		out.push_back(st.top());
		st.pop();
	}
}

int main() {
	int ntests;
	char line[50];

	gets(line);
	sscanf(line, "%d", &ntests);
	gets(line);

	for(int ct = 0;ct < ntests;ct++) {
		int c = 0;
		char input[200];
		vector<token> tokens;
		vector<token> post;

		memset(input, 0, sizeof(input));

		while(gets(line)) {
			if(line[0] == 0) { break; }

			input[c++] = line[0];
		}

		tokenize(input, tokens);

		infixtopost(tokens, post);

		if(ct > 0) {
			putchar('\n');
		}

		for(vector<token>::iterator it = post.begin();it != post.end();it++) {
			putchar(it->t);
		}

		putchar('\n');
	}

	return 0;
}