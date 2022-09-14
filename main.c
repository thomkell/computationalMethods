// Thomas Keller 09/14/2022
// COMP526: Computational Methods for Scientists
// Assignment 2
#include <stdio.h>
#include <math.h> // math lib for pow and sqrt

// Functions
// Calculate the surface A of the triangle
double surfaceTriangle(double t, double x, int c){
    double a = c*t;
    double b = sqrt(pow((c*t),2)+pow(t,2));
    double d = 2*c*t;
    double s = (a+b+d)/2;

    double A = sqrt(s*(s-a)*(s-b)*(s-d));
    return A;
}

// Calculate function f(x)
double functionF(double x){
    double f = 1/(1+pow(x,2));
    return f;
}

// Calculate function h(x)
double functionH(double t, double x){
    double h = pow(t,2)+pow(x,2);
    return h;
}

// Solve Integrand
double Integrand(double t, double x, int c){
    double I = cos(x+c*t)-cos(x-c*t);
    return I;
}

// Main Function
int main() {

    printf("--------------------Input-----------------------\n");

    // Variable declaration
    int c = 2;
    double t = 7.2;
    double x = 5.4;
    printf("c = %f\n", c);
    printf("t = %f\n", t);
    printf("x = %f\n", x);

    printf("------------------------------------------------\n");

    // Calculate surface of triangle, input t, x, c
    double A = surfaceTriangle(t,x,c);
    printf("Surface A = %f\n", A);

    // Calculate function f(x), input x
    double f = functionF(x);
    printf("f(x) = %f\n", f);

    // Calculate function h(x), input t, x
    double h = functionH(t, x);
    printf("h(x) = %f\n", h);

    // Calculate Integrand, input t, x, c
    double I = Integrand(t, x, c);
    printf("Integrand = %f\n", I);

    // Calculate f(x), input x-ct & x+ct
    double f1 = functionF(x-c*t);
    double f2 = functionF(x+c*t);

    printf("-------------------Output-----------------------\n");

    // declaration of vertices: v1(x,t), v2(x-ct,0), v3(x+ct)
    double v1 = c*t;
    double v2 = sqrt(pow(c*t,2)+pow(t,2));
    double v3 = 2*c*t;

    // Calculate d'alembert Result
    double result = (0.5*f1+f2)+((1/(2*c))*I)+(1/(2*c))*(A/3)*(functionH(0.5*v1,0.5*v2)+functionH(0.5*v1,0.5*v3)+functionH(0.5*v2,0.5*v3));
    printf("Result of d'Alembert u(t,x) = %f\n", result);

    printf("------------------------------------------------\n");
    printf("------------------------------------------------\n");

    return 0;
}
