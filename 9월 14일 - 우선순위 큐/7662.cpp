#include <iostream>
#include <queue>

using namespace std;
bool visited[1000001] = {false, }; // ���� ���� ǥ���ϴ� �迭

void insert_num(int i, int n, priority_queue<pair<int, int>, vector<pair<int, int>>> &max_queue, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> &min_queue) { // ������ ����
    max_queue.push({n, i});
    min_queue.push({n, i});
    visited[i] = true;
}

void delete_max(priority_queue<pair<int, int>, vector<pair<int, int>>> &max_queue) { // �ִ� pop
    while(!visited[max_queue.top().second] && !max_queue.empty()) max_queue.pop();
    if(!max_queue.empty()) {
        visited[max_queue.top().second] = false;
        max_queue.pop();
    }
}

void delete_min(priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> &min_queue) { // �ּڰ� pop
    while(!visited[min_queue.top().second] && !min_queue.empty()) min_queue.pop();
    if(!min_queue.empty()) {
        visited[min_queue.top().second] = false;
        min_queue.pop();
    }
}

void delete_num(int n, priority_queue<pair<int, int>, vector<pair<int, int>>> &max_queue, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> &min_queue) { // ������ ����
    if(n == 1 && !max_queue.empty()) delete_max(max_queue); // �ִ� pop
    else if(n == -1 && !min_queue.empty()) delete_min(min_queue); // �ּڰ� pop
}

void operation(int k, priority_queue<pair<int, int>, vector<pair<int, int>>> &max_queue, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> &min_queue) {
    char cmd;
    int num;
    for(int i = 0; i < k; i++) { // ����
        cin >> cmd >> num;
        if (cmd == 'I') insert_num(i, num, max_queue, min_queue);
        else if (cmd == 'D') delete_num(num, max_queue, min_queue);
    }
}

void print_result(priority_queue<pair<int, int>, vector<pair<int, int>>> &max_queue, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> &min_queue) {
    while(!max_queue.empty()) { // �ִ� ����ϱ�
        if(visited[max_queue.top().second]) {
            cout << max_queue.top().first  << ' ';
            break;
        }
        max_queue.pop();
    }

    if(max_queue.empty()) {
        cout << "EMPTY\n";
        return;
    }

    while(!min_queue.empty()) { // �ּڰ� ����ϱ�
        if(visited[min_queue.top().second]) {
            cout << min_queue.top().first << '\n';
            break;
        }
        min_queue.pop();
    }
}

int main() {
    int t, k;
    cin >> t;

    while(t--) {
        cin >> k;
        priority_queue<pair<int, int>, vector<pair<int, int>>> max_queue;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> min_queue;
        operation(k, max_queue, min_queue); // ����
        print_result(max_queue, min_queue); // ��� ���
    }
    return 0;
}