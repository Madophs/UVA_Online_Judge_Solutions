#include <bits/stdc++.h>
#include <cctype>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

inline void pluckOperation(const string &equ, int &a, int &b, char &op, string &res)
{
    stringstream ss(equ);
    string operation;
    getline(ss, operation, '=');
    getline(ss, res, '=');

    string s1, s2;
    unsigned int i = 0;
    for (; i < operation.size(); ++i) {
        if (!isdigit(operation[i])) {
            break;
        }
        s1.push_back(operation[i]);
    }
    op = operation[i];
    s2 = operation.substr(i+1, string::npos);
    a = atoi(s1.c_str());
    b = atoi(s2.c_str());
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int a, b, equAnswer;
    char c;
    string toEvaluate, studentAnswerStr;
    int correctAnswers = 0;
    while (cin >> toEvaluate) {
        pluckOperation(toEvaluate, a, b, c, studentAnswerStr);
        if (studentAnswerStr == "?") continue;
        int studentAnswerInt = atoi(studentAnswerStr.c_str());
        equAnswer = (c == '+') ? a + b : a - b;
        correctAnswers += (equAnswer == studentAnswerInt);
    }
    cout << correctAnswers << '\n';
    return 0;
}
