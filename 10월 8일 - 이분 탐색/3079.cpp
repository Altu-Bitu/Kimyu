#include <iostream>
#include <queue>

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> t; // (first : �ɻ�� ��� �ð� / second : �ҿ� �ð�)

int minTime(int m) { // �ּ� �ɻ� �ð� ��ȯ
    int sec = 0, pass = 0;
    while(true) {
        sec++;
        while(!t.empty()) {
            if(t.top().first == sec) { // �ɻ�밡 ����ִ� ���
                pass++;
                if(pass == m) return sec; // ��� ����� ��� �ð� ��ȯ
                t.push({sec + t.top().second, t.top().second}); t.pop();
            }
            else break; // �ɻ�밡 ������� ���� ���
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, time;
    cin >> n >> m;

    for(int i = 0 ; i < n; i++) {
        cin >> time;
        t.push({time, time});
    }

    cout << minTime(m);
    return 0;
}