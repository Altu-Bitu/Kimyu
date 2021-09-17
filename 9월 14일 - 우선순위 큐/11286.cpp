#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator() (int a, int b) {
        if(abs(a) != abs(b)) return abs(a) > abs(b); // ���� ��������
        return a > b; // ��������
    }
};

int main() {
    int n, x, min;
    priority_queue<int, vector<int>, cmp> pq;
    cin >> n;

    while(n--) {
        cin >> x;
        if(x) pq.push(x);
        else {
            if(pq.empty()) min = 0;
            else {
                min = pq.top();
                pq.pop();
            }
            cout << min << '\n';
        }
    }
    return 0;
}