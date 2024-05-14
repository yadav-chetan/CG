#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

void circlePlotPoints (int xcen, int ycen, int x, int y, int col)
{
	putpixel (xcen + x, ycen + y, col);
	putpixel (xcen - x, ycen + y, col);
	putpixel (xcen + x, ycen - y, col);
	putpixel (xcen - x, ycen - y, col);
	putpixel (xcen + y, ycen + x, col);
	putpixel (xcen - y, ycen + x, col);
	putpixel (xcen + y, ycen - x, col);
	putpixel (xcen - y, ycen - x, col);
}

void circlemidpoint(int xcen, int ycen, int r)
{
	int x=0;
	int y=r;
	int p = 1 - r;
	circlePlotPoints (xcen, ycen, x, y, 3);
	
	while (x < y) {
	x++;
	if (p < 0)
		p += 2 * x + 2;
	else
	{
		y--;
		p += 2 * (x-y) + 5;
	}
	
	circlePlotPoints (xcen, ycen, x, y, 3);
	}
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    int r, xcen, ycen;

    cout << "Enter the radius of the circle: ";
    cin >> r;
    cout << "Enter coordinates of center: ";
    cin >> xcen >> ycen;

    circlemidpoint(xcen, ycen, r);

    getch();
    closegraph();

    return 0;
}


