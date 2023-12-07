/*
TEKST ZADATKA I TEST CASEOVI: https://github.com/emanuelkufrin/tvz_c-2023/blob/8e1758dff62200e0fb85c9d59919ad2d29e44cba/tekstovi%20i%20test%20caseovi/%5B5%5DTo%C4%8Dke%201.PDF
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

double udaljenost(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void sjeciste(double a1, double b1, double a2, double b2)
{
    double xs = (b2 - b1) / (a1 - a2);
    double ys = a1 * xs + b1;
    
    printf("Ts(%.2f, %.2f)\n", xs, ys);
}

int main()
{
    int n;
    scanf("%d", &n);

    double tocke[150][2];

    for (int i = 0; i < n; i++)
    {
        scanf("%lf %lf", &tocke[i][0], &tocke[i][1]);
    }

    double najudaljeniji = 0;
    double najblizi = 2000000;

    double p1x, p1y, p2x, p2y;
    double p3x, p3y, p4x, p4y;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double trenutna_udaljenost = udaljenost(tocke[i][0], tocke[i][1], tocke[j][0], tocke[j][1]);

            if (trenutna_udaljenost > najudaljeniji)
            {
                    najudaljeniji = trenutna_udaljenost;
                    p1x = tocke[i][0];
                    p1y = tocke[i][1];     
                    p2x = tocke[j][0];
                    p2y = tocke[j][1];
            }
            if (trenutna_udaljenost < najblizi && trenutna_udaljenost > 0)
            {
                najblizi = trenutna_udaljenost;
                p3x = tocke[i][0];
                p3y = tocke[i][1];
                p4x = tocke[j][0];
                p4y = tocke[j][1];
                
            }
        }
    }

    double a1 = (p2y - p1y) / (p2x - p1x);
    double b1 = p1y - a1 * p1x;
    double a2 = (p4y - p3y) / (p4x - p3x);
    double b2 = p3y - a2 * p3x;

    sjeciste(a1, b1, a2, b2);

}
