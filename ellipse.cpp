#include <iostream>
#include <graphics.h>
using namespace std;
#define ROUND(a) ((int)(a+0.5))

void ellipsePlotPoints(int xcen, int ycen, int x, int y) {
    putpixel(xcen + x, ycen + y, GREEN);
    putpixel(xcen - x, ycen + y, GREEN);
    putpixel(xcen + x, ycen - y, GREEN);
    putpixel(xcen - x, ycen - y, GREEN);
}

void ellipseMidpoint(int xcen, int ycen, int a, int b) {
    int a2 = a * a;
    int b2 = b * b;
    int twoa2 = 2 * a2;
    int twob2 = 2 * b2;
    double p1,p2;
    int x = 0;
    int y = b;
    // plotting the first set of points 
    ellipsePlotPoints(xcen, ycen, x, y);

    // region 1 
    p1 = ROUND(b2 - (a2 * b) + (0.25 * a2));
    while (a2*(y-0.5)> b2*(x+1)) {
        
        if (p1 < 0)
            p1 +=b2*(2*x+3) ;
        else {

            p1 += b2*(2*x+3)+a2*(2-(2*y));
            y--;
        }
        x++;
        ellipsePlotPoints(xcen, ycen, x, y);
    }

    // region 2
    p2 = ROUND((b2 * (x + 0.5) * (x + 0.5)) + (a2 * (y - 1) * (y - 1)) - a2 * b2);
    while (y > 0) {
        
        if (p2 < 0)
            {
				p2 += b2*(2*x+2)+a2*(3-(2*y));
            	x++;
            }
        else {
            p2+=a2*(3-(2*y));
        }
        y--;
        ellipsePlotPoints(xcen, ycen, x, y);
    }
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int a, b, xcen, ycen;

    cout << "Length of major axis of the ellipse: ";
  	cin >> a;
    cout << "Length of minor axis of the ellipse: ";
    cin >> b;
    cout << "Enter coordinates of center: ";
    cin >> xcen >> ycen;

    ellipseMidpoint(xcen, ycen, a, b);

    getch();
    closegraph();

    return 0;
}

