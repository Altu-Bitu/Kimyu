#include <iostream>
<<<<<<< HEAD
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
=======
#include <queue>

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> time;
priority_queue<int, vector<int>, greater<>> room;

int count_room() { // ���ǽ� ���� ����
    room.push(time.top().second); // �ʱ� ���ǽ� ����
    time.pop();
    
    while(!time.empty()) {
        if(room.top() <= time.top().first) { // ���ǽ� �ð� ����
            room.pop();
            room.push(time.top().second);
        }
        else room.push(time.top().second); // ���ο� ���ǽ�
        time.pop();
>>>>>>> main
    }
    return room.size();
}

int main() {
    int n, start, end;
    cin >> n;

    while(n--) { // ���ǽ� �ð�ǥ �Է�
        cin >> start >> end;
<<<<<<< HEAD
        time_table.push_back({start, end});
    }
    sort(time_table.begin(), time_table.end());

    cout << countRoom();
=======
        time.push({start, end});
    }
    
    cout << count_room();
>>>>>>> main
    return 0;
}