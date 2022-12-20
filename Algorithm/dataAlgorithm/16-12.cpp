#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
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
    static bool lessY(const Point& p0, const Point& p1) {
        return p0.y != p1.y ? p0.y < p1.y : p0.x < p1.x;
    }
    void print() { printf("Point, x: %lf, y: %lf\n", x, y); }

   private:
};
class Polygon {
   public:
    vector<Point> vertex;
    Polygon() {}
    int getVertexNum() { return vertex.size(); }
    void push(Point p) { vertex.push_back(p); }
    void push(double x, double y) { vertex.push_back(Point(x, y)); }

   private:
};
typedef Point Vector;
double getDotProduct(Point& p0, Point& p1) { return p0.x * p1.x + p0.y * p1.y; }
double getCrossProduct(Point& p0, Point& p1) {
    return p0.x * p1.y - p0.y * p1.x;
}
VectorState getVectorState(Vector v0, Vector v1) {
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

int getPolygonandPointRelation(Polygon* pg, const Point& target) {
    bool isContain = false;
    int n = pg->getVertexNum();
    rep(i, n) {
        Vector vtarget_gn0 = Vector(target, pg->vertex[i % n]);
        Vector vtarget_gn1 = Vector(target, pg->vertex[(i + 1) % n]);

        if (abs(getCrossProduct(vtarget_gn0, vtarget_gn1)) < EPS &&
            getDotProduct(vtarget_gn0, vtarget_gn1) < EPS) {
            return 1;
        }
        if (vtarget_gn0.y > vtarget_gn1.y) {
            swap(vtarget_gn0, vtarget_gn1);
        }
        if (vtarget_gn0.y < EPS && EPS < vtarget_gn1.y &&
            EPS < getCrossProduct(vtarget_gn0, vtarget_gn1)) {
            isContain = !isContain;
        }
    }

    return (isContain ? 2 : 0);
}

int main() {
    int n;
    Polygon pg;
    cin >> n;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        pg.push(x, y);
    }

    if (pg.vertex.size() <= 3) {
        sort(pg.vertex.begin(), pg.vertex.end(), Point::lessY);
        cout << pg.vertex.size() << endl;
        rep(i, pg.vertex.size()) {
            cout << pg.vertex[i].x << " " << pg.vertex[i].y << endl;
        }
    } else {
        vector<Point> upper, lower;
        sort(pg.vertex.begin(), pg.vertex.end());
        upper.push_back(pg.vertex[0]);
        upper.push_back(pg.vertex[1]);
        lower.push_back(pg.vertex[pg.vertex.size() - 1]);
        lower.push_back(pg.vertex[pg.vertex.size() - 2]);

        for (int i = 2; i < pg.vertex.size(); i++) {
            Point* target = &pg.vertex[i];

            while (2 <= upper.size() &&
                   getVectorState(
                       Point(upper[upper.size() - 2], upper[upper.size() - 1]),
                       Point(upper[upper.size() - 2], *target)) ==
                       VectorState::COUNTER_CLOCKWISE) {
                upper.pop_back();
            }
            upper.push_back(*target);
        }

        for (int i = pg.getVertexNum() - 3; i >= 0; i--) {
            Point* target = &pg.vertex[i];
            while (2 <= lower.size() &&
                   getVectorState(
                       Vector(lower[lower.size() - 2], lower[lower.size() - 1]),
                       Vector(lower[lower.size() - 2], *target)) ==
                       VectorState::COUNTER_CLOCKWISE) {
                lower.pop_back();
            }
            lower.push_back(*target);
        }

        reverse(lower.begin(), lower.end());
        for (int i = upper.size() - 2; i >= 1; i--) {
            lower.push_back(upper[i]);
        }
        cout << "upper" << endl;
        rep(i, upper.size()) {
            cout << upper[i].x << " " << upper[i].y << endl;
        }
        cout << "lower" << endl;
        rep(i, lower.size()) {
            cout << lower[i].x << " " << lower[i].y << endl;
        }
        cout << "end" << endl;

        // output
        cout << lower.size() << endl;
        rep(i, lower.size()) {
            cout << lower[i].x << " " << lower[i].y << endl;
        }
    }

    return 0;
}