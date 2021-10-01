#include <iostream>
#include <deque>

using namespace std;
deque<int> d[2], g[2]; // �� & �׶��� (0: ���� / 1: ����)

bool isDodoWinner() {
    // ���� ���� ��ġ�� ī�忡 5�� ������ ���
    if((!g[0].empty() && g[0].front() == 5) ||
    (!g[1].empty() && g[1].front() == 5)) return true;
    return false;
}

bool isSuyeonWinner() {
    // ���� ���� ��ġ�� ī���� ���� ���� 5�� �Ǵ� ���
    if(!g[0].empty() && !g[1].empty() &&
        g[0].front() + g[1].front() == 5) return true;
    return false;
}

void emptyGround(int deq, int ground) { // �׶��� ����
    while(!g[ground].empty()) {
        // �׶��� ī�� ����� (���Ϲ���) �ڽ��� �� �Ʒ��� ��ġ�� (push back)
        d[deq].push_back(g[ground].back());
        g[ground].pop_back();
    }
}

void groundCheck() {
    int winner = -1, loser = -1;
    // 3. ���� ĥ �� �ִ°�
    if(isDodoWinner()) winner = 0;
    else if(isSuyeonWinner()) winner = 1;
    if(winner == -1) return; // �� ĥ �� ���� ���

    // 4. ī�� ��ġ��
    loser = winner ? 0 : 1;
    emptyGround(winner, loser);  // ���� �׶��� ����
    emptyGround(winner, winner); // �ڽ��� �׶��� ����
}

void game(int m) { // �Ҹ� ���� ����
    int turn = 0; // (���� : 0 / ���� : 1)

    while(m--) {
        g[turn].push_front(d[turn].front()); // 2��
        d[turn].pop_front();
        if(d[turn].empty()) { // ���� ���� ���߿� �� ������ ��� ���� �¸�
            if(!turn) cout << "su";
            else cout << "do";
            return;
        }
        groundCheck(); // 3�� & 4��
        turn = !turn;  // turn �ٲ�
    }
    if(d[0].size() > d[1].size()) cout << "do";
    else if(d[0].size() < d[1].size()) cout << "su";
    else cout << "dosu";
}

int main() {
    int n, m, d_card, s_card;
    cin >> n >> m;

    // 1�� : �� ��� �ޱ�
    for(int i = 0; i < n; i++) { // �� �Ʒ� ��ġ�� ī����� �Է�
        cin >> d_card >> s_card;
        d[0].push_front(d_card);
        d[1].push_front(s_card);
    }

    game(m);
    return 0;
}