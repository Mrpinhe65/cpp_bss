/*
 钻石继承和虚基类
*/

#include <iostream>
using namespace std;

class B0 {
public:
  int m;

public:
  B0() : m(0) { cout << "Create B0" << endl; }
  ~B0() { cout << "Free B0" << endl; }
};

class B1 : virtual public B0 {
  // class B1 : public B0 {
public:
  B1() : n(0) { cout << "Create B1" << endl; }
  ~B1() { cout << "Free B1" << endl; }

public:
  int n;
};

class B2 : virtual public B0 {
  // class B2 : public B0 {
public:
  B2() : n(0) { cout << "Create B2" << endl; }
  ~B2() { cout << "Free B2" << endl; }

public:
  int n;
};

class D : public B1, public B2 {
public:
  int x;

public:
  D() : x(0) { cout << "Create D" << endl; }
};

int main(int argc, char *argv[]) {
  cout << "c021 钻石继承和虚基类" << endl;
  D d;
  // d.n = 10; // 两个父类都有成员n 产生了二义性
  // 指定作用域用以区分
  d.B1::n = 10;
  d.B2::n = 20;

  // 钻石继承 造成B0 的m二义性
  d.B1::m = 100;
  cout << "d.B1::m = " << d.B1::m << endl;
  cout << "d.m = " << d.m << endl;
  d.B2::m = 200;
  cout << "d.B2::m = " << d.B2::m << endl;
  cout << "d.m = " << d.m << endl;

  return 0;
}
