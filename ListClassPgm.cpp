#include<iostream>
#include<iomanip>
#include<fstream>
#include "List.h"
using namespace std;

int main() {
  fout.open("ListPgmResults.txt");
  List a, b; int endit;

  for (int i = 1; i <= 20; i++)
  a.insertAfter(i, i * 2);
  cout << "List a : " << endl;
  cout << " " << a << endl;
  cout << "Number of elements in a - " << a.size() << endl;
  fout << "List a : " << endl;
  fout << " " << a << endl;
  fout << "Number of elements in a - " << a.size() << endl;

  for (int i = 1; i <= 20; i++)
    b.insertBefore(i, i * 2);
  cout << "List b : " << endl;
  cout << " " << b << endl;
  cout << "Number of elements in b - " << b.size() << endl;
  fout << "List b : " << endl;
  fout << " " << b << endl;
  fout << "Number of elements in b - " << b.size() << endl;

  if (a == b) {
    cout << "List a & b are equal" << endl;
    fout << "List a & b are equal" << endl;
  }
  else {
    cout << "List a & b are Not equal" << endl;
    fout << "List a & b are Not equal" << endl;
  }

  a.first();
  b.first();
  cout << "First element in list a & b: " << a.getXElement() << ' ' << a.getYElement() << ", " << b.getXElement() << ' ' << b.getYElement() << endl;
  fout << "First element in list a & b: " << a.getXElement() << ' ' << a.getYElement() << ", " << b.getXElement() << ' ' << b.getYElement() << endl;
  a.last();
  b.last();
  cout << "Last element in list a & b: " << a.getXElement() << ' ' << a.getYElement() << ", " << b.getXElement() << ' ' << a.getYElement() << endl;
  cout << endl << endl << " Start of new stuff" << endl;
  fout << "Last element in list a & b: " << a.getXElement() << ' ' << a.getYElement() << ", " << b.getXElement() << ' ' << a.getYElement() << endl;
  fout << endl << endl << " Start of new stuff" << endl;

  b.erase();
  cout << "Empty List b: " << b << endl;
  fout << "Empty List b: " << b << endl;

  if (a == b) {
    cout << "List a & b are equal" << endl;
    fout << "List a & b are equal" << endl;
  }
  else {
    cout << "List a & b are Not equal" << endl;
    fout << "List a & b are Not equal" << endl;
  }

  for (int i = 1; i <= 20; i++)
    b.insertBefore(i, i - 2);
  cout << "List b : " << endl;
  fout << "List b : " << endl;

  a.setPos(10);
  b.first();
  for (int i = 1; i < 8; i++) {
    a.erase();
    b.replace(i, -i);
    b.next();
  }

  cout << "Modified Object 'a' (shorter) " << endl;
  cout << "List a: " << a << endl;
  cout << "Modified Object 'b' " << endl;
  cout << "List b: " << b << endl;
  fout << "Modified Object 'a' (shorter) " << endl;
  fout << "List a: " << a << endl;
  fout << "Modified Object 'b' " << endl;
  fout << "List b: " << b << endl;

  List c(b);
  cout << "Copy Constructor c(b)" << endl;
  cout << "List b : " << b << endl;
  cout << "List c : " << c << endl;
  fout << "Copy Constructor c(b)" << endl;
  fout << "List b : " << b << endl;
  fout << "List c : " << c << endl;

  if (c == b) {
    cout << "List c & b are equal" << endl;
    fout << "List c & b are equal" << endl;
  }
  else {
    cout << "List c & b are not equal" << endl;
    fout << "List c & b are not equal" << endl;
  }

  List e;
  e = c;
  cout << "Object 'c' assigned to Object 'e':" << endl;
  cout << "List c : " << c << endl;
  cout << "List e : " << e << endl;
  fout << "Object 'c' assigned to Object 'e':" << endl;
  fout << "List c : " << c << endl;
  fout << "List e : " << e << endl;

  List d;
  d = a;

  d.first();
  endit = d.size();
  for (int i = 1; i < endit; d.next(), i++) {
    d.insertBefore(d.getXElement() * -2, d.getYElement() * -2);
    d.next();
  }
  cout << "Results after some replaces on d " << endl;
  cout << "List d : " << d << endl;
  fout << "Results after some replaces on d " << endl;
  fout << "List d : " << d << endl;

  a.first();
  endit = a.size();
  for (int i = 1; i < endit; a.next(), i++) {
    a.replace(a.getPos() + a.getXElement(), a.getPos() + a.getYElement());
    a.next();
  }
  cout << "Results after some weird stuff on list a" << endl;
  cout << "List a : " << a << endl;
  fout << "Results after some weird stuff on list a" << endl;
  fout << "List a : " << a << endl;

  List alist(b);
  alist.clear();
  for (int i = 1; i <= 10; i++)
    alist.insertAfter(i, i-1);
  alist.first();
  cout << "New List alist with positions above: " << endl;
  fout << "New List alist with positions above: " << endl;
  for (int i = 1; i <= 10; i++) {
    cout << setw(5) << alist.getPos();
    fout << setw(5) << alist.getPos();
    alist.next();
  }
  cout << endl;
  fout << endl;
  alist.first();
  for (int i = 1; i <= 10; i++) {
    cout << setw(5) << alist.getXElement() << ' ' << alist.getYElement();
    fout << setw(5) << alist.getXElement() << ' ' << alist.getYElement();
    alist.next();
  }
  cout << endl;
  fout << endl;

  cout << endl << " check out boundary conditions" << endl;
  fout << endl << " check out boundary conditions" << endl;
  List sq;
  cout << "number of elements in empty sq list = " << sq.size() << endl;
  fout << "number of elements in empty sq list = " << sq.size() << endl;
  sq.first();
  sq.erase();
  sq.setPos(5);
  cout << "empty sq values " << sq << endl;
  fout << "empty sq values " << sq << endl;
  sq.insertBefore(333, 11);
  cout << "sq values " << sq << endl;
  fout << "sq values " << sq << endl;
  sq.next(); sq.next();
  cout << "sq.getElement() = " << sq.getXElement() << ' ' << sq.getYElement() << endl;
  cout << "sq list = " << sq << endl;
  fout << "sq.getElement() = " << sq.getXElement() << ' ' << sq.getYElement() << endl;
  fout << "sq list = " << sq << endl;
  fout.close();
  return 0;
}
