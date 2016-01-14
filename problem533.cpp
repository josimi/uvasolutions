// problem 533
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <cstring>
#include <cctype>
#include <stack>
#include <map>

using namespace std;

class token {
public:
	token() {
		t = 0;
	}

	token(int i) {
		t = 0;
		v[0] = i;
	}

	token(char t_) {
		t = t_;

		if(t_ == 'x') {
			v[1] = 1;
			t = 0;
		}
	}

	token operator+(token& r) {
		token ret;

		for(map<int, int>::iterator it = this->v.begin();it != this->v.end();it++) {
			ret.v[it->first] += it->second;
		}

		for(map<int, int>::iterator it = r.v.begin();it != r.v.end();it++) {
			ret.v[it->first] += it->second;
		}

		return ret;
	}

	token operator-(token& r) {
		token ret;

		for(map<int, int>::iterator it = this->v.begin();it != this->v.end();it++) {
			ret.v[it->first] += it->second;
		}

		for(map<int, int>::iterator it = r.v.begin();it != r.v.end();it++) {
			ret.v[it->first] -= it->second;
		}

		return ret;
	}

	token operator*(token& r) {
		token ret;

		for(map<int, int>::iterator itx = this->v.begin();itx != this->v.end();itx++) {
			for(map<int, int>::iterator ity = r.v.begin();ity != r.v.end();ity++) {
				ret.v[itx->first + ity->first] += itx->second * ity->second;
			}
		}

		return ret;
	}

	bool isop() {
		return (t == '*' || t == '+' || t == '-');
	}

	bool prec(const token& rt) {
		if(t == '*' && rt.t != '*') { return true; }
		else { return false; }
	}

	void print() {
		if(v.size() > 0) {
			for(map<int, int>::iterator it = v.begin();it != v.end();it++) {
				printf("%dx^%d ", it->second, it->first);
			}
		} else {
			putchar(t);
		}
	}

	char t;
	map<int, int> v;
};

void tokenize(const char* s, int len, vector<token>& out) {
	int c = 0;

	while(c < len) {
		if(isdigit(s[c])) {
			int n = 0;

			while(isdigit(s[c])) {
				n *= 10;
				n += (s[c] - '0');
				c++;
			}

			out.push_back(token(n));
		} else {
			if(s[c] == ' ') {
				c++;
			} else {
				out.push_back(token(s[c]));
				c++;
			}
		}
	}
}

void infixtopost(vector<token>& in, vector<token>& out) {
	stack<token> st;

	for(vector<token>::iterator it = in.begin();it != in.end();it++) {
		if(it->t == 0) {
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

token processpost(vector<token>& postfix) {
	stack<token> st;
	
	for(vector<token>::iterator it = postfix.begin();it != postfix.end();it++) {
		if(it->t != 0) {
			token o2 = st.top();
			st.pop();
			token o1 = st.top();
			st.pop();

			if(it->t == '+') {
				st.push(o1 + o2);
			} else if(it->t == '-') {
				st.push(o1 - o2);
			} else if(it->t == '*') {
				st.push(o1 * o2);
			}
		} else {
			st.push(*it);
		}
	}

	return st.top();
}

int main() {
	char line[200];
	bool pr = false;
	int ct = 0;

	while(gets(line)) {
		int len;
		int eq;
		vector<token> ltokens, rtokens;
		vector<token> lpost, rpost;

		ct++;

		len = strlen(line);
		
		for(int c = 0;c < len;c++) {
			if(line[c] == '=') {
				eq = c;
				break;
			}
		}

		tokenize(line, eq, ltokens);
		infixtopost(ltokens, lpost);

		tokenize(line + eq + 1, len - eq - 1, rtokens);
		infixtopost(rtokens, rpost);

		token l = processpost(lpost);
		token r = processpost(rpost);

		int l0, l1, r0, r1;

		l0 = l.v[0];
		l1 = l.v[1];
		r0 = r.v[0];
		r1 = r.v[1];

		r0 -= l0;
		l1 -= r1;

		if(pr) {
			putchar('\n');
		}

		printf("Equation #%d\n", ct);

		if(l1 == 0 && r0 != 0) {
			puts("No solution.");
		} else if(l1 == 0 && r0 == 0) {
			puts("Infinitely many solutions.");
		} else {
			printf("x = %.6lf\n", (double)r0 / (double)l1);
		}

		pr = true;
	}

	return 0;
}