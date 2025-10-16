#include <iostream>
using namespace std;

/*
try
throw
catch
 */

float Div(int a, int b) {
  if (b == 0)
    throw b;
  return (float)a / float(b);
}

int main(int argc, char *argv[]) {
  int a = 10;
  int b = 0;
  try {
    float result = Div(a, b);
  } catch (int) {
    cout << "Div error, b==0" << endl;
  } catch (short) {
    cout << "Div error, b==0" << endl;
  } catch (...) {
    cout << "Div error,b==0" << endl;
  }
  return 0;
}
