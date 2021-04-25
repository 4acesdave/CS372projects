#ifndef POINTSCLASSOVERLOAD_H_INCLUDED
#define POINTSCLASSOVERLOAD_H_INCLUDED
#include <iostream>
#include <fstream>
using namespace std;
ofstream fout;
class olPoint {
  private:
    int x;
    int y;

  public:
    olPoint(int x,int y) {
      this->x=x;
      this->y=y;
    }

    int getX() const {
      return x;
    }

    int getY() const {
      return y;
    }

    void setX(int x) {
      this->x=x;
    }

    void setY(int y) {
      this->y=y;
    }

    friend std::ostream & operator <<(std::ostream &dout, const olPoint &p) {
      dout<<"("<<p.x<<","<<p.y<<")";
      return dout;
    }

    bool operator==(const olPoint& p) const /* operator==() */ {
      if(this->x==p.x && this->y==p.y)
        return true;
      else
        return false;
    }

    bool operator!=(const olPoint& p) const /* operator!=() */ {
      if(x==p.x && y==p.y)
        return false;
      else
        return true;
    }

    void operator+(const olPoint& p) /* operator+() */ {
      cout<<"("<<x<<","<<y<<") + ";
        cout<<p;
      fout<<"("<<x<<","<<y<<") + ";
        fout<<p;
        this->x+=p.x;
        this->y+=p.y;
      cout<<" = ("<<x<<","<<y<<")"<<endl;
      fout<<" = ("<<x<<","<<y<<")"<<endl;
    }

    void operator-(const olPoint& p) /* operator-() */ {
      cout<<"("<<x<<","<<y<<") - ";
        cout<<p;
      fout<<"("<<x<<","<<y<<") - ";
        fout<<p;
        this->x-=p.x;
        this->y-=p.y;
      cout<<" = ("<<x<<","<<y<<")"<<endl;
      fout<<" = ("<<x<<","<<y<<")"<<endl;
    }

    bool operator>(const olPoint& p) const /* operator>() */ {
      int dist1=sqrt(x*x+y*y);
      int dist2=sqrt(p.getX()*p.getX()+p.getY()*p.getY());

      if(dist1>dist2) {
        return true;
      }
      else {
        return false;
      }
    }

    bool operator<(const olPoint& p) const /* operator>() */ {
      int dist1=sqrt(x*x+y*y);
      int dist2=sqrt(p.getX()*p.getX()+p.getY()*p.getY());
      if(dist1<dist2) {
        return true;
      }
      else {
        return false;
      }
    }

    bool operator>=(const olPoint& p) const  { // operator>()
      int dist1=sqrt(x*x+y*y);
      int dist2=sqrt(p.getX()*p.getX()+p.getY()*p.getY());
      if(dist1>=dist2) {
        return true;
      }
      else {
        return false;
      }
    }
};
#endif // POINTSCLASSOVERLOAD_H_INCLUDED
