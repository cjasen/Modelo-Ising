#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    double a,b,c,beta,da,db,dc,sa,sb,sc,sbeta;
    a= -245484 ;
    b=312113  ;
    c= -132109 ;
    sa=5.651e+04  ;
    sb=7.372e+04 ;
    sc=3.204e+04 ;
    if(a<0) {
        beta=(-b/3/a)+sqrt((b*b/9/a/a)-(c*a/3/a/a));
        da=(b/3/a/a)+((c/3/a/a)-(2*b*b/9/a/a/a))/2/sqrt((b*b/9/a/a)-(c/3/a));
        db=b/9/a/a/sqrt((b*b/9/a/a)-(c/3/a))-(1/3/a);
        dc=-1/2/a/sqrt((b*b-(3*a*c))/a/a);
        sbeta=sqrt((da*da*sa*sa)+(db*db*sb*sb)+(dc*dc*sc*sc));
        printf("%lf %lf %lf\n",da,db,dc);
    }
    else {
        beta=(-b/3/a)-sqrt((b*b/9/a/a)-(c*a/3/a/a));
        da=(b/3/a/a)-((c/3/a/a)-(2*b*b/9/a/a/a))/2/sqrt((b*b/9/a/a)-(c/3/a));
        db=-b/9/a/a/sqrt((b*b/9/a/a)-(c/3/a))-(1/3/a);
        dc=1/2/a/sqrt((b*b-(3*a*c))/a/a);
        sbeta=sqrt((da*da*sa*sa)+(db*db*sb*sb)+(dc*dc*sc*sc));
    }
    printf("%lf \t %lf",beta,sbeta);
}
