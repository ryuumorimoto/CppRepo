#include <cmath>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define EPS (1e-10)
class Point {
   public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}

    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
    double abs() { return sqrt(norm()); }
    double norm() { return x * x + y * y; }
    bool operator<(const Point &p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
    bool operator==(const Point &p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }

    void print() { printf("Point, x: %lf, y: %lf\n", x, y); }

   private:
};
typedef Point Vector;
int main() {
    Point p0 = Point(1, 2);
    Point p1 = Point(4, 5);

    Point added = p0 + p1;
    Point subed = p0 - p1;
    Point multi = p0 * 100;
    Point div = p0 / 2;

    added.print();
    subed.print();
    multi.print();
    div.print();

    return 0;
}