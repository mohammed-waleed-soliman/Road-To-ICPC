#include<bits/stdc++.h>
using namespace std;
const double pi = acosl(-1.0);
#define EPS 1e-9 // optimize according to required precision 

struct point_i {
    int x, y;
    point_i() { x = y = 0; }
    point_i(int _x, int _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if(abs(x-other.x) > 0) return x < other.x;
        return y < other.y;
    }
    bool operator == (const point & other) const {
        return (abs(x-other.x) == 0) && (abs(y-other.y) == 0);
    }
};

struct point
{
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if(fabs(x-other.x) > EPS) return x < other.x;
        return y < other.y;
    }
    bool operator == (const point & other) const {
        return (fabs(x-other.x) < EPS) && (fabs(y-other.y) < EPS);
    }
};

/* distance between two points */
double dist (const point & p1, const point & p2) {
    return hypot(p1.x-p2.x, p1.y-p2.y);
}