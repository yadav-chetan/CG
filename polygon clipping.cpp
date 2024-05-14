#include <iostream>
#include <graphics.h>
using namespace std;

int xmin = 100, ymin = 300, xmax = 500, ymax = 500;

// Function prototypes
void clipLeft(int poly[][2], int &n);
void clipRight(int poly[][2], int &n);
void clipTop(int poly[][2], int &n);
void clipBottom(int poly[][2], int &n);
void drawClippedPolygon(int poly[][2], int n);

int main() {
    int window1 = initwindow(800, 800); // Initialize graphics window

    rectangle(xmin, ymin, xmax, ymax); 

    int n;

    cout << "Enter the number of vertices: ";
    cin >> n;

    int poly[20][2];

    for (int i = 0; i < n; i++) {
        cout << "Enter the x-coordinate for vertex " << (i + 1) << ": ";
        cin >> poly[i][0];
        cout << "Enter the y-coordinate for vertex " << (i + 1) << ": ";
        cin >> poly[i][1];
    }

    // Close the polygon
    poly[n][0] = poly[0][0];
    poly[n][1] = poly[0][1];

    // Draw the original polygon
    drawpoly(n + 1, (int *)poly);

    delay(5000);

    // Clip the polygon against the edges of the clipping window
    clipLeft(poly, n);
    clipRight(poly, n);
    clipTop(poly, n);
    clipBottom(poly, n);

    // Draw the clipped polygon
    drawClippedPolygon(poly, n);

    closegraph(); 
    return 0; 
}

void clipLeft(int poly[][2], int &n) {
    int temp[20][2];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (poly[i][0] >= xmin || poly[(i + 1) % n][0] >= xmin) {
            if (poly[i][0] >= xmin) {
                temp[k][0] = poly[i][0];
                temp[k][1] = poly[i][1];
                k++;
            }
            if ((poly[i][0] >= xmin && poly[(i + 1) % n][0] < xmin) || 
                (poly[i][0] < xmin && poly[(i + 1) % n][0] >= xmin)) {
                float m = (float)(poly[(i + 1) % n][1] - poly[i][1]) / (poly[(i + 1) % n][0] - poly[i][0]);
                temp[k][0] = xmin;
                temp[k][1] = poly[i][1] + (int)((xmin - poly[i][0]) * m);
                k++;
            }
        }
    }
    n = k;
    for (int i = 0; i < n; i++) {
        poly[i][0] = temp[i][0];
        poly[i][1] = temp[i][1];
    }
}

void clipRight(int poly[][2], int &n) {
    int temp[20][2];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (poly[i][0] <= xmax || poly[(i + 1) % n][0] <= xmax) {
            if (poly[i][0] <= xmax) {
                temp[k][0] = poly[i][0];
                temp[k][1] = poly[i][1];
                k++;
            }
            if ((poly[i][0] <= xmax && poly[(i + 1) % n][0] > xmax) || 
                (poly[i][0] > xmax && poly[(i + 1) % n][0] <= xmax)) {
                float m = (float)(poly[(i + 1) % n][1] - poly[i][1]) / (poly[(i + 1) % n][0] - poly[i][0]);
                temp[k][0] = xmax;
                temp[k][1] = poly[i][1] + (int)((xmax - poly[i][0]) * m);
                k++;
            }
        }
    }
    n = k;
    for (int i = 0; i < n; i++) {
        poly[i][0] = temp[i][0];
        poly[i][1] = temp[i][1];
    }
}

void clipBottom(int poly[][2], int &n) {
    int temp[20][2];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (poly[i][1] >= ymin || poly[(i + 1) % n][1] >= ymin) {
            if (poly[i][1] >= ymin) {
                temp[k][0] = poly[i][0];
                temp[k][1] = poly[i][1];
                k++;
            }
            if ((poly[i][1] >= ymin && poly[(i + 1) % n][1] < ymin) || 
                (poly[i][1] < ymin && poly[(i + 1) % n][1] >= ymin)) {
                float m = (float)(poly[(i + 1) % n][0] - poly[i][0]) / (poly[(i + 1) % n][1] - poly[i][1]);
                temp[k][0] = poly[i][0] + (int)((ymin - poly[i][1]) * m);
                temp[k][1] = ymin;
                k++;
            }
        }
    }
    n = k;
    for (int i = 0; i < n; i++) {
        poly[i][0] = temp[i][0];
        poly[i][1] = temp[i][1];
    }
}

void clipTop(int poly[][2], int &n) {
    int temp[20][2];
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (poly[i][1] <= ymax || poly[(i + 1) % n][1] <= ymax) {
            if (poly[i][1] <= ymax) {
                temp[k][0] = poly[i][0];
                temp[k][1] = poly[i][1];
                k++;
            }
            if ((poly[i][1] <= ymax && poly[(i + 1) % n][1] > ymax) || 
                (poly[i][1] > ymax && poly[(i + 1) % n][1] <= ymax)) {
                float m = (float)(poly[(i + 1) % n][0] - poly[i][0]) / (poly[(i + 1) % n][1] - poly[i][1]);
                temp[k][0] = poly[i][0] + (int)((ymax - poly[i][1]) * m);
                temp[k][1] = ymax;
                k++;
            }
        }
    }
    n = k;
    for (int i = 0; i < n; i++) {
        poly[i][0] = temp[i][0];
        poly[i][1] = temp[i][1];
    }
}

void drawClippedPolygon(int poly[][2], int n) {
	
	poly[n][0] = poly[0][0];
    poly[n][1] = poly[0][1];
    // Draw the clipped polygon
    setcolor(GREEN);
    drawpoly(n+1, (int *)poly);
    delay(5000);
}

