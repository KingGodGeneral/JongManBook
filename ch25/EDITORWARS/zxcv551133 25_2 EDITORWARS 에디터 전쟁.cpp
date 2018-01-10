#ifndef ONLINE_JUDGE
#define _CRT_SECURE_NO_WARNINGS
#endif // !ONLINE_JUDGE
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <math.h>
#include <bitset>
#include <set>
#include <map>
#include <queue>
#include <functional> // for greater less
using namespace std;
const int I32MAX = 2147483647;
const vector<pair<int, int>> cardinalP = { { 0,1 },{ 0,-1 },{ -1,0 },{ 1,0 } };
// write below


int n, m;
struct BipartiteUnionFind {
	// parent[i] = i�� �θ� ���, ��Ʈ���, i
	// rank[i] = i�� ��Ʈ�� ���, i�� ��Ʈ�� �ϴ� Ʈ���� ��ũ
	// enemy[i] = i�� ��Ʈ�� ���, �ش� ���հ� ���� ������ ������ ��Ʈ�� ��ȣ. (������ -1)
	// size[i] = i�� ��Ʈ�� ���, �ش� ������ ũ��
	vector<int> parent, rank, enemy, size;
	BipartiteUnionFind(int n) : parent(n), rank(n, 0),
		enemy(n, -1), size(n, 1) {
		for (int i = 0; i < n; ++i)	parent[i] = i;
	}
	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}

	int merge(int u, int v) {
		// u�� v�� �������� ��� ������ �ϳ��� ��ȯ�Ѵ�.
		if (u == -1 || v == -1) return max(u, v);
		u = find(u); v = find(v);
		// �̹� ���� ���� Ʈ���� ���� ���
		if (u == v) return u;
		if (rank[u] > rank[v]) swap(u, v);
		// ���� �׻� rank[v]�� �� ũ�Ƿ� u�� v�� �ڽ����� �ִ´�.
		if (rank[u] == rank[v]) rank[v]++;
		parent[u] = v;
		size[v] += size[u];
		return v;
	}
	// u�� v�� ���� ���̴�. ����� �Ͼ�ٸ� false, �ƴϸ� true�� ��ȯ�Ѵ�.
	bool dis(int u, int v) {
		// �켱 ��Ʈ�� ã�´�.
		u = find(u);  v = find(v);
		// ���� ���տ� ���� ������ ���!
		if (u == v) return false;
		// ���� ���� ���� ����
		int a = merge(u, enemy[v]), b = merge(v, enemy[u]);
		enemy[a] = b; enemy[b] = a;
		return true;
	}

	// u�� v�� ���� ������. ����� �Ͼ�ٸ� false, �ƴϸ� true�� ��ȯ�Ѵ�.
	bool ack(int u, int v) {
		// �켱 ��Ʈ�� ã�´�.
		u = find(u); v = find(v);
		// �ٸ� ���տ� ���� ������ ���!
		if (enemy[u] == v) return false;
		// ������ ���� ���� ��
		int a = merge(u, v), b = merge(enemy[u], enemy[v]);
		enemy[a] = b;
		// �� ���� �� �����ϴ� ������ ������ b�� -1�� ���� �ִ�.
		if (b != -1)	enemy[b] = a;
		return true;
	}

};

// BipartiteUnionFind �ν��Ͻ��� �־��� ��,
// �� ��Ƽ�� �� ���ɼ��� �ִ� �ִ� �ο��� ���Ѵ�.
int maxParty(const BipartiteUnionFind& buf) {
	int ret = 0;
	for (int node = 0; node < n; ++node) {
		if (buf.parent[node] == node) {
			int enemy = buf.enemy[node];
			// ���� ���� ���� �� �� ���� �ʱ� ����, enemy < node�� ��츸 ����.
			// enemy  == 1�� ��쵵 ��Ȯ�� �� ���� ���� �ȴ�.
			if (enemy > node) continue;
			int mySize = buf.size[node];
			int enemySize = (enemy == -1 ? 0 : buf.size[enemy]);
			// �� ���� �� ū ������ ���Ѵ�.
			ret += max(mySize, enemySize);
		}
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif // !ONLINE_JUDGE
	cin.tie(0); ios_base::sync_with_stdio(0);
	//write your code below
	int tc; cin >> tc;
	while (tc--) {
		cin >> n >> m;
		BipartiteUnionFind	myBuf(n);
		string s; int u, v;
		bool cd = true;
		int cont = 0;
		for (int i = 0; i < m; i++) {
			cin >> s >> u >> v;
			if (!cd) continue;
			if (s == "ACK") {
				cd = myBuf.ack(u, v);
			}
			else {
				cd = myBuf.dis(u, v);
			}
			if (!cd) cont = i + 1;
		}
		if (cd) cout << "MAX PARTY SIZE IS " << maxParty(myBuf) << '\n';
		else cout << "CONTRADICTION AT " << cont << '\n';
	}
	// code ended
	return 0;
}