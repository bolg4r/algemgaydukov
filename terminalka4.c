#include <stdio.h>
double modul(double u){
  return u<0 ?-1*u :u;
}

int main(void) {
  int n,l,k=0;
  double eps=0.0000001;
  scanf("%d",&n);
  long double a[n][n];
  for (int i=0;i<n;i++){
    for (int j=0;j<n;j++){
      scanf("%Lf",&a[i][j]);
    }
  }
  int i=0,j=0;
  for (int l=0;l<n;l++){
    long double max=modul(a[l][l]);
    i=l;
    while (a[i][l]==0) {
      i++;
    }
    if (i!=l){
    for (int j = 0; j < n; j++) {
      long double temp = a[l][j];
      a[l][j] = a[i][j];
      a[i][j] = temp;
    }
    }
    long double cur=a[l][l];
    for (int i=l+1;i<n;i++){
        if (cur==0)break;
        long double koef=a[i][l]/cur;
        for (int j=l;j<n;j++){
          a[i][j]-=a[l][j]*koef;
        }
      }
  }
  long double  det=1;
  for (int i=0;i<n;i++){
    det*=a[i][i];
    for (int j=0;j<n;j++){
      printf("%Lf ",a[i][j]);
    }
    printf("\n");
  }
  printf("Определитель: %Lf", det);
  return 0;
}
