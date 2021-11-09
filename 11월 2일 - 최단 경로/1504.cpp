#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> ci;

int n;
const int INF = 1e8 * 2 + 1;
vector<vector<ci>> graph;

int shortestPath (int start, int end) { // start���� end���� �ִ� ���
    vector<int> dist(n+1, INF);
    priority_queue<ci, vector<ci>, greater<>> pq; // (first : ���������κ��� �Ÿ�, second: ����)

    // ���� ��ġ �ʱ�ȭ
    dist[start] = 0;
    pq.push({0, start});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if(weight > dist[node]) continue; // �̹� Ȯ���ߴ� ����

        for(int i = 0; i < graph[node].size(); i++) {
            int next_node = graph[node][i].first; // ����� ����
            int next_weight = weight + graph[node][i].second; // ���������κ��� ����� ���������� �Ÿ�

            if(dist[next_node] > next_weight) { // �� ª�� ��η� �� �� �ִٸ�
                dist[next_node] = next_weight;
                pq.push({next_weight, next_node});
            }
        }
    }
    return dist[end];
}

int main() {
    int e, a, b, c, v1, v2;
    cin >> n >> e;

    graph.assign(n+1, vector<ci> (0)); // ���� ����Ʈ
    while(e--) {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    cin >> v1 >> v2;

    int path1 = shortestPath(1, v1) + shortestPath(v1, v2) + shortestPath(v2, n); // 1 -> v1 -> v2 -> n
    int path2 = shortestPath(1, v2) + shortestPath(v2, v1) + shortestPath(v1, n); // 1 -> v2 -> v1 -> n

    int ans = min(path1, path2); // �ִ� ��� ����

    if(ans >= INF) cout << -1;
    else cout << ans;
    return 0;
}