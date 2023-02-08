#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
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
class Segment {
   public:
    Point p0, p1;
    enum type { HORIZONTAL, VERTICAL, NORMAL };
    Segment::type attr;
    Segment(Point _p0, Point _p1) {
        if (_p0.y < _p1.y) {
            p0 = _p0;
            p1 = _p1;
        } else if (_p0.y > _p1.y) {
            p0 = _p1;
            p1 = _p0;
        } else {
            if (_p0.x < _p1.x) {
                p0 = _p0;
                p1 = _p1;
            } else {
                p0 = _p1;
                p1 = _p0;
            }
        }

        if (p0.x == p1.x) {
            attr = VERTICAL;
        } else if (p0.y == p1.y) {
            attr = HORIZONTAL;
        } else {
            attr = NORMAL;
        }
    }
    Segment() {}
    void print() {
        printf("Segment: p0: (%lf, %lf), p1: (%lf, %lf)\n", p0.x, p0.y, p1.x,
               p1.y);
    }
    bool operator<(const Segment& seg) const {
        return p0.y != seg.p0.y ? p0.y < seg.p0.y : p0.x < seg.p0.x;
    }

   private:
};
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
class Manhattan {
   public:
    int x, y;
    int x1;
    enum type {
        HORIZONTAL_LEFT = 1,
        HORIZONTAL_RIGHT = 2,
        VERTICAL_TOP = 3,
        VERTICAL_BOTTOM = 0
    };
    Manhattan::type attr;
    Manhattan(int _x, int _y, Manhattan::type _attr) {
        x = _x;
        y = _y;
        attr = _attr;
    }
    Manhattan(int _x, int _y, int _x1, Manhattan::type _attr) {
        // Manhattan(_x, _y, _attr);
        x = _x;
        y = _y;
        attr = _attr;
        x1 = _x1;
    }
    bool operator<(const Manhattan& m) const {
        if (y == m.y) {
            return (int)attr < (int)m.attr;
        } else {
            return y < m.y;
        }
    }
};
#define MAXNUM 100000

int main() {
    // input
    Segment seg[MAXNUM];
    vector<Manhattan> M;
    int n;
    cin >> n;
    rep(i, n) {
        int x0, x1, y0, y1;
        cin >> x0 >> y0 >> x1 >> y1;
        seg[i] = Segment(Point(x0, y0), Point(x1, y1));
        if (seg[i].attr == Segment::HORIZONTAL) {
            M.push_back(Manhattan(seg[i].p0.x, seg[i].p0.y, seg[i].p1.x,
                                  Manhattan::HORIZONTAL_LEFT));
            M.push_back(Manhattan(seg[i].p1.x, seg[i].p1.y,
                                  Manhattan::HORIZONTAL_RIGHT));
        } else if (seg[i].attr == Segment::VERTICAL) {
            M.push_back(Manhattan(seg[i].p0.x, seg[i].p0.y,
                                  Manhattan::VERTICAL_BOTTOM));
            M.push_back(
                Manhattan(seg[i].p1.x, seg[i].p1.y, Manhattan::VERTICAL_TOP));
        }
    }

    // solve
    sort(M.begin(), M.end());
    // rep(i, 2 * n) { cout << M[i].x << " " << M[i].y << endl; }    
    int ans = 0;
    set<int> S;
    S.insert(1000000001);
    int count = 0;
    while (count < 2 * n) {
        Manhattan* target = &M[count];
        // cout << target->x << " " << target->y << endl;
        if (target->attr == Manhattan::HORIZONTAL_LEFT) {
            int leftX = target->x;
            int rightX = target->x1;
            set<int>::iterator leftIndex =
                lower_bound(S.begin(), S.end(), leftX);
            set<int>::iterator rightIndex =
                upper_bound(S.begin(), S.end(), rightX);
            int addNum = distance(leftIndex, rightIndex);
            // cout << "left: " << leftX << "right: " << rightX << " " << addNum
            //<< endl;
            ans += addNum;
        } else if (target->attr == Manhattan::VERTICAL_BOTTOM) {
            // cout << "Bottom: " << target->x << endl;
            S.insert(target->x);
        } else if (target->attr == Manhattan::VERTICAL_TOP) {
            // cout << "Top: " << target->x << endl;
            S.erase(target->x);
        }
        count += 1;
    }

    // output
    cout << ans << endl;

    return 0;
}