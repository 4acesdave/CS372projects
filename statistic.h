// statistic.h
#ifndef STATISTIC_H_
#define STATISTIC_H_
#include <iostream>
using namespace std;

class statistic {
  private:
    int count; // length of numbers in the sequence
    double total; // The sum of all the numbers in the sequence
    double smallest; // The smallest number in the sequence
    double largest; // The largest number in the sequence

  public:
    statistic(); // default constructor
    statistic(const statistic &other); //copy constructor
    void next(double r); // function to add next number in the sequence
    void reset() ; // reset the sequence
    int getlength( ) const; // return length of numbers in the sequence
    double getsum( ) const; // return the total sum of numbers in the sequence
    double getaverage( ) const; // return the average of numbers in the sequence
    double getsmallest( ) const; //return the smallest number in the sequence
    double getlargest() const ; // return the largest number in the sequence
    bool operator ==(const statistic& s1); //check if two statistic objects are equal
    bool operator !=(const statistic& s1); // check if two statistic objects are not equal
    statistic operator + (const statistic& s1); //add two statistic objects and return the result of this addition
    friend ostream& operator<<(ostream &out, const statistic &stat);
};
#endif /* STATISTIC_H_ */
