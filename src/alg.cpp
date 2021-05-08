// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"

int priority(char a) {
    switch (a) {
    case '(': return 0;
    case ')': return 1;
    case '+': return 2;
    case '-': return 2;
    case '*': return 3;
    case '/': return 3;
    default:return -1;
    }
}

std::string infx2pstfx(std::string inf) {
  TStack<char> stack1;
    std::string str;
    for (int i = 0; i < inf.length(); i++) {
        if ((inf[i] >= '0') && (inf[i] <= '9')) {
            str += inf[i];
            str += ' ';
        } 
        else if ((inf[i] == '(')
                 || (priority(inf[i]) > priority(stack1.get()))
                 || (stack1.isEmpty())) {
            stack1.push(inf[i]);
        } 
        else if (inf[i] == ')') {
            char s = stack1.get();
            stack1.pop();
            while (s != '(') {
                str += s;
                str += ' ';
              s = stack1.get();
              stack1.pop();
            }
        } 
        else {
            while ((!stack1.isEmpty())
                   && (priority(stack1.get()) >= priority(inf[i]))) {
                str += stack1.get();
                str += ' ';
                stack1.pop();
            }
            stack1.push(inf[i]);
        }
    }
            while (!stack1.isEmpty()) {
                str += stack1.get();
                str += ' ';
                stack1.pop();
            }
    str.pop_back();
    return str;
}

int eval(std::string pst) {
  TStack<int> stack2;
    for (int i = 0; i < pst.length(); i++) {
        if ((pst[i] >= '0') && (pst[i] <= '9')) {
            stack2.push(pst[i] - '0');
        } 
        else if (pst[i] != ' ') {
                int y = stack2.get();
                stack2.pop();
                int x = stack2.get();
                stack2.pop();
                if (pst[i] == '-') {
                    stack2.push(x - y);
                } 
                else if (pst[i] == '+') {
                    stack2.push(x + y);
                } 
                else if (pst[i] == '*') {
                    stack2.push(x * y);
                } 
                else {
                    stack2.push(x / y);
                }
            }
    }
    int res;
    res = stack2.get();
    return res;
}
