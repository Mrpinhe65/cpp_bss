#pragma once
#include <iostream>
using namespace std;

class Complex;                                       // 先声明
ostream &operator<<(ostream &out, const Complex &o); // 先声明

class Complex {
  friend Complex operator+(int i, const Complex &c);
  friend ostream &operator<<(ostream &out, const Complex &o); // 先声明
public:
  Complex() : m_real(0), m_imag(0) {}
  Complex(int real, int imag) : m_real(real), m_imag(imag) {}
  ~Complex() {}

  void PrintComplex() const {
    cout << "(" << m_real << "+" << m_imag << "i)" << endl;
  }

  Complex Add(const Complex &comp) {
    return Complex(m_real + comp.m_real, m_imag + comp.m_imag);
  }

public:
  // operator 运算符重载
  Complex operator+(const Complex &c) {
    /*
    Complex tmp(m_real + c.m_real, m_imag + c.m_imag);
    return tmp;
    */

    return Complex(m_real + c.m_real, m_imag + c.m_imag);
  }

  // 复数运算 对象+整型 c3 = c1 + 10
  Complex operator+(const int i) {
    return Complex(this->m_real + i, this->m_real);
  }

private:
  int m_real;
  int m_imag;
};

class Int {
public:
  Int(int i = 0) : m_i(i) {}

  void printData() { cout << m_i << endl; }

  Int operator+(Int const &i) { return Int(m_i + i.m_i); }

  Int &operator++() { // 返回值*this不会消亡，可以用引用返回
    this->m_i++;
    return *this;
  }

  Int operator++(int) { // 返回值tmp会消亡 不能用引用返回
    Int tmp(this->m_i);
    this->m_i++;
    return tmp;
  }

private:
  int m_i;
};
