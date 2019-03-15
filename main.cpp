#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>

#define PI 3.14159265
#define G 9.8

int main()
{
    initwindow(400, 300, "C\\TC\\BGI");
    double omega = 45.0;
    double teta = 0;
    int page = 0;

    double radyan = PI / 180;
    float t = 0;
    double x, y;

    while(true){
        setactivepage(page);
        setvisualpage(1 - page);

        cleardevice();
        teta = 75 * cos(omega * t * radyan);
        y = 150 * cos(teta * radyan);
        x = 150 * sin(teta * radyan);

        fillellipse(200 + x, 50 + y, 15, 15);

        char xPosText[80];
        sprintf(xPosText, "xPoz  : %lf", x);
        outtextxy(0, 0, xPosText);

        char yPosText[80];
        sprintf(yPosText, "yPoz  : %lf", y);
        outtextxy(0, 15, yPosText);

        char tetaText[80];
        sprintf(tetaText, "teta  : %lf", teta);
        outtextxy(0, 30, tetaText);

        double uzunluk = sqrt(pow(x, 2) + pow(y, 2));
        double period  = 2 * PI * sqrt(uzunluk / G);
        char periyodText[80];
        sprintf(periyodText, "Period : %lf", period);
        outtextxy(0, 45, periyodText);

        t += 0.005;
        page = 1 - page;
    }

    getch();
    closegraph();
    return 0;
}
