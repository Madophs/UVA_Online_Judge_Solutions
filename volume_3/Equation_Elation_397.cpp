#include <bits/stdc++.h>
#include <limits>
#ifdef __MDS_DEBUG__
#include "cpp_debug.hpp"
#else
#define debug(...)
#endif

using namespace std;

/******************    START_CODING   ******************/

constexpr int MAX_INT = std::numeric_limits<int>::max();
const string OPERATOR_ORDER[] = {"*/", "+-"};


void parseEquation(const string &equation, vector<int> &operands, vector<char> &operators, string &var) {
    string operandStr = "";
    uint32_t i = 0;
    for (;  i < equation.length(); ++i) {
        if (equation[i] == '=') break;
        if (equation[i] == ' ') continue;
        if (isdigit(equation[i]) || (operandStr.empty() && (equation[i] == '-' || equation[i] == '+'))) {
            operandStr.push_back(equation[i]);
        } else {
            operators.push_back(equation[i]);
            operands.push_back(atoi(operandStr.c_str()));
            operandStr = "";
        }
    }

    operands.push_back(atoi(operandStr.c_str()));

    for (; i < equation.length(); ++i) {
        if (isalnum(equation[i])) {
            var.push_back(equation[i]);
        }
    }
}

bool performOperation(vector<int> &operands, vector<char> &operators, string ops) {
    int operationResult = MAX_INT;
    uint32_t i = 0;
    for (i = 0; i < operators.size(); ++i) {
        if (operators[i] == ops[0] || operators[i] == ops[1]) {
            switch (operators[i]) {
                case '*':
                    operationResult = operands[i] * operands[i + 1];
                    break;
                case '/':
                    operationResult = operands[i] / operands[i + 1];
                    break;
                case '+':
                    operationResult = operands[i] + operands[i + 1];
                    break;
                case '-':
                    operationResult = operands[i] - operands[i + 1];
                    break;
            }
            break;
        }
    }

    if (operationResult != MAX_INT) {
        vector<char>::iterator iter1 = operators.begin();
        advance(iter1, i);
        operators.erase(iter1);

        vector<int>::iterator iter2 = operands.begin();
        advance(iter2, i + 1);
        operands.erase(iter2);
        operands[i] = operationResult;
    }

    return operationResult != MAX_INT;
}

void printEquation(const vector<int> &operands, const vector<char> &operators, const string &var) {
    uint32_t i = 0;
    for (; i < operators.size(); ++i) {
        cout << operands[i] << " " << operators[i] << " ";
    }
    cout << operands[i] << " = " << var << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    bool firstInput = true;
    string rawEquation, var;
    vector<int> operands;
    vector<char> operators;
    while(getline(cin, rawEquation)) {
        if (!firstInput) cout << '\n';
        firstInput = false;

        parseEquation(rawEquation, operands, operators, var);
        printEquation(operands, operators, var);
        for (uint32_t i = 0; i < 2 && !operators.empty();) {
            bool ret = performOperation(operands, operators, OPERATOR_ORDER[i]);
            if (ret) {
                printEquation(operands, operators, var);
            } else {
                ++i;
            }
        }
        operands.clear();
        operators.clear();
        var.clear();
    }
    return 0;
}
