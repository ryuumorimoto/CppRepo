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
    double abs() { return sqrt(x * x + y * y); }

    bool operator<(const Point& p) const {
        return x != p.x ? x < p.x : y < p.y;
    }
    bool operator==(const Point& p) const {
        return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
    }

    void print() { printf("Point, x: %lf, y: %lf\n", x, y); }

   private:
};
double getDotProduct(Point& p0, Point& p1) { return p0.x * p1.x + p0.y * p1.y; }
typedef Point Vector;
int main() {
    int n;
    cin >> n;
    rep(i, n) {
        int x0, x1, x2, x3, y0, y1, y2, y3;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        Vector v0 = Vector(x1 - x0, y1 - y0);
        Vector v1 = Vector(x3 - x2, y3 - y2);

        double cosTheta = getDotProduct(v0, v1) / (v0.abs() * v1.abs());
        // cout << "cos: " << cosTheta << endl;
        if (abs(cosTheta) < EPS) {
            cout << 1 << endl;
        } else if (abs(cosTheta - 1) < EPS || abs(cosTheta + 1) < EPS) {
            cout << 2 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}