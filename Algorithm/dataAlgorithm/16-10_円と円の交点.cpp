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
    void add(Point delta) {
        addX(delta.x);
        addY(delta.y);
    }
    void addX(double deltaX) { x = x + deltaX; }
    void addY(double deltaY) { y = y + deltaY; }
    static double getDistance(Point p0, Point p1) {
        Point tmp = Point(p0, p1);
        return tmp.abs();
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
class Circle {
   public:
    double r;
    Point center;
    Circle(double radius, Point centerPoint) {
        center = centerPoint;
        r = radius;
    }
    void print() {
        printf("Circle, x: %lf y: %lf r: %lf\n", center.x, center.y, r);
    }
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
pair<Point, Point> getCircleCrossPoints(const Circle& c0, const Circle& c1) {
    double distanceCircle = Point::getDistance(c0.center, c1.center);
    double cosTheta0 =
        (c0.r * c0.r + distanceCircle * distanceCircle - c1.r * c1.r) /
        (2 * c0.r * distanceCircle);
    double theta0 = acos(cosTheta0);
    Vector v0_1 = Vector(c0.center, c1.center);
    double theta1 = atan2(v0_1.y, v0_1.x);
    Point ans0 =
        Point(c0.r * cos(theta0 + theta1), c0.r * sin(theta0 + theta1));
    ans0.add(c0.center);
    Point ans1 =
        Point(c0.r * cos(-theta0 + theta1), c0.r * sin(-theta0 + theta1));
    ans1.add(c0.center);
    if (ans0 < ans1) {
        return make_pair(ans0, ans1);
    } else {
        return make_pair(ans1, ans0);
    }
}

int main() {
    double cx, cy, r;
    cin >> cx >> cy >> r;
    Circle c0 = Circle(r, Point(cx, cy));
    cin >> cx >> cy >> r;
    Circle c1 = Circle(r, Point(cx, cy));

    pair<Point, Point> ans = getCircleCrossPoints(c0, c1);
    printf("%.9lf %.9lf %.9f %.9f\n", ans.first.x, ans.first.y, ans.second.x,
           ans.second.y);

    return 0;
}