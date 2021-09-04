#include <iostream>
#include <vector>

using namespace std;
vector<int> a,b;

void ascending(int n) { // �������� ���� ����
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}

void descending(int n) { // �������� ���� ����
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1-i; j++) {
            if(b[j] < b[j+1])
                swap(b[j], b[j+1]);
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

    ascending(n);
    descending(n);
    cout << computeMin(n);
    return 0;
}