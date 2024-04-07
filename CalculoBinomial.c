#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>

unsigned long long int fatorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fatorial(n - 1);}

double calcularElevado(double z, double y){
  double resultado;
  resultado = pow(z,y);
  return resultado;
}

double converter_para_decimal(char *entrada) {
    double valor;
    int numerador, denominador;
    char *ptr;
    if (strchr(entrada, '/')) {
        numerador = strtol(entrada, &ptr, 10);
        denominador = strtol(ptr + 1, NULL, 10);
        valor = (double) numerador / denominador;
    } 
    else if (strchr(entrada, '%')) {
        valor = atof(entrada) / 100;
    } 
    else {
        valor = atof(entrada);
    }
    return valor;
}

int main() {
    int n, x;
    char entrada_p[20];
    printf("/// Calculo de distribuição binomial  ///\n");
    printf("Digite o valor de N (inteiro): ");
    scanf("%d", &n);
    printf("Digite o valor de P: ");
    scanf("%s", entrada_p);
    double p = converter_para_decimal(entrada_p); 
    printf("Digite o valor de X (inteiro): ");
    scanf("%d", &x);
    if (n < 0 || p < 0 || x < 0){
    printf("Digite valores positivos, não trabalhamos com probabilidades negativas!");
      return 0;
   
    }
    if (p > 1){
      p = p / 100;
    }

    unsigned long long int coeficiente_binomial = fatorial(n) / (fatorial(n - x) * fatorial(x));
    float calculoProbabilidade;
    calculoProbabilidade = coeficiente_binomial * calcularElevado(p, x) * calcularElevado(1 - p, n - x);
    double probabilidade_acumulada = 0.0;
    for (int i = 0; i <= x; ++i) {
        unsigned long long int coeficiente_binomial = fatorial(n) / (fatorial(n - i) * fatorial(i));
        double probabilidade = coeficiente_binomial * calcularElevado(p, i) * calcularElevado(1 - p, n - i);
        probabilidade_acumulada += probabilidade;
    }
    
    printf("A probabilidade de x ser igual a %d é: %.2f%\n", x, (calculoProbabilidade * 100));
    printf("A probabilidade de x ser menor ou igual a %d é: %.2f%\n", x, (probabilidade_acumulada * 100));
   

    return 0;
} 
