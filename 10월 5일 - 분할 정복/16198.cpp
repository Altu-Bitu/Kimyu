#include <iostream>
#include <vector>

using namespace std;

int max_energy = 0;
vector<int> w; // ������ �����ϴ� ����

void backtracking(int energy) {
    if(w.size() == 2) { // ���� ���� : ù��°�� ������ ������ ������ ������ �� ����
        max_energy = max(max_energy, energy);
        return;
    }

    for(int i = 1; i < w.size() - 1; i++) { // (i: ������ ����)
        int save = w[i];
        energy += w[i-1] * w[i+1]; // ������ ������
        w.erase(w.begin() + i);    // ������ ���� ����
        backtracking(energy);

        w.insert(w.begin() + i, save); // ���󺹱�
        energy -= w[i-1] * w[i+1];
    }
}

int main() {
    int n;
    cin >> n;

    w.assign(n, 0);
    for(int i = 0; i < n; i++)
        cin >> w[i];

    backtracking(0);
    cout << max_energy;
    return 0;
}