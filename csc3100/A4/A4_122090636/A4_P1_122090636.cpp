#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Compare {
    map<int, int>& index;
    Compare(map<int, int>& idx) : index(idx) {}

    bool operator() (int a, int b) {
        return index[a] < index[b];
    }
};

class DFS {
private:
    vector<vector<int> > graph;
    vector<bool> visited;
    vector<int> dfs_order;
    int v;

    void run_dfs(int node) {
        visited[node] = true;
        dfs_order.push_back(node);
        for (size_t i = 0; i < graph[node].size(); ++i) {
            int nb = graph[node][i];
            if (!visited[nb]) {
                run_dfs(nb);
            }
        }
    }

public:
    DFS(int v) : v(v), graph(v + 1), visited(v + 1, false) {}

    bool compare(const vector<int>& parents, const vector<int>& order) {
        for (int i = 0; i < v - 1; ++i) {
            graph[parents[i]].push_back(i + 2);
        }

        map<int, int> index;
        for (size_t i = 0; i < order.size(); ++i) {
            index[order[i]] = i;
        }

        for (size_t i = 1; i < graph.size(); ++i) {
            Compare comp(index);
            sort(graph[i].begin(), graph[i].end(), comp);
        }

        run_dfs(1);
        return dfs_order == order;
    }
};

int main() {
    int num;
    cin >> num;
    while (num--) {
        int v;
        cin >> v;
        vector<int> parents(v - 1);
        vector<int> order(v);

        for (int i = 0; i < v - 1; ++i) {
            cin >> parents[i];
        }

        for (int i = 0; i < v; ++i) {
            cin >> order[i];
        }

        DFS dfs(v);
        if (dfs.compare(parents, order)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
