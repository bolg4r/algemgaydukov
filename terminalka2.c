#include <stdio.h>
#include<math.h>

int main(void) {
  double x1,x2,x3,y1,y2,y3,z1,z2,z3,k=0;
  scanf("%lf %lf %lf",&x1,&y1,&z1);
  scanf("%lf %lf %lf",&x2,&y2,&z2);
  scanf("%lf %lf %lf",&x3,&y3,&z3);
  /*scanf("%d %d %d ",&x2,&y2,&z2);
  scanf("%d %d %d ",&x3,&y3,&z3);*/
  int opr=x1*y2*z3+x3*y1*z2+x2*y3*z1-x3*y2*z1-x2*y1*z3-x1*z2*y3;
  if (opr==0){
    printf("Компланарны \n");
  } else printf("Не компланарны \n");
  if (y1*z2-z1*y2==0 && z1*x2-x1*z2==0 && x1*y2-z1*x2==0) {
    printf("первый и второй колллинеарны \n");
    k++;
  }
  if (y1*z3-z1*y3==0 && z1*x3-x1*z3==0 && x1*y3-z1*x3==0) {
    printf("третий и второй колллинеарны \n");
    k++;
  }
  if (y3*z2-z3*y2==0 && z3*x2-x3*z3==0 && x3*y2-z3*x2==0) {
    printf("первый и третий колллинеарны \n");
    k++;
  }
  if (k==3){
    printf("то есть все коллинеарны \n");
    printf("Ранг равен 1");
  } 
  if (k==1){
    printf("Ранг равен 2");
  }
  if (k==0){
    printf("Ранг равен 3");
  }
    return 0;
}
