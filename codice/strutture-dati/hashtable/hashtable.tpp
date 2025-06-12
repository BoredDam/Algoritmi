#include "hashtable.hpp"

// Costruttore
template <typename T>
hashTable<T>::hashTable(int capacity) {

    this->capacity = capacity;

    // Tutti gli slot sono settati di default a "empty" e contengono 0.
    this->table = new T[capacity];
    this->slotState = new _slotState[capacity];
    keysNo = 0;
    for (int i = 0; i < capacity; i++) {
        table[i] = 0;
        slotState[i] = _slotState::empty;
    }

}



// Distruttore
template <typename T>
hashTable<T>::~hashTable() {
    delete[] table;
    delete[] slotState;
}



// Funzione privata usata impostare il valore di un determinato indice.
// È usata dalla funzione pubblica insert.
template <typename T>
void hashTable<T>::set(int index, T val) {
    if (index < 0  || index >= capacity) {
        std::cout<<"\n**OUT OF BOUNDS**\n";
        exit(0);
    }
    table[index] = val;
    slotState[index] = _slotState::taken;
    keysNo = keysNo+1;
}



template <typename T>
void hashTable<T>::print() {

    // Stampiamo tutti gli slot. Quando lo slot non è empty or deleted, stampiamo i valori
    // Altrimenti, stampiamo "NULL"

    for (int i=0; i<capacity; i++) {
        if (slotState[i] == _slotState::taken) {
            std::cout<<i<<": "<<this->table[i]<<"\n";
        } else {
            std::cout<<i<<": NULL\n";
        }

    }
}

// Ritorna il valore contenuto in un determinato indice.
// È pubblica, in quanto non permette modifiche illegali alla tabella.
template <typename T>
T hashTable<T>::get(int index) {
    if (index < 0  || index >= capacity) {
        std::cout<<"** OUT OF BOUNDS **\n";
        exit(0);
    }
    return table[index];
}



// Funzione di hashing.
// Opto per una scansione lineare, ma potrebbe essere modificata.
template <typename T>
int hashTable<T>::hashFunc(T val, int i) {
    return ((int)val + i)%capacity;
}


// Inserimento della chiave val secondo la funzione hash.
template <typename T>
void hashTable<T>::insert(T val) {
    // Se il numero delle chiavi è uguale alla capienza della tabella,
    // non esegue l'inserimento.
    if(keysNo == this->capacity) {
        std::cout<<"\nerror: table overflow. '" << val << "' not inserted.\n";
        return;
    }

    int i=0;

    while (i < capacity && slotState[hashFunc(val, i)] == _slotState::taken) {

        if (table[hashFunc(val, i)] == val) {
            std::cout << "\nerror: '" << val << "' already exists in the table.\n";
            return;
        }
        i++;
    }

    if (i >= this->capacity) {
        std::cout<<"\nerror: table overflow. '"<<val<<"' not inserted.\n";
        return;
    }

    this->set(hashFunc(val, i), val);
}



// Rimuove la chiave "val" dalla tabella. Sfrutta una ricerca con successo 
// per trovare l'indice dello slot da eliminare.
template <typename T>
void hashTable<T>::del(T val) {

    int tmp = search(val);
    // La funzione search ritorna l'indice -1 se l'elemento non è trovato.
    if (tmp == -1) {
        std::cout <<"'"<< val << "' not found.\n";
        return;
    }
    // Imposta lo stato dello slot a "deleted", in modo da non causare problemi alla ricerca.
    slotState[tmp] = _slotState::deleted;
    keysNo = keysNo - 1;
}



// La funzione di ricerca. Ritorna l'indice dell'elemento cercato, se è presente.
// Altrimenti, ritorna -1.
// Ricerca l'elemento usando la funzione hash.
template <typename T>
int hashTable<T>::search(T val) {
    int i=0;
    int index;
    while(i < capacity){

        index = hashFunc(val,i);

        if(table[index] == val && slotState[index] == _slotState::taken) {
            return index;
        }
        if(slotState[index] == _slotState::empty) {
            return -1;
        }
        i++;
    }
    return -1;
}



// Funzione usata per verificare la presenza di un determinato elemento.
// Ritorna "true" se l'elemento è stato trovato, altrimenti "false".
template <typename T>
bool hashTable<T>::isIn(T val) {
    return this->search(val) != -1;
}



// Funzione usata per verificare se la tabella è piena.
template <typename T>
bool hashTable<T>::isFull() {
    return (this->keysNo == this->capacity);   
}