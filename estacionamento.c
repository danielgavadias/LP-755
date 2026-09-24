#include <stdio.h>
#include <stdlib.h>
//=============================================================================

char placa[10], CM; int horasPRV; // Características dos veículos

float fatPHVG, fatPHCT, fatPHMT, fatD, fatT; //Faturamentos: Veiculos no geral, Carro total, Moto total, Diário, Total

int EstOpcaoMel; char EstApagarD, EstEncerrarD, lixo; // Continuidade

int QualV, quantC, quantM, quantVT; // Quantidade de veículos

int i, dia;

//=============================================================================
void carregarV(void);
int estacionamento(void);
int EstacionamentoCodigo(void);
int registroEst(void);
int saidaEst(void);
int consultarEst(void);
int faturamentoEst(void);
int encerrarDiaEst(void);
//=============================================================================
FILE *EstHistorico;
FILE *EstInfoVeic;
FILE *EstGuardarVariaveis;
//=============================================================================
void carregarV()
{
        EstGuardarVariaveis = fopen("arquivos/EstGuardarVariaveis.txt", "r");
        if (EstGuardarVariaveis == NULL)
        {
            printf("Erro ao abrir o arquivo!\n");
            return;
        }
        fscanf(EstGuardarVariaveis,"%d %d %d %f %f %f %f %d", &quantC, &quantM, &quantVT, &fatPHCT, &fatPHMT, &fatT, &fatD, &dia);
        fclose(EstGuardarVariaveis);   
}
int estacionamento()
{
    carregarV();
    EstacionamentoCodigo();
    return 0;
}
//=============================================================================
int EstacionamentoCodigo()
{
    //=============================================================================
    system("cls");
    //=============================================================================
    printf("\n=== ESTACIONAMENTO SENAI ===\n");
    printf("Dia %d", dia);
    printf("\n1 - REGISTRAR ENTRADA");
    printf("\n2 - REGISTRAR SAÍDA");
    printf("\n3 - CONSULTAR SITUAÇÃO");
    printf("\n4 - EXIBIR FATURAMENTO");
    printf("\n5 - ENCERRAR O DIA");
    printf("\n6 - SAIR");
    printf("\n0 - APAGAR TODOS OS DADOS DO SISTEMA\n");

    printf("\nDigite aqui: ");

    scanf(" %d", &EstOpcaoMel);
    //=============================================================================
    switch (EstOpcaoMel)
    {
    case 1:
        registroEst();
    break;
    //=============================================================================
    case 2:
         saidaEst();
    break;
    //=============================================================================
    case 3:
         consultarEst();
    break;
    //=============================================================================
    case 4:
         faturamentoEst();
    break;
    //=============================================================================
    case 5:
         encerrarDiaEst();
    break;
    //=============================================================================
    case 0:
    printf("\nTEM CERTEZA DE QUE QUER APAGAR TODOS OS DADOS?(s/n) "); 
        
        scanf(" %c", &EstApagarD);
        switch(EstApagarD)
        {
        case 's':
            EstHistorico = fopen("arquivos/EstHistorico.txt", "w"); fclose(EstHistorico);
            EstGuardarVariaveis = fopen("arquivos/EstGuardarVariaveis.txt", "w"); fclose(EstGuardarVariaveis);
            EstInfoVeic = fopen("arquivos/EstInfoVeic.txt", "w"); fclose(EstInfoVeic);
            fatPHVG = 0;
            fatPHCT = 0;
            fatPHMT = 0;
            fatD = 0;
            fatT = 0;
            dia = 0;
            quantC = 0;
            quantM = 0;
            quantVT = 0;
            
            EstGuardarVariaveis = fopen("arquivos/EstGuardarVariaveis.txt", "w");
            fprintf(EstGuardarVariaveis, "%d %d %d %f %f %f %f %d", quantC, quantM, quantVT, fatPHCT, fatPHMT, fatT, fatD, dia);
            fclose(EstGuardarVariaveis);

            printf("FINALIZADO! Digite qualquer tecla para voltar a tela inical: ");  scanf(" %c", &lixo);
            EstacionamentoCodigo();
        break;
    
        case 'n':
             EstacionamentoCodigo();
        break;
    
        default:
        break;
        }
    break;
    //=============================================================================
    case 6:
             printf("\nvai toma no cu\n");
             EstGuardarVariaveis = fopen("arquivos/EstGuardarVariaveis.txt", "w");
             fprintf(EstGuardarVariaveis, "%d %d %d %f %f %f %f %d", quantC, quantM, quantVT, fatPHCT, fatPHMT, fatT, fatD, dia);
             fclose(EstGuardarVariaveis);
    break;
    }
    //=============================================================================
}
//=============================================================================
int registroEst()
{
    if(quantVT<20)
    {
        EstInfoVeic = fopen("arquivos/EstInfoVeic.txt", "a");
        EstHistorico = fopen("arquivos/EstHistorico.txt", "a");
        
        //system("cls");
        //=============================================================================
        if (EstHistorico == NULL)
        {
            printf("\nErro ao abrir o arquivo!H\n");
        }
        if (EstInfoVeic == NULL)
        {
            printf("\nErro ao abrir o arquivo!I\n");
        }
        //=============================================================================
        printf("\n=== REGISTRO ===\n");
    
        printf("\nQual a placa do veiculo que deseja registrar? ");
        scanf("%9s", placa);
        
        printf("Qual o tipo do veiculo que deseja registrar?(c/m) ");
        scanf(" %c", &CM);
    
        while (CM != 'c' && CM != 'm')
        {
            printf("Apenas carros(c) e motos(m) são validos! Digite um tipo de veículo válido: ");
            scanf(" %c", &CM);
        }
    
        printf("Quantas horas pretende ficar? ");
        scanf("%d", &horasPRV);
        switch (CM) //valorPH e quant++
        {
            case 'c':
                fatPHVG = (horasPRV * 5) + 10;
                fatD += fatPHVG;
                fatPHCT += fatPHVG;
                quantC++;
            break;
            case 'm':
                fatPHVG = (horasPRV * 4) + 12;
                fatD += fatPHVG;
                fatPHMT += fatPHVG;
                quantM++;
            break;
        }
        fatT += fatPHVG;
        
        quantVT++;
        fprintf(EstInfoVeic, "Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %.2f\n", placa, CM, horasPRV, fatPHVG);
        fprintf(EstHistorico, "ENTRADA: Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %.2f\n", placa, CM, horasPRV, fatPHVG);
    
        //=============================================================================
        printf("\nREGISTRO COMPLETO.\n");
        //=============================================================================
        fclose(EstHistorico);
        fclose(EstInfoVeic);
        //=============================================================================
        printf("\nDeseja fazer outro registro?(s/n) "); 
            char EstContReg;
            scanf(" %c", &EstContReg);
            switch (EstContReg)
            {
            case 's':
                registroEst();
            break;
        
            default:
            EstacionamentoCodigo();
            break;
        }
    }
    else
    {
        printf("ESTACIONAMENTO LOTADO!");
        printf("\n\nDigite qualquer tecla para voltar para o menu: ");
        scanf(" %c", &lixo);
        EstacionamentoCodigo();
    }
    
        return 0;
}
//=============================================================================
int saidaEst()
{
    if((quantC+quantM) != 0)
    {
    EstHistorico = fopen("arquivos/EstHistorico.txt", "r");
    EstInfoVeic = fopen("arquivos/EstInfoVeic.txt", "r");
    //system("cls");
    //=============================================================================
    if (EstHistorico == NULL)
    {
        printf("\nErro ao abrir o arquivo!H\n");
    }
    if (EstInfoVeic == NULL)
    {
        printf("\nErro ao abrir o arquivo!I\n");
    }
    //=============================================================================
    printf("\n=== SAIDA ===\n");
    i = 0;        
        while (fscanf(EstInfoVeic, "Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %f\n", placa, &CM, &horasPRV, &fatPHVG)  == 4)
        {
            i++;
            printf("\n=== Veículo N°%d ===", i);
            printf("\nPlaca: %10s", placa);
            printf("\nHoras previstas: %d", horasPRV);
            printf("\nTipo do Veículo: %c\n", CM);
        }
    fclose(EstHistorico);
    fclose(EstInfoVeic);
    //=============================================================================
    FILE *EstTemporario;
    EstHistorico = fopen("arquivos/EstHistorico.txt", "a");
    EstInfoVeic = fopen("arquivos/EstInfoVeic.txt", "r");
    EstTemporario = fopen("arquivos/EstTemporario.txt", "w");

    printf("\nQual veiculo desejas retirar? ");
    scanf("%d", &QualV);
    //=============================================================================
    i = 0;
    //=============================================================================
    
    while (fscanf(EstInfoVeic, "Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %f\n", placa, &CM, &horasPRV, &fatPHVG) == 4)
    {
        i++;
            if (i != QualV)
                {
                    fprintf(EstTemporario, "Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %f\n", placa, CM, horasPRV, fatPHVG);
                }
            
            else
                {
                    fprintf(EstHistorico, "SAÍDA: Placa: %10s | VeiculoC/M: %c | horasPRV: %d | valorPH: %f\n", placa, CM, horasPRV, fatPHVG);
                    if(CM=='c')
                    {
                        quantC--;
                    }
                    
                    else
                    {
                        quantM--;
                    }
                }
    }
    //=============================================================================
    fclose(EstInfoVeic);
    fclose(EstHistorico);
    fclose(EstTemporario);
    remove("arquivos/EstInfoVeic.txt");
    rename("arquivos/EstTemporario.txt", "arquivos/EstInfoVeic.txt");
    
    printf("\nDeseja fazer outra saída?(s/n) "); 
        char EstContSaida;
        scanf(" %c", &EstContSaida);
        switch (EstContSaida)
        {
        case 's':
            saidaEst();
        break;
    
        default:
            EstacionamentoCodigo();
        break;
        }
    }
    else
    {
        printf("\nImpossivel realizar saídas com o estacionamento vazio.");
        printf("\n\nDigite qualquer tecla para voltar para o menu: ");
        scanf(" %c", &lixo);
        EstacionamentoCodigo();
    }
    return 0;
}
//=============================================================================
int consultarEst()
{
    EstHistorico = fopen("arquivos/EstHistorico.txt", "r");
    printf("\n===SITUAÇÂO GERAL ===\n");

    if (EstHistorico == NULL)
    {
        printf("\nErro ao abrir o arquivo!\n");
    }

    printf("\nVagas ocupadas por motos: %d/20", quantM);
    printf("\nVagas ocupadas por carros: %d/20", quantC);
    printf("\nVagas ocupadas: %d/20", quantC + quantM);
    printf("\nVagas livres: %d/20", 20 - (quantC + quantM));
    printf("\nQuantidade total de veículos que já passaram pelo estacionamento Senai: %d",  quantVT);
    printf("\nFaturamento total acumulado: %.2f", fatT);

    printf("\n\nDigite qualquer tecla para voltar para o menu: ");
    scanf(" %c", &lixo);
    fclose(EstHistorico);
    EstacionamentoCodigo();
}
//=============================================================================
int faturamentoEst()
{
    EstHistorico = fopen("arquivos/EstHistorico.txt", "r");
    printf("\n===SITUAÇÂO GERAL ===\n");

    printf("COMO É FEITA A COBRANÇA: ");
    printf("\nCARROS : (HORAS PREVISTAS * 5) + 10(TAXA FIXA)");
    printf("\nMOTOS: (HORAS PREVISTAS * 4) + 12(TAXA FIXA)\n");
    
    printf("\nFaturamento sobre as motos: %.2f", fatPHMT);
    printf("\nFaturamento sobre os carros: %.2f", fatPHCT);
    printf("\nFaturamento do Dia(%d): %.2f", dia, fatD);
    printf("\nFaturamento Total: %f", fatT);

    printf("\nDigite qualquer tecla para voltar para o menu: ");
    scanf(" %c", &lixo);
    fclose(EstHistorico);
    EstacionamentoCodigo();
}
//=============================================================================
int encerrarDiaEst()
{   
    FILE *EstFatHistorico;
    //=============================================================================
    EstFatHistorico = fopen("arquivos/EstFatHistorico.txt", "a");
    printf("\nTem certeza de que quer encerrar o dia?(s/n) "); 
    scanf(" %c", &EstApagarD);
    //=============================================================================
        switch(EstApagarD)
        {
        case 's':
            
            fprintf(EstFatHistorico, "Dia %d: %.2f\n", dia, fatD);
            printf("\nFaturamento do dia: %.2f\nDia encerrado!", fatD);
            fatD = 0;
            dia++;
        break;
        //=============================================================================
        default:
            
            EstacionamentoCodigo();
        break;
        }
    fclose(EstFatHistorico);
    printf("Digite qualquer tecla para voltar para o menu: ");
    scanf(" %c", &lixo);
    EstacionamentoCodigo();
}