#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

class Image {
   public:
    int r, g, b;
    Image(int _r, int _g, int _b) {
        r = _r;
        g = _g;
        b = _b;
    }
    int getBrightness() const { return r * r + g * g + b * b; }
    void show() { cout << r << " " << g << " " << b << endl; }
    bool operator==(const Image& other) const {
        return (r == other.r) && (g == other.g) && (b == other.b);
    }
    bool operator<(const Image& other) const {
        return getBrightness() < other.getBrightness();
    }
};

int main(int argc, char* argv[]) {
    FILE* fp;
    if ((fp = fopen("problem.in", "r")) == NULL) {
        cout << "not exist file" << endl;
        exit(-1);
    }
    vector<Image> v;
    int r, g, b;
    while (fscanf(fp, "%d %d %d", &r, &g, &b) != EOF) {
        // cout << r << " " << g << " " << b << endl;
        v.push_back(Image(r, g, b));
    }
    stable_sort(v.begin(), v.end());
    rep(i, v.size()) { v[i].show(); }

    return 0;
}