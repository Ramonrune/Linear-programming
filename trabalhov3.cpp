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
    int base[linha];
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



    cout << endl << endl;
    for(counterLinha = 0; counterLinha < linha; counterLinha++){

        for(counterColuna = coluna; counterColuna < coluna + 1; counterColuna++){


            cout << "Informe elemento do vetor B: " << endl;
            cin >> matrizA[counterLinha][counterColuna];


        }
    }



    cout << endl << endl;



    for(i = 0; i < linha; i++){
        int q;
        cout << "O I vale " << i << endl;
        if(matrizA[i][i] == 0){

            int c;



            int jAux = 0;
            float variavelZero;

            int achou = 0;
                //jaux = 0
            for(jAux = i; jAux < linha; jAux++){
                if(matrizA[jAux][i] != 0){
                    variavelZero = matrizA[jAux][i]; //variavel diferente de 0
                    q = i;
                    int mudaJ;
                    for(mudaJ = 0; mudaJ < coluna + 1; mudaJ++){
                        float temp = matrizA[i][mudaJ];
                        matrizA[i][mudaJ] = matrizA[jAux][mudaJ];
                        matrizA[jAux][mudaJ] = temp;
                    }
                    base[i] = i;
                      cout << "Vai tentar pular de linha" << endl;
                    achou = 1;
                    break;
                }

            }

            cout << "ACHOU ? " << achou << endl;

            if(achou == 0){
                cout << "Vai tentar pular de coluna" << endl;
                int jAux;
                int encontrou = 0;

                for(jAux = i; jAux < coluna; jAux++){
                    if(matrizA[i][jAux] != 0){
                        encontrou++;
                        base[i] = jAux;
                        q = jAux;

                        break;
                    }
                }


                if(encontrou == 0){
                    cout << "\nSem solucao\n" << endl;
                    return 0;
                }

            }


        }
        else{

            base[i] = i;
            q = i;
        }


        pivo[i] = 1.0 / matrizA[i][q];
        cout << "O valor anterior de pivo e de " << matrizA[i][q] << endl;
        cout << "O valor de q e de " << q << endl;



        if( pivo [i] == 1.0 / 0.0){
            pivo[i] = 0;
        }

        int j;

        cout << "L" << i << " -> " << "L" << i << " * " << pivo[i] << endl;
        for(j = 0; j < coluna + 1; j++){

            matrizA[i][j] = matrizA[i][j] * pivo[i];

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

            cout << fixed << matrizA[c][c1] << "\t";

        }
        cout << endl;
    }

    cout << endl << endl;




        float multi;
        for(j = 0; j < linha; j++){

            if(j != i && matrizA[j][q] != 0 ){

                    multi = matrizA[j][q];
                    int c;

                    cout << "L" << j << " -> " << "L" << j << " - " << multi << " * " << "L" << i << endl;
                    for(c = 0; c < coluna + 1; c++){

                        matrizA[j][c] = matrizA[j][c] - multi * matrizA[i][c];
                    }


            }
        }
         cout << endl << endl;
    cout << "Matriz" << endl;

    for(c = 0; c < linha; c++){

        for(c1 = 0; c1 < coluna + 1; c1++){
            if(matrizA[c][c1] == -0.00){
                matrizA[c][c1] = 0.00;
            }

            cout << fixed << matrizA[c][c1] << "\t";

        }
        cout << endl;
    }

    cout << endl << endl;



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

            cout << fixed << matrizA[c][c1] << "\t";

        }
        cout << endl;
    }

    cout << endl << endl;


    int linha_counter = 0;

    for(i = 0; i < coluna; i++){

        int encontrou = 0;
        for(j = 0; j < linha; j++){

            if(i == base[j]){
                cout << matrizA[linha_counter][coluna] << endl;
                encontrou = 1;
                linha_counter++;

                break;
            }

        }

        if(encontrou == 0){
            cout << "0.00" << endl;
        }
    }


    return 0;
 }


