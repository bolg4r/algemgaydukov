#include <stdio.h>
double modul(double u){
  return u<0 ?-1*u :u;
}

int main(void) {
  int n,l,k=0;
  double eps=0.0000001;
  scanf("%d",&n);
  double a[n][n+1];
  for (int i=0;i<n;i++){
    for (int j=0;j<n+1;j++){
      scanf("%lf",&a[i][j]);
    }
  }
  int i=0,j=0;
  for (int l=0;l<n;l++){
    double max=modul(a[l][l]);
    i=l;
    while (a[i][l]==0) {
      i++;
    }
    if (i!=l){
    for (int j = 0; j < n+1; j++) {
      double temp = a[l][j];
      a[l][j] = a[i][j];
      a[i][j] = temp;
    }
    }
    double cur=a[l][l];
    for (int i=l+1;i<n;i++){
        if ((cur<0?cur*(-1):cur) <eps) break;
        double koef=a[i][l]/cur;
        for (int j=l;j<n+1;j++){
          a[i][j]-=a[l][j]*koef;
        }
      }
  }
  /*for (int i=0;i<n;i++){
    for (int j=0;j<n+1;j++){
      printf("%lf ",a[i][j]);
    }
    printf("\n");
  }*/
  double ans[n];
  for (int i=n-1;i>=0;i--){
    if ((a[i][i]<0?a[i][i]*-1:a[i][i])> eps) ans[i]=a[i][n]/a[i][i];
    else ans[i]=0;
    for (int j=0;j<i;j++){
      a[j][n]-=a[j][i]*ans[i];
    }
  }
  for (int i=0;i<n;i++){
    printf("x[%d] = %0.11lf\n",i+1,ans[i]);
  }
  
  
  return 0;
}
