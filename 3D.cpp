#include<stdio.h>
#include<graphics.h>
#include<iostream>
#include<cmath>
using namespace std;
const int MAX=100;
void readPolygon(int edges, int polygon[][4]) 
{
    cout << "Enter the coordinates of the vertices:\n";
    for (int i = 0; i < edges; ++i) 
	{
        cout << "Vertex " << i + 1 << ": ";
        cin >> polygon[i][0] >> polygon[i][1]>>polygon[i][2];
        polygon[i][3] = 1; // Set the homogenous coordinate to 1
    }
}
void drawPolygon(int edges,double polygon[][4]) 
{
    for (int i = 0; i < edges; ++i) 
	{
        int j = (i + 1) % edges; 
        line(polygon[i][0], polygon[i][1], polygon[j][0], polygon[j][1]);
    }
}
void drawPolygon(int edges, int polygon[][4]) 
{
    for (int i = 0; i < edges; ++i) 
	{
        int j = (i + 1) % edges; 
        line(polygon[i][0], polygon[i][1], polygon[j][0], polygon[j][1]);
    }
}
void printMatrix(int mat[][4], int r, int c)
	{
        for(int i =0 ; i < r; i++)
		{
            cout<<"[ ";
            for(int j = 0; j <c; j++)
			{
                cout<<mat[i][j]<<" ";
            }
            
            i==r-1 ? printf("](%d,%d)\n",r,c): printf("]\n");
        }
    }
void printMatrix(double mat[][4], int r, int c)
	{
        for(int i =0 ; i < r; i++)
		{
            cout<<"[ ";
            for(int j = 0; j <c; j++)
			{
                cout<<mat[i][j]<<" ";
            }
            
            i==r-1 ? printf("](%d,%d)\n",r,c): printf("]\n");
        }
    }
void multiply(int mat1[][4],double mat2[][4],double res[][4], int r1, int c1, int r2, int c2) {
    if (c1 != r2) {
        // Matrices cannot be multiplied
        cout << "Error: Incompatible matrix sizes for multiplication." << endl;
        return;
    }

    // Perform matrix multiplication
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            res[i][j] = 0;
            for (int k = 0; k < c1; ++k) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void pr(double mat[][4], int r, int c)
{
	for (int i=0;i<r;i++)
	{
		for(int j=0; j<c; j++)
		{
			mat[i][j]/=mat[i][3];	
		}
	}
}
int main()
{
 	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
	int edges;
	cout << "Enter the number of edges of the figure: ";
	cin>>edges;
	int figure[edges][4];
	double transformed[edges][4];
	readPolygon(edges, figure);
	printMatrix(figure,edges,4);
	drawPolygon(edges, figure);
	int choice;
    cout << "Choose the transformation:\n";
    cout << "1. Translation\n";
    cout << "2. Scaling\n";
    cout << "3. Rotation\n";
    cout << "4. Perspective Projection\n";
    cout << "5. Parallel Projection\n";
    
    double tx, ty, tz, sx, sy, sz,p,q,r;
    double x,f;
    int ch;
    double t[4][4]= {{1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
    setcolor(RED);
    do
    {
    	cout << "Enter your choice: ";
    	cin >> choice;
	    switch (choice) 
		{
	        case 1:
	            cout << "Enter the translation parameters (tx ty tz): ";
	            cin >> tx >> ty >> tz;
	            t[3][0]=tx;
	            t[3][1]=ty;
	            t[3][2]=tz;
	            multiply(figure,t,transformed,edges,4,4,4);
	            printMatrix(t,4,4);
	            cout<<"The transformed matrix is: "<<endl;
	            printMatrix(transformed,edges,4);
	            drawPolygon(edges, transformed);
	        	break;
	        case 2:
	            cout << "Enter the scaling factors (sx sy sz): ";
	            cin >> sx >> sy >> sz;
	            t[0][0]=sx;
	            t[1][1]=sy;
	            t[2][2]=sz;
	            multiply(figure,t,transformed,edges,4,4,4);
	            //printMatrix(t,4,4);
	            cout<<"The transformed matrix is: "<<endl;
	            printMatrix(transformed,edges,4);
	            drawPolygon(edges, transformed);
	            break;
	        case 3:
	        	cout << "Choose the rotation:\n";
			    cout << "1. x-axis\n";
			    cout << "2. y-axis\n";
			    cout << "3. z-axis\n";
			    cout<<"Enter your choice:";
			    cin>>ch;
	            cout << "Enter the rotation angle (in degrees): ";
	            cin >> x;
	            x = x * (M_PI / 180);
	            switch(ch)
	            {
	            	case 1: t[1][1]=cos(x);
	            			t[1][2]=sin(x);
	            			t[2][1]=-sin(x);
	            			t[2][2]=cos(x);
	            			break;
	            	case 2: t[0][0]=cos(x);
	            			t[2][0]=sin(x);
	            			t[0][2]=-sin(x);
	            			t[2][2]=cos(x);
	            			break;
	            	case 3: t[0][0]=cos(x);
	            			t[0][1]=sin(x);
	            			t[1][0]=-sin(x);
	            			t[1][1]=cos(x);
	            			break;
				}
		        multiply(figure,t,transformed,edges,4,4,4);
		        //printMatrix(t,4,4);
		        cout<<"The transformed matrix is: "<<endl;
	            printMatrix(transformed,edges,4);
		        drawPolygon(edges, transformed);
	            break;
	        case 4: 
	        		cout<<"Enter the value of projection points (p q r):";
	        		cin>>p>>q>>r;
	        		t[0][3]=p;
	        		t[1][3]=q;
	        		t[2][3]=r;
	        		t[2][2]=0;
	        		multiply(figure,t,transformed,edges,4,4,4);
	        		pr(transformed,edges,4);
	        		setcolor(RED);
	        		drawPolygon(edges, transformed);
	        		cout<<"The transformed matrix is: "<<endl;
	            	printMatrix(transformed,edges,4);
	        		break;
	        case 5: cout<<"Choose the following projections:"<<endl;
	        		cout<<"1. Orthographic "<<endl;
	        		cout<<"2. Oblique (taking angle to be 30 deg)"<<endl;
	        		cout<<"Enter your choice: ";
	        		cin>>ch;
	        		switch(ch)
	        		{
	        			case 1: t[2][2]=0;
	        					break;
	        			case 2: cout<<"Enter the value of f (forshortening factor): ";
	        					cin>>f;
	        					x=(M_PI / 180);
	        					t[2][0]=-f*cos(30*x);
	        					t[2][1]=-f*sin(30*x);
								t[2][2]=0;
								break;        					
	        		}
	        		multiply(figure,t,transformed,edges,4,4,4);
	        		pr(transformed,edges,4);
	        		setcolor(RED);
	        		drawPolygon(edges, transformed);
	        		cout<<"The transformed matrix is: "<<endl;
	            	printMatrix(transformed,edges,4);
	        		break;
	        default:
	            cout << "Invalid choice!";
	    }
	}while(choice<6);
    getch();
    closegraph();

    return 0;
}