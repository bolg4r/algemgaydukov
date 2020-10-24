#include <stdio.h>

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
  for (int l=0;l<n;l++){
    double cur=a[l][l];
    for (int i=l+1;i<n;i++){
        if ((cur<0?cur*(-1):cur) <eps) break;
        double koef=a[i][l]/cur;
        for (int j=l;j<n+1;j++){
          a[i][j]-=a[l][j]*koef;
        }
      }
  }
  int u=0;
  printf("Базис:\n");
  for (int i=0;i<n;i++){
    int  t=1;
    for (int j=0;j<n+1;j++){
      printf("%lf ",a[i][j]);
      if (a[i][j] && t) {
        u++;
        t=0;
     }
    }
    printf("\n");
  }
  printf("Ранг: %d \n", u);
  int prov=1;
  double ans[n];
  for (int i=n-1;i>=0;i--){
    if ((a[i][i]<0?a[i][i]*-1:a[i][i])> eps) ans[i]=a[i][n]/a[i][i];
    else ans[i]=0;
    if (ans[i]==0) prov=0;
    for (int j=0;j<i;j++){
      a[j][n]-=a[j][i]*ans[i];
    }
  }
  if (prov) printf("Линейно независмая");
  else printf("Линейно зависимая");

  
  /*for (int i=0;i<n;i++){
    printf("%0.11lf\n",ans[i]);
  }*/
  

  
   
  return 0;
}
