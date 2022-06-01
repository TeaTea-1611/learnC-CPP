#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
  string data;
  Node *next;
};
typedef struct Node* node;

node createNode(string x){
  node tmp = new Node();
  tmp->data = x;
  tmp->next = NULL;
  return tmp;
}

void push(node &back, string data) {
  node tmp = createNode(data);
  tmp->next = back;
  back = tmp;
}

void pop(node &back) {
  node truoc = NULL, sau = back;
  while (sau->next != NULL) {
    truoc = sau;
    sau = sau->next;
  }
  if (truoc == NULL) {
    back = NULL;
  }
  else {
    truoc->next = NULL;
  }
}

string front(node back) {
  while (back->next != NULL) {
    back = back->next;
  }
  return back->data;
}

int main() {
  node top = NULL;
  string s;
  getline(cin, s);
  stringstream ss(s);
  string word;
  while (ss >> word) {
    push(top, word);
  }
  cout << front(top) << " ";
  cout << endl;
  while (top != NULL) {
    cout << front(top) << " ";
    pop(top);
  }
  return 0;
}