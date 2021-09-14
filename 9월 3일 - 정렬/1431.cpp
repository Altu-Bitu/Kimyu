#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<string> serial;

long long computeSum(string serial) { // 2. ������ ���� ���� ����
    long long result = 0;
    for(int i = 0; i < serial.length(); i++)
        if(serial[i] >= '0' && serial[i] <= '9') result += serial[i]-'0';
    return result;
}

bool cmp(const string &num1, const string &num2) {
    if(num1.length() != num2.length())
        return num1.length() < num2.length(); // 1. ª�� ���� ����
    if(computeSum(num1) != computeSum(num2))
        return computeSum(num1) < computeSum(num2); // 2. ������ ���� ���� ����
    return num1 < num2; // 3. ������
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