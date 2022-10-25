#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <locale.h>

typedef struct data{
    int dia;
    int mes;
    int ano;
}DATA1;


//Funcao para fazer a leitura do primeiro conjunto de data;
void leituraData(DATA1 *d1,  DATA1 *d2){
    printf("DIGITE A PRIMEIRA DATA DD/MM/AAAA:  ");
    scanf("%d/%d/%d", &d1->dia, &d1->mes, &d1->ano);
    printf("DIGITE A SEGUNDA DATA DD/MM/AAAA:  ");
    scanf("%d/%d/%d", &d2->dia, &d2->mes, &d2->ano);

}

//funcao para transformar cada casa da data em dias
int calculaDias(DATA1 d1){
    int dias_mes[13] = {0, 31, 59, 90, 120,  151, 181, 212, 243, 273, 304, 334, 365};//convetendo os meses mesAtual + proximo mes
    int dias_convert;

    dias_convert = d1.dia;
    dias_convert += dias_mes[d1.mes - 1];
    dias_convert += d1.ano * 365;//
    //printf("%d\n", dias_convert); Teste para ver se a data foi convertida
    return dias_convert;
}
//funcao para verificar se o ano é bissexto
int verificaBissexto(int ano){
    if(ano % 400 == 0){
        return 1;
    }else if((ano % 4 == 0) && (ano % 100 != 0)){
            return 1;
    }else{
            return 0;
    }

}
//assumindo que d2 é sempre maior que d1
int verificaQuantBissexto(DATA1 d1, DATA1 d2){
    int cont;
    int quantBissexto = 0;
    if(d1.mes > 2){
        d1.ano += 1;
    }
    if(d1.mes == 2 && d1.dia == 29){
            d1.ano += 1;
        }
    if(d2.mes <= 2){
        d2.ano += 1;
    }
    for(cont = d1.ano; cont <= d2.ano; cont++){
        if(verificaBissexto(cont)){
            quantBissexto += 1;
        }
    }

    return quantBissexto;

}
/*void imprimeData(DATA1 d1){
    printf("Dia: %d\n", d1.dia);
    printf("Mes: %d\n", d1.mes);
    printf("Ano: %d\n", d1.ano);
}
*/
int main(){
    setlocale(LC_ALL, "Portuguese");
    DATA1 d1;
    DATA1 d2;

    int valorDias1, valorDias2, quantBissexto;
    do{//do while usado para verificar se é uma data valida(data 2 maior que data 1)
        printf("\n----------------------------DIGITE AS DATAS----------------------------\n");
        leituraData(&d1, &d2);//chama a função de leitura

        //imprimeData(d1);
        valorDias1 = calculaDias(d1);//chama função para converter
        valorDias2 = calculaDias(d2);//chama função para converter
    }while(valorDias2 < valorDias1);//condição de parada


    quantBissexto = verificaQuantBissexto(d1, d2);//chama a função para ver a quantidade de anos bissextos para caso tenha, somar com as dtas
    printf("A diferença entre as duas datas é: %d dias\n", valorDias2 - valorDias1+quantBissexto);
    system("pause");
    return 0;
}
