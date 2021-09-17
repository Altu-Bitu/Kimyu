#include <iostream>
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
    }
    return room.size();
}

int main() {
    int n, start, end;
    cin >> n;

    while(n--) { // ���ǽ� �ð�ǥ �Է�
        cin >> start >> end;
        time.push({start, end});
    }
    
    cout << count_room();
    return 0;
}