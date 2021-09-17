#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<int> need; // �ּ����� ���ϸ���

int min_mileage(int p, int l) { // �ּ� ���ϸ��� ���ϱ�
    int temp;
    priority_queue<int, vector<int>, greater<>> pq;

    for(int i = 0; i < p; i++) {
        cin >> temp;
        if(pq.size() < l) pq.push(temp);
        else if(pq.top() < temp) {
            pq.pop();
            pq.push(temp);
        }
    }
    if(p < l) return 1; // �ο� �̴��� ���
    return pq.top();
}

int max_subject(int n, int m) { // �ִ� ���� �� ���ϱ�
    int count = 0, remain = m;
    sort(need.begin(), need.end()); // �ּ����� ���ϸ��� �������� ����

    for(int i = 0; i < n; i++) {
        remain -= need[i];
        if(remain >= 0) count++;
        else break;
    }
    return count;
}

int main() {
    int n, m, p, l;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> p >> l;
        need.push_back(min_mileage(p, l));
    }

    cout << max_subject(n, m);
    return 0;
}