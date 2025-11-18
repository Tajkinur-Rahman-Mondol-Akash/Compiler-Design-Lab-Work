#include <fstream>
#include <iostream>
#include <string>
using namespace std;

bool isKeyword(string word) {
    string keywords[100] = {
        "int", "float", "double", "char", "if", "else", "for", "while", "do",
        "return", "void", "break", "continue", "switch", "namespace", "using",
        "true", "false", "bool", "main", "cout"};
    for (int i = 0; i < 20; i++) {
        if (word == keywords[i])
            return true;
    }
    return false;
}

bool isOperator(char c) {
    string ops = "+-*/=%<>!";
    for (int i = 0; i < ops.length(); i++) {
        if (c == ops[i])
            return true;
    }
    return false;
}

bool isPunctuation(char c) {
    string punct = "(){}[];,'\"";
    for (int i = 0; i < punct.length(); i++) {
        if (c == punct[i])
            return true;
    }
    return false;
}

bool isValidId(string s) {
    if (!((s[0] >= 'a' && s[0] <= 'z') || (s[0] >= 'A' && s[0] <= 'Z') || s[0] == '_'))
        return false;

    for (int i = 1; i < s.length(); i++) {
        if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') ||
              (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
            return false;
    }
    return true;
}

int main() {
    string fname;
    cout << "Enter file name (with .txt): ";
    cin >> fname;

    ifstream file(fname);
    if (!file.is_open()) {
        cout << "Error: file not found!" << endl;
        return 0;
    }

    string line;
    int lineNumber = 1;

    cout << "\n---Lexical Analysis ---\n";

    while (getline(file, line)) {
        string kw = "", id = "", op = "", punct = "", num = "", word = "";
        int i = 0;

        while (i < line.length()) {
            char ch = line[i];

            if (isOperator(ch)) {
                op += ch;
                op += " ";
                i++;
            } else if (isPunctuation(ch)) {
                punct += ch;
                punct += " ";
                i++;
            } else if (isalpha(ch) || ch == '_') {
                word = "";
                while (i < line.length() &&
                       (isalpha(line[i]) || isdigit(line[i]) || line[i] == '_')) {
                    word += line[i];
                    i++;
                }
                if (isKeyword(word))
                    kw += word + " ";
                else if (isValidId(word))
                    id += word + " ";
            } else if (isdigit(ch)) {
                word = "";
                while (i < line.length() && isdigit(line[i])) {
                    word += line[i];
                    i++;
                }
                num += word + " ";
            } else {
                i++;
            }
        }

        cout << "Line " << lineNumber << " : ";

        cout << "Kw -> " << (kw == "" ? "None" : kw) << ", ";
        cout << "Id -> " << (id == "" ? "None" : id) << ", ";
        cout << "Op -> " << (op == "" ? "None" : op) << ", ";
        cout << "Punct ->" << (punct == "" ? "None" : punct) << ", ";
        cout << "Num -> " << (num == "" ? "None" : num) << endl;

        lineNumber++;
    }

    file.close();

    return 0;
}
