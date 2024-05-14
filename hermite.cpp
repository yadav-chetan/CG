#include<iostream>
#include<stdio.h>
#include<graphics.h>
#include<math.h>
using namespace std;

int main(){
    int x[4],y[4],i;
    double puty,putx,t;
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"C:\\TURBO3\\BGI");
    for ( i = 0; i < 4; i++)
    {
        cout<<"Enter X and Y coordinated of point ";		
        cin>>x[i]>>y[i];
        putpixel(x[i],y[i],3);
        
    }
    float t3,t2;
    for(t=0.0;t<=1.0;t+=0.001){
    	t3=pow(t,3);
    	t2=pow(t,2);
        putx=(2*t3-3*t2+1)*x[0]+ (3*t2-2*t3)*x[1]+ (t3-2*t2+t)*x[2]+ (t3-t2)*x[3];
        puty=(2*t3-3*t2+1)*y[0]+ (3*t2-2*t3)*y[1]+ (t3-2*t2+t)*y[2]+ (t3-t2)*y[3];
        cout<<puty<<endl;
        putpixel(putx,puty,WHITE);
    }
    getch();
    closegraph();
}
