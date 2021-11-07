#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 125 * 9 + 1;

typedef pair<int, pair<int, int>> node;
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0}; // �� �� �� ��

int loseRupee(int n, vector<vector<int>> cave) { // (0, 0)���� (n-1, n-1)���� �ִ� ��� ��ȯ
    vector<vector<int>> dist(n, vector<int> (n, INF));
    priority_queue<node, vector<node>, greater<>> pq;

    // ���� ��ġ ����
    dist[0][0] = cave[0][0];
    pq.push({dist[0][0], {0, 0}});

    while(!pq.empty()) {
        int weight = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();

        if(weight > dist[row][col]) continue;

        for(int i = 0; i < 4; i++) {
            int new_row = row + dy[i];
            int new_col = col + dx[i];
            if(new_row < 0 || new_row >= n || new_col < 0 || new_col >= n) continue;

            int new_weight = weight + cave[new_row][new_col];
            if(dist[new_row][new_col] > new_weight) { // �� ª�� ��� ������ ���
                dist[new_row][new_col] = new_weight;
                pq.push({new_weight, {new_row, new_col}});
            }
        }
    }
    return dist[n-1][n-1];
}

int main() {
    int n; // ���� ũ��

    int num = 0;
    while(true) {
        cin >> n;
        num++;
        if(!n) break;

        vector<vector<int>> cave(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) { // ���Ϸ��� ũ�� �Է�
            for(int j = 0; j < n; j++)
                cin >> cave[i][j];
        }
        cout << "Problem " << num << ": " << loseRupee(n, cave) << '\n';
    }
    return 0;
}