// problem 12532
// Jonathon Simister

#include <cstdio>
#include <cstdlib>

using namespace std;

class fenwick {
public:
	fenwick(int size) {
		this->size = size;
		this->bit = (int*)std::calloc(size, sizeof(int));
	}

	~fenwick() {
		std::free(this->bit);
	}

	void increase(int i, int d) {
		for(;i < this->size;i |= i + 1) {
			this->bit[i] += d;
		}
	}

	int get(int i) {
		return sum(i) - sum(i - 1);
	}

	int get(int a, int b) {
		return sum(b) - sum(a - 1);
	}
private:
	int sum(int i) {
		int sum = 0;

		while(i >= 0) {
			sum += bit[i];
			i &= i + 1;
			i--;
		}

		return sum;
	}

	int size;
	int* bit;
};

int main() {
	int n, k;

	while(scanf("%d %d", &n, &k) == 2) {
		fenwick negs(n);
		fenwick zeros(n);

		for(int i = 0;i < n;i++) {
			int x;
			scanf("%d", &x);

			if(x == 0) {
				zeros.increase(i, 1);
			} else if(x < 0) {
				negs.increase(i, 1);
			}
		}

		for(int i = 0;i < k;i++) {
			char s[10];
			int a, b;

			scanf("%s %d %d", s, &a, &b);

			if(s[0] == 'C') {
				a--;

				if(zeros.get(a) == 1) {
					if(b > 0) {
						zeros.increase(a, -1);
					} else if(b < 0) {
						zeros.increase(a, -1);
						negs.increase(a, 1);
					}
				} else {
					if(b == 0) {
						zeros.increase(a, 1);

						if(negs.get(a) == 1) {
							negs.increase(a, -1);
						}
					}

					if(b > 0 && negs.get(a) == 1) {
						negs.increase(a, -1);
					}

					if(b < 0 && negs.get(a) == 0) {
						negs.increase(a, 1);
					}
				}
			} else if(s[0] == 'P') {
				a--;
				b--;

				if(zeros.get(a, b) > 0) {
					putchar('0');
				} else {
					if((negs.get(a, b) % 2) == 0) {
						putchar('+');
					} else {
						putchar('-');
					}
				}
			}
		}

		putchar('\n');
	}

	return 0;
}