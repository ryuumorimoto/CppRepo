#include <cmath>
#include <cstdio>
#include <iostream>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

#define EPS (1e-10)
enum class VectorState {
    ONLINE_FRONT = -2,
    CLOCKWISE = -1,
    ONSEGMENT = 0,
    COUNTER_CLOCKWISE = 1,
    ONLINE_BACK = 2,
};
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
VectorState getVectorState(Vector& v0, Vector& v1) {
    if (getCrossProduct(v0, v1) > EPS) {
        return VectorState::COUNTER_CLOCKWISE;
    }
    if (getCrossProduct(v0, v1) < -EPS) {
        return VectorState::CLOCKWISE;
    }
    if (getDotProduct(v0, v1) < -EPS) {
        return VectorState::ONLINE_BACK;
    }
    if (v0.abs() < v1.abs()) {
        return VectorState::ONLINE_FRONT;
    }

    return VectorState::ONSEGMENT;
}
bool isInterSect(Point& p0, Point& p1, Point& p2, Point& p3) {
    VectorState cross0, cross1, cross2, cross3;
    Vector v0_1 = p1 - p0;
    Vector v0_2 = p2 - p0;
    Vector v0_3 = p3 - p0;

    Vector v2_0 = p0 - p2;
    Vector v2_1 = p1 - p2;
    Vector v2_3 = p3 - p2;
    cross0 = getVectorState(v0_1, v0_2);
    cross1 = getVectorState(v0_1, v0_3);
    cross2 = getVectorState(v2_3, v2_0);
    cross3 = getVectorState(v2_3, v2_1);
    return ((int)cross0 * (int)cross1 <= 0) && ((int)cross2 * (int)cross3 <= 0);
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
        if (isInterSect(p0, p1, p2, p3)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}