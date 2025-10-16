#include <iostream>
#include <string>
using namespace std;

template <typename Type> class PushOnStackFull {
private:
  Type value;
  string str;

public:
  PushOnStackFull(const char *s, int val) : str(s), value(val) {}
  ~PushOnStackFull() {}
  void _What() const {
    cout << str << endl;
    cout << value << "can't push stack!" << endl;
  }
};

template <typename Type> class Stack {
private:
  enum { STACK_SIZE = 8 };
  Type *data;
  size_t capacity;
  size_t top;

public:
  Stack(int sz = STACK_SIZE) {
    capacity = sz > STACK_SIZE ? sz : STACK_SIZE;
    data = new Type[capacity];
    top = 0;
  }
  ~Stack() {
    delete[] data;
    data = nullptr;
    capacity = top = 0;
  }

public:
  bool IsFull() const { return top >= capacity; }
  bool Push(const Type &x) {
    if (IsFull()) {
      /*
      cout << "栈已满,数据【" << x << "】不能入栈" << endl;
      return false;
      */
      throw PushOnStackFull<Type>("栈已满，不能入栈", x);
    }
    data[top++] = x;
    return true;
  }
  void ShowStack() {
    for (int i = top - 1; i >= 0; --i)
      cout << "data[" << i << "] = " << data[i] << endl;
  }
};

int main(int argc, char *argv[]) {
  cout << "\n//c030 自定义异常类和标准异常类" << endl;
  Stack<int> st;
  try {
    for (int i = 1; i <= 10; ++i)
      st.Push(i);
  } catch (const PushOnStackFull<int> &e) {
    e._What();
  }
  st.ShowStack();
  return 0;
}
