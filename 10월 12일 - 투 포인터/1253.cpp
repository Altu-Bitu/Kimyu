#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> a;

bool twoPointer(int i, int n) {
    int left = 0, right = n-1;

    while(left < right) { // a[i]�� ���� ���ΰ�
        if(left == i) { left++; continue; }
        if(right == i) { right--; continue; }

        // ���� �ٸ� �� ���� ������
        int sum = a[left] + a[right];
        if(a[i] == sum) return true; // ���� ���� ���
        else if(a[i] < sum) right--;
        else left++;
    }
    return false; // ���� �� �ƴ� ���
}

int findGood(int n) { // ���� �� ���� ��ȯ
    int cnt = 0;

    for(int i = 0; i < n; i++)
        cnt += twoPointer(i, n);
    return cnt;
}

int main() {
    int n;
    cin >> n;

    a.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    cout << findGood(n);
    return 0;
}
