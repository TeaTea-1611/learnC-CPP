#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
  string data;
  Node *next;
};
typedef struct Node* node;

bool isEmpty(node top) {
  return top == NULL;
}

int getSize(node top) {
  int count = 0;
  while (top != NULL) {
    ++count;
    top = top->next;
  }
  return count;
}

node createNode(string data) {
  node tmp = new Node();
  tmp->data = data;
  tmp->next = NULL;
  return tmp;
}

void push(node &top, string data) {
  node tmp = createNode(data);
  if (top == NULL) {
    top = tmp;
  }
  else {
    tmp->next = top;
    top = tmp;
  }
}

void pop(node &top) {
  if (top == NULL) return;
  top = top->next;
}

string getTop(node top) {
  return top->data;
}

int main() {
  node top = NULL;
  string s;
  getline(cin, s);
  stringstream ss(s);
  string word;
  while (ss >> word) {
    push(top, word);
    cout << getTop(top) << " ";
  }
  cout << endl;
  while (!isEmpty(top)) {
    cout << getTop(top) << " ";
    pop(top);
  }
  return 0;
}