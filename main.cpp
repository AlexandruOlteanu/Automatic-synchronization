#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> edges;
set<int> accessible;

void dfs(int x) {
    if (accessible.count(x)) {
        return;
    }
    accessible.insert(x);
    for (auto edge : edges[x]) {
        dfs(edge);
    }
}


int main(int argc, char **argv) {

    if (strcmp(argv[1], "accessible") == NULL) {
        int n, m, s;
        cin >> n >> m >> s;
        edges.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                int x;
                cin >> x;
                edges[i].push_back(x);
            }
        }

        for (int i = 1; i <= s; ++i) {
            int x;
            cin >> x;
            dfs(x);
        }
        for (int i = 0; i < n; ++i) {
            if (accessible.count(i)) {
                cout << i << '\n';
            }
        }

    }


    return 0;
}