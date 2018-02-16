 /**
 @date 03/04/2017

 Ax = b
 x = A^ -1 * b

 [A | I]

    |
    |
    |
    v
[I | A ^ -1]

Método para encontrar a inversa de uma matriz

Entrada de Dados:
A e B.

 */


 #include <iostream>

 using namespace std;


 int main(){

    int i;
    int j;

    float k;

    int linha, coluna;

    cout << "Informe a quantidade de linhas da matriz: " ;
    cin >> linha ;

     cout << "Informe a quantidade de colunas da matriz: " ;
    cin >> coluna ;

    float matrizA[linha][coluna + 1];
    float pivo[linha];
    float matrizB[linha];
    int colunaVetor[coluna];
    int auxCounterColuna = 0;



    int counterLinha, counterColuna;
    cout << "Matriz A:" << endl;
    for(counterLinha =0; counterLinha < linha; counterLinha++){

        for(counterColuna = 0; counterColuna < coluna; counterColuna++){

            cout << "\nInforme o elemento[" << counterLinha << "][" << counterColuna << "]: " ;
            cin >> matrizA[counterLinha][counterColuna];
        }
    }



    cout << endl << endl;
    for(counterLinha = 0; counterLinha < linha; counterLinha++){

        for(counterColuna = coluna; counterColuna < coluna + 1; counterColuna++){


            cout << "Informe elemento do vetor B: " << endl;
            cin >> matrizA[counterLinha][counterColuna];


        }
    }



    cout << endl << endl;



    int conseguiu = 0;
     int found = 0;
     int coluna_achou;


    int coluna_guarda[coluna];
    int contador_de_coluna = 0;
    for(i = 0; i < linha; i++){

        if(matrizA[i][i] == 0 && i == 0){

            int c;



            int jAux = 0;
            float variavelZero;


                //jaux = 0
            for(jAux = i; jAux < linha; jAux++){
                if(matrizA[jAux][i] != 0){
                    variavelZero = matrizA[jAux][i]; //variavel diferente de 0
                    int mudaJ;
                    for(mudaJ = 0; mudaJ < coluna + 1; mudaJ++){
                        float temp = matrizA[i][mudaJ];
                        matrizA[i][mudaJ] = matrizA[jAux][mudaJ];
                        matrizA[jAux][mudaJ] = temp;
                    }

                    break;
                }

            }

        }



        pivo[i] = 1.0 / matrizA[i][i];



        if( pivo [i] == 1.0 / 0.0){
            int jAux;


            for(jAux = i + 1; jAux < coluna; jAux++){
                if(matrizA[i][jAux] != 0){
                    pivo[i] = 1.0 / matrizA[i][jAux];
                    coluna_achou = jAux;

                    found = 1;


                    break;
                }
            }
        }




        if(found == 0 && pivo[i] == 1.0 / 0.0){
            pivo[i] = 0;
            break;
        }





        int j;

        for(j = 0; j < coluna + 1; j++){

            matrizA[i][j] = matrizA[i][j] * pivo[i];

        }

        if(found == 0){
            coluna_guarda[contador_de_coluna] = i;
        }



        float multi;
        for(j = 0; j < linha; j++){

                if(found == 0){

                        if(j != i && matrizA[j][i] != 0 ){
                            coluna_guarda[contador_de_coluna] = i;

                            multi = matrizA[j][i];
                            int c;

                            for(c = 0; c < coluna + 1; c++){

                                matrizA[j][c] = matrizA[j][c] - multi * matrizA[i][c];
                            }



                        }


                }

                  if(found == 1){

                        if(j != i && matrizA[j][coluna_achou ] != 0){
                            multi = matrizA[j][coluna_achou];

                            coluna_guarda[contador_de_coluna] = coluna_achou;


                            int c;

                            for(c = 0; c < coluna + 1; c++){

                                matrizA[j][c] = matrizA[j][c] - multi * matrizA[i][c];
                            }



                        }

                  }


            int c , c1;
            for(c = 0; c < linha; c++){

               for(c1 = 0; c1 < coluna + 1; c1++){
                    if(matrizA[c][c1] == -0.00){
                        matrizA[c][c1] = 0.00;
                    }

                    cout << matrizA[c][c1] << "\t";

                }
                cout << endl;
            }

           cout << endl << endl;


        }
        contador_de_coluna++;
        coluna_achou++;





    }

    cout << endl << endl;
    cout << "Matriz" << endl;
    int c;
    int c1;
    for(c = 0; c < linha; c++){

        for(c1 = 0; c1 < coluna + 1; c1++){
            if(matrizA[c][c1] == -0.00){
                matrizA[c][c1] = 0.00;
            }

            cout << matrizA[c][c1] << "\t";

        }
        cout << endl;
    }

    cout << endl << endl;




    int linha_counter = 0;




    for(i = 0; i < coluna; i++){

        int encontrou = 0;
        for(j = 0; j < contador_de_coluna; j++){

            if(i == coluna_guarda[j]){
                cout << matrizA[linha_counter][coluna] << endl;
                encontrou = 1;
                linha_counter++;

                break;
            }

        }

        if(encontrou == 0){
            cout << "0" << endl;
        }
    }



    return 0;
 }


