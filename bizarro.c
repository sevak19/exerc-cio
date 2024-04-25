#include <stdio.h>

float numero=1;
float resultado=1;
float resultado2=1;
float base;
int expoente;
int repeticao=1;
float total=0;

//all rights reserved to sevak®

void leitura(){
    printf("Digite um valor para x: ");
        scanf(" %f", &numero);
    if(numero>0){   //se o valor digitado for menor que zero, nao pede a quantidade de somatoria
    printf("Digite ate quantas repeticoes deseja fazer: ");
        scanf(" %d", &repeticao);
    }while(repeticao<=0 || numero<=0){  //e pula direto para ca, onde printa que o valor é invalido
        printf("valor invalido!\n\n");  
        leitura();                      //e repete a propria funcao leitura, criando um loop
    }                                   //sempre que uma das respostas for invalida
}

//funcao que calcula todos os fatoriais necessarios

void fatorial(int numero1){
    resultado=1;
    for(int i = 1; i <= numero1; i++){
      resultado *= i;
    }
}

//funcao que calcula todas as potenciacoes necessarias

void potenciacao(int numero2){
    resultado2=1;
    for(int i = 1;i<=numero2;i++){
        resultado2 *= numero;
    }
}

void printador(){
    printf("\n\t");
    for(int i=1;i<=repeticao;i++){
        if(i % 2 != 0){
           printf(" + (%.0f^%d)", numero, i);
        }else{
           printf(" - (%.0f^%d)", numero, i);
        }
    }
    printf("\n\t");
    int contador = 0;
    for(int i=1;contador<repeticao;i++){
        if(contador>=repeticao){
                   break;
               }
        printf("    %d!  ", i);
        contador++;
        if(i==4){
            i=1;
            for(int j=3;j>=1;j--){
               if(contador>=repeticao){
                   break;
               }
               printf("    %d!  ", j);
               contador++;
            }
        }
    }               
}

void calculo_bizarro(){
    int contador=0;
    for(int i=1;contador<repeticao;i++){
        fatorial(i);
        potenciacao(contador+1);
        if(contador % 2 != 0){
            total+= (resultado2/resultado);
        }else{
            total-= (resultado2/resultado);
        }
        contador++;
        if(i==4){
            i=1;
            for(int j=3;j>=1;j--){
               if(contador>=repeticao){
                   break;
               }
               contador++;
               fatorial(j);
               potenciacao(contador);
                if(contador % 2 == 0){
                    total+= resultado2/resultado;
                }else{
                    total-= resultado2/resultado;
                }
            }
        }
    }
}

int main()
{
    leitura();
    printador();
    calculo_bizarro();
    printf("\n\n\tRESULTADO = %.4f", total);

    return 0;
}
