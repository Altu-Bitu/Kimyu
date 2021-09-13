#include <iostream>
#include <vector>
#include <deque>

using namespace std;
vector<string> result;

void make_arr(bool reverse, deque<int> &d) { // �迭 �籸��
    cout << '[';
    if(!d.empty()) {
        if (reverse) { // �������� ���
            while (d.size() > 1) {
                cout << d.back() << ',';
                d.pop_back();
            }
        } else { // ������� ���
            while (d.size() > 1) {
                cout << d.front() << ',';
                d.pop_front();
            }
        }
        cout << d.front();
    }
    cout << "]\n";
}

void ac_compute(string &cmd, string &arr) {
    deque<int> d;
    bool error = false, reverse = false; // ���� ����, ���� ����

    if(arr == "[]") error = true;
    else {
        string temp = "";
        for (char ch: arr) {
            if (ch == '[') continue;
            else if((ch == ']' || ch == ',') && temp != "") {
                d.push_back(stoi(temp)); temp = "";
                continue;
            }
            temp += ch;
        }

        for (char ch: cmd) {
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
    }
    if(error) cout << "error\n";
    else make_arr(reverse, d);
}

int main() {
    int t, n;
    string p, arr;

    cin >> t;
    result.assign(t, "");
    while(t--) {
        cin >> p;
        cin >> n;
        cin >> arr;
        ac_compute(p, arr);
    }
    return 0;
}