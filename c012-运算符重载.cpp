#include <stdlib.h>
#include <string.h>

#include <iostream>
using namespace std;

// 复数
class Complex {
public:
  Complex() : m_real(0), m_imag(0) {}

  Complex(int real, int imag) {
    this->m_real = real;
    this->m_imag = imag;
  }

  ~Complex() {}

  Complex operator+(const Complex &c) {
    /*
    可将此段代码用匿名对象返回，减少临时对象的构造和析构
    Complex cmp(m_real + c.m_real, m_imag + c.m_imag);
    return cmp;
    */
    return Complex(m_real + c.m_real, m_imag + c.m_imag);
  }

  Complex operator-(const Complex &c) {
    /*
    可将此段代码用匿名对象返回，减少临时对象的构造和析构
    Complex cmp(m_real - c.m_real, m_imag - c.m_imag);
    return cmp;
    */
    return Complex(m_real - c.m_real, m_imag - c.m_imag);
  }
  // 重载<<运算符
  friend ostream &operator<<(ostream &os, const Complex &c) {
    os << c.m_real << " + " << c.m_imag << "*i";
    return os;
  }

  // private:
  int m_real; // 实部
  int m_imag; // 虚部
};

int main(int argc, char *argv[]) {
  Complex c;
  Complex c1(1, 2);
  Complex c2(3, 4);

  c = c1 + c2; // 等效于c=c1.operator+(c2);
  // c = c1.operator+(c2);
  // cout << c.m_real << " + " << c.m_imag << "*i" << endl;
  c = c1 - c2; // 等效于c=c1.operator-(c2);
               // c = c1.operator-(c2);
               // cout << c.m_real << " + " << c.m_imag << "*i" << endl;
  cout << c << endl;

  return 0;
}
