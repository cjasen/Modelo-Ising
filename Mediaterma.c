#include <stdio.h>
#include <stdlib.h>

#define D 100
#define h 10

void med_var(double *serie, int N, double *media, double *varianza, double *varianza_est);

int main(){
    int i;
    double medias[h];
    double varianzas[h];
    double varianzas_est[h];
    FILE *datos;
    FILE *resultados;
    double s[D];
    int n[D];
    if((datos=fopen("magnetizacion.txt","rt"))==NULL){
        printf("el archivo de los datos no existe");
        exit(1);
    }
    else{
        for(i=0;i<D;i++){
            fscanf(datos,"%d %lf",&n[i],&s[i]);
        }
        for(i=0;i<h;i++){
            med_var(&s[i*D/h],D/h,&medias[i],&varianzas[i],&varianzas_est[i]);
        }
        /**
        med_var(s,D/h,&medias[0],&varianzas[0],&varianzas_est[0]);
        med_var(&s[D/h],D/4,&medias[1],&varianzas[1],&varianzas_est[1]);
        med_var(&s[2*D/h],D/4,&medias[2],&varianzas[2],&varianzas_est[2]);
        med_var(&s[3*D/4],D/4,&medias[3],&varianzas[3],&varianzas_est[3]);*/
        if((resultados=fopen("resultantes.txt","wt"))==NULL){
            printf("no creo el archivo");
            exit(2);
        }
        else{
            for(i=0;i<h;i++)
                fprintf(resultados,"%lf\t%lf\t%lf\n",medias[i],varianzas[i],varianzas_est[i]);
        }
        fclose(resultados);
    }
    fclose(datos);
}

void med_var(double *serie, int N, double *media, double *varianza, double *varianza_est)
{
    int i;
    double suma;
    suma=0;
    for(i=0;i<N;i++)
        suma+=serie[i];
    *media=(double)suma/N;
    for(i=0;i<N;i++)
        *varianza+=serie[i]*serie[i]-(*media*(*media));
    *varianza=(*varianza)/(N-1);
    *varianza_est=(*varianza)/N;
}
