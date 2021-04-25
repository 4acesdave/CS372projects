
#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
ofstream fout;
enum ROOTS {NO_ROOTS=0,ONE_ROOT=2,TWO_ROOTS=2,INFINITE_ROOTS=3};

class quadraticExpression
{
private:
float a;
float b;
float c;
public:
quadraticExpression()
{
a=b=c=0;
}

quadraticExpression(float a_,float b_,float c_)
{
a=a_;
b=b_;
c=c_;
}

float getACoffecient()
{
return a;
}

float getBCoffecient()
{
return b;
}

float getCCoffecient()
{
return c;
}

double evaluate(double val)
{
return (a*val*val)+(b*val)+c;
}

int getNumberOfRoots()
{
if((a==0 && b==0 && c==0)||(a==0 && b!=0)||(a!=0 && b*b==4*a*c))
{
return 1;
}
if( ( a==0&&b==0&&c!=0 ) || ( a!=0 && (b*b)<(4*a*c) ) )
{
return 0;
}
if(a!=0&& b*b>4*a*c)
{
return 2;
}
return 3;
}

double getFirstRoot()
{
if(getNumberOfRoots()==ONE_ROOT||getNumberOfRoots()==TWO_ROOTS)
{
if((a==0 && b==0 && c==0))
{
return 0;
}
if(a==0 && b!=0)
{
return -c/b;
}
if(a!=0 && b*b==4*a*c)
{
return -b/(2*a);
}
if(a!=0 && b*b>4*a*c)
{
return ( -b-( sqrt((b*b)-(4*a*c)) ) )/( 2*a );
}
}
else
{
cout<<"\nInvalid call";
fout<<"\nInvalid call";
return 0;
}
}

double getSecondRoot()
{
if(getNumberOfRoots()==TWO_ROOTS)
{
if(a!=0 && b*b>4*a*c)
{
return ( -b+( sqrt((b*b)-(4*a*c)) ) )/( 2*a );
}
}
else
{
domain_error e("Invalid call");
throw(e);
return 0;
}
}
};

quadraticExpression operator +(quadraticExpression& q1,quadraticExpression& q2)
{
quadraticExpression q3((q1.getACoffecient()+q2.getACoffecient()),(q1.getBCoffecient()+q2.getBCoffecient()),(q1.getCCoffecient()+q2.getCCoffecient()));
return q3;
}

quadraticExpression operator *(double r,quadraticExpression& q2)
{
quadraticExpression q3((r*q2.getACoffecient()),(r*q2.getBCoffecient()),(r*q2.getCCoffecient()));
return q3;
}

void evaluateExpression(quadraticExpression &);

int main ()
{
    fout.open("Asg1P3results.txt");
quadraticExpression q[6] = {
  quadraticExpression(1, -8, 5),
  quadraticExpression(5, -2, 32),
  quadraticExpression(4, 3, 2),
  quadraticExpression(4, 12, 9),
  quadraticExpression(5, 20, 5),
  quadraticExpression()    };
for (int i=0; i<6; i++)
evaluateExpression(q[i]);
return EXIT_SUCCESS;
}

void evaluateExpression(quadraticExpression &q)
{
int errorsHandled = 0;

cout << "f(1) = " << q.evaluate(1) << endl;
fout << "f(1) = " << q.evaluate(1) << endl;

if (q.getNumberOfRoots() == INFINITE_ROOTS)
{
cout << "The Expression has Infinite Roots" << endl;
fout << "The Expression has Infinite Roots" << endl;
}
else if (q.getNumberOfRoots() == ONE_ROOT)
{
cout << "The Expression has One Root at x = " << q.getFirstRoot() << endl;
fout << "The Expression has One Root at x = " << q.getFirstRoot() << endl;
}
else if (q.getNumberOfRoots() == TWO_ROOTS)
{
cout << "The Expression has First Root at x = " << q.getFirstRoot() << endl;
cout << "The Expression has Second Root at x = " << q.getSecondRoot() << endl;
fout << "The Expression has First Root at x = " << q.getFirstRoot() << endl;
fout << "The Expression has Second Root at x = " << q.getSecondRoot() << endl;
}
else
cout << "The Expression has No Roots" << endl;
fout << "The Expression has No Roots" << endl;

try {
q.getFirstRoot();
}
catch (domain_error e) {
errorsHandled ++;
}

try {
q.getSecondRoot();
}
catch (domain_error e) {
errorsHandled ++;
}

cout << "Errors Handled: " << errorsHandled << endl;
fout << "Errors Handled: " << errorsHandled << endl;

cout << endl;
cout << endl;
fout << endl;
fout << endl;
}
