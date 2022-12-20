#include <string.h>

#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

void printKoch(int count, double startX, double startY, double endX,
               double endY) {
    double vertex0[2], vertex1[2], vertex2[2], len;
    vertex0[0] = (endX - startX) / 3 + startX;
    vertex0[1] = (endY - startY) / 3 + startY;
    vertex2[0] = (endX - startX) / 3 * 2 + startX;
    vertex2[1] = (endY - startY) / 3 * 2 + startY;

    len = sqrt((startX - endX) * (startX - endX) +
               (startY - endY) * (startY - endY)) /
          3;

    if (startY == endY) {
        vertex1[0] = (startX + endX) / 2;
        if (startX < endX) {
            vertex1[1] = startY + len * sqrt(3) / 2;
        } else {
            vertex1[1] = startY - len * sqrt(3) / 2;
        }
    } else if (endY > startY) {
        if (endX > startX) {
            vertex1[0] = vertex2[0] - len;
            vertex1[1] = vertex2[1];
        } else {
            vertex1[0] = vertex0[0] - len;
            vertex1[1] = vertex0[1];
        }
    } else {
        if (endX > startX) {
            vertex1[0] = vertex0[0] + len;
            vertex1[1] = vertex0[1];
        } else {
            vertex1[0] = vertex2[0] + len;
            vertex1[1] = vertex2[1];
        }
    }

    if (count == 1) {
        printf("%lf %lf\n", vertex0[0], vertex0[1]);
        printf("%lf %lf\n", vertex1[0], vertex1[1]);
        printf("%lf %lf\n", vertex2[0], vertex2[1]);
        printf("%lf %lf\n", endX, endY);
    } else if (count == 0) {
        // printf("%lf %lf\n", startX, startY);
        printf("%lf %lf\n", endX, endY);
    } else {
        /*printf("%lf %lf\n", vertex0[0], vertex0[1]);
        printf("%lf %lf\n", vertex1[0], vertex1[1]);
        printf("%lf %lf\n", vertex2[0], vertex2[1]);
        printf("%lf %lf\n", endX, endY);
        printf("\n");*/
        printKoch(count - 1, startX, startY, vertex0[0], vertex0[1]);
        printKoch(count - 1, vertex0[0], vertex0[1], vertex1[0], vertex1[1]);
        printKoch(count - 1, vertex1[0], vertex1[1], vertex2[0], vertex2[1]);
        printKoch(count - 1, vertex2[0], vertex2[1], endX, endY);
    }
}

int main() {
    int n;
    cin >> n;
    printf("%lf %lf\n", double(0), double(0));
    printKoch(n, 0, 0, 100.0, 0);
    return 0;
}