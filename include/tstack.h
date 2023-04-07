// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
private:
    static const int size;
    type arr[size];
    int top;
public:
    TStack() : top(-1) {}
    type get() const {
        return arr[top];
    }
    bool isEmpty() const {
        return top == -1;
    }
    bool isFull() const {
        return top == size - 1;
    }
    void pop() {
        if (!isEmpty())
            --top;
    }
    void push(type item) {
        if (!isFull())
            arr[++top] = item;
    }
};

#endif  // INCLUDE_TSTACK_H_
