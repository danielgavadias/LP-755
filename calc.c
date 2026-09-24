#include <stdio.h>
#include <stdlib.h>

float n1=0, n2=0, resultado=0;
char opcaocalc;
char ContinuarCalc, GRopcao = 's', GRexclusao = 0, lixo;

int calculos(void);

void calculadora()
{
    //system("cls");
    
    printf("\n====CALCULADORA====\n");
    printf("\nQual operação desejas resolver? ");
    printf("\nAdição(+)");
    printf("\nSubtração(-)");
    printf("\nMultiplicação(*)");
    printf("\nDivisão(/)");
    printf("\nDigite qualquer outra tecla para sair do Menu.");
    printf("\nDigite aqui: "); 
    scanf(" %c", &opcaocalc);

    calculos();
}   
//=======================================================
int calculos()
{
//=======================================================
    switch (GRexclusao)
    {
        case 1:
        n1 = resultado;
        break;
        
        default:
        printf("\nQual o primeiro valor? "); 
        scanf("%f", &n1); 
        break;
    }
      
    printf("\nQual o segundo valor? "); 
    scanf("%f", &n2);
//=======================================================
    switch(opcaocalc) //calculos
    {    
    
    case '+':
    printf("%.2f + %.2f = %.2f", n1, n2, n1+n2);
    resultado = n1+n2;
    break;
    
    case '-':
    printf("%.2f - %.2f = %.2f", n1, n2, n1-n2);
    resultado = n1-n2;
    break;
    
    case '*':
    printf("%.2f * %.2f = %.2f", n1, n2, n1*n2);
    resultado = n1*n2;
    break;
  
    case '/':
    while(n2==0)
    {
    printf("\nImpossível dividir por 0! Insira um valor válido: "); scanf("%f", &n2);
    }
    printf("%.2f / %.2f = %.2f", n1, n2, n1/n2);
    resultado = n1/n2;
    break;
    
    default:
    printf("Programa finalizado.");  
    break;
    } 
//=======================================================
    printf("\nDeseja fazer outra operação?(s/n) "); 
    scanf(" %c", &ContinuarCalc);
//=======================================================
    switch (ContinuarCalc) 
    {
    case 's':
        printf("Deseja armazernar o resultado?(s/n) "); 
        scanf(" %c", &GRopcao);
        
        switch(GRopcao) //guardar resultado opção
        {
            case 's':
            GRexclusao = 1;;
            calculadora();
            break;

            case 'n':
            GRexclusao = 0;
            resultado = 0;
            calculadora();
            break;

            default:
            printf("digite s ou n.");
            break;
        }
        
    break;

    case 'n':
        printf("Programa finalizado.");
    break;
    
    default:
    break; 
    }
//=======================================================
    return 0;
//=======================================================
}

