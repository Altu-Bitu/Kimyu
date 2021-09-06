#include<iostream>
#include<vector>

using namespace std;
vector<int> atm;

void ascending(int n) { // �������� ���� ����
    for(int i = 0; i < n; i++) {
        bool flag = true;
        for(int j = 0; j < n-i-1; j++) {
            if(atm[j] > atm[j+1]){
                flag = false;
                swap(atm[j], atm[j+1]);
            }
        }
        if(flag) break;
    }
}

long long computeMin(int n) {
    long long sum = 0, tmp = 0;
    for(int i = 0; i < n; i++) {
        tmp += atm[i]; // i��° ���
        sum += tmp;
    }
    return sum; // ��� ���
}

int main() {
    int n;
    cin >> n;
    atm.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> atm[i];
    ascending(n);
    cout << computeMin(n); // �ּڰ� ���
    return 0;
}