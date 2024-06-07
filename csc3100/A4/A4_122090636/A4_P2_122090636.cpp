#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

class Prim {
private:
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > gifts;
    set<int> connected;
    vector<vector<int> > costs;
    int total;
    int W;
    int N;

public:
    Prim(vector<vector<int> >& costs, int W, int N) : costs(costs), W(W), N(N) {
        total = W;
        connected.insert(0); 
    }

    void randomAdd() {
        for (int node = 1; node < N; ++node) {
            int cost_0_out = costs[0][node];
            if (cost_0_out > 0) {
                gifts.push(make_pair(cost_0_out, node));
            }
        }
    }

    int addMin() {
        while (!gifts.empty()) {
            pair<int, int> top = gifts.top();
            int cost = top.first;
            int next = top.second;
            gifts.pop();
            if (connected.find(next) != connected.end()) {
                continue;
            }
            connected.insert(next);
            total += min(cost, W);

            for (int node = 0; node < N; ++node) {
                if (connected.find(node) != connected.end()) {
                    continue;
                }
                int cost_next_out = costs[next][node];
                if (cost_next_out > 0) {
                    gifts.push(make_pair(cost_next_out, node));
                }
            }
        }
        return total;
    }
};

int main() {
    int N, W;
    cin >> N >> W;

    vector<vector<int> > costs(N, vector<int>(N));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> costs[i][j];
        }
    }

    Prim prim(costs, W, N);
    prim.randomAdd();
    cout << prim.addMin() << endl;

    return 0;
}
