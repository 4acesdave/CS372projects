/*
You are to develop a class call "statistic" that will do some simple statistical calculations.  The program will allow you to add new value(s) to a collection of data and then be able to print out information about the data.  For example, how many values are in the set of data (length), the average for the set of data, the largest, smallest values, and the sum of the values?  You will NOT need to save the individual elements of the data collection, just the values indicated.
Your main program will need to be able to declare an object (ex stat) and then add data elements to this object.  For example you may add new values "stat.next( 5.5)", then "stat.next(6.6)" and so on.  The class object "stat" will accumulate a sum, count the new element, determine if this is a larger value, and determine if new value is a smaller value.  (Again, you will not save the individual elements.)  You will then be asked to print out information about the statistical object (number of values, average, smallest value in collection, largest value, and the sum.

Methods needed for the "statistician" are:  next, getlength, getsum, getaverage, getlargest, getsmallest, reset, constructor(s).  (Your methods may not be the same names as listed and that is fine.  Use yours.)
       The methods should be self explanatory.   constructor will set a statistical object to zero out so as to accumulate a new collection.
Overload the ==, != and + operators, and the output << operator.  As stated above the output of a statistician is number of values, average, smallest value in collection, largest value, and the sum.

Use the following input to test you program.

Data for statistician1:   5.5, 6.6, 8.8, -3.4, -0.5, 4.7, 9.1
	                        Print out:  statistician1

	add to statistician1:   5.2 - 3.3 - 8.5 3.2 5.5
                          Print out: statistician1

Data for statistician2:   empty
	                        Print out: statistician2

add to statistician2:    103 821 871 487 312 245 224 623 424 432
	                       Print out statistician2

Erase statistician2:

Data for Statistician2:   9.3 -6.3 8.2 7.2 8.2 8.8 7.2 -3.2 7.6 9.3
	                        Print out statistician2

Set up statistician3:     with the data form statistician2 (copy constructor).
	                        Print out statistician3

Add to your ‘main’ program code to test the overloaded methods.  The == method need only check to see if the sums are equal and the averages are equal and the != method.  The + method should add the sums, the counts, select the smallest and select the largest value from the two stats when adding.  Print out Statisticians with the << operator.

Note:  This program is very similar to problem #2 & #3 at the end of Chapter 2.  You should read it to get a better feel of the class.
*/

#include <iostream>
#include <cfloat>
#include <cmath>
#include "statistic.h"
#include <fstream>
using namespace std;

ofstream fout;

statistic::statistic() : count(0),total(0),smallest(DBL_MAX),largest(-DBL_MAX)
{}

statistic::statistic(const statistic &other) : count(other.count), total(other.total), smallest(other.smallest), largest(other.largest)
{}

void statistic::next(double r) {
  if(largest < r)
        largest = r;
  if(smallest > r)
        smallest = r;
  count++;
  total += r;
}

void statistic:: reset() {
  count = 0;
  total = 0;
  smallest = DBL_MAX;
  largest = -DBL_MAX;
}

int statistic::getlength( ) const {
  return count;
}

double statistic:: getsum( ) const {
  return total;
}

double statistic:: getaverage( ) const {
  if(count > 0)
     return(total/count);
  return 0;
}

double statistic:: getsmallest( ) const {
  return smallest;
}

double statistic:: getlargest() const {
  return largest;
}

bool statistic:: operator ==(const statistic& s1) {
  const double EPSILON = 1e-5;
  return((fabs(getsum()- s1.getsum()) < EPSILON) && (fabs(getaverage()- s1.getaverage()) < EPSILON));
}

bool statistic::operator !=(const statistic& s1) {
  return (!(*this == s1));
}

statistic statistic:: operator+ (const statistic& s1) {
  statistic s;
  s.count = count + s1.count;
  s.total = total + s1.total;
  if(smallest <= s1.smallest)
    s.smallest =smallest;
  else
    s.smallest = s1.smallest;
  if(largest >= s1.largest)
    s.largest = largest;
  else
    s.largest = s1.largest;
  return s;
}

ostream& operator<<(ostream &out, const statistic &stat) {
  out<<"Number of values : "<<stat.getlength()<<endl;
  fout<<"Number of values : "<<stat.getlength()<<endl;
  if(stat.getlength() > 0) {
    out<<"Sum : "<<stat.getsum()<<endl;
    out<<"Average : "<<stat.getaverage()<<endl;
    out<<"Smallest value : "<<stat.getsmallest()<<endl;
    out<<"Largest value : "<<stat.getlargest()<<endl;
    fout<<"Sum : "<<stat.getsum()<<endl;
    fout<<"Average : "<<stat.getaverage()<<endl;
    fout<<"Smallest value : "<<stat.getsmallest()<<endl;
    fout<<"Largest value : "<<stat.getlargest()<<endl;
  }
  else
    out<<"No values present"<<endl;
    fout<<"No values present"<<endl;
  return out;
}

int main() {
  fout.open("StatOverloadResults.txt");
  statistic statistician1;
  statistician1.next(5.5);
  statistician1.next(6.6);
  statistician1.next(8.8);
  statistician1.next(-3.4);
  statistician1.next(-0.5);
  statistician1.next(4.7);
  statistician1.next(9.1);
  cout<<"statistician1 : "<<endl;
  cout<<statistician1<<endl;
  fout<<"statistician1 : "<<endl;
  fout<<statistician1<<endl;
  statistician1.next(5.2);
  statistician1.next(-3.3);
  statistician1.next(-8.5);
  statistician1.next(3.2);
  statistician1.next(5.5);
  cout<<"statistician1 : "<<endl;
  cout<<statistician1<<endl;
  fout<<"statistician1 : "<<endl;
  fout<<statistician1<<endl;
  statistic statistician2;
  cout<<"statistician2 :"<<endl;
  cout<<statistician2<<endl;
  fout<<"statistician2 :"<<endl;
  fout<<statistician2<<endl;
  statistician2.next(103);
  statistician2.next(821);
  statistician2.next(871);
  statistician2.next(487);
  statistician2.next(312);
  statistician2.next(245);
  statistician2.next(224);
  statistician2.next(623);
  statistician2.next(424);
  statistician2.next(432);
  cout<<"statistician2 : "<<endl;
  cout<<statistician2<<endl;
  fout<<"statistician2 : "<<endl;
  fout<<statistician2<<endl;
  statistician2.reset();
  statistician2.next(9.3);
  statistician2.next(-6.3);
  statistician2.next(8.2);
  statistician2.next(7.2);
  statistician2.next(8.2);
  statistician2.next(8.8);
  statistician2.next(7.2);
  statistician2.next(-3.2);
  statistician2.next(7.6);
  statistician2.next(9.3);
  statistic statistician3(statistician2);
  cout<<"statistician3 : "<<endl;
  cout<<statistician3<<endl;
  fout<<"statistician3 : "<<endl;
  fout<<statistician3<<endl;
  fout.close();
  return 0;
}
