#include <stdio.h>
double modul(double u){
  return u<0 ?-1*u :u;
}

int main(void) {
  int n,m,l,k=0;
  double eps=0.0000001;
  scanf("%d %d",&m,&n );
  double a[n][m];
  for (int i=0;i<n;i++){
    for (int j=0;j<m;j++){
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
    for (int j = 0; j < m; j++) {
      double temp = a[l][j];
      a[l][j] = a[i][j];
      a[i][j] = temp;
    }
    }
    double cur=a[l][l];
    for (int i=l+1;i<n;i++){
        if ((cur<0?cur*(-1):cur) <eps) break;
        double koef=a[i][l]/cur;
        for (int j=l;j<m;j++){
          a[i][j]-=a[l][j]*koef;
        }
      }
  }
  printf("Базис: \n");
  int rank=0;
  for (int i=0;i<n;i++){
    int t=1;
    for (int j=0;j<m;j++){
      printf("%lf ",a[i][j]);
      if (a[i][j] && t){
        rank++;
        t=0;
      }
    }
    printf("\n");
  }
  printf("Ранг: %d \n", rank);
  /*double ans[n];
  for (int i=n-1;i>=0;i--){
    if ((a[i][i]<0?a[i][i]*-1:a[i][i])> eps) ans[i]=a[i][n]/a[i][i];
    else ans[i]=0;
    for (int j=0;j<i;j++){
      a[j][n]-=a[j][i]*ans[i];
    }
  }
  for (int i=0;i<n;i++){
    printf("%0.11lf\n",ans[i]);
  }
  */
  if (rank==m){
    printf("Линейно зависимая");
  } else printf("Линейно независимая");

  
  return 0;
}
