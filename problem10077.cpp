// problem 10077
// Jonathon Simister

#include <cstdio>

using namespace std;

int gcd(int a, int b) {
	int c;

	while(a != 0) {
		c = b%a;
		b = a;
		a = c;
	}

	return b;
}

class node {
public:
	node(int num_, int den_) {
		num = num_;
		den = den_;
		parent = NULL;
		left = NULL;
		right = NULL;
	}

	node(node* parent_, int side) {
		parent = parent_;
		left = NULL;
		right = NULL;

		if(side == 1) {
			parent->right = this;
		} else {
			parent->left = this;
		}

		node* rp = this->rightparent();
		node* lp = this->leftparent();

		if(lp == NULL) {
			num = rp->num + 1;
			den = rp->den;
		} else if(rp == NULL) {
			num = lp->num;
			den = lp->den + 1;
		} else {
			num = rp->num + lp->num;
			den = rp->den + lp->den;
		}

		int g = gcd(num, den);

		num = num / g;
		den = den / g;

		
	}

	int compare(int num_, int den_) {
		if(num_ == num && den_ == den) {
			return 0;
		}
		
		double tr = (double)num_ / (double)den_;
		double r = (double)num / (double)den;

		if(tr > r) {
			return 1;
		} else {
			return -1;
		}
	}

	void setchild(node* child,int side) {
		child->parent = this;

		if(side == -1) {
			this->left = child;
		} else {
			this->right = child;
		}
	}

	node* leftchild() {
		if(left == NULL) {
			left = new node(this, -1);
		}

		return left;
	}

	node* rightchild() {
		if(right == NULL) {
			right = new node(this, 1);
		}

		return right;
	}

	node* leftparent() {
		node* tp = parent;
		node* tc = this;

		while(tp != NULL) {
			if(tp->left == tc) {
				return tp;
			}

			tp = tp->parent;
			tc = tc->parent;
		}

		return NULL;
	}

	node* rightparent() {
		node* tp = parent;
		node* tc = this;

		while(tp != NULL) {
			if(tp->right == tc) {
				return tp;
			}

			tp = tp->parent;
			tc = tc->parent;
		}

		return NULL;
	}

	int num_() {
		return num;
	}

	int den_() {
		return den;
	}

private:
	node* parent;
	node* left;
	node* right;

	int num, den;
};

int main() {
	int num, den;

	node* root = new node(1, 1);

	root->setchild(new node(1, 2), -1);
	root->setchild(new node(2, 1), 1);
	

	while(scanf("%d %d", &num, &den) == 2) {
		if(num == 1 && den == 1) { break; }

		int g = gcd(num, den);

		num = num / g;
		den = den / g;

		node* t = root;

		while(true) {
			int cmp = t->compare(num, den);

			if(cmp == 0) { break; }

			if(cmp == -1) {
				putchar('L');
				t = t->leftchild();
			}

			if(cmp == 1) {
				putchar('R');
				t = t->rightchild();
			}
		}

		putchar('\n');
	}

	return 0;
}