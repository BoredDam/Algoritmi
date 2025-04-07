# Classe template tabella hash in C++

All'interno di questa cartella sono presenti i file .tpp e .hpp per l'implementazione di una classe template per una tabella hash a indirizzamento aperto.
Usufruisce di una funzione di scansione lineare per inserire gli elementi all'interno della tabella.

## Attributi

### Private

    T * table
È un puntatore ad un oggetto di tipo T. 

    size_t capacity;
Indica la capacità della tabella. Coincide con $m$.

    size_t keysNo;
Indica il numero di chiavi contenute nella tabella. Coincide con $n$.

    enum class _slotState { empty, deleted, taken };
È un'enumerazione che useremo in un array di stati, che permetterà di implementare la lazy deletion. Senza questo, non si potrebbero inserire chiavi $k = 0$, ottenendo una pseudo-deletion.

    _slotState * slotState;
È un puntatore ad un oggetto di tipo slotState. Ci permetterà di creare un array di dimensione $m$, che permetterà di marcare in maniera opportuna ogni slot.

## Metodi

### Private

    int hashFunc(T val, int i);

È una funzione di hash di permutazione. Usa la scansione lineare.

#### 
    void set(int index, T val);

Imposta a ``val`` il valore dello slot ``T[index]``. È private in quanto non è contemplato che l'utente utilizzi questa funzione.

### Public

    hashTable(int capacity);

È il costruttore, va specificata la dimensione della tabella.

    ~hashTable();

Il distruttore della classe.

    void print();

Stampa il contenuto dell'hash table nella forma 

    1: n_1
    2: n_2
    .
    .
    .
    m: n_m

Con $m$ dimensione della table.

    a