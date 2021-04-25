#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include "PointsClassOverload.h"
#include "PointsClassFirst.h"
#define TIMES 2
using namespace std;

char ary[30*TIMES+1][30*TIMES+1];

void printTwoPoint(point a,point b) {
  double low=a.x-b.x;
  int max,min,y;

  if((int)low==0) {
    if(a.y>b.y) {
        max=(int)a.y;
        min=(int)b.y;
    }

    else {
        max=(int)b.y;
        min=(int)a.y;
    }

    for(int i=min;i<=max;i++) {
        y=(int)(((a.x-b.x)/(a.y-b.y))*i+(a.x-a.y*((a.x-b.x)/(a.y-b.y))));
        ary[15*TIMES+y][15*TIMES+i]='*';
    }
  }

   else {
    if(a.x>b.x) {
        max=(int)a.x;
        min=(int)b.x;
    }

     else {
        max=(int)b.x;
        min=(int)a.x;
    }

     for(int i=min;i<=max;i++){
        y=(int)(((a.y-b.y)/(a.x-b.x))*i+(a.y-a.x*((a.y-b.y)/(a.x-b.x))));
        ary[15*TIMES+i][15*TIMES+y]='*';
    }
  }
  cout<<"\nL["<<low<<"]"<<min<<"|"<<max<<" ";
  fout<<"\nL["<<low<<"]"<<min<<"|"<<max<<" ";
}


// print the box
void printBox(point a,point b,point c,point d){
  cout<<"\nA: ("<<a.x<<","<<a.y<<")";
  cout<<"\tB: ("<<b.x<<","<<b.y<<")";
  cout<<"\tC: ("<<c.x<<","<<c.y<<")";
  cout<<"\tD: ("<<d.x<<","<<d.y<<")\n";
  fout<<"\nA: ("<<a.x<<","<<a.y<<")";
  fout<<"\tB: ("<<b.x<<","<<b.y<<")";
  fout<<"\tC: ("<<c.x<<","<<c.y<<")";
  fout<<"\tD: ("<<d.x<<","<<d.y<<")\n";

  ///// graph scaling to 4 times
  a.x*=TIMES;
  b.x*=TIMES;
  c.x*=TIMES;
  d.x*=TIMES;


  a.y*=TIMES;
  b.y*=TIMES;
  c.y*=TIMES;
  d.y*=TIMES;

  for(int i=0;i<30*TIMES+1;i++){
      for(int j=0;j<30*TIMES+1;j++){
          ary[i][j]=' ';
          if(i==15*TIMES+1){
              ary[i][j]='|';
          }
          if(j==15*TIMES+1){
              ary[i][j]='-';
          }
      }
  }
  printTwoPoint(a,b);
  printTwoPoint(b,c);
  printTwoPoint(c,d);
  printTwoPoint(d,a);
  cout<<endl;
  fout<<endl;
  for(int i=0;i<30*TIMES+1;i++) {
    for(int j=0;j<30*TIMES+1;j++) {
      cout<<ary[j][30*TIMES-i];
      fout<<ary[j][30*TIMES-i];
    }
    cout<<endl;
    fout<<endl;
  }
}

int main() {
  fout.open("PointsClassMasterResults.txt");
  point A(2,2);
  point B(2,5);
  point C(4,5);
  point D(4,2);

  // print box
  cout<<"\n Box is - ";
  fout<<"\n Box is - ";
  printBox(A,B,C,D);

  // translate each point at x=2 and y=1
  cout<<"\nTranslating x=2 , y=1";
  fout<<"\nTranslating x=2 , y=1";
  A.translation(2,1);
  B.translation(2,1);
  C.translation(2,1);
  D.translation(2,1);
  printBox(A,B,C,D);

  // scaling by x=2 and y=0.5
  cout<<"\nScaling x=2 , y=.5";
  fout<<"\nScaling x=2 , y=.5";
  A.scaling(2,.5);
  B.scaling(2,.5);
  C.scaling(2,.5);
  D.scaling(2,.5);
  printBox(A,B,C,D);

  // rotate 30 degree PI/6
  cout<<"\nRotate 30 degree";
  fout<<"\nRotate 30 degree";
  A.rotation(22/(double)42);
  B.rotation(22/(double)42);
  C.rotation(22/(double)42);
  D.rotation(22/(double)42);
  printBox(A,B,C,D);

  // rotate 60 degree PI/3
  cout<<"\nRotate 60 degree";
  fout<<"\nRotate 60 degree";
  A.rotation(22/(double)21);
  B.rotation(22/(double)21);
  C.rotation(22/(double)21);
  D.rotation(22/(double)21);
  printBox(A,B,C,D);

  // shearing in the x direction 1.5
  cout<<"\nShearing x direction 1.5";
  fout<<"\nShearing x direction 1.5";
  A.shearingX(1.5);
  B.shearingX(1.5);
  C.shearingX(1.5);
  D.shearingX(1.5);
  printBox(A,B,C,D);

  // shearing in the y direction 1.7
  cout<<"\nShearing y direction 1.7";
  fout<<"\nShearing y direction 1.7";
  A.shearingY(1.7);
  B.shearingY(1.7);
  C.shearingY(1.7);
  D.shearingY(1.7);
  printBox(A,B,C,D);

  //Declaring variables
  olPoint p1(3,4),p2(5,7),p3(4,4);
  cout<<"Point #1 = "<<p1<<endl;
  cout<<"Point #2 = "<<p2<<endl;
  fout<<"Point #1 = "<<p1<<endl;
  fout<<"Point #2 = "<<p2<<endl;
  p1+p2;
  if(p1<p2) {
    cout<<"Point #1: "<<p1<<" is less than Point #2: "<<p2<<endl;
    fout<<"Point #1: "<<p1<<" is less than Point #2: "<<p2<<endl;
  }
  else {
    cout<<"Point #1: "<<p1<<" is not less than Point #2: "<<p2<<endl;
    fout<<"Point #1: "<<p1<<" is not less than Point #2: "<<p2<<endl;
  }
  if(p1>p2) {
    cout<<"Point #1: "<<p1<<" is greater than Point #2: "<<p2<<endl;
    fout<<"Point #1: "<<p1<<" is greater than Point #2: "<<p2<<endl;
  }
  else {
    cout<<"Point #1: "<<p1<<" is not greater than Point #2: "<<p2<<endl;
    fout<<"Point #1: "<<p1<<" is not greater than Point #2: "<<p2<<endl;
  }
  if(p1>=p2) {
    cout<<"Point #1: "<<p1<<" is greater than or equal to Point #2: "<<p2<<endl;
    fout<<"Point #1: "<<p1<<" is greater than or equal to Point #2: "<<p2<<endl;
  }
  else {
    cout<<"Point #1: "<<p1<<" is not greater than or equal to Point #2: "<<p2<<endl;
    fout<<"Point #1: "<<p1<<" is not greater than or equal to Point #2: "<<p2<<endl;
  }
  cout<<"Point #3 = "<<p3<<endl;
  fout<<"Point #3 = "<<p3<<endl;
  p1-p2;
  fout.close();
  return(0);
}
