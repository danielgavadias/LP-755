#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "banco.c"
#include "calc.c"
#include "boletim.c"
#include "estacionamento.c"
//.\main.exe

int main() 
{  
int opcaomain;
system("cls"); 
    
    
    printf("\n==== MAIN ====");
    
    printf("\n1 - BOLETIM");
    printf("\n2 - CALCULADORA");
    printf("\n3 - BANCO");
    printf("\n4 - ESTACIONAMENTO");
    printf("\n0 - SAIR");
    printf("\nDigite aqui a opção que deseja selecionar: "); 
    scanf("%d", &opcaomain);
    
    switch(opcaomain)
    {
        case 1:
        boletim();
        break;
        
        case 2:
        calculadora();
        break;
        
        case 3:
        banco();
        break;

        case 4:
        estacionamento();
        break;

        case 0:
        printf("\nPROGRAMA FINALIZADO.");
        break;

        default:
        break;

    }
    return 0;
}
 
