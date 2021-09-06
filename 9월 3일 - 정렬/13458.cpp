#include <iostream>
#include <vector>

using namespace std;
vector<int> a, sorted;

long long countSupervisor(int n, int b, int c) { // ������ �� ����
    long long result = 0;
    for(int i = 0; i < n; i++) {
        a[i] -= b;
        result++; // �Ѱ�����
        if(a[i] > 0) { // �ΰ�����
            result += a[i]/c;
            if(a[i] % c) result++;
        }
    }
    return result;
}

int main() {
    int n, b, c;
    cin >> n;

    a.assign(n, 0);
    sorted.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> b >> c;
    cout << countSupervisor(n, b, c); // ������ �� ����
    return 0;
}