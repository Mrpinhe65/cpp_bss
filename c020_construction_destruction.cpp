#include <iostream>
using namespace std;

class Base1 {
private:
  int x1;

public:
  Base1() { cout << "Create Base1" << endl; }
  ~Base1() { cout << "Free Base1" << endl; }
};
class Base2 {
private:
  int x2;

public:
  Base2() { cout << "Create Base2" << endl; }
  ~Base2() { cout << "Free Base2" << endl; }
};
class Base3 {
private:
  int x3;

public:
  Base3() { cout << "Create Base3" << endl; }
  ~Base3() { cout << "Free Base3" << endl; }
};

class D : public Base1, public Base2, public Base3 {
private:
  Base3 b3;
  Base1 b1;
  Base2 b2;

public:
  D() { cout << "Create D" << endl; }
  ~D() { cout << "Free D" << endl; }
};

int main(int argc, char *argv[]) {
  D d;
  return 0;
}
