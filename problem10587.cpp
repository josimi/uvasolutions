// problem 10587
// Jonathon Simister

#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <unordered_set>
#include <functional>

using namespace std;

class poster {
public:
	poster() {
		l = 0;
		r = 0;
		z = -1;
	}

	poster(int l, int r, int z) {
		this->l = l;
		this->r = r;
		this->z = z;
	}

	int l, r;
	int z;
};

class point {
public:
	point(int x, bool b, int z) {
		this->x = x;
		this->begin = b;
		this->z = z;
	}

	bool operator<(const point& l) const {
		return this->x < l.x;
	}

	bool begin;
	int x;
	int z;
};

int main() {
	int ntests;

	scanf("%d", &ntests);

	while(ntests--) {
		vector<poster> posters;
		vector<point> points;
		int n;

		scanf("%d", &n);

		for(int i = 0;i < n;i++) {
			int l, r;

			scanf("%d %d", &l, &r);

			posters.push_back(poster(l, r+1, posters.size()));
		}

		for(vector<poster>::iterator it = posters.begin();it != posters.end();it++) {
			points.push_back(point(it->l, true, it->z));
			points.push_back(point(it->r, false, it->z));
		}

		sort(points.begin(), points.end());

		unordered_set<int> visible;

		int x = 1;

		set<int,greater<int> > current;

		for(vector<point>::iterator it = points.begin();it != points.end();it++) {
			if(it->x > x && current.size() > 0) {
				visible.insert(*current.begin());
			}

			if(it->begin) {
				current.insert(it->z);
			} else {
				current.erase(it->z);
			}

			x = it->x;
		}

		printf("%d\n", (int)visible.size());
	}

	return 0;
}