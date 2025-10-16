#include <fstream>
#include <iostream>
using namespace std;

class Complex;
ostream &operator<<(ostream &out, const Complex &c);

class Complex {
  friend ostream &operator<<(ostream &out, const Complex &c);

private:
  int m_real;
  int m_imag;

public:
  Complex() : m_real(0), m_imag(0) {
    ifstream ifile;
    ifile.open("data.dat", ios::in);
    if (!ifile) {
      cerr << "File open fail!" << endl;
      exit(1);
    }
    ifile >> m_real >> m_imag;
    ifile.close();
  }
  Complex(int real, int imag) : m_real(real), m_imag(imag) {}
  ~Complex() {
    ofstream ofile;
    ofile.open("data.dat", ios::out);
    if (!ofile) {
      cerr << "Open file fail!" << endl;
      exit(1);
    }
    ofile << m_real << " " << m_imag;
    ofile.close();
  }

  void SetComplex(int real, int imag) {
    m_real = real;
    m_imag = imag;
  }
};
ostream &operator<<(ostream &out, const Complex &c) {
  cout << "(" << c.m_real << "+" << c.m_imag << "*i)";
  return out;
}

int main(int argc, char *argv[]) {
  Complex c;
  cout << c << endl;
  c.SetComplex(3, 4);
  cout << c << endl;
  return 0;
}
