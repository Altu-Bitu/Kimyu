#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 1e5;

typedef pair<int, int> ci;

vector<int> dijkstra(int n, int start, vector<vector<ci>> &graph) {
    vector<int> dist(n + 1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    // ���� ��ġ
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (weight > dist[node]) continue;

        for (int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first;
            int new_weight = weight + graph[node][i].second;

            if (dist[next_node] > new_weight) { // �� ª�� ��� �� �� �ִ� ���
                dist[next_node] = new_weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    return dist;
}

int roundTrip(int n, vector<int> &go, vector<int> &back) {
    int result = 0;
    for(int i = 1; i <= n; i++)
        result = max(result, go[i] + back[i]);
    return result;
}

int main() {
    int n, m, x, start, end, t;
    cin >> n >> m >> x;

    vector<vector<ci>> graph (n+1, vector<ci> ());
    vector<vector<ci>> rev_graph (n+1, vector<ci> ());

    while(m--) {
        cin >> start >> end >> t;
        graph[start].push_back({end, t});
        rev_graph[end].push_back({start, t});
    }

    vector<int> go = dijkstra(n, x, rev_graph); // ��� ���� ~ x������ �Ÿ�
    vector<int> back = dijkstra(n, x, graph);   // x ~ ��� ���������� �Ÿ�

    cout << roundTrip(n, go, back);
    return 0;
}