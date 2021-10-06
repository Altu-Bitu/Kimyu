#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> v; // ����ũ ���� �����ϴ� �迭

bool cmp(int &i1, int &i2) { // (10�� ����� ����ũ�� ���� �;� ��)
    if(i1%10 && !(i2%10)) return i1%10 < i2%10;
    else if(!(i1%10) && i2%10) return i1%10 < i2%10;
    return i1 < i2;
}

int cutCake(int len) { // ����ũ �ڸ��� & ���� 10�� ����ũ ���� ��ȯ
    if(len == 10) return 1;
    if(len < 10) return 0;

    int cake = 0;
    while(m > 0 && len > 10) { // ����ũ �߶�� �ϴ� ���
        len -= 10;
        cake++; m--;
    }
    if(len == 10) cake++; // (���� �κ��� ���̰� 10�� ��� ����ũ ������ ����)
    return cake;
}

int countCake() {
    int cake = 0;
    for(int i = 0; i < n; i++) { // 10�� ����� ����ũ
        if(m == 0) break;
        cake += cutCake(v[i]);
    }
    return cake;
}

int main() {
    cin >> n >> m;

    v.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end(), cmp);

    cout << countCake();
    return 0;
}