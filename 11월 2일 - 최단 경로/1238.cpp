#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
const int INF = 1e7 + 1;

typedef pair<int, int> ci;
vector<vector<ci>> road;

int dijkstra(int start, int end, int n) {
    vector<int> dist (n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    // ���� ��ġ
    dist[start] = 0;
    pq.push({dist[start], start});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node]) continue;

        for(int i = 0; i < road[node].size(); i++) {
            int next_node = road[node][i].first;
            int new_weight = weight + road[node][i].second;

            if(dist[next_node] > new_weight) { // �� ª�� ��� �� �� �ִ� ���
                dist[next_node] = new_weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    return dist[end]; // start���� end������ �ִܰŸ� ��ȯ
}

vector<int> singleDestination(int end, int n) { // �� �������� ��� ���������� �Ÿ� ����
    vector<int> dist(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq;

    // ���� ��ġ
    dist[end] = 0;
    pq.push({dist[end], end});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node]) continue;

        for(int i = 0; i < road[node].size(); i++) {
            int next_node = road[node][i].first;
            int new_weight = weight + road[node][i].second;

            if(dist[next_node] > new_weight) { // �� ª�� ��� �� �� �ִ� ���
                dist[next_node] = new_weight;
                pq.push({dist[next_node], next_node});
            }
        }
    }
    return dist;
}

int roundTrip(int x, int n, vector<int> single_dst) { // ���� ���� �ɸ��� �л��� �ҿ�ð� ����
    vector<int> result (n+1, INF);
    for(int i = 1; i <= n; i++)
        result[i] = dijkstra(i, x, n) + single_dst[i];

    sort(result.begin()+1, result.end());
    return result[n];
}

int main() {
    int n, m, x, start, end, t;
    cin >> n >> m >> x;

    road.assign(n+1, vector<ci> ());
    while(m--) {
        cin >> start >> end >> t;
        road[start].push_back({end, t});
    }

    vector<int> single_dst = singleDestination(x, n); // x���� ��� ���������� �Ÿ�
    cout << roundTrip(x, n, single_dst);
    return 0;
}