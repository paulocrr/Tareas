#include <stdio.h>
#include <math.h>
#define N 20

struct Tpunto                   // punto en un plano, x abscisas, y ordenadas
{
    float x;
    float y;
};


float distancia_puntos(struct Tpunto x, struct Tpunto y);


void main()
{
    struct Tpunto p1, p2;
    p1.x=20.0;
    p1.y=30.0;
    p2.x=100.0;
    p2.y=40.0;
    printf("La distancia entre los puntos x1=%f ,y1=%f y x2=%f, y2=%f es %f",p1.x,p1.y,p2.x,p2.x, distancia_puntos(p1, p2));

    printf("\n\n");

}

float distancia_puntos(struct Tpunto punto1, struct Tpunto punto2)
{
    float resul=sqrt((pow(punto2.x-punto1.x, 2))+(pow(punto2.y-punto1.y, 2)));

    return resul;
}

