// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"
int getPrior(char s) {
    if (s == '(')
        return 0;
    else if (s == ')')
        return 1;
    else if (s == '+' || s == '-')
        return 2;
    else if (s == '*' || s == '/')
        return 3;
    return 0;
}
std::string infx2pstfx(std::string inf) {
    std::string str = "";
    int pr = 0;
    TStack<char> myStack;
    for (int i = 0; i < inf.size(); i++) {
        if (inf[i] >= '0' && inf[i] <= '9') {
            if (i < inf.size() - 1 && inf[i + 1] >= '0' && inf[i + 1] <= '9') {
                str.push_back(char(inf[i]));
            } else {
                str.push_back(char(inf[i]));
                str.push_back(' ');
            }
        } else {
            pr = getPrior(inf[i]);
            if ((pr == 0) || (myStack.isEmpty()) || (pr > getPrior(myStack.get()))) {
                myStack.push(inf[i]);
            } else if (pr == 1) {
                while (myStack.get() != '(') {
                    if (myStack.get() != ')' && myStack.get() != '(') {
                        str.push_back(myStack.get());
                        str.push_back(' ');
                    }
                    myStack.pop();
                }
                myStack.pop();
            } else {
                while (!myStack.isEmpty() && getPrior(myStack.get()) >= pr) {
                    str.push_back(myStack.get());
                    str.push_back(' ');
                    myStack.pop();
                }
                myStack.push(inf[i]);
            }
        }
    }
    while (!myStack.isEmpty()) {
        str.push_back(myStack.get());
        str.push_back(' ');
        myStack.pop();
    }
    return str;
}
int eval(std::string post) {
    TStack<int> stack1;
    int num = 0;
    for (int i = 0; i < post.size(); i++) {
        if (post[i] >= '0' && post[i] <= '9') {
            num = num * 10 + (post[i] - '0');
        } else if (post[i] == ' ') {
            if (num != 0) {
                stack1.push(num);
                num = 0;
            }
        } else {
            int op1 = stack1.get();
            stack1.pop();
            int op2 = stack1.get();
            stack1.pop();
            switch (post[i]) {
            case '+':
                stack1.push(op2 + op1);
                break;
            case '-':
                stack1.push(op2 - op1);
                break;
            case '*':
                stack1.push(op2 * op1);
                break;
            case '/':
                stack1.push(op2 / op1);
                break;
            }
        }
    }
    return stack1.get();
}
