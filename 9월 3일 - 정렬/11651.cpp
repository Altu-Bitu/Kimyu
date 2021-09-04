#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct cor{ // ��ǥ ����ü
    int x, y;
};
vector<cor> xy;

bool cmp(const cor &p1, const cor &p2) {
    if(p1.y != p2.y) return p1.y < p2.y; // y ��ǥ ��������
    return p1.x < p2.x; // x ��ǥ ��������
}

int main() {
    int n;
    cin >> n;
    xy.assign(n, {0, 0});
    for(int i = 0; i < n; i++)
        cin >> xy[i].x >> xy[i].y;

    sort(xy.begin(), xy.end(), cmp);
    for(int i = 0; i < n; i++)
        cout << xy[i].x << ' ' << xy[i].y << '\n';
    return 0;
}