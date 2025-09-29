#include <iostream>
using namespace std;

class Test {
public:
  Test(int d = 0) : data(d) { cout << "\nCreate Test Object" << this << endl; }

  // 拷贝构造函数
  Test(const Test &t) {
    cout << "\nCopy Create Test Object " << this << endl;
    this->data = t.data;
  }

  // t2=t1 赋值函数
  // 返回对象本身，为了链式赋值，注意返回的值必须考虑其生命周期
  // const 是保护数据防止被修改
  Test &operator=(const Test &t) {
    cout << "\nAssign:" << this << " = " << &t << endl;
    if (this != &t) { // 防止自身给自身赋值
      this->data = t.data;
    }
    cout << "Test &operator=(const Test &t)" << endl;
    return *this; // 返回值要考虑生命周期
  }

  ~Test() { cout << "\nFree Test Object" << this << endl; }

  int getData() { return this->data; }

private:
  int data;
};

int main(int argc, char *argv[]) {
  Test t1(10);
  Test t2 = t1;

  return 0;
}
