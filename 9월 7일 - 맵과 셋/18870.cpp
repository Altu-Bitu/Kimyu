#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int> v, sorted;

int main() {
    int n, tmp;
    cin >> n;

    while(n--) { // ��ǥ �Է�
        cin >> tmp;
        sorted.push_back(tmp);
        v.push_back(tmp);
    }

    sort(sorted.begin(), sorted.end()); // �������� ����
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end()); // �ߺ� ����

    for(int & iter : v) {
        int order = lower_bound(sorted.begin(), sorted.end(), iter) - sorted.begin(); // bst ��� Ž��
        cout << order << ' ';
    }
    return 0;
}