
#include <iostream>      //  <<, >>, cout, cin, fixed, showpoint
#include <iomanip>       // setprecision(), setw()
#include <cstdlib>
using namespace std;

class incy
{
private:
   int intslot;

public:
   void Display();
   void incri();
   void decri();
   void initi( int value);
   int geti();
};


   void incy::decri()
   {	intslot--; }

   void incy::Display()
   {	cout << intslot; }

   void incy::incri()
   {  intslot++; }

   void incy::initi( int value)
   {  intslot = value;};

   int incy::geti()
   {  intslot;  }

int  main()
{	incy k, i, l;

   k.initi(0);
       cout << "just set k= ";  k.Display();  cout << endl;
   k.incri();
       cout << "just increment k= ";  k.Display();  cout << endl;
   k.Display();
   cout << endl;

   l.initi(10);
       cout << "just set l= ";  l.Display();  cout << endl;

   i.initi(2);
   l.initi(20);
   k.decri();

   cout << "i= ";  i.Display();  cout << endl;
   cout << "l= ";  l.Display();  cout << endl;
   cout << "k= ";  k.Display();  cout << endl;

   cout << "Finish" << endl;
   return EXIT_SUCCESS;
}
