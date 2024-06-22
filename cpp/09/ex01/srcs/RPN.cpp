#include "RPN.hpp"

int applyOperator(std::stack<int>& stack, std::string& operation) {
    int second = stack.top();
    stack.pop();
    int first = stack.top();
    stack.pop();
    if (operation == "+")
        return first + second;
    if (operation == "-")
        return first - second;
    if (operation == "*")
        return first * second;
    if (operation == "/")
        return first / second;
    return 0;
}

bool isOperator(std::string& token) {
    return (token == "+" || token == "-" || token == "*" || token == "/");
}

bool isOperand(std::string& token, int& operand) {
    std::stringstream ss(token);
    ss >> operand;
    return (!ss.fail() && ss.eof());
}

std::string next(std::string& expr) {
    size_t pos = 0;
    size_t prev;
    std::string token;

    while (pos < expr.size() && expr[pos] == ' ')
        pos++;
    prev = pos;
    while (pos < expr.size() && expr[pos] != ' ')
        pos++;
    token = expr.substr(prev, pos - prev);
    expr.erase(0, pos);
    return token;
}

bool rpn(std::string expr) {

    int result = 0;
    std::string token;
    std::stack<int> stack;
    int operand;

    while (!expr.empty()) {
        token = next(expr);
        if (token.empty())
            continue;
        else if (isOperand(token, operand))
            stack.push(operand);
        else if (isOperator(token) && stack.size() >= 2)
            stack.push(applyOperator(stack, token));
        else
            return false;
    }

    if (stack.size() > 1)
        return false;
    if (!stack.empty())
        result = stack.top();
    std::cout << result << std::endl;
    return true;
}