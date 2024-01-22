#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class A {
  private:
    const int a;
    int b;

  public:
    A() : a(0), b() {};
    A(int x, int y) : a(x), b(y) {};

    void print() const {
      cout << "a: " << a << endl;
      cout << "b: " << b << endl;
    }

    // void set_a(int x) {
    //   a = x;
    // } 
    // a is a constant int, cannot modify.
    void set_b(int x) {
      b = x;
    }
    int get_a() const {
      return a;
    }
    int get_b() const {
      return b;
    }
    // cannot modify b in constant function.
    int get_b_plus_one() {
      return ++b;
    }
};

int main() {
  {
    A a1(1, 1);
    a1.print();
    cout << "a1.get_a(): " << a1.get_a() << endl;
    a1.set_b(2);
    cout << "a1.get_b(): " << a1.get_b() << endl;
    cout << "a1.get_b_plus_one(): " << a1.get_b_plus_one() << endl;

    const A a2(2, 2);
    a2.print();
    // a2.set_b(3);
    // a2 is a constant A class, can not use non-const member function.
    cout << "a2.get_b(): " << a2.get_b() << endl;

    const A *p1 = &a1;
    p1->print();
    // p1->set_b();
    // p1 is a pointer to constant A class, cannot use non-const member function.
    cout << "p1->get_b(): " << p1->get_b() << endl;

    const A &q1 = a1;
    q1.print();
    // q1.set_b();
    // q1 is a reference of constant A, cannot use non-const member function.
    cout << "q1.get_b(): " << q1.get_b() << endl;
  }

  {
    char str[] = "string";
    char str2[] = "string2";
    char* p1 = str;
    cout << p1 << endl;
    p1[0] = 'S';
    cout << p1 << endl;

    const char* p2 = str;
    // p2[1] = 'T';
    // p2 is a pointer to constant char, cannot modify str.

    char* const p3 = str;
    // p3 = str2;
    // p3 is a constant pointer, connot change p3;

    const char* const p4 = str;
  }
}