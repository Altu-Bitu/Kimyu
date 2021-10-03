#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<int> v1, v2; // v1  10�� ��� / v2 : 10�� ��� �ƴ� ���

int cutCake(int len) { // ����ũ �ڸ��� & ���� 10�� ����ũ ���� ��ȯ
    if(len == 10) return 1;
    else if(len < 0) return 0;
    if(m == 0) return 0;

    int cake = 0;
    len -= 10; cake++; m--;
    if(len >= 10) cake += cutCake(len);
    return cake;
}

int countCake() {
    int cake = 0;
    for(int i = 0; i < v1.size(); i++) { // 10�� ����� ����ũ
        if(m == 0) break;
        cake += cutCake(v1[i]);
    }
    for(int i = 0; i < v2.size(); i++) { // 10�� ����� �ƴ� ����ũ
        if(m == 0) break;
        cake += cutCake(v2[i]);
    }
    return cake;
}

int main() {
    int len;
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> len;
        if(len%10 == 0) v1.push_back(len);
        else v2.push_back(len);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    cout << countCake();
    return 0;
}