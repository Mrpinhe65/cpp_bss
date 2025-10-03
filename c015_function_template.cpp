#include <iostream>
using namespace std;
/*
int Max(int a, int b) { return a > b ? a : b; }
float Max(float a, float b) { return a > b ? a : b; }
double Max(double a, double b) { return a > b ? a : b; }
char Max(char a, char b) { return a > b ? a : b; }
*/
// 函数模版
template <typename Type> Type Max(Type a, Type b) {
  cout << typeid(Type).name() << endl;
  return a > b ? a : b;
}

int main(int argc, char *argv[]) {
  cout << "\nFunction template" << endl;
  cout << "int Max" << Max(1, 2) << endl;
  cout << "int Max" << Max('d', 'k') << endl;
  cout << "float Max" << Max(1.2f, 2.3f) << endl;
  cout << "double Max" << Max(1.3, 2.1) << endl;
  cout << "double Max" << Max<int>(1, 2.1) << endl;
  cout << "double Max" << Max<double>(1, 2.1) << endl;

  return 0;
}
