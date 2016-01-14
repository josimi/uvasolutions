// problem 914
// Jonathon Simister

#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <map>

using namespace std;

const int limit = 1000005;

int main() {
	bool* era = new bool[limit];
	vector<int> primes;
	
	memset(era, true, limit);

	era[0] = false;
	era[1] = false;

	for(long long x = 2;x < limit;x++) {
		if(era[x])
		{
			primes.push_back(x);
			for(long long y = x*x;y < limit;y += x)
			{
				era[y] = false;
			}
		}
	}

	int t;
	scanf("%d", &t);

	for(int i = 0;i < t;i++)
	{
		int l, h;
		scanf("%d %d", &l, &h);
		map<int, int> count;

		for(vector<int>::iterator it = lower_bound(primes.begin(), primes.end(), l);it < primes.end();)
		{
			int a = *it;
			it++;
			int b = *it;

			if(b > h) {
				break;
			}

			count[b - a]++;
		}

		int jc = -1;
		int jcn = 0;

		for(map<int, int>::iterator it = count.begin();it != count.end();it++)
		{
			if(it->second > jcn)
			{
				jc = it->first;
				jcn = it->second;
			}
			else if(it->second == jcn)
			{
				jcn = 0;
				jc = -1;
				break;
			}
		}

		if(jc == -1)
		{
			puts("No jumping champion");
		}
		else
		{
			printf("The jumping champion is %d\n", jc);
		}
	}

	return 0;
}