#include <iostream>
#include <string>

using namespace std;

struct Student
{
  string name, id;
  double gpa;
};

struct SV
{
  Student sv;
  SV *next;
};

typedef struct SV* sv;

sv createSV() {
  Student s;
  cout << "ID: ";
  cin >> s.id;
  cout << "Name: ";
  cin.ignore();
  getline(cin, s.name);
  cout << "Gba: ";
  cin >> s.gpa;

  sv tmp = new SV();
  tmp->sv = s;
  tmp->next = NULL;
  return tmp;
}

bool isEmpty(sv a) {
  return a == NULL;
}

int Size(sv a) {
  int count = 0;
  while(a != NULL) {
    count++;
    a = a->next;
  }
  return count;
}

void insertFirst(sv &a) {
  sv tmp = createSV();
  if (isEmpty(a)) {
    a = tmp;
  }
  else {
    tmp->next = a;
    a = tmp;
  }
}

void insertLast(sv &a) {
  sv tmp = createSV();
  if (isEmpty(a)) {
    a = tmp;
  }
  else {
    sv p = a;
    while(p->next != NULL) {
      p = p->next;
    }
    p->next = tmp;
  }
}

void insertMiddle(sv &a, int pos) {
  int n = Size(a);
  if (pos <= 0 || pos > n + 1) {
    cout << "khong hop le" << endl;
  }
  else if (pos == 1) {
    insertFirst(a);
  }
  else if (pos == n + 1) {
    insertLast(a);
  }
  else {
    sv p = a;
    sv tmp = createSV();
    for (int i = 1; i < pos - 1; i++) {
      p = p->next;
    }
    tmp->next = p->next;
    p->next = tmp;
  }
}

void deleteFirst(sv &a) {
  if (isEmpty(a)) {
    cout << "Khong hop le";
  }
  else {
    a = a->next;
  }
}

void deleteLast(sv &a) {
  if (isEmpty(a)) {
    cout << "khong hop le" << endl;
  }
  else {
    sv truoc = NULL, sau = a;
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

void deleteMiddle(sv &a, int pos) {
  if (pos <= 0 || pos > Size(a)) {
    cout << "khong hop le" << endl;
  }
  else {
    sv truoc = NULL, sau = a;
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

void in(Student a) {
  cout << "ID: " << a.id << endl;
  cout << "Name: " << a.name << endl;
  cout << "Gba: " << a.gpa << endl;
}

void inds(sv a) {
  cout << "-----------------------------" << endl;
  while(a != NULL) {
    in(a->sv);
    a = a->next;
  }
  cout << endl;
  cout << "-----------------------------" << endl;
}

int main() {
  sv head = NULL;
  while(true) {
    int choice, pos;
    cout << "1. them vao dau" << endl;
    cout << "2. them vao cuoi" << endl;
    cout << "3. them vao giua" << endl;
    cout << "4. xoa o dau" << endl;
    cout << "5. xoa o cuoi" << endl;
    cout << "6. xoa o giua" << endl;
    cout << "7. in" << endl;
    cout << "-----------------------------" << endl;
    cout << "Lua chon ";
    cin >> choice;
    switch(choice) {
      case 1:
        insertFirst(head);
        break;
      case 2:
        insertLast(head);
        break;
      case 3:
        cin >> pos;
        insertMiddle(head, pos);
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
        inds(head);
        break;
      default:
        break;
    }
  }
  return 0;
}