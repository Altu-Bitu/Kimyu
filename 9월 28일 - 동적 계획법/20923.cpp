#include <iostream>
#include <deque>

using namespace std;
// ����, ���� �� / ����, ���� �׶���
deque<int> d, s, d_ground, s_ground;

bool isDodoWinner() {
    // ���� ���� ��ġ�� ī�忡 5�� ������ ���
    if((!d_ground.empty() && d_ground.front() == 5) ||
    (!s_ground.empty() && s_ground.front() == 5)) return true;
    return false;
}

bool isSuyeonWinner() {
    // ���� ���� ��ġ�� ī���� ���� ���� 5�� �Ǵ� ���
    if(!d_ground.empty() && !s_ground.empty() &&
        d_ground.front() + s_ground.front() == 5) return true;
    return false;
}

void emptyGround(deque<int> &deq, deque<int> &ground) { // �׶��� ����
    while(!ground.empty()) {
        // �׶��� ī�� ����� (���Ϲ���) �ڽ��� �� �Ʒ��� ��ġ�� (push back)
        deq.push_back(ground.back());
        ground.pop_back();
    }
}

void groundCheck() { // 3. ���� ĥ �� �ִ°�
    if(isDodoWinner()) {
        // 4. ī�� ��ġ��
        emptyGround(d, s_ground);
        emptyGround(d, d_ground);
    }
    else if(isSuyeonWinner()) {
        // 4. ī�� ��ġ��
        emptyGround(s, d_ground);
        emptyGround(s, s_ground);
    }
}

void game(int m) { // �Ҹ� ���� ����
    int cnt = 0; // ���� ���� Ƚ�� ī��Ʈ

    while(true) {
        // ����
        d_ground.push_front(d.front()); d.pop_front(); // 2��
        if(d.empty()) { cout << "su"; return; }
        groundCheck(); // 3�� & 4��
        if(++cnt == m) break;
        // ����
        s_ground.push_front(s.front()); s.pop_front(); // 2��
        if(s.empty()) { cout << "do"; return; }
        groundCheck(); // 3�� & 4��
        if(++cnt == m) break;
    }

    if(d.size() > s.size()) cout << "do";
    else if(d.size() < s.size()) cout << "su";
    else cout << "dosu";
}

int main() {
    int n, m, d_card, s_card;
    cin >> n >> m;

    // 1�� : �� ��� �ޱ�
    for(int i = 0; i < n; i++) { // �� �Ʒ� ��ġ�� ī����� �Է�
        cin >> d_card >> s_card;
        d.push_front(d_card);
        s.push_front(s_card);
    }

    game(m);
    return 0;
}