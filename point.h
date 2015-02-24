#include <string>
using std::string;

class Point {
  public:
    Point(double=0.0, double=0.0);
    Point(const Point&);
    ~Point();
    Point& operator=(const Point&);
    double x() const;
    double y() const;
    string toString() const;
  protected:
    double _x, _y;
};
