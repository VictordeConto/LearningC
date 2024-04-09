 #include <stdio.h>
struct triangulo{
          int a, b, c;};
          typedef struct triangulo triangulo;

          triangulo setTria(int x, int y, int z){
          triangulo trg;
          trg.a = x;
          trg.b = y;
          trg.c = z;
          return trg;}

          int isTriangle(triangulo d){
          if(d.a + d.b > d.c && d.b + d.c > d.a && d.a + d.c > d.b){return 1;}
          else {return 0;}}

      int main(void)
      {
         int e = 16;
         int f = 20;
         int g = 30;
         if (isTriangle(setTria(e,f,g))==1){printf("verdade");}
         else{printf("falso");
         }
         return 0;}
