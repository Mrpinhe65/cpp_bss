#include <iostream>
#include <stdlib.h>
using namespace std;

// 友元类 先声明
template <typename Type> class List;

// 链表结点的类定义
template <typename Type> class ListNode {

  // 声明友元类 注意模版类和普通类的声明差别 <Type>
  friend class List<Type>;

public:
  ListNode() : data(Type()), next(nullptr) {}
  ListNode(Type d, ListNode<Type> *n = nullptr) : data(d), next(n) {}
  ~ListNode() {}

private:
  Type data;
  ListNode<Type> *next;
};

// 链表结点的类定义
template <typename Type> class List {
public:
  List();
  ~List() {}
  bool pushBack(Type x);
  void showList() const;

private:
  ListNode<Type> *first;
  ListNode<Type> *last;
  size_t size;
};

// 末班类的成员函数类外实现需要声明模版
template <typename Type> List<Type>::List() {
  first = last = (ListNode<Type> *)malloc(sizeof(ListNode<Type>));
  last->next = nullptr;
  size = 0;
}
template <typename Type> bool List<Type>::pushBack(Type x) {
  ListNode<Type> *s = (ListNode<Type> *)malloc(sizeof(ListNode<Type>));
  if (s == nullptr)
    return false;
  s->data = x;
  s->next = nullptr;

  last->next = s;
  last = s;
  size++;

  return true;
}

template <typename Type> void List<Type>::showList() const {
  ListNode<Type> *p = first->next;
  while (p != nullptr) {
    cout << p->data << "->";
    p = p->next;
  }
  cout << "nil" << endl;
}
int main(int argc, char *argv[]) {
  cout << "\n// Class template" << endl;

  List<int> myList_i;
  for (int i = 0; i < 10; ++i)
    myList_i.pushBack(i);
  myList_i.showList();

  List<char> myList_c;
  for (int i = 65; i < 75; ++i)
    myList_c.pushBack(i);
  myList_c.showList();

  return 0;
}
