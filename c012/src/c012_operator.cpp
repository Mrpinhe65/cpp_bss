#include "c012_operator.hpp"

class Complex;                                       // 先声明
ostream &operator<<(ostream &out, const Complex &o); // 先声明
// 先声明后实现
ostream &operator<<(ostream &out, const Complex &o) {
  out << "( " << o.m_real << " + " << o.m_imag << "*i)" << endl;
  return out;
}

Complex operator+(int i, const Complex &c) {
  return Complex(i + c.m_real, c.m_imag);
}
