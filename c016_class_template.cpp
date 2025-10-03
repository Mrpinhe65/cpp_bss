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

int main(int argc, char *argv[]) {
  cout << "\n// Class template" << endl;
  List<int> myList;
  return 0;
}
