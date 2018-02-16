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


    int contando = 0;
    int conseguiu = 0;
    for(i = 0; i < linha; i++){
        int ativo = 0;
        float variavelAuxPivo = 0.00;
        if(matrizA[i][i] == 0){

            int c;

            for(c = 0; c < linha; c++){

                int jAux = 0;
                float variavelZero;

                //jaux = 0
                for(jAux = i; jAux < linha; jAux++){
                    if(matrizA[jAux][i] != 0){
                        variavelZero = matrizA[jAux][i]; //variavel diferente de 0
                        break;
                    }

                }

                if(matrizA[c][i] == variavelZero){

                    int mudaJ;
                    for(mudaJ = 0; mudaJ < coluna + 1; mudaJ++){
                        float temp = matrizA[c][mudaJ];
                        matrizA[c][mudaJ] = matrizA[i][mudaJ];
                        matrizA[i][mudaJ] = temp;
                    }

                    ativo = 0;


                }
                else{


                    /*
                    cout << "Nao tem inversa!" << endl;
                    conseguiu++;
                     break;
                    */

                    int jAux = 0;
                    float variavelZero;

                    //jaux = 0
                    for(jAux = i; jAux < coluna; jAux++){
                        if(matrizA[i][jAux] != 0){

                            variavelZero = matrizA[i][jAux]; //variavel diferente de 0
                            ativo = 1;
                            variavelAuxPivo = variavelZero;

                            cout << "ativoooooo" << endl << endl;
                            break;
                        }

                    }

                }
            }


        }

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


        if(ativo == 0){
            pivo[i] = 1.0 / matrizA[i][i];

        }
        else{

            pivo[i] = 1.0 / variavelAuxPivo;

           // ativo = 0;

        }

        if(pivo[i] == 1.0 / 0.0){
            break;
        }

 cout << "pivo " << pivo[i] << endl << endl;

        int j;

        for(j = 0; j < coluna + 1; j++){
            matrizA[i][j] = matrizA[i][j] * pivo[i];
        }
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



        float multi;
        for(j = 0; j < linha; j++){
            if(j != i && matrizA[j][i] != 0){
                if(ativo == 0){
                     multi = matrizA[j][i];
                     colunaVetor[i] = 1;
                }
                else{
                    multi = matrizA[j][i + 1];
                    colunaVetor[i] = 0;
                    colunaVetor[i + 1] = 1;
                }


                int c;
                 cout << "l" << j  << "=" << "l" << j << " -" << multi << "*" << "l" << i  << endl;
                for(c = 0; c < coluna + 1; c++){
                    cout << (matrizA[j][c]) << " = " << "ela msm  - " << multi << " * " << matrizA[i][c] << endl;
                    matrizA[j][c] = matrizA[j][c] - multi * matrizA[i][c];
                }


            }
        }

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

    cout << "Resultado" << endl;



    int linhaAux = 0;
    for(c1 = 0; c1 < coluna; c1++){
            //cout << colunaVetor[c1] << endl;
        if(colunaVetor[c1] == 1){
             cout << matrizA[linhaAux][coluna] << "\t";
            linhaAux++;
        }else{
            cout << "0" << "\t";
        }


    }


    cout << endl << endl;




    return 0;
 }


