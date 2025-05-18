#include<iostream>

int* cur;
int* min;
int max = 8001;
int size ;


struct MinStack {
    MinStack() {
        cur = new int[max];
        min = new int[max];
        size = 0;

    }

    void push(int val) {
        cur[size] = val;
        min[size] = (size==0) || (min[size - 1] > val ) ? val: min[size - 1];
        size++;
    }

    void pop() {
        size--;
    }

    int top() {
        return cur[size -1];
    }

    int getMin() {
        return min[size - 1];
    }
};

int main() {

	return 0;
}
