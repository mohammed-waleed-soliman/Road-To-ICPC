/// angle for regular polygon: angle = (n-2)*180/n
long double regular_polygon_angle(int no_of_sides){
    long double angle = ((no_of_sides-2)*180)/no_of_sides;
    return angle;
}