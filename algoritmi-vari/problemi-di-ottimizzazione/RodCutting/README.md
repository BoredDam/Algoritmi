# ROD-CUTTING #

Il problema del taglio delle aste cade nella categoria dei problemi di ottimizzazione. 

## Descrizione del problema ##
Data un'asta di lunghezza $n$ è un vettore di prezzi $prices = \{p_0, p_1, \dots, p_{n}\}$, $p_0$=0, trovare il prezzo massimo di vendita dell'asta.

$p_i$ sarà il prezzo di vendita di un'asta di lunghezza $i$.

### Formulazione ricorsiva del problema
La funzione $r(n)$ ritorna il valore massimo di vendita di un'asta di lunghezza $n$.

$$
r(n) =
\begin{cases}
0 & \text{ se } n = 0 \\
\max \{ P(i) + r(n-i)\} & \text{ con } 1 \leq i \leq n
\end{cases}
$$

## Programmazione dinamica o greedy?

Il problema in questione gode di sottostruttura ottima e di overlapping subproblems, ma non della proprietà di scelta greedy, quindi baseremo la nostra soluzione sulla programmazione dinamica.

### Overlapping Subproblems

I problemi che si ripetono sono il calcolo della migliore combinazione di tagli per massimizzare il prezzo di vendita dell'asta di dimensione $n$-esima.

### Sottostruttura ottima (con dimostrazione)
Sia $r(n)^* $ una soluzione ottima al problema.

$$
r(n)^* = r(n-i)^* + P(i)
$$

Supponiamo per assurdo che $r(n-i)^*$ non sia ottima al sottoproblema $r(n-i)$.

Allora, esisterà una soluzione ottima tale che

$$
r(n-i)' \geq r(n-i) \Rightarrow r(n-i)' > r(n-i)^*
$$

Sarà quindi possibile sostituire $r(n-i)^*$ con $r(n-i)'$, ottenendo una soluzione migliore della soluzione ottima.

$$
r(n)^* = r(n-i)^* + P(i) < r(n-i)' + P(i) = r(n)'
$$

Ne consegue che

$$
r(n)^* < r(n)'
$$

Ma questo è un assurdo, in quanto $r(n)^*$ è una soluzione ottima per ipotesi: abbiamo dimostrato che $r(n-i)^*$ deve essere una soluzione ottima, e quindi la sottostruttura ottima del problema!

## In questa repository

#### Last update: 05/02/2025
Funzione per la risoluzione del problema del taglio delle aste (senza output della combinazione di tagli) in C++.
