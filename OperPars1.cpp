#include <iostream>
using namespace std;

class Point
{
   friend ostream &operator<<(ostream &, const Point &);
   friend istream &operator>>(istream &, Point &);
    
public:
   void setX(int);
   void setY(int);
   int getX() const;
   int getY() const;
   Point &operator=(const Point &);
   Point operator++(); //prefiksa (++x)
   Point operator++(int); //postfiksa (x++)

private:
   int X;
   int Y;
};

void Point::setX(int x)
{
    X=x;
}

void Point::setY(int y)
{
    Y=y;
}

int Point::getX() const
{
   return X;
}

int Point::getY() const
{
   return Y;
}

Point &Point::operator=(const Point &p)
{
   X=p.X;
   Y=p.Y;
   return *this;
}

ostream &operator<<(ostream &output, const Point &p)
{
   output << "x=" << p.X << ", y=" << p.Y ;
   return output;
}

istream &operator>>(istream &input, Point &p)
{
   input >> p.X >> p.Y;
   return input;
}

Point Point::operator++()
{
    X++;
    Y++;
    return *this;
}
    
Point Point::operator++(int)
{
    Point temp = *this;
    X++;
    Y++;
    return temp;
}
    

int main()
{
   Point p1, p2;
////////////////////////////////////////////////////////////////////////// 
//ievades un izvades paarbaude 
   cout << "### Ievades/Izvades parbaude ###" << endl;
   cout << "Ievadiet pirmo punktu:" << endl;
   cin >> p1;
   cout << "Ievadiet otro punktu:" << endl;
   cin >> p2;
   cout << endl;   
   cout << p1 << endl << p2 << endl << endl;

//////////////////////////////////////////////////////////////////////////
//pieskirsanas paarbaude   
   p1=p2;
   cout << "### Pieskirsanas parbaude ###" << endl;
   cout << p1 << endl << p2 << endl;
   
//////////////////////////////////////////////////////////////////////////
//++ paarbaude 
   cout << endl;
   cout << "### ++ parbaude ###" << endl;
   Point tests;
   tests = p1++;
   cout << "tests pec p1++: " << tests << endl;
   cout << "p1 pec p1++: " << p1 << endl;
   tests = ++p2;
   cout << "tests pec ++p2: " << tests << endl;
   cout << "p2 pec ++p2: " << p2 << endl;
   system("PAUSE");
   
   return 0;
}
