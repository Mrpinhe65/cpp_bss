#include <iostream>
#include <pthread.h>
using namespace std;

class Test {
public:
  Test(int d = 0) : data(d) { cout << "\nCreate Test Object" << this << endl; }

  // 拷贝构造函数
  Test(const Test &t) {
    cout << "Copy Create Test Object " << this << endl;
    this->data = t.data;
  }

  Test &operator=(const Test &t) {
    if (this != &t) {
      this->data = t.data;
    }
    return *this;
  }

  ~Test() { cout << "Free Test Object" << this << endl; }

  int getData() { return this->data; }

private:
  int data;
};

// 函数参数是Test对象，传参时产生无名的拷贝构造函数
Test fun(Test t) {
  int value;
  value = t.getData();
  Test tmp(value);

  // 返回Text对象 构造一个临时对象，构造函数和拷贝构造函数都被调用
  return tmp;
}

int main(int argc, char *argv[]) {

  Test t(10);
  cout << "Test t1(t); // 拷贝构造函数" << endl;
  cout << "\n拷贝构造函数的形式 Test(const Test &t){......}" << endl;
  Test t1(t);

  cout << "Test t2 = t1; // 拷贝构造函数" << endl;
  Test t2 = t1; // 拷贝构造函数
  Test t3;

  cout << "t3 = t2; // 调动赋值函数" << endl;
  t3 = t2; // 调动赋值函数
  cout << "\n类作为形参传参，也是通过拷贝构造函数\n" << endl;
  fun(t1);
  cout << "\n函数调用结束\n" << endl;

  return 0;
}
