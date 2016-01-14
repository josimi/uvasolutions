// problem 586
// Jonathon Simister

#include <cstdio>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

class cost {
public:
	cost& operator+=(cost& r) {
		for(map<int, int>::iterator it = r.m.begin();it != r.m.end();it++) {
			m[it->first] += it->second;
		}

		return *this;
	}

	map<int, int> m;
};

class parsenode {
public:
	void appendChild(parsenode* child) {
		children.push_back(child);
	}

	virtual cost* getcost() {
		return NULL;
	}

	virtual void print(int tabs) {
	}

	vector<parsenode*> children;
};

class programnode : public parsenode {
public:
	cost* getcost() {
		cost* ret = new cost();

		for(vector<parsenode*>::iterator it = children.begin();it != children.end();it++) {
			*ret += *((*it)->getcost());
		}

		return ret;
	}

	void print(int tabs) {
		printf("ProgramNode\n");

		for(vector<parsenode*>::iterator it = children.begin();it != children.end();it++) {
			(*it)->print(tabs + 1);
		}
	}
};

class loopnode : public parsenode {
public:
	loopnode(int size_) {
		size = size_;
	}

	cost* getcost() {
		cost* ret = new cost();
		cost* ret2 = new cost();

		for(vector<parsenode*>::iterator it = children.begin();it != children.end();it++) {
			*ret += *((*it)->getcost());
		}

		if(size == -1) {
			for(map<int, int>::iterator it = ret->m.begin();it != ret->m.end();it++) {
				ret2->m[it->first + 1] = it->second;
			}
		} else {
			for(map<int, int>::iterator it = ret->m.begin();it != ret->m.end();it++) {
				ret2->m[it->first] = it->second * size;
			}
		}

		return ret2;
	}

	void print(int tabs) {
		for(int c = 0;c < tabs;c++) {
			putchar('\t');
		}

		printf("LoopNode %d\n",size);

		for(vector<parsenode*>::iterator it = children.begin();it != children.end();it++) {
			(*it)->print(tabs + 1);
		}
	}
private:
	int size;
};

class opnode : public parsenode {
public:
	opnode(int size_) {
		size = size_;
	}

	cost* getcost() {
		cost* ret = new cost();

		ret->m[0] = size;

		return ret;
	}

	void print(int tabs) {
		for(int c = 0;c < tabs;c++) {
			putchar('\t');
		}

		printf("OpNode %d\n", size);
	}
private:
	int size;
};

char token[100];

void readnext() {
	scanf("%s", token);
}

void expect(char* s) {
	if(strcmp(token, s) != 0) {
		printf("expecting %s\n", s);
	}
	
	readnext();
}

parsenode* parseOp() {
	parsenode* ret;
	int l;

	expect("OP");

	sscanf(token, "%d", &l);

	readnext();

	ret = new opnode(l);

	return ret;
}

parsenode* parseLoop() {
	parsenode* ret;
	int l;

	expect("LOOP");

	if(strcmp(token, "n") == 0) {
		l = -1;
	} else {
		sscanf(token, "%d", &l);
	}

	readnext();

	ret = new loopnode(l);

	while(true) {
		if(strcmp(token, "LOOP") == 0) {
			ret->appendChild(parseLoop());
		} else if(strcmp(token, "OP") == 0) {
			ret->appendChild(parseOp());
		} else if(strcmp(token, "END") == 0) {
			break;
		}
	}

	expect("END");

	return ret;
}

parsenode* parseProgram() {
	parsenode* ret;

	ret = new programnode();

	expect("BEGIN");

	while(true) {
		if(strcmp(token, "LOOP") == 0) {
			ret->appendChild(parseLoop());
		} else if(strcmp(token, "OP") == 0) {
			ret->appendChild(parseOp());
		} else if(strcmp(token, "END") == 0) {
			break;
		}
	}

	expect("END");

	return ret;
}

int main() {
	int ntests;

	scanf("%d", &ntests);

	readnext();

	for(int c = 1;c <= ntests;c++) {
		parsenode* programNode = parseProgram();
		cost* cost = programNode->getcost();

		printf("Program #%d\n", c);
		printf("Runtime = ");

		bool pr = false;

		for(int exp = 20;exp >= 0;exp--) {
			int sig = cost->m[exp];

			if((exp != 0 && sig == 0) || (exp == 0 && sig ==0 && pr)) { continue; }
			
			if(pr) {
				putchar('+');
			}

			if(sig != 1 || exp == 0) {
				printf("%d", sig);
			}

			if(exp > 0) {
				if(sig > 1) {
					printf("*");
				}
				printf("n");
			}

			if(exp > 1) {
				printf("^%d", exp);
			}

			pr = true;
		}

		printf("\n\n");
	}

	return 0;
}