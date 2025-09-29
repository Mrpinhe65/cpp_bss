#include <iostream>
using namespace std;

class Test {
public:
  Test(int d = 0) : data(d) { cout << "\nCreate Test Object:" << this << endl; }

  Test(const Test &t) {
    cout << "\nCopy Test Object:" << this << endl;
    this->data = t.data;
  }

  Test &operator=(const Test &t) {
    cout << "\nAssign: " << this << " = " << &t << endl;
    if (this != &t)
      this->data = t.data;
    return *this;
  }

  ~Test() { cout << "\nFree Test Object:" << this << endl; }

  int getData() const { return data; }

private:
  int data;
};

Test fun(Test &x) {
  int value = x.getData();
  // Test tmp(value);
  cout << "\nin fun" << endl;
  return Test(value);
}
/*
Test fun(Test &x) {
  int value = x.getData();
  Test tmp(value);
  cout << "\nin fun" << endl;
  return tmp;
}
*/

int main(int argc, char *argv[]) {

  Test t1(100);
  Test t2;
  t2 = fun(t1);

  return 0;
}
