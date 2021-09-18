#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<pair<int, int>> time_table;

int countRoom() { // ���ǽ� ���� ����
    int idx = 0, time_cnt = time_table.size();
    priority_queue<int, vector<int>, greater<>> room;
    room.push(time_table[idx++].second); // �ʱ� ���ǽ� ����

    while(idx < time_cnt) {
        if(room.top() <= time_table[idx].first) // (���ǽ� �ð� ����)
            room.pop();
        room.push(time_table[idx++].second); // ���ο� ���ǽ�
    }
    return room.size();
}

int main() {
    int n, start, end;
    cin >> n;

    while(n--) { // ���ǽ� �ð�ǥ �Է�
        cin >> start >> end;
        time_table.push_back({start, end});
    }
    sort(time_table.begin(), time_table.end());

    cout << countRoom();
    return 0;
}