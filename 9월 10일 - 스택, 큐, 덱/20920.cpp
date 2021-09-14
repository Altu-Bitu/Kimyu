#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
vector<string> word; // ���� �ܾ���
map<string, int> temp; // ���ܾ� �� �����ϴ� ��

bool cmp(string &w1, string &w2) { // ���� ����
    if(temp[w1] != temp[w2]) return temp[w1] > temp[w2];     // 1. ���� ������ �ܾ��ϼ��� �տ� ��ġ
    if(w1.size() != w2.size()) return w1.size() > w2.size(); // 2. �ܾ��� ���̰� ����� �տ� ��ġ
    return w1 < w2; // 3. ������
}

int main() {
    int n, m;
    string input;
    cin >> n >> m;

    while(n--) {
        cin >> input;
        if(input.length() < m) continue; // ���̰� m �̸��� ��� �ܾ��忡 �������� ����
        if(!temp[input]) word.push_back(input); // ���ο� �ܾ� �߰�
        temp[input]++; // �ܾ� �󵵼� ����
    }
    sort(word.begin(), word.end(), cmp); // ����

    for(auto & i : word) // �ܾ��� ���
        cout << i << '\n';
    return 0;
}