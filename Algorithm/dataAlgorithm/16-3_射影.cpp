#include <cmath>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define EPS (1e-10)
class Point {
   public:
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point(Point p1, Point p2) {
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }
    Point operator+(Point p) { return Point(x + p.x, y + p.y); }
    Point operator-(Point p) { return Point(x - p.x, y - p.y); }
    Point operator*(double k) { return Point(x * k, y * k); }
    Point operator/(double k) { return Point(x / k, y / k); }
    double abs() { return sqrt(x * x + y * y); }
    double abs2() { return x * x + y * y; }
    bool operator<(const Point& p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
    bool operator==(const Point& p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }

    void print() { printf("Point, x: %lf, y: %lf\n", x, y); }

   private:
};
typedef Point Vector;
double getDotProduct(Point& p0, Point& p1) { return p0.x * p1.x + p0.y * p1.y; }

int main() {
    int x0, x1, y0, y1, q;
    cin >> x0 >> y0 >> x1 >> y1;
    Point p1 = Point(x0, y0);
    Point p2 = Point(x1, y1);
    Vector v1_2 = Vector(p1, p2);
    cin >> q;
    rep(i, q) {
        int x, y;
        cin >> x >> y;
        Point p3 = Point(x, y);
        Vector v1_3 = Vector(p1, p3);
        Point ans = p1 + v1_2 * getDotProduct(v1_2, v1_3) / v1_2.abs2();
        printf("%.9lf %.9lf\n", ans.x, ans.y);
    }

    return 0;
}