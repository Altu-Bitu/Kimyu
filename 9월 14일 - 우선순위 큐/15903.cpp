#include <iostream>
#include <queue>

using namespace std;
priority_queue<long long, vector<long long>, greater<>> pq;

void combinateCard(int m) {
    long long card1, card2, sum;
    while(m--) {
        card1 = pq.top(); pq.pop(); // x�� ī��
        card2 = pq.top(); pq.pop(); // y�� ī��
        sum = card1 + card2;
        pq.push(sum); pq.push(sum); // �� �忡 �����
    }
}

long long cardScore() {
    long long sum = 0;
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    return sum; // ���� ���� ���� ��ȯ
}

long long cardGame(int m) { // ī�� ��ü
    combinateCard(m);
    return cardScore();
}

int main() {
    int n, m, num;
    cin >> n >> m;

    while(n--) {
        cin >> num;
        pq.push(num);
    }
    cout << cardGame(m);
    return 0;
}