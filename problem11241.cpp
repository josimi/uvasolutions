// problem 11241
// Jonathon Simister

#include <cstdio>
#include <map>
#include <cmath>

using namespace std;

double humidex(double temperature, double dewpoint) {
	double e = 6.11 * exp(5417.7530 * ((1.0 / 273.16) - (1.0 / (dewpoint + 273.16))));
	double h = (0.5555)*(e - 10.0);

	return temperature + h;
}

double dewpoint(double humidex, double temperature) {
	double h = humidex - temperature;

	double e = (h / 0.5555) + 10.0;

	double a = e / 6.11;
	double b = log(a);

	double c = b / 5417.7530;
	double d = (1.0 / 273.16) - c;

	double f = 1.0 / d;

	return f - 273.16;

}

int main() {
	char l1[10];
	char l2[10];
	double v1, v2;

	while(scanf("%s %lf %s %lf", l1, &v1, l2, &v2) == 4) {
		bool tset = false;
		bool dset = false;
		bool hset = false;
		double t, d, h;

		switch(l1[0]) {
		case 'T':
			tset = true;
			t = v1;
			break;
		case 'D':
			dset = true;
			d = v1;
			break;
		case 'H':
			hset = true;
			h = v1;
			break;
		}

		switch(l2[0]) {
		case 'T':
			tset = true;
			t = v2;
			break;
		case 'D':
			dset = true;
			d = v2;
			break;
		case 'H':
			hset = true;
			h = v2;
			break;
		}

		if(tset && dset) {
			h = humidex(t, d);
		} else if(tset && hset) {
			dewpoint(h, t);
		} else if(dset && hset) {
			t = h - humidex(0, d);
		}

		printf("T %.1lf D %.1lf H %.1lf\n", t, d, h);
	}

	return 0;
}