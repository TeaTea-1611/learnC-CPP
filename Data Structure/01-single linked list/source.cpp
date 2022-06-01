#include <iostream>

using namespace std;

struct Node
{
  int data;
  Node *next;
};

typedef struct Node* node;

node makeNode(int data) {
  node tmp = new Node();
  // Node *tmp = new Node();
  tmp->data = data;
  tmp->next = NULL;
  return tmp;
}

bool isEmpty(node a) {
  return a == NULL;
}

int Size(node a) {
  int count = 0;
  while(a != NULL) {
    count++;
    a = a->next;
  }
  return count;
}

void insertFirst(node &a, int data) {
  node tmp = makeNode(data);
  if (isEmpty(a)) {
    a = tmp;
  }
  else {
    tmp->next = a;
    a = tmp;
  }
}

void insertLast(node &a, int data) {
  node tmp = makeNode(data);
  if (isEmpty(a)) {
    a = tmp;
  }
  else {
    node p = a;
    while(p->next != NULL) {
      p = p->next;
    }
    p->next = tmp;
  }
}

void insertMiddle(node &a, int data, int pos) {
  int n = Size(a);
  if (pos <= 0 || pos > n + 1) {
    cout << "khong hop le" << endl;
  }
  else if (pos == 1) {
    insertFirst(a, data);
  }
  else if (pos == n + 1) {
    insertLast(a, data);
  }
  else {
    node p = a;
    node tmp = makeNode(data);
    for (int i = 1; i < pos - 1; i++) {
      p = p->next;
    }
    tmp->next = p->next;
    p->next = tmp;
  }
}

void deleteFirst(node &a) {
  if (isEmpty(a)) {
    cout << "Khong hop le";
  }
  else {
    a = a->next;
  }
}

void deleteLast(node &a) {
  if (isEmpty(a)) {
    cout << "khong hop le" << endl;
  }
  else {
    node truoc = NULL, sau = a;
    while(sau->next != NULL) {
      truoc = sau;
      sau = sau->next;
    }
    if (truoc == NULL) {
      a = NULL;
    }
    else {
      truoc->next = NULL;
    }
  }
}

void deleteMiddle(node &a, int pos) {
  if (pos <= 0 || pos > Size(a)) {
    cout << "khong hop le" << endl;
  }
  else {
    node truoc = NULL, sau = a;
    for (int i = 1; i < pos; ++i)
    {
      truoc = sau;
      sau = sau->next;
    }
    if (truoc == NULL) {
      a = a->next;
    }
    else {
      truoc->next = sau->next;
    }
  }
}

void in(node a) {
  while (!isEmpty(a)) {
    cout << a->data << "->";
    a = a->next;
  }
  cout << endl;
}

void sapxep(node &a){
  for(node p = a; p->next != NULL; p = p->next){
    node min = p;
    for(node q = p->next; q != NULL; q = q->next){
      if(q->data < min->data){
        min = q;
      }
    }
    int tmp = min->data;
    min->data = p->data;
    p->data = tmp;
  }
}

int main() {
  node head = NULL;
  while(true) {
    int choice, data, pos;
    cout << "1. them vao dau" << endl;
    cout << "2. them vao cuoi" << endl;
    cout << "3. them vao giua" << endl;
    cout << "4. xoa o dau" << endl;
    cout << "5. xoa o cuoi" << endl;
    cout << "6. xoa o giua" << endl;
    cout << "7. in" << endl;
    cout << "Lua chon ";
    cin >> choice;
    switch(choice) {
      case 1:
        cin >> data;
        insertFirst(head, data);
        break;
      case 2:
        cin >> data;
        insertLast(head, data);
        break;
      case 3:
        cin >> data >> pos;
        insertMiddle(head, data, pos);
        break;
      case 4:
        deleteFirst(head);
        break;
      case 5:
        deleteLast(head);
        break;
      case 6:
        cin >> pos;
        deleteMiddle(head, pos);
        break;
      case 7:
        in(head);
        break;
      default:
        break;
    }
  }
  return 0;
}