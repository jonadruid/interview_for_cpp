#include <iostream>

using std::cin;
using std::cout;
using std::endl;

static int static_int = 0;
// static_int cannot be used in other file;

static void static_function() {
  cout << "static_function output." << endl;
}
// static_function cannot be used in other file;

int count_function() {
  static int count = 0;
  ++count;
  return count;
}

class A {
  private:
    static int count;

  public:
    A() {
      count++;
    }
    ~A() {
      count--;
    }
    static int num() {
      return count;
    }
};

int A::count = 0;

int main() {
  cout << "static_int: " << static_int << endl;

  static_function();

  cout << "A::num(): " << A::num() << endl;
  {
    A a;
    cout << "A::num(): " << A::num() << endl;
  }
  cout << "A::num(): " << A::num() << endl;

  cout << "count_function(): " << count_function() << endl;
  cout << "count_function(): " << count_function() << endl;
  cout << "count_function(): " << count_function() << endl;
}