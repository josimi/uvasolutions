// problem 10341
// Jonathon Simister

#include <cstdio>
#include <cmath>

using namespace std;

int p, q, r, s, t, u;

double f(double x) {
	return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

double df(double x) {
	return -p*exp(-x) + q*cos(x) - r*sin(x) + (s / (cos(x)*cos(x))) + 2 * t*x;
}

double newtonMethod() {
	double x0 = 0.5;
	double x1 = 1;

	for(int c = 0;c < 7;c++) {
		x1 = x0 - f(x0) / df(x0);

		x0 = x1;
	}
	
	return x1;
}

int main() {
	while(scanf("%d %d %d %d %d %d", &p, &q, &r, &s, &t, &u) == 6) {
		double root = newtonMethod();

		if(abs(f(root)) < 1e-10 && root >= 0 && root <= 1.0) {
			printf("%1.4lf\n", root);
		} else {
			puts("No solution");
		}
	}

	return 0;
}