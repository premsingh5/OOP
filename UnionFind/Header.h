
#include<iostream>
#include<vector>
using namespace std;
class UnionFind {
	vector<int> id;
	vector<int> sz;
	int len;
public:
	UnionFind(int n = 0) {
		id = vector<int>(n,0);
		sz = vector<int>(n, 1);
		for (int i = 0; i < n; i++) {
			id[i] = i;
		}
		len = id.size();
	}
	int root(int i) {
		vector<int>visited(0);
		while (i != id[i]) {
			//int parent = id[i];
			//id[i] = id[id[i]];
			//sz[parent] -= sz[i];
			//cout << "i:" << i << endl;
			visited.push_back(i);
			i = id[i];
		}
		if (visited.size()) {
			for (int j = visited.size() - 1; j >= 0; j--) {
				if (j == 0) {
					id[visited[j]] = i;
				}
				else {
					id[visited[j]] = i;
					sz[visited[j]] -= sz[visited[j - 1]];
				}
			}

		}
		return i;
	}
	bool find(int x, int y) {
		return (root(x) == root(y));
	}

	void Union(int i1, int i2) {
		int root1 = root(i1);
		int root2 = root(i2);
		if (sz[root1] < sz[root2]) {
			id[root1] = root2;
			sz[root2] += sz[root1];
		}
		else {
			id[root2] = root1;
			sz[root1] += sz[root2];
		}

	}
	void insert() {
		id.push_back(len);
		sz.push_back(1);
		len = id.size();
	}
	int getSize() {
		return len;
	}
	int subtreeSize(int k) {
		return sz[k];
	}
};