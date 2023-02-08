#include <cmath>
#include <cstdio>
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
double getCrossProduct(Point& p0, Point& p1) {
    return p0.x * p1.y - p0.y * p1.x;
}



int main() {
    int n;
    cin >> n;
    rep(i, n) {
        int x0, y0, x1, y1, x2, y2, x3, y3;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Point p0 = Point(x0, y0);
        Point p1 = Point(x1, y1);
        Point p2 = Point(x2, y2);
        Point p3 = Point(x3, y3);
        Vector v0_1 = Vector(p0, p1);
        Vector v2_0 = Vector(p2, p0);
        Vector v2_1 = Vector(p2, p1);
        Vector v2_3 = Vector(p2, p3);
        double d1 = abs(getCrossProduct(v2_0, v2_3)) / v2_3.abs();
        double d2 = abs(getCrossProduct(v2_1, v2_3)) / v2_3.abs();
        Point ans = p0 + v0_1 * d1 / (d1 + d2);

        printf("%.9lf %.9lf\n", ans.x, ans.y);
    }
    return 0;
}