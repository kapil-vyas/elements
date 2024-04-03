#include <sstream>
#include "point.h"
using std::ostringstream;

Point::Point(double x, double y) : _x(x), _y(y) { }
Point::Point(const Point& p) : _x(p._x), _y(p._y) { }
Point::~Point() { }

Point& Point::operator=(const Point& p) {
  _x = p._x;
  _y = p._y;
  return *this;
}

double Point::x() const { return _x; }
double Point::y() const { return _y; }
string Point::toString() const {
  ostringstream output;
  output << "(" << _x << "," << _y << ")";
  return output.str();
}
