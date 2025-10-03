#include <iostream>
using namespace std;

class Complex {
public:
  friend Complex operator+(int i, const Complex &c);
  friend ostream &operator<<(ostream &out, Complex &c);
  friend istream &operator>>(istream &in, Complex &c);
  Complex() {}
  Complex(int real, int imag) : m_real(real), m_imag(imag) {}
  ~Complex() {}
  // 成员函数会造成格式不符合常用模式 c<<cout<<endl;
  ostream &operator<<(ostream &out) {
    out << "(" << m_real << "+" << m_imag << "*i)" << endl;
    return out;
  }

private:
  int m_real;
  int m_imag;
};

class Test {
  // 友元函数 friend
  friend void Show(const Test &t);

public:
  Test(int d = 0) : data(d) {}
  void Fun() { cout << "data = " << data << endl; }

private:
  int data;
};

void Show(const Test &t) {
  cout << "This is friend Show(), data = " << t.data << endl;
}

Complex operator+(int i, const Complex &c) {
  return Complex(i + c.m_real, c.m_imag);
}

ostream &operator<<(ostream &out, Complex &c) {
  out << "(" << c.m_real << "+" << c.m_imag << "*i)";
  return out;
}
istream &operator>>(istream &in, Complex &c) {
  cin >> c.m_real >> c.m_imag;
  return in;
}
int main(int argc, char *argv[]) {
  cout << "\nc013_friend.cpp 友元" << endl;
  Test t(100);
  cout << "\n//调用类方法 t.Fun();" << endl;
  t.Fun();
  cout << "\n//调用友元函数 Show();" << endl;
  Show(t);

  Complex c;
  Complex c1(1, 2);
  c = 10 + c1;
  cout << "友元函数重载<< :cout<<c<<endl;" << endl;
  cout << c << endl;
  cout << "成员函数重载<< :c<<cout<<endl;" << endl;
  c << cout << endl; // c.operator<<(cout)<<endl;

  cout << "友元函数重载>> :" << endl;
  cin >> c;
  cout << c << endl;

  return 0;
}
