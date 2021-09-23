#include <iostream>
#include <vector>

using namespace std;
vector<int> t, p;

int getProfit(int day, int last) { // �ִ� ���� ���ϱ�
    if(day >= last || day+ t[day] -1 >= last) return 0; // ���� �ʰ��� ���

    int a = p[day] + getProfit(day + t[day], last); // ���� ���ϴ� ���
    int b = getProfit(day+1, last); // ���� ������ �ʴ� ���
    return a >= b ? a : b;
}

int main() {
    int n;
    cin >> n;

    t.assign(n, 0);
    p.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> t[i] >> p[i];
    cout << getProfit(0, n);
    return 0;
}