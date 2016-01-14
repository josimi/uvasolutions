// problem 12911
// Jonathon Simister

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int n;
	long long t;
	
	while(scanf("%d %lld", &n, &t) == 2)
	{
		long long a[40];
		vector<long long> lv;
		map<long long, int> hv;

		for(int i = 0;i < n;i++)
		{
			scanf("%lld", a + i);
		}

		int l = n / 2;
		int h = n - l;

		for(int m = 0;m < (1 << l);m++)
		{
			long long sum = 0;

			for(int x = 0;x < l;x++)
			{
				if(m & (1 << x))
				{
					sum += a[x];
				}
			}

			lv.push_back(sum);
		}

		for(int m = 0;m < (1 << h);m++)
		{
			long long sum = 0;

			for(int x = 0;x < h;x++)
			{
				if(m & (1 << x))
				{
					sum += a[x + l];
				}
			}

			hv[sum]++;
		}

		long long count = 0;

		for(vector<long long>::iterator it = lv.begin();it != lv.end();it++)
		{
			count += hv[t - *it];
		}

		if(t == 0) { count--; }

		printf("%lld\n", count);
	}

	return 0;
}