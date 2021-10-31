#include <iostream>
#include <queue>

using namespace std;

const int MAX_TIME = 100000;
int time[MAX_TIME+1]; // �ش� �������� ���� �� �ɸ��� �ּ� �ð� ����

int bfs(int n, int k) {
    queue<int> q;

    q.push(n); // ���� ��ġ ����
    time[n] = 0;

    while(!q.empty()) {
        int temp = q.front(); q.pop(); // Ž�� ��ġ
        if(temp == k) return time[temp]; // �ҿ� �ð� ��ȯ

        // 1. �ȱ�
        int walk1 = temp - 1, walk2 = temp + 1;
        if(walk1 >= 0 && !time[walk1]) {
            q.push(walk1);
            time[walk1] = time[temp] + 1;
        }
        if(walk2 <= MAX_TIME && !time[walk2]) {
            q.push(walk2);
            time[walk2] = time[temp] + 1;
        }
        // 2. �����̵�
        int teleport = temp * 2;
        if(teleport <= MAX_TIME && !time[teleport]) {
            q.push(teleport);
            time[teleport] = time[temp] + 1;
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    cout << bfs(n, k);
    return 0;
}