#include <iostream>

using namespace std;

bool is_java(string &arg) {
    // 1. ù���� �ݵ�� �ҹ���
    // 2. �ҹ���, �빮�� �ܿ� �ٸ� ���� �Ұ�
    if(arg[0] < 'a' || arg[0] > 'z') return false;     // (1��)
    if(arg.find('_') != string::npos) return false; // (2��)
    for(int i = 1; i < arg.length(); i++) {
        if ((arg[i] < 'A' || arg[i] > 'Z') && (arg[i] < 'a' || arg[i] > 'z')) // (2��)
            return false;
    }
    return true;
}

bool is_cpp(string &arg) {
    // 1. ù���� �ݵ�� �ҹ���
    // 2. ������ ���� _ �Ұ�
    // 3. �������� _ �Ұ�
    if(arg[0] < 'a' || arg[0] > 'z') return false;      // (1��)
    if(arg[arg.length()-1] == '_') return false;        // (2��)
    if(arg.find("__") != string::npos) return false; // (3��)
    for(int i = 1; i < arg.length(); i++) {
        if ((arg[i] < 'a' || arg[i] > 'z') && arg[i] != '_') return false;
    }
    return true;
}

string java(string &arg) { // �ڹ� ������ �����
    string temp = "";
    for(int i = 0; i < arg.length(); i++) {
        if(arg[i] == '_') {
            temp += arg[i+1] - 'a' + 'A';
            i++;
            continue;
        }
        temp += arg[i];
    }
    return temp;
}

string cpp(string &arg) { // c++ ������ �����
    string temp = "";
    for(char ch : arg) {
        if(ch >= 'A' && ch <= 'Z') {
            temp += '_';
            temp += ch - 'A' + 'a';
            continue;
        }
        temp += ch;
    }
    return temp;
}

string make_identifier(string &arg) { // ������ �����
    bool isJava = is_java(arg);
    bool isCpp = is_cpp(arg);

    if(!isJava && !isCpp) return "Error!";
    if(isJava) return cpp(arg); // �ڹ� -> ���ܻ�
    else return java(arg);      // ���ܻ� -> �ڹ�
}

int main() {
    string argument;
    cin >> argument;

    cout << make_identifier(argument);
    return 0;
}