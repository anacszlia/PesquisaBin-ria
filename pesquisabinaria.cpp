#include <ctime>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <cstring>
using namespace std;

void ordena(int vet[]) {
    int aux;
    for(int i = 0; i < 5; i++) {
        aux = vet[i];
        for(int j = i + 1; j < 5; j++) {
            if(aux > vet[j]) {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "portuguese");

    int vet[5] = {1, 6, 2, 7, 65};
    int pposi, ultpos, metade;
    int numerolido;

    cout << "Insira o número para busca binária: ";
    cin >> numerolido;

    bool achou = false;

    ordena(vet);

    pposi = 0;
    ultpos = 4;

    while (pposi <= ultpos && !achou) {
        metade = (pposi + ultpos) / 2;

        if (vet[metade] == numerolido) {
            achou = true;
        } else if (vet[metade] > numerolido) {
            ultpos = metade - 1;  // ajusta a posição superior
        } else {
            pposi = metade + 1;  // ajusta a posição inferior
        }
    }

    if (achou) {
        cout << "O número lido foi encontrado na posição: " << metade << " do vetor." << endl;
    } else {
        cout << "O número lido não foi encontrado no vetor." << endl;
    }

    return 0;
}
