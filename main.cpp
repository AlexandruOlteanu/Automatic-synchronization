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

    int n, m, s;
    cin >> n >> m >> s;
    int source[s + 1];
    edges.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int x;
            cin >> x;
            edges[i].push_back(x);
        }
    }

    for (int i = 1; i <= s; ++i) {
            cin >> source[i];
    }

    if (strcmp(argv[1], "accessible") == NULL) {
        
        for (int i = 1; i <= s; ++i) {
            dfs(source[i]);
        }
        
        for (int i = 0; i < n; ++i) {
            if (accessible.count(i)) {
                cout << i << '\n';
            }
        }
    }
    


    return 0;
}