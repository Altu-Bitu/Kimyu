#include <iostream>
#include <queue>

using namespace std;
priority_queue<long long, vector<long long>, greater<>> pq;

long long card_game(int m) { // ī�� ��ü
    long long card1, card2, sum;
    while(m--) {
        card1 = pq.top(); pq.pop(); // x�� ī��
        card2 = pq.top(); pq.pop(); // y�� ī��
        sum = card1 + card2;
        pq.push(sum); pq.push(sum); // �� �忡 �����
    }
    sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    return sum; // ���� ���� ���� ��ȯ
}

int main() {
    int n, m, num;
    cin >> n >> m;

    while(n--) {
        cin >> num;
        pq.push(num);
    }
    cout << card_game(m);
    return 0;
}