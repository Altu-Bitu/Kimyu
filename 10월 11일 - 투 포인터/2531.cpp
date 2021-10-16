#include <iostream>
#include <vector>

using namespace std;
const int N = 30000;

int cnt = 0; // ������ ���� �ٸ� ���� ���� ���� �����ϴ� ����
int sushi[N+1];
vector<int> belt;

void removeSushi(int left) {
    if(sushi[belt[left]] == 1) cnt--; // (�ش� ������ ���� �ƿ� �����)
    sushi[belt[left]]--;
}

void addSushi(int right) {
    if(!sushi[belt[right]]) cnt++; // (���ο� ������ ����)
    sushi[belt[right]]++;
}

int maxSushi(int n, int k, int c) {
    int max_sushi = 0;
    sushi[c] = 1; cnt++; // ���� ����

    for(int i = 0; i < k; i++) // ù��° ���� Ž��
        addSushi(i);
    max_sushi = max(max_sushi, cnt); // �ִ� ����

    // left: �̹� ��Ʈ���� ���ŵǴ� ���� / right: �̹� ��Ʈ���� �߰��Ǵ� ����
    int left = 0, right = k;
    while(true) {
        removeSushi(left); // ���� ����
        addSushi(right);   // ���� �߰�
        max_sushi = max(max_sushi, cnt); // �ִ� ����

        // �� ĭ�� �̵�
        right = (right + 1) % n;
        if(right == k) break; // (��� ���� Ž�� �Ϸ�)
        left = (left + 1) % n;
    }
    return max_sushi;
}

int main() {
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    belt.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> belt[i];

    cout << maxSushi(n, k, c);
    return 0;
}