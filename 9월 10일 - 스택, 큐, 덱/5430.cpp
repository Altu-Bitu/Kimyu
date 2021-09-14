#include <iostream>
#include <deque>
#include <string>

using namespace std;

string make_arr(bool reverse, deque<int> &d) { // �迭 �籸��
    string temp = "[";
    if(!d.empty()) {
        if (reverse) { // �������� ���
            while (d.size() > 1) {
                temp += to_string(d.back());
                temp += ',';
                d.pop_back();
            }
        } else { // ������� ���
            while (d.size() > 1) {
                temp += to_string(d.front());
                temp += ',';
                d.pop_front();
            }
        }
        temp += to_string(d.back()); // ������ ���� (�޸� ���� ���)
    }
    temp += ']';
    return temp;
}

deque<int> make_deque(string &arr) { // �� �����
    deque<int> d;
    string temp = "";
    for (char ch: arr) {
        if (ch == '[') continue;
        else if((ch == ']' || ch == ',') && temp != "") {
            d.push_back(stoi(temp)); temp = "";
            continue;
        }
        else if(ch >= '0' && ch <= '9') temp += ch;
    }
    return d;
}

void ac_compute(string &cmd, string &arr) {
    bool error = false, reverse = false; // ���� ����, ���� ����
    deque<int> d = make_deque(arr);   // �� ����� (���ڸ�)

    for (char ch: cmd) { // ��ɾ� ó��
        if (ch == 'R') {
            reverse = !reverse; // ���� �ݴ��
            continue;
        }
        if (d.empty()) { // ���̻� ���Ұ� ���� ��� error
            error = true;
            break;
        }
        if (reverse) d.pop_back(); // ������ ���
        else d.pop_front();        // ���� �ƴ� ���
    }
    if(error) cout << "error\n";
    else cout << make_arr(reverse, d) << '\n';
}

int main() {
    int t, n;
    string p, arr;

    cin >> t;
    while(t--) {
        cin >> p;
        cin >> n;
        cin >> arr;
        ac_compute(p, arr);
    }
    return 0;
}