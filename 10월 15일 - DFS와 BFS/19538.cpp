#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

queue<pair<int, int>> q; // (first: ������, second: ���� �ð�)
vector<int> time, believer; // ��� �ϴ� �� �ɸ��� �ð�, ��� �ϴ� ���
vector<vector<int>> people; // �ֺ��� ����

vector<pair<int, int>> simultaneousSpreader() { // ���� ������ ����
    vector<pair<int, int>> simultaneous_spreader; // ���� ������ �����ϴ� ť
    simultaneous_spreader.push_back(q.front());
    q.pop();

    while(!q.empty()) { // ���� ������ �ִ°�
        if(simultaneous_spreader.front().second != q.front().second) break; // ���� ������ ���̻� ����
        simultaneous_spreader.push_back(q.front());
        q.pop();
    }
    return simultaneous_spreader;
}

set<int> findNeighbor(int simul_cnt, vector<pair<int, int>> simultaneous_spreader) { // �ֺ��� ����
    set<int> neighbor;
    for(int i = 0; i < simul_cnt; i++) {
        int spreader = simultaneous_spreader[i].first; // ������

        for (int j = 0; j < people[spreader].size(); j++) {
            int near = people[spreader][j];
            believer[near]++;
            if(time[near] == -1) neighbor.insert(near); // ��� ���� �ʴ� �ֺ��θ� ���
        }
    }
    return neighbor;
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

bool trust(int near) { return (double) believer[near] >= (double) people[near].size() / 2; }

void bfs() {
    while(!q.empty()) {
        vector<pair<int, int>> simultaneous_spreader = simultaneousSpreader(); // ���� ������
        int simul_cnt = simultaneous_spreader.size(); // ���� ������ ��
        if(!simul_cnt) continue;

        set<int> neighbor = findNeighbor(simul_cnt, simultaneous_spreader); // �ֺ���
        int spread_time = simultaneous_spreader[0].second; // ���� �ð�

        queue<pair<int, int>> temp; // ���� ��� �ӽ� ����
        for(auto iter = neighbor.begin(); iter != neighbor.end(); iter++) // �ֺ��� �� ���� ��� Ž��
            if(trust(*iter)) temp.push({*iter, spread_time});

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
    believer.assign(n+1, 0);
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