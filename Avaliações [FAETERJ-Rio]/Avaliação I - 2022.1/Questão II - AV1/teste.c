#include <stdio.h>

void main () {
    
    int numero;
    int numeroAnterior;
    int cont = 1;
    
    printf("Insira um numero: ");
    scanf("%d", &numero);
    
    numeroAnterior = numero;
        
    while (numero != 0) {
        
        printf("Insira um numero: ");
        scanf("%d", &numero);
    
        if (numeroAnterior == numero) {
            cont++;
        }
        
        else {
            printf("%d - %d vezes\n", numeroAnterior, cont);
            cont = 1;
        }
    
        numeroAnterior = numero;
    }
}
