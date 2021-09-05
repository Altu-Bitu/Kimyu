#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> serial;

long long computeSum(string serial) { // 2. ������ ���� ���� ����
    long long result = 0;
    for(int i = 0; i < serial.length(); i++)
        if(serial[i] < 65) result += serial[i]-48;
    return result;
}

bool computeDict(const string &num1, const string &num2) { // 3. ������
    for(int i = 0; i < num1.length(); i++) {
        if(num1[i] != num2[i]) {
            // ���� : ���� < ���ĺ�
            if(num1[i] < 65 && num2[i] >= 65) return true;
            if(num1[i] >= 65 && num2[i] < 65) return false;
            return num1 < num2;
        }
    }
    return num1 < num2;
}

bool cmp(const string &num1, const string &num2) {
    if(num1.length() != num2.length())
        return num1.length() < num2.length(); // 1. ª�� ���� ����
    if(computeSum(num1) != computeSum(num2))
        return computeSum(num1) < computeSum(num2); // 2. ������ ���� ���� ����
    return computeDict(num1, num2); // 3. ������
}

int main() {
    int n;
    cin >> n;
    serial.assign(n, "");
    for(int i = 0; i < n; i++)
        cin >> serial[i];

    sort(serial.begin(), serial.end(), cmp); // ����
    for(int i = 0; i < n; i++)
        cout << serial[i] << '\n';
    return 0;
}