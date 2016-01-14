// problem 1013
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <functional>
#include <algorithm>

using namespace std;

#define inf 1.0E40

struct island {
	int x, y;
	int pop;
};

double isledist(island a,island b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;

	return sqrt(dx*dx + dy*dy);
}

int main() {
	int nislands;
	int ct = 0;
	vector<island> islands;
	vector<double> dist;
	priority_queue<pair<double,int>,vector<pair<double,int> >,greater<pair<double,int> > > q;

	while(scanf("%d", &nislands) == 1) {
		if(nislands == 0) { break; }

		ct++;

		islands.clear();
		dist.clear();

		for(int c = 0;c < nislands;c++) {
			int x, y, pop;

			scanf("%d %d %d", &x, &y, &pop);
			islands.push_back({ x, y, pop });
		}

		dist.assign(nislands, inf);
		dist[0] = 0;

		q.push({ 0, 0 });
		
		while(!q.empty()) {
			int t = q.top().second;
			q.pop();

			for(int x = 0;x < nislands;x++) {
				if(dist[x] > max(dist[t],isledist(islands[t], islands[x]))) {
					dist[x] = max(dist[t], isledist(islands[t], islands[x]));
					q.push({ dist[x], x });
				}
			}
		}

		double avg = 0;
		double popsum = 0;

		for(int x = 0;x < nislands;x++) {
			popsum += islands[x].pop;
			avg += islands[x].pop * dist[x];
		}

		avg = avg / popsum;

		printf("Island Group: %d Average %.2lf\n\n", ct, avg);
	}

	return 0;
}