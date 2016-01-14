// problem 218
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class point {
public:
	point(double x_, double y_) {
		this->x = x_;
		this->y = y_;
	}

	double x, y;
};

// Three points are a counter - clockwise turn if ccw > 0, clockwise if
// ccw < 0, and collinear if ccw = 0 because ccw is a determinant that
// gives twice the signed  area of the triangle formed by p1, p2 and p3.
int ccw(point p1, point p2, point p3) {
	return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x);
}

bool ylower(point& a, point& b) {
	return a.y < b.y;
}


class polarsort {
public:
	polarsort(point& p) {
		this->px = p.x;
		this->py = p.y;
	}

	bool operator() (point& a, point& b) const {
		return atan2(a.y - py, a.x - px) < atan2(b.y - py, b.x - px);
	}

private:
	int px, py;
};

int main() {
	int n;
	int ct = 0;

	while(scanf("%d", &n) == 1) {
		vector<point> points;

		if(n == 0) { break; }

		if(ct > 0) {
			putchar('\n');
		}

		ct++;

		points.push_back(point(0, 0));

		for(int i = 0;i < n;i++) {
			double x, y;

			scanf("%lf %lf", &x, &y);
			points.push_back(point(x, y));
		}

		nth_element(points.begin() + 1, points.begin() + 1, points.end(), ylower);

		sort(points.begin() + 2, points.end(), polarsort(points[1]));

		points[0] = points[points.size() - 1];

		int m = 1;

		for(int i = 2;i < points.size();i++) {
			while(ccw(points[m - 1], points[m], points[i]) < 0) {
				if(m > 1) {
					m -= 1;
				} else if(i == n) {
					break;
				} else {
					i += 1;
				}
			}

			m += 1;

			swap(points[m], points[i]);
		}

		double length = 0;

		for(int i = 1;i < m;i++) {
			double dx = points[i - 1].x - points[i].x;
			double dy = points[i - 1].y - points[i].y;

			length += sqrt(dx*dx + dy*dy);
		}

		{
			double dx = points[m - 1].x - points[0].x;
			double dy = points[m - 1].y - points[0].y;

			length += sqrt(dx*dx + dy*dy);
		}

		printf("Region #%d\n", ct);

		printf("(%.1lf,%.1lf)-", points[0].x, points[0].y);

		for(int i = m-1;i > 0;i--) {
			printf("(%.1lf,%.1lf)-", points[i].x, points[i].y);
		}

		printf("(%.1lf,%.1lf)\n", points[0].x, points[0].y);

		printf("Perimeter length = %.2lf\n", length);
	}

	return 0;
}