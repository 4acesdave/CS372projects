/*
First pgm.
  Create the "throttle" class as shown in the text with
          a.  data members of "position" and "Top_Position" (maximum throttle position)
          b.  Default "constructor" with two arguments.  The first sets the "Top_position" and the second sets the current "position".
  Ex declaration:
  throttle car - set Top_Positon to 6 and current to 0
  throttle truck(30) - sets Top_position to 30 and current position to 0
  throttle shuttle(20,6) - sets Top_position to 20 and current position to 6
      You will write your own ‘main’ program that will test every method in throttle.  Print out what you are testing and the results of the test. Make sure you test boundary conditions. Use more than one object in your testing.
*/

#include <iostream>
#include <cstdlib>
#include <cassert>
#include <fstream>
using namespace std;

class throttle
{
  public:
    // CONSTRUCTORS
    throttle( );
    throttle(int size);
    // MODIFICATION MEMBER FUNCTIONS
    void shut_off( ) { position = 0; }
    void shift(int amount);
    // CONSTANT MEMBER FUNCTIONS
    double flow( ) const { return position / double(top_position); }
    bool is_on( ) const { return position > 0; }
  private:
    int top_position;
    int position;
};

throttle::throttle() {
  top_position = 1;
  position = 0;
}

throttle::throttle(int size) {
  assert(size > 0);
  top_position = size;
  position = 0;
}

void throttle::shift(int amount) {
  position+=amount;
  if(position<0)
    position=0;
  else if (position > top_position)
    position = top_position;
}

const int CAR_SIZE = 6;
const int TRUCK_SIZE = 30;
const int SHUTTLE_SIZE = 20;

int main() {
  ofstream fout;
  fout.open("Asg1P1output.txt");
  throttle car(CAR_SIZE);
  int user_input;
  cout << "I have a throttle with " << CAR_SIZE << " positions." << endl;
  cout << "Where would you like to set the throttle?" << endl;
  cout << "Please type a number from 0 to " << CAR_SIZE << ": ";
  fout << "I have a throttle with " << CAR_SIZE << " positions." << endl;
  fout << "Where would you like to set the throttle?" << endl;
  fout << "Please type a number from 0 to " << CAR_SIZE << ": ";
  cin >> user_input;
  car.shift(user_input);
  // Shift the throttle down to zero, printing the flow along the way.
  while (car.is_on( ))
  {
    cout << "The flow is now " << car.flow() << endl;
    fout << "The flow is now " << car.flow() << endl;
    car.shift(-1);
  }
  cout << "The flow is now off" << endl;
  fout << "The flow is now off" << endl;

  throttle truck(TRUCK_SIZE);
  cout << "I have a throttle with " << TRUCK_SIZE << " positions." << endl;
  cout << "Where would you like to set the throttle?" << endl;
  cout << "Please type a number from 0 to " << TRUCK_SIZE << ": ";
  fout << "I have a throttle with " << TRUCK_SIZE << " positions." << endl;
  fout << "Where would you like to set the throttle?" << endl;
  fout << "Please type a number from 0 to " << TRUCK_SIZE << ": ";
  cin >> user_input;
  truck.shift(user_input);
  // Shift the throttle down to zero, printing the flow along the way.
  while (truck.is_on( ))
  {
    cout << "The flow is now " << truck.flow() << endl;
    fout << "The flow is now " << truck.flow() << endl;
    truck.shift(-1);
  }
  cout << "The flow is now off" << endl;
  fout << "The flow is now off" << endl;

  throttle shuttle(SHUTTLE_SIZE);
  cout << "I have a throttle with " << SHUTTLE_SIZE << " positions." << endl;
  cout << "Where would you like to set the throttle?" << endl;
  cout << "Please type a number from 0 to " << SHUTTLE_SIZE << ": ";
  fout << "I have a throttle with " << SHUTTLE_SIZE << " positions." << endl;
  fout << "Where would you like to set the throttle?" << endl;
  fout << "Please type a number from 0 to " << SHUTTLE_SIZE << ": ";
  cin >> user_input;
  shuttle.shift(user_input);
  // Shift the throttle down to zero, printing the flow along the way.
  while (shuttle.is_on( ))
  {
    cout << "The flow is now " << shuttle.flow() << endl;
    fout << "The flow is now " << shuttle.flow() << endl;
    shuttle.shift(-1);
  }
  cout << "The flow is now off" << endl;
  fout << "The flow is now off" << endl;
  return EXIT_SUCCESS;
}
