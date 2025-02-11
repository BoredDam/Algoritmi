# Dalla prova del 2 Dicembre 2024


## Esercizio 1 : APSP e Floyd Warshall
Fornire le funzioni ricorsive utilizzate per calcolare il costo di una soluzione ottimale negli algoritmi
di Floyd-Warshall e All-Pairs-Shortest-Path.

In entrambi i casi, spiegare l’idea alla base
della funzione ricorsiva e chiarire il significato delle variabili e dei parametri utilizzati nel calcolo.

## Esercizio 2 : Rod-Cutting problem

Definire formalmente il problema del Rod-Cutting, mostrando, anche attraverso un esempio perché
è considerato un problema di ottimizzazione.

Fornire una definizione ricorsiva della funzione utilizzata
per il calcolo di una soluzione ottima al problema e mostrare lo pseudo-codice dell’algoritmo di programmazione dinamica basato su tale funzione.

## Esercizio 3 : Codici di Huffman
Descrivere formalmente il problema della compressione di un testo. Spiegare, anche tramite un esempio, perché questo è considerato un problema di ottimizzazione. 

Definire il concetto di codici prefissi e fornire lo pseudocodice dell’algoritmo di Huffman per il calcolo di una soluzione ottima
al problema, indicandone la complessità computazionale.

## Esercizio 4 : Bellman-Ford
Si fornisca lo pseudo-codice (o i codici in linguaggio C/C++) dell’algoritmo Bellman-Ford per il calcolo dei cammini minimi da sorgente singola in un grafo pesato. 

Indicare la complessità computazionale dell’algoritmo fornito.

## Esercizio 5 : Teorema Master

## Esercizio 6 : Longest Common Subsequence

Si consideri il seguente problema di ottimizzazione computazionale.

#### Longest Common Subsequence Problem (LCS)

Input, due sequenze: 

$$
X = \langle x_1, x_2, \dots, x_m \rangle
$$

$$
Y = \langle y_1, y_2, \dots, y_n \rangle
$$

GOAL: 

trovare una sottosequenza Z comune a X e Y di lunghezza massima.

<br/>
<br/>
<br/>
<br/>

# Soluzioni

## Esercizio 1 : APSP e Floyd Warshall

## Esercizio 2 : Rod-Cutting problem

Il Rod-Cutting problem è un problema di ottimizzazione.

Data un'asta di lunghezza $n$ e un vettore contenente i prezzi di vendita delle aste di lunghezza $i$, con $i \in \{ 0, 1, \dots, n\}$ (con $p[0] = 0$ ), trovare il prezzo di vendita maggiore dell'asta di lunghezza $n$, sfruttando un opportuna combinazione di tagli.

È un problema di ottimizzazione in quanto, nonostante siano molte le soluzioni valide (che rispettano le condizioni per essere una soluzione), non tutte massimizzano il prezzo di vendita. Esiste quindi una soluzione ottima. Qualsiasi altra soluzione può essere o peggiore, o equivalente.

### Formulazione ricorsiva

$$
r(n)=
\begin{cases}
0 & \quad \text{se $n = 0$}\\ 
\max\{r(n-i) + p(i)\} & \quad \text{con $1 \leq i \leq n$} 
\end{cases}
$$

### Pseudocodice

```
Rod-Cutting(p, n)
    r = new array (n+1)
    t = new array (n+1)
    r[0] = 0
    for k = 1 to n
        r[k] = -∞
        for i = 1 to k
            q = r[k-i] + p[i]
            if r[k] < q
                r[k] = q
                t[k] = i
    return r, t
```
N.B.
Nella repo è presente un'implementazione del rod-cutting problem in C++ :)))