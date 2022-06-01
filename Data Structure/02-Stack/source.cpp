#include <iostream>

using namespace std;

int current_size = -1;
const int MAX_SIZE = 100;
int stack[MAX_SIZE];

bool isEmpty() {
  return (current_size == -1);
}

bool isFull() {
  return (current_size == MAX_SIZE);
}

void push(int data) {
  if (!isFull()) {
    current_size++;
    stack[current_size] = data;
  }
  else {
    cout << "Stack full" << endl;
  }
}

int top() {
  if (!isEmpty()) {
    int data = stack[current_size];
    return data;
  }
  else {
    cout << "Stack empty" << endl;
  }
  return 1;
}

int pop() {
  if (!isEmpty()) {
    int data = stack[current_size];
    current_size--;
    return data;
  }
  else {
    cout << "Stack empty" << endl;
  }
  return 1;
}

int main() {
  push(16);
  push(11);
  push(12);
  cout << top() << endl;
  pop();
  cout << top() << endl;
  while (!isEmpty()) {
    cout << pop() << " ";
  }
  return 0;
}