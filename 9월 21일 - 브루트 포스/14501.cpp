#include <iostream>
#include <vector>

using namespace std;
vector<pair<int, int>> consult; // time, pay ��

int getProfit(int day, int last) { // �ִ� ���� ���ϱ�
    if(day >= last) return 0; // ���� �ʰ��� ���
    else if(day+ consult[day].first -1 >= last) return getProfit(day+1, last);

    int a = consult[day].second + getProfit(day + consult[day].first, last); // ���� ���ϴ� ���
    int b = getProfit(day+1, last); // ���� ������ �ʴ� ���
    return max(a, b);
}

int main() {
    int n;
    cin >> n;

    consult.assign(n, {0, 0});
    for(int i = 0; i < n; i++)
        cin >> consult[i].first >> consult[i].second;
    cout << getProfit(0, n);
    return 0;
}