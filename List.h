#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
#include<iostream>
#include<fstream>
using namespace std;
const int CAPACITY = 20;
ofstream fout;

class List {
  private:
    int aryList[CAPACITY][2];
    int arySize;
    int pos;


  public:
    List();
    List(List& aryList);
    void clear();
    void first();
    void prev();
    void next();
    void last();
    void replace(int, int);
    void setPos(int);
    void erase();
    void insertAfter(int, int);
    void insertBefore(int, int);
    int size();
    bool empty();
    int getXElement();
    int getYElement();
    int getPos();
    List operator= (List& aryListB);
    friend List operator + (List& ListA, List& ListB);
};

ostream& operator <<(ostream& outs, List& aryList);
List operator + (List& ListA, List& ListB);
bool operator == (List aryList1, List aryList2);

List::List() {
  this->clear();
};

List::List(List& aryListB) {
  this->clear();
  int orig_pos = aryListB.getPos();
  aryListB.first();
  for (int i = 0; i < aryListB.size(); aryListB.next(), i++) {
  this->aryList[i][0] = aryListB.getXElement();
  this->aryList[i][1] = aryListB.getYElement();
  this->arySize++;
  }
  this->pos = orig_pos;
  aryListB.setPos(orig_pos);
}

void List::clear()
{
  arySize = 0;
  pos = 0;
  int i;
  for (i = 0; i < CAPACITY; i++) {
    aryList[i][0] = 0;
    aryList[i][1] = 0;
  }
}

void List::first() {
  pos = 0;
}

void List::prev() {
  if (pos > 0)
  pos--;
}

void List::next() {
  if (pos < (arySize - 1))
  pos++;
}

void List::last() {
  if (arySize > 0)
  pos = (arySize - 1);
  else
  pos = 0;
}

void List::replace(int a, int b) {
  aryList[pos][0] = a;
  aryList[pos][1] = b;
}

void List::setPos(int newPos) {
  if (newPos >= 0 && newPos < arySize)
  pos = newPos;
}

void List::erase()
{
  if (arySize > 0)
  {
    for (int i = pos; i < arySize - 1; i++)
    {
      aryList[i][0] = aryList[i + 1][0];
      aryList[i][1] = aryList[i + 1][1];
    }
    aryList[arySize - 1][0] = 0;
    aryList[arySize - 1][1] = 0;
    arySize -= 1;
  }
}

void List::insertAfter(int a, int b) {
  if (pos >= CAPACITY - 1) {
    cout << "No insert made" << endl;
    fout << "No insert made" << endl;
  }
  else {
    for (int i = arySize; i > pos; i--) {
      aryList[i][0] = aryList[i + 1][0];
      aryList[i][1] = aryList[i + 1][1];
    }
    if (arySize == 0) {
      aryList[pos][0] = a;
      aryList[pos][1] = b;
    }
    else {
      aryList[pos + 1][0] = a;
      aryList[pos + 1][b] = b;
      pos++;
    }
    arySize++;
  }
}

void List::insertBefore(int a, int b) {
  if (pos == (int)CAPACITY - 1) {
    aryList[pos][0] = a;
    aryList[pos][1] = b;
  }
  else {
    for (int i = arySize; i >= pos && i != 0; i--) {
      aryList[i][0] = aryList[i + 1][0];
      aryList[i][1] = aryList[i + 1][1];
    }
    aryList[pos][0] = a;
    aryList[pos][1] = b;
    if (arySize < CAPACITY)
      arySize++;
  }
}

int List::size() {
  return arySize;
}

bool List::empty() {
  return (size() == 0);
}

int List::getXElement() {
  if (size() <= 0)
  return 0;
  else
  return aryList[pos][0];
}

int List::getYElement() {
  if (size() <= 0)
  return 0;
  else
  return aryList[pos][1];
}

int List::getPos() {
  return pos;
}

ostream& operator <<(ostream& outs, List& aryList) {
  int orig_pos = aryList.getPos();
  aryList.first();
  outs << "[ ";
  fout << "[ ";
  for (int i = 0; i < aryList.size(); aryList.next(), i++) {
    outs << '[' << aryList.getXElement() << " " << aryList.getYElement() << "]";
    fout << '[' << aryList.getXElement() << " " << aryList.getYElement() << "]";
  }
  outs << " ]";
  fout << " ]";
  aryList.setPos(orig_pos);
  return outs;
}

List operator+(List& ListA, List& ListB)
{
  List ListC(ListA);
  int orig_pos = ListB.getPos();
  ListC.first();
  ListB.first();

  for (int i = 0; i < ListB.size(); ListB.next(), ListC.next(), i++) {
    ListC.replace(ListB.getXElement() + ListC.getXElement(), ListB.getYElement() + ListC.getYElement());
  }
  ListB.setPos(orig_pos);
  return ListC;
}

bool operator == (List aryList1, List aryList2)
{
  if (aryList1.size() == aryList2.size()) {
    int orig_pos1 = aryList1.getPos();
    int orig_pos2 = aryList2.getPos();
    aryList1.first();
    aryList2.first();

    for (int i = 0; i < aryList1.size(); i++, aryList1.next(), aryList2.next()) {
      if (aryList1.getXElement() != aryList2.getXElement() && aryList1.getYElement() != aryList2.getYElement()) {
        aryList1.setPos(orig_pos1);
        aryList2.setPos(orig_pos2);
        return false;
      }
    }
    aryList1.setPos(orig_pos1);
    aryList2.setPos(orig_pos2);
    return true;
  }
  return false;
}

bool operator != (List aryList1, List aryList2) {
  if (aryList1 == aryList2)
    return false;
  else
    return true;
}

List List::operator = (List& aryListB) {
  int orig_pos = aryListB.getPos();
  aryListB.first();
  first();
  arySize = 0;
  for (int i = 0; i < aryListB.size(); aryListB.next(), this->next(), i++) {
    this->aryList[i][0] = aryListB.getXElement();
    this->aryList[i][1] = aryListB.getYElement();
    this->arySize++;
  }
  pos = orig_pos;
  aryListB.setPos(orig_pos);
  return aryListB;
}
#endif // LIST_H_INCLUDED
