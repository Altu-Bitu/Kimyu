#include <iostream>
#include <queue>

using namespace std;
priority_queue<long long, vector<long long>, greater<>> pq;

<<<<<<< HEAD
void combinateCard(int m) {
=======
long long card_game(int m) { // ī�� ��ü
>>>>>>> main
    long long card1, card2, sum;
    while(m--) {
        card1 = pq.top(); pq.pop(); // x�� ī��
        card2 = pq.top(); pq.pop(); // y�� ī��
        sum = card1 + card2;
        pq.push(sum); pq.push(sum); // �� �忡 �����
    }
<<<<<<< HEAD
}

long long cardScore() {
    long long sum = 0;
=======
    sum = 0;
>>>>>>> main
    while(!pq.empty()) {
        sum += pq.top();
        pq.pop();
    }
    return sum; // ���� ���� ���� ��ȯ
}

<<<<<<< HEAD
long long cardGame(int m) { // ī�� ��ü
    combinateCard(m);
    return cardScore();
}

=======
>>>>>>> main
int main() {
    int n, m, num;
    cin >> n >> m;

    while(n--) {
        cin >> num;
        pq.push(num);
    }
<<<<<<< HEAD
    cout << cardGame(m);
=======
    cout << card_game(m);
>>>>>>> main
    return 0;
}