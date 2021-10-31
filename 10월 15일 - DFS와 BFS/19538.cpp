#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<int> q; // ������ �����ϴ� ť
vector<int> time;
vector<vector<int>> people;

bool trust(int p) { // ��� ���� ���ΰ�
    int believer = 0;
    for(int i : people[p]) // �ֺ� ��� �˻�
        if (time[i] != -1) believer++;
    return (double) believer >= (double) people[p].size() / 2;
}

void spreadRumor(int start, queue<int> &temp) { // ��� ����
    while(!temp.empty()) {
        int new_spread = temp.front(); temp.pop();
        time[new_spread] = time[start] + 1;
        q.push(new_spread); // ���ο� ������ �߰�
    }
}

void bfs() {
    queue<int> temp; // ���� ��� �ӽ� ����

    while(!q.empty()) {
        int start = q.front(); q.pop(); // ���� ������

        for(int i = 0; i < people[start].size(); i++) {
            int near = people[start][i]; // ���� ���

            if(time[near] != -1) continue; // �̹� ��� �ϴ� ��� ���� �Ұ�
            if(trust(near)) temp.push(near); // ���� ��� �ӽ� ����
        }
        spreadRumor(start, temp); // ��� ����
    }
}

int main() {
    int n, m, temp;

    cin >> n;
    time.assign(n+1, -1);
    people.assign(n+1, vector<int>());

    for(int i = 1; i <= n; i++) { // �ֺ��� �Է�
        while(true) {
            cin >> temp;
            if(!temp) break;
            people[i].push_back(temp);
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++) { // ���� ������ �Է�
        cin >> temp;
        time[temp] = 0;
        q.push(temp);
    }

    bfs();
    for(int i = 1; i <= n; i++) // ��� ���
        cout << time[i] << ' ';
    return 0;
}