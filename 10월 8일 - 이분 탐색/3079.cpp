#include <iostream>
#include <queue>

using namespace std;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> t; // (first : �ɻ�� ��� �ð� / second : �ҿ� �ð�)

int minTime(int m) { // �ּ� �ɻ� �ð� ��ȯ
    int sec, pass = 0;
    while(!t.empty()) {
        pass++;
        sec = t.top().first;
        if (pass == m) return sec; // ��� ����� ��� �ð� ��ȯ
        t.push({sec + t.top().second, t.top().second});
        t.pop();
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