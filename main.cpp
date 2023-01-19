#include <bits/stdc++.h>
using namespace std;

#define MAX_SEQ_SIZE 7

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


vector<int> path;
bool ok = false;


void bkt(int p, int d, vector<int> place) {

    if (ok || d > MAX_SEQ_SIZE) {
        return;
    }
    int source = 0;
    int sz = place.size();
    for (int i = 0; i < sz; ++i) {
        place[i] = edges[place[i]][p];
    }

    int s1 = 0;

    for (int i = 0; i < sz; ++i) {
        s1 += (place[i] == place[0]);
    }

    if (s1 == sz) {
        for (int i = 0; i < path.size(); ++i) {
            cout << path[i] << '\n';
        }
        ok = true;
    }

    for (int j = 0; j < edges[0].size(); ++j) {
        path.push_back(j);
        bkt(j, d + 1, place);
        path.pop_back();
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
    if (strcmp(argv[1], "synchronize") == NULL) {

        vector<int> place(n);
        for (int i = 0; i < n; ++i) {
            place[i] = i;
        }
        for (int j = 0; j < m; ++j) {
            if (ok) {
                break;
            }
            path.push_back(j);
            bkt(j, 1, place);
            path.pop_back();
        }

    }
    


    return 0;
}