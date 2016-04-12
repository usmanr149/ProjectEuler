#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

double calculateintercept(double slope, double x, double y){
  double intercept;
  intercept= y-slope*x;
  return intercept;
}

double calculateslope(double xi, double yi, double xf, double yf){
  double slope = (yf-yi)/(xf-xi);
  return slope;

}

double calcualtexell(double m, double b, double e, double f, double c, int zig){
  double x;
  if(zig == 1)  x = (-(2*m*b*f) + sqrt(4*m*m*b*b*f*f - 4*(m*m*f+e)*(b*b*f-c)))/(2*(m*m*f+e));
  if(zig == -1) x = (-(2*m*b*f) - sqrt(4*m*m*b*b*f*f - 4*(m*m*f+e)*(b*b*f-c)))/(2*(m*m*f+e));
  return x;
}


double ellipsederivative(double e, double f, double x, double y){
  double der = -e*x/(f*y);
  return der;
}

int main(){

  //c = ex^2+fy^2
  double c = 100, e = 4, f =1;
  //y=m*x+b
  double m, b;

  double x, y;

  double xell = 1, yell = -1;
  int count = 1;
  m = calculateslope(0.0, 10.1, 1.4, -9.6);
  b = calculateintercept(m, 0.0, 10.1);
    
  //find the point of intersection
  //(mx+b)^2 = (e*x^2-c)/f
  xell = calcualtexell(m, b, e, f, c, 1);
  yell = -sqrt((c - e*xell*xell)/f);

  while( xell>=0.01 || xell<=-0.01 || yell < 0 ){
    //calulate the dervative of the ellipse at the point of intersection
    double ellipseder = ellipsederivative(e, f, xell, yell); //this is the slope that is the derivative
    
    double angle = atan(ellipseder);
    //find the angle that the incoming light makes with the slope of ellipse
    double angle2 = atan(m); //this will give the angle light make with the x-axis
    
    angle2=angle2-angle;
    
    //new slope
    m = tan(-(angle2)+angle);
    b = calculateintercept(m, xell, yell);
  
    double xella = calcualtexell(m, b, e, f, c, 1);
    //find the point of intersection
    //(mx+b)^2 = (e*x^2-c)/f
    if((xella - xell) > -0.001 && (xella - xell) < 0.001){
      xell = calcualtexell(m, b, e, f, c, -1);
    }
    else xell = xella;
   
    yell = m*xell+b;
    printf("\nxell = %f\n", xell);
    printf("yell = %f\n", yell);
    printf("count = %d\n", count);
    count++;
    //getchar();
  }
}
