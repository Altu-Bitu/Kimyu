#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 1e7 + 1;
vector<vector<int>> road;

//�÷��̵�-����
void floydWarshall(int n) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                int dist = road[i][k] + road[k][j]; //k�� ���ļ� i���� j�� ��
                road[i][j] = min(road[i][j], dist);
            }
        }
    }
}

int roundTrip(int x, int n) {
    vector<int> result (n+1, INF);
    for(int i = 1; i <= n; i++)
        result[i] = road[i][x] + road[x][i];
    sort(result.begin()+1, result.end());
    return result[n];
}

int main() {
    int n, m, x, start, end, t;
    cin >> n >> m >> x;

    road.assign(n+1, vector<int> (n+1 , INF));
    for(int i = 1; i <= n; i++) road[i][i] = 0; // �ڱ� �ڽŰ��� �Ÿ�

    while(m--) {
        cin >> start >> end >> t;
        road[start][end] = t;
    }
    floydWarshall(n);
    cout << roundTrip(x, n);
    return 0;
}