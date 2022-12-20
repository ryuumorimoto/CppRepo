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
Point getProjectionPoint(Point& p0, Point& p1, Point& target) {
    Vector v0_1 = p1 - p0;
    Vector v0_target = target - p0;
    return p0 + v0_1 * getDotProduct(v0_1, v0_target) / v0_1.abs2();
}
int main() {
    int cx, cy, r;
    cin >> cx >> cy >> r;
    Point circle = Point(cx, cy);
    int n;
    cin >> n;
    rep(i, n) {
        int x0, y0, x1, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        Point p0 = Point(x0, y0);
        Point p1 = Point(x1, y1);
        Vector v0_1 = Point(p0, p1);
        Point projection = getProjectionPoint(p0, p1, circle);
        Vector toProjection = Vector(circle, projection);
        double base = sqrt(r * r - toProjection.abs2());
        Point ans0 = projection + v0_1 * base / v0_1.abs();
        Point ans1 = projection - v0_1 * base / v0_1.abs();
        if (ans0 < ans1) {
            printf("%.9lf %.9lf %.9f %.9f\n", ans0.x, ans0.y, ans1.x, ans1.y);
        } else {
            printf("%.9lf %.9lf %.9f %.9f\n", ans1.x, ans1.y, ans0.x, ans0.y);
        }
    }

    return 0;
}