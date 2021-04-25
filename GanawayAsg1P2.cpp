/*
Second pgm.
  In your text on Programming projects at the end of Chapter 2, do number 2, the statistician program.  It requires you to set up a class and keep track of several values of a sequence of numbers.  YOU will NOT store the individual numbers of the sequence.  The methods are next_number, erase and several getter methods for each of the values you object keeps up with.   Get the programs working because later we will be adding some additional methods to them.

  The data for statisticians:
    statOne : 5.5, 3.6, 8.9, 5.2, 2.7, 8.3, 3.9, 8.9, 3.4, 7.6, 9.1, 3.2
    statTwo:  .0134, .8232, .4593, .2921, .825, .2316, .634, .2982, .828
    statThree:
  Again, make sure you test all methods and show all results.  You may put the data in an input file. Print out all values for each of the objects above. Be sure to label all output values.
  Then print out only the average for statOne,  the sum for statTwo, and the length for statThree, again with labels.
  Print out the largest number in each of the three objects (3 outputs here).
*/

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
using namespace std;

const int INT_MIN=0;
const int INT_MAX=0;

class statistician {
  private:
    double length, last, sum, mean;
    double smallest, largest;
  public:
    statistician();
    void next_number(double val);
    void erase_sequence();
    double get_length();
    double get_last();
    double get_sum();
    double get_mean();
    double get_smallest();
    double get_largest();
} ;

statistician::statistician() {
  length=0;
  last=double(NULL);
  sum=0;
  mean=0;
  smallest=INT_MAX;
  largest=INT_MIN;
}

void statistician::next_number(double val) {
  length++;
  last=val;
  sum+=val;
  mean=sum/length;
  if(val<smallest) {
    smallest=val;
  }
  else if(val>largest) {
    largest=val;
  }
}

void statistician::erase_sequence() {
  length=0;
  last=double(NULL);
  sum=0;
  mean=0;
  smallest=INT_MAX;
  largest=INT_MIN;
}

double statistician::get_length() {
  return length;
}

double statistician::get_last() {
  if(length==0) {
    cout<<"\tEmpty sequence!"<<endl;
  }
  else {
    return last;
  }
}

double statistician::get_sum() {
  return sum;
}

double statistician::get_mean() {
  if(length==0) {
    cout<<"\tEmpty sequence!"<<endl;
  }
  else {
    return mean;
  }
}

double statistician::get_smallest() {
  if(length==0) {
    cout<<"\tEmpty sequence!"<<endl;
  }
  else {
    return smallest;
  }
}

double statistician::get_largest() {
  if(length==0) {
    cout<<"\tEmpty sequence!"<<endl;
  }
  else {
    return largest;
  }
}

int main() {
  ofstream fout;
  fout.open("Asg1P2output.txt");

  cout<<"Using data from statOne...\n\n";
  fout<<"Using data from statOne...\n\n";
  statistician statOne;
  statOne.next_number(5.5);
  statOne.next_number(3.6);
  statOne.next_number(8.9);
  statOne.next_number(5.2);
  statOne.next_number(2.7);
  statOne.next_number(8.3);
  statOne.next_number(3.9);
  statOne.next_number(8.9);
  statOne.next_number(3.4);
  statOne.next_number(7.6);
  statOne.next_number(9.1);
  statOne.next_number(3.2);
  cout<<"Length of the sequence: "<<statOne.get_length()<<endl;
  cout<<"Last number of the sequence: "<<statOne.get_last()<<endl;
  cout<<"Sum of numbers in the sequence: "<<statOne.get_sum()<<endl;
  cout<<"Mean of numbers in the sequence: "<<statOne.get_mean()<<endl;
  cout<<"Smallest number in the sequence: "<<statOne.get_smallest()<<endl;
  cout<<"Largest number in the sequence: "<<statOne.get_largest()<<endl;
  fout<<"Length of the sequence: "<<statOne.get_length()<<endl;
  fout<<"Last number of the sequence: "<<statOne.get_last()<<endl;
  fout<<"Sum of numbers in the sequence: "<<statOne.get_sum()<<endl;
  fout<<"Mean of numbers in the sequence: "<<statOne.get_mean()<<endl;
  fout<<"Smallest number in the sequence: "<<statOne.get_smallest()<<endl;
  fout<<"Largest number in the sequence: "<<statOne.get_largest()<<endl;
  statOne.erase_sequence();

  cout<<endl<<endl;
  fout<<endl<<endl;

  cout<<"Using data from statTwo...\n\n";
  fout<<"Using data from statTwo...\n\n";
  statistician statTwo;
  statTwo.next_number(0.0134);
  statTwo.next_number(0.8232);
  statTwo.next_number(0.4593);
  statTwo.next_number(0.2921);
  statTwo.next_number(0.825);
  statTwo.next_number(0.2316);
  statTwo.next_number(0.634);
  statTwo.next_number(0.2982);
  statTwo.next_number(0.828);
  cout<<"Length of the sequence: "<<statTwo.get_length()<<endl;
  cout<<"Last number of the sequence: "<<statTwo.get_last()<<endl;
  cout<<"Sum of numbers in the sequence: "<<statTwo.get_sum()<<endl;
  cout<<"Mean of numbers in the sequence: "<<statTwo.get_mean()<<endl;
  cout<<"Smallest number in the sequence: "<<statTwo.get_smallest()<<endl;
  cout<<"Largest number in the sequence: "<<statTwo.get_largest()<<endl;
  fout<<"Length of the sequence: "<<statTwo.get_length()<<endl;
  fout<<"Last number of the sequence: "<<statTwo.get_last()<<endl;
  fout<<"Sum of numbers in the sequence: "<<statTwo.get_sum()<<endl;
  fout<<"Mean of numbers in the sequence: "<<statTwo.get_mean()<<endl;
  fout<<"Smallest number in the sequence: "<<statTwo.get_smallest()<<endl;
  fout<<"Largest number in the sequence: "<<statTwo.get_largest()<<endl;
  statTwo.erase_sequence();
  return EXIT_SUCCESS;
}
