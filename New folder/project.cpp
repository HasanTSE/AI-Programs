#include<graphics.h>
#include<math.h>


void DrawCircle(int x, int y, int r)
{
    float theta;
    int x1, y1;
    for(int i = 0; i < 360; i++)
    {
        theta = i * 3.1416 / 180;
        x1 = x + r * cos(theta);
        y1 = y + r * sin(theta);
        putpixel(x1, y1, RED);
    }
}


void DrawEllipse(int x, int y, int a, int b)
{
    float theta;
    int x1, y1;
    for(int i = 0; i < 360; i++)
    {
        theta = i * 3.1416 / 180;
        x1 = x + a * cos(theta);
        y1 = y + b * sin(theta);
        putpixel(x1, y1, RED);
    }
}

void DrawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx, sy;

    if (x1 < x2) {
        sx = 1;
    }
    else {
        sx = -1;
    }

    if (y1 < y2) {
        sy = 1;
    }
    else {
        sy = -1;
    }

    int err = dx - dy;

    while (true) {
        putpixel(x1, y1, WHITE);

        if (x1 == x2 && y1 == y2) {
            break;
        }

        int e2 = 2 * err;

        if (e2 > -dy) {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y1 += sy;
        }
    }
}

void DrawSmilingFace() {
    // Draw the face circle
    circle(300, 300, 100);

    // Draw the eyes
    circle(265, 275, 10);
    circle(335, 275, 10);

    // Draw the mouth
    arc(300, 325, 220, 320, 50);
}


int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");

    outtextxy(100,50,"G");
   delay(1000); // Pause for 1 second
   outtextxy(120,50,"R");
   delay(1000); // Pause for 1 second
   outtextxy(140,50,"A");
   delay(1000); // Pause for 1 second
   outtextxy(160,50,"P");
   delay(1000); // Pause for 1 second
   outtextxy(180,50,"H");
   delay(1000); // Pause for 1 second
   outtextxy(200,50,"I");
   delay(1000); // Pause for 1 second
   outtextxy(220,50,"C");
   delay(1000); // Pause for 1 second
   outtextxy(240,50,"S");

    DrawCircle(200, 200, 100);
    DrawEllipse(200, 200, 100, 30);
    DrawLine(50, 50, 3000, 2000);
    DrawSmilingFace();

    getch();
    closegraph();
    return 0;
}

