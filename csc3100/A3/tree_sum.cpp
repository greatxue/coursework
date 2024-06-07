#include <iostream>
#include <vector>
#include <numeric>  

using namespace std;

const int MOD = 1000000007;

struct Node {
    vector<pair<int, int> > adj;
};

class BlackWhiteTree {
private:
    vector<Node> tree;
    vector<int> color;
    vector<long long> count, dis;
    vector<long long> ans;  
    long long total = 0;

public:
    BlackWhiteTree(int node_num) : tree(node_num), color(node_num), count(node_num),
                                   dis(node_num), ans(node_num) {}

    void saveColor(const vector<int>& colors) {
        color = colors;
        total = accumulate(color.begin(), color.end(), 0LL);
    }

    void addEdge(int u, int v, int w) {
        tree[u].adj.push_back(make_pair(v, w));
        tree[v].adj.push_back(make_pair(u, w));
    }

    void dfsHelper(int node, int parent) {
        count[node] = color[node];
        for (auto& adj_weight : tree[node].adj) {
            int adj = adj_weight.first;
            int weight = adj_weight.second;
            if (adj != parent) {
                dfsHelper(adj, node);
                count[node] += count[adj];
                dis[node] += dis[adj] + count[adj] * weight;
            }
        }
    }

    void dfs(int node, int parent) {
        ans[node] = dis[node];
        for (auto& adj_weight : tree[node].adj) {
            int adj = adj_weight.first;
            int weight = adj_weight.second;
            if (adj != parent) {
                long long node_to_adj_root = dis[node] - (dis[adj] + count[adj] * weight);
                long long node_to_adj = (total - count[adj]) * weight;
                dis[adj] += node_to_adj_root + node_to_adj;
                dfs(adj, node);
            }
        }
    }
    
    const vector<long long>& answer() {
        dfsHelper(0, -1);
        dfs(0, -1);
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    BlackWhiteTree tree(n);

    vector<int> colors(n);
    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }
    tree.saveColor(colors);

    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        tree.addEdge(u - 1, v - 1, w);
    }

    const vector<long long>& answers = tree.answer();
    for (int i = 0; i < n; ++i) {
        cout << (answers[i] % MOD) << endl;
    }

    return 0;
}
