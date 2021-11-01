#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, int>> q; // (first: ������, second: ���� �ð�)
vector<int> time; // ��� �ϴ� �� �ɸ��� �ð�
vector<vector<int>> people; // �ֺ��� ����

queue<pair<int, int>> simultaneousSpreader() { // ���� ������ ����
    queue<pair<int, int>> simultaneous_spreader; // ���� ������ �����ϴ� ť
    simultaneous_spreader.push(q.front());

    while(!q.empty()) { // ���� ������ �ִ°�
        if(simultaneous_spreader.front().second != q.front().second) break; // ���� ������ ���̻� ����
        simultaneous_spreader.push(q.front());
        q.pop();
    }
    return simultaneous_spreader;
}

void spreadRumor(queue<pair<int, int>> &temp) { // ��� ����
    while(!temp.empty()) {
        int new_spreader = temp.front().first;
        int new_spread_time = temp.front().second;
        temp.pop();

        time[new_spreader] = new_spread_time + 1;
        q.push({new_spreader, time[new_spreader]}); // ���ο� ������ �߰�
    }
}

bool trust(int p) { // ��� ���� ���ΰ�
    int believer = 0;
    for(int i : people[p]) // �ֺ� ��� �˻�
        if (time[i] != -1) believer++;
    return (double) believer >= (double) people[p].size() / 2;
}

void bfs() {
    while(!q.empty()) {
        queue<pair<int, int>> simultaneous_spreader = simultaneousSpreader(); // ���� ������
        queue<pair<int, int>> temp; // ���� ��� �ӽ� ����

        while(!simultaneous_spreader.empty()) {
            int spreader = simultaneous_spreader.front().first;     // ������
            int spread_time = simultaneous_spreader.front().second; // ���� �ð�
            simultaneous_spreader.pop();

            for(int i = 0; i < people[spreader].size(); i++) { // �ֺ��� �˻�
                int near = people[spreader][i]; // ���� ���

                if(time[near] != -1) continue;   // �̹� ��� �ϴ� ��� ���� �Ұ�
                if(trust(near)) temp.push({near, spread_time}); // ���� ��� �ӽ� ����
            }
        }
        spreadRumor(temp); // ��� ���� (���� �������� ���� ��� �ľ� �� ���� ����)
    }
}

void printAnswer(int n) { // ��� ���
    for(int i = 1; i <= n; i++)
        cout << time[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, person;

    cin >> n;
    time.assign(n+1, -1);
    people.assign(n+1, vector<int>());

    for(int i = 1; i <= n; i++) { // �ֺ��� �Է�
        while(true) {
            cin >> person;
            if(!person) break;
            people[i].push_back(person);
        }
    }

    cin >> m;
    for(int i = 0; i < m; i++) { // ���� ������ �Է�
        cin >> person;
        time[person] = 0;
        q.push({person, time[person]});
    }

    bfs();
    printAnswer(n);
    return 0;
}