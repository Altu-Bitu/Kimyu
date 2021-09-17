#include <iostream>
#include <stack>

using namespace std;
stack<pair<int, int>> top; // (����ž ����, ����ž ��ġ)

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, height;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> height;
        while(!top.empty()) {
            if(height < top.top().first) { // ����ž �߰�
                cout << top.top().second << ' ';
                break;
            }
            top.pop(); // ���� ž ������
        }
        if(top.empty()) cout << 0 << ' ';
        top.push({height, i+1}); // ����ž ���� ����
    }
    return 0;
}