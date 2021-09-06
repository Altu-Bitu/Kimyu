#include <iostream>
#include <vector>

using namespace std;
vector<int> a,b;

void ascending(int n) { // �������� ���� ����
    for(int i = 0; i < n; i++) {
        bool flag = true;
        for(int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1]) {
                flag = false;
                swap(a[j], a[j+1]);
            }
        }
        if(flag) break;
    }
}

void descending(int n) { // �������� ���� ����
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1-i; j++) {
            bool flag = true;
            if(b[j] < b[j+1]) {
                flag = false;
                swap(b[j], b[j+1]);
            }
            if(flag) break;
        }
    }
}

int computeMin(int n) { // �ּڰ� ���
    int result = 0;
    for(int i = 0; i < n; i++)
        result += a[i] * b[i];
    return result;
}

int main() {
    int n;
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> b[i];

    ascending(n); // �������� ����
    descending(n); // �������� ����
    cout << computeMin(n); // �ּڰ� ���
    return 0;
}