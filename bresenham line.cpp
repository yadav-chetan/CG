#include<iostream>
#include<graphics.h>
using namespace std;

void bresenham(int x, int y, int x2, int y2)
{
    int dx = abs(x2 - x);
    int dy = abs(y2 - y);
    int p;

    if (dx >= dy) // If the slope is less than or equal to 1
    {
        p = 2 * dy - dx; // Initial decision parameter
        int incr = y2 >= y ? 1 : -1; // Increment direction for y

        if (x2 < x) // Swap points if x2 is less than x
        {
            swap(x, x2);
            swap(y, y2);
        }

        putpixel(x, y, GREEN); // Plot the starting point

        for (int i = x + 1; i <= x2; ++i)
        {
            if (p < 0) // If p is negative, move towards the line
                p += 2 * dy;
            else // If p is non-negative, move towards the line and increment y
            {
                p += 2 * (dy - dx);
                y += incr;
            }
            putpixel(i, y, GREEN); // Plot the pixel
        }
    }
    else // If the slope is greater than 1
    {
        p = 2 * dx - dy; // Initial decision parameter
        int incr = x2 >= x ? 1 : -1; // Increment direction for x

        if (y2 < y) // Swap points if y2 is less than y
        {
            swap(x, x2);
            swap(y, y2);
        }

        putpixel(x, y, GREEN); // Plot the starting point

        for (int i = y + 1; i <= y2; ++i)
        {
            if (p < 0) // If p is negative, move towards the line
                p += 2 * dx;
            else // If p is non-negative, move towards the line and increment x
            {
                p += 2 * (dx - dy);
                x += incr;
            }
            putpixel(x, i, GREEN); // Plot the pixel
        }
    }
}


int main() {
	
	int gd=DETECT,gm;
	initgraph(&gd,&gm,(char*)"");
	
    int x1, y1, x2, y2;

    cout << "Enter the first coordinate (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the second coordinate (x2, y2): ";
    cin >> x2 >> y2;

    bresenham(x1, y1, x2, y2);
    
    getch(); 
	closegraph();

    return 0;
}


/* Horizontal Line: (100, 150) and (200, 150)
Vertical Line: (150, 100) and (150, 200)
Positive Slope Line: (100, 100) and (200, 200)
Negative Slope Line: (100, 200) and (200, 100)
Steep Slope Line: (100, 100) and (100, 200)
Shallow Slope Line: (100, 100) and (200, 120)
Diagonal Line: (120, 120) and (220, 220)
Endpoint Reversal: (200, 120) and (120, 220)
Horizontal Line Reversed: (200, 150) and (100, 150)
Vertical Line Reversed: (150, 200) and (150, 100) */
