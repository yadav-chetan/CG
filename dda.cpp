#include<iostream>
#include<math.h>
#include<graphics.h>
using namespace std;

void DDA(int x1, int y1, int x2, int y2) {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    float dx = x2 - x1;
    float dy = y2 - y1;

    int steps = max(abs(dx), abs(dy));

    float xi = dx / (float) steps;
    float yi = dy / (float) steps;

    float x = x1, y = y1;

    for (int i = 0; i <= steps; i++) {
        putpixel(round(x), round(y), YELLOW);
        x += xi;
        y += yi;
    }

    getch();
    closegraph();
}

int main() {
    int x1, y1, x2, y2;
   
    cout << "Enter the first coordinate (x1, y1): ";
    cin >> x1 >> y1;
    cout << "Enter the second coordinate (x2, y2): ";
    cin >> x2 >> y2;
    
    DDA(x1, y1, x2, y2);

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
