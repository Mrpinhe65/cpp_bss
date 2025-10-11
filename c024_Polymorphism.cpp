#include <iostream>
using namespace std;

class Base {
private:
  int x;

protected:
public:
  Base() : x(0) {}
  ~Base() {}
  virtual void Show() { cout << "Show in Base" << endl; }
  virtual void Print() { cout << "Print in Base" << endl; }
  void Fun() { cout << "Fun in Base" << endl; }
};

class D : public Base {
private:
  int y;

public:
  D() : y(0) {}
  ~D() {}
  void Show() { cout << "Show in D" << endl; }
  // void Print() { cout << "Print in D" << endl; }
  void Fun() { cout << "Fun in D" << endl; }

public:
  virtual void List() { cout << "List in D" << endl; }
};

int main(int argc, char *argv[]) {
  cout << "c024_polymorphism.cpp 多态的实现原理分析" << endl;
  D d;
  Base *pb = &d;
  pb->Show();
  pb->Print();
  pb->Fun();

  return 0;
}
