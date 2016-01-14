// problem 11503
// Jonathon Simister

#include <cstdio>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> pids;
vector<int> root;
vector<int> treesize;

int getpid(string name) {
	if(pids.count(name) == 0) {
		pids[name] = pids.size();
		root.push_back(root.size());
		treesize.push_back(1);
	}

	return pids[name];
}

int unionfind(int v) {
	int u = v;

	while(root[u] != u) {
		u = root[u];
	}

	root[v] = u;

	return root[v];
}

int makeunion(int u, int v) {
	int ur = unionfind(u);
	int vr = unionfind(v);

	if(ur == vr) {
		return treesize[ur];
	}

	if(ur < vr) {
		root[vr] = ur;
		treesize[ur] += treesize[vr];

		return treesize[ur];
	} else if(vr < ur) {
		root[ur] = vr;
		treesize[vr] += treesize[ur];

		return treesize[vr];
	}
}

int main() {
	int ntests;

	scanf("%d", &ntests);

	while(ntests--) {
		int nfriends;
		char buf1[50];
		char buf2[50];

		pids.clear();
		root.clear();
		treesize.clear();

		scanf("%d", &nfriends);

		for(int c = 0;c < nfriends;c++) {
			scanf("%s %s", buf1, buf2);

			int v = getpid(string(buf1));
			int u = getpid(string(buf2));

			int s = makeunion(v, u);

			printf("%d\n", s);
		}

		//if(ntests > 0) { putchar('\n'); }
	}

	return 0;
}