 /**
 @date 23/06/2017

 */


 #include <iostream>
 #include <stdio.h>
 #include <stdlib.h>
 #include <math.h>
 #include <map>
 #include <string>
 #include <string.h>

 using namespace std;
float semNumerosNegativos(float numero)
{

   char convertido[100];
   sprintf(convertido, "%.4f", numero);

    string a(convertido);

  // cout << a << endl;

    numero = strtof((a).c_str(),0);

   if((numero < 0.0000)  && (numero > -0.0001))
   {
     return -numero;
   }
   else
   {
     return numero;
   }
}

 int main(){

    int i;
    int j;

    float k;

    int linha, coluna;

    cout << "Informe a quantidade de linhas da matriz: " ;
    cin >> linha ;

     cout << "Informe a quantidade de colunas da matriz: " ;
    cin >> coluna ;

    float matrizA[linha +1][coluna + 1];
    float pivo[linha];
    int base[linha];
    int naoBase[linha];
    int colunaVetor[coluna];
    int auxCounterColuna = 0;

    cout.precision(2);
    int counterLinha, counterColuna;
    cout << "Matriz A:" << endl;
    for(counterLinha =0; counterLinha < linha; counterLinha++){

        for(counterColuna = 0; counterColuna < coluna; counterColuna++){

            cout << "\nInforme o elemento[" << counterLinha << "][" << counterColuna << "]: " ;
            cin >> matrizA[counterLinha][counterColuna];
        }
    }

    int counter = 0;
    for(counterLinha = linha; counterLinha < coluna; counterLinha ++){

        base[counter] = counterLinha;
        counter++;

    }



    cout << endl << endl;
    for(counterLinha = 0; counterLinha < linha; counterLinha++){

        for(counterColuna = coluna; counterColuna < coluna + 1; counterColuna++){


            cout << "Informe elemento do vetor B: " << endl;
            cin >> matrizA[counterLinha][counterColuna];

        }
    }



    cout << endl << endl;


    for(counterLinha = linha; counterLinha < linha + 1; counterLinha++){

        for(counterColuna = 0; counterColuna < coluna + 1; counterColuna++){

            if(counterColuna+1 == coluna+1){
                matrizA[counterLinha][counterColuna] = 0;
            }else{
                cout << "Informe a funcao objetivo: " << endl;
                cin >> matrizA[counterLinha][counterColuna];
            }


        }
    }

    int printLinha;
    int printColuna;
    for(printLinha = 0; printLinha < linha + 1; printLinha++){

        for(printColuna = 0; printColuna < coluna + 1; printColuna++){
            if(matrizA[printLinha][printColuna] == -0.00){
                matrizA[printLinha][printColuna] = 0.00;
            }

            cout << fixed << matrizA[printLinha][printColuna] << "\t";

        }
        cout << endl;
    }


    cout << "-----------BASE-------------" << endl;
    int contador;
    for(contador = 0; contador < counter; contador ++){

        cout << "NA BASE " << base[contador] << endl;
    }

    cout << "----------------------------" << endl;



    for(i = 0; i < linha + 1; i++){

        int podeContinuar = 0;

        int auxiliarLinha, auxiliarColuna;
        float menor = 0;
        int colunaMenor;


        for(auxiliarLinha = linha; auxiliarLinha < linha + 1; auxiliarLinha++){

            for(auxiliarColuna = 0; auxiliarColuna < coluna + 1; auxiliarColuna++){

                if(auxiliarColuna == 0){
                    menor = matrizA[auxiliarLinha][auxiliarColuna];
                    colunaMenor = auxiliarColuna;

                }else{

                    if(matrizA[auxiliarLinha][auxiliarColuna] < menor){
                        menor = matrizA[auxiliarLinha][auxiliarColuna];
                        colunaMenor = auxiliarColuna;

                    }

                }

                if(matrizA[auxiliarLinha][auxiliarColuna] < 0){

                    podeContinuar = 1;
                }



            }
        }



        cout << "Menor coluna " << menor << endl;
        cout << "Indice da menor coluna " << colunaMenor << endl;




        if(podeContinuar == 1){
            cout << "Pode continuar" << endl;

            int encontraMin;
            int menorLinha;
            float menorValor;

            int achouNumero = 0;
            for(encontraMin = 0; encontraMin < linha; encontraMin++){


                if(matrizA[encontraMin][colunaMenor] > 0){
                    if(encontraMin == 0){
                        menorLinha = encontraMin;
                        cout <<  matrizA[encontraMin][coluna] << " / " << matrizA[encontraMin][colunaMenor] << endl;;

                        menorValor = matrizA[encontraMin][coluna] /matrizA[encontraMin][colunaMenor];
                        achouNumero = 1;
                    }else{

                        cout <<  matrizA[encontraMin][coluna] << " / " << matrizA[encontraMin][colunaMenor] << endl;;

                        float num = matrizA[encontraMin][coluna] /matrizA[encontraMin][colunaMenor];

                        if(num < menorValor){
                            menorLinha = encontraMin;
                            menorValor = num;
                        }
                         achouNumero = 1;

                    }
                }



            }


            if( achouNumero = 0){
                cout << " Impossivel, Nao ha como continuar, todos os numeros que serao utilizados para sair da base sao negativos. " << endl;
                break;
            }

            base[menorLinha] = colunaMenor;

            cout << "-----------BASE-------------" << endl;
            int contador;
            for(contador = 0; contador < counter; contador ++){

                cout << "NA BASE " << base[contador] << endl;
            }

            cout << "----------------------------" << endl;


            cout << "Menor valor " << menorValor << endl;;
            cout << "Menor linha " << menorLinha << endl;




            pivo[i] = 1.0 / matrizA[menorLinha][colunaMenor];

            cout << "O pivo vale " << pivo[i] << endl;


            if( pivo [i] == 1.0 / 0.0){
                pivo[i] = 0;
            }

            int j;

            cout << "L" << i << " -> " << "L" << i << " * " << pivo[i] << endl;
            for(j = 0; j < coluna + 1; j++){

                matrizA[i][j] = matrizA[i][j] * pivo[i];

            }

            int printLinha;
            int printColuna;
            for(printLinha = 0; printLinha < linha + 1; printLinha++){

                for(printColuna = 0; printColuna < coluna + 1; printColuna++){
                    if(matrizA[printLinha][printColuna] == -0.00){
                        matrizA[printLinha][printColuna] = 0.00;
                    }

                cout << fixed << matrizA[printLinha][printColuna] << "\t";

                }
                cout << endl;
            }


            float multi;
            for(j = 0; j < linha + 1; j++){

                if(j != i && matrizA[j][colunaMenor] != 0 ){

                    multi = matrizA[j][colunaMenor];
                    int c;

                    cout << "L" << j << " -> " << "L" << j << " - " << multi << " * " << "L" << i << endl;
                    for(c = 0; c < coluna + 1; c++){

                        matrizA[j][c] = matrizA[j][c] - multi * matrizA[i][c];
                        //cout << matrizA[j][c] << endl;

                        matrizA[j][c] = semNumerosNegativos( matrizA[j][c]);
                    }


                }
            }


            for(printLinha = 0; printLinha < linha + 1; printLinha++){

                for(printColuna = 0; printColuna < coluna + 1; printColuna++){
                    if(matrizA[printLinha][printColuna] == -0.00){
                        matrizA[printLinha][printColuna] = 0.00;

                    }

                cout << fixed << matrizA[printLinha][printColuna] << "\t";

                }
                cout << endl;
            }





        }



    }


    cout << endl << endl;

    cout << "----------------------------" << endl;

    for(contador = 0; contador < counter; contador ++){

        cout << "NA BASE " << base[contador] << endl;
    }

    cout << "----------------------------" << endl;


    cout << endl << endl;

    cout << "Matriz final" << endl;
    for(printLinha = 0; printLinha < linha + 1; printLinha++){

        for(printColuna = 0; printColuna < coluna + 1; printColuna++){
            if(matrizA[printLinha][printColuna] == -0.00){
                        matrizA[printLinha][printColuna] = 0.00;

            }

        cout << fixed << matrizA[printLinha][printColuna] << "\t";

        }
        cout << endl;
    }



     cout << "Valor de Z(x) = " << matrizA[linha+1][coluna+1] << endl;


    std::map<int,float> mapa;

    contador = 0;
    for(counterLinha = 0; counterLinha < coluna; counterLinha++){
         if(contador<  coluna - linha){
            mapa[base[contador]]=matrizA[counterLinha][coluna];
            contador++;
        }

    }

    cout << "X = " << endl;

    int num = 0;
    for(num = 0; num < coluna; num++){
        int encontrou = 0;
        for(std::map<int,float>::iterator it = mapa.begin(); it != mapa.end(); it++){


            if(num == it->first){
                cout<< it->second << endl;
                encontrou = 1;
            }


        }

        if(encontrou == 0){
            cout << "0.00" << endl;
        }

    }


    return 0;
 }





