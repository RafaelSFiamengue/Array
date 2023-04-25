#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
//
int main() {
    //
    const int maxTentativas = 5;
    //
    int nivel, numero, palpites, tentativas = 0;
    //
    int intervalos[3][2] = {{1,10}, {1,50}, {1,100}}; 
    bool acertou = false;
    //
    srand(time(NULL));
    
    //
    cout << "Bem-Vindo ao jogo!\n";
    cout << "Escolha um nível de dificuldade para começar!\n";
    cout << "1 - Fácil -> 1 a 10 \n";
    cout << "2 - Médio -> 1 a 50 \n";
    cout << "3 - Difícil -> 1 a 100 \n";
    cin >> nivel;
    
    //
    if (nivel < 1 || nivel > 3) {
        cout << "Opção invalida, pare de alastrar\n";
        return 0;
    }
    //
    numero = rand() % (intervalos[nivel-1][1] - intervalos[nivel-1][0] + 1) + intervalos[nivel-1][0];
    //
    while (!acertou && tentativas < maxTentativas) {
        cout << "Digite um palpite entre " << intervalos[nivel-1][0] << " e " << intervalos[nivel-1][1] << ":\n";
        cin >> palpites;
        tentativas++;
        
        if(palpites < numero) {
            cout << "O número é maior. \n";
        }
        else if (palpites > numero) {
            cout << "O número é menor. \n";
        }
        else {
            cout << "Parabéns, você acertou em " << tentativas << " tentativas :) \n";
          
        }
    }
    //
    if (palpites != numero && tentativas >= maxTentativas) {
        cout << "Você perdeu o jogo, muito ruim! O número era " << numero << ":( \n";
    }
    return 0;
}