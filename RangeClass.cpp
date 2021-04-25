//  Example Class:  Range Class
#include <iostream>             //  <<, >>, cout, cin, fixed, showpoin
#include <iomanip>              // setprecision(), setw()
using namespace std;

class range
{
public:	
   range();		
   int set_range(int s, int e);
   int get_low();
   int get_high();
   void set_low( int v );
   void set_high( int v );
   bool value_n_range( int v );
   void display();
 
 private:  
   int low, high;
};        // Don't forget this ;
 range::range()
   {  low = 0;  high = 0; }      

   int range::set_range(int s, int e)
   {
   	 low = s;
   	 high = e;
   }

   void range::display()
   {
   	cout << "low: " << get_low() << "  end: " << get_high();
   }
   
   void range::set_low( int v )
   {  low = v;  }
   void range::set_high( int v )
   {  high = v;   }

   int range::get_low()
   {  return low;  }
   int range::get_high()
   {  return high;  }
   
   bool range::value_n_range( int v )
   {   return ( v >= get_low() && v <= get_high() );  }
   int  main()
{
   range car;
   int price;
   
   car.set_low(10000);
   car.set_high(16000);
   
   cout << "car " ;
   car.display();
   cout << endl;
   
   price = 12000;
   cout << "Car price OK? ";
   if ( car.value_n_range(price) )
      cout << " Yes " << endl;
   else
      cout << " No " << endl;
      
   int dummy;
   cout << "Finish" << endl;
   cin >> dummy;
   return 0
}
