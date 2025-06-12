#include <iostream>

// Prototipo
int rodCutting(int *prices, int rodLen);

// Main:
//  prices = array dei prezzi, con zero al primo posto e con un numero di valori pari 
//  alla lunghezza dell'asta + 1;

int main() {
    int prices[] = {0, 2, 7, 9, 10}; 
    std::cout<<rodCutting(prices, 4)<<"\n";
}

// Obiettivo: trovare il taglio ottimo per massimizzare il prezzo di vendita
// l'array r sarà la nostra funzione r(n)


int rodCutting(int *prices, int rodLen) {

    // r[n] conterrà il prezzo massimo di vendita di una barra 
    // di lunghezza n, tagliata in maniera opportuna
    int r[rodLen + 1];
    r[0]=0;

    // ciclo for per scorrere tutte le lunghezze
    for (int k = 1; k <= rodLen; k++) {

        r[k] = -10000;

        // ciclo for per verificare se esiste un modo migliore per tagliare l'asta di lunghezza r[k]. 
        // Esempio: se attualmente r[5] = 4, r[2] = 3 e price(3) = 5, 
        // con k = 5 e i = 2 => r[5] < prices[5-2] + r[2]. 
        // Essendo true, entrerà nell'if, aggiornando il miglior prezzo di vendita per l'asta di lunghezza 5.

        for (int i = 1; i <= k; i++) {
            if (r[k] < prices[i] + r[k-i]) {
                r[k] = prices[i] + r[k-i];
            }
        }
    }

    return r[rodLen]; 
}