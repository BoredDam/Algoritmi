# Knapsack problem

I problemi dello zaino sono un insieme di problemi di otttimizzazione.

## Introduzione al problema generale

Dato un insieme $X$ di $n$ oggetti e uno zaino di capienza $k$, trovare la migliore combinazione di oggetti per massimizzare il guadagno (proporzionale a valore, peso o numero di oggetti, dipendentemente dal problema).

Oggetti:
$$
X = \langle x_1, x_2, \dots, x_n\rangle  
$$


$ 0 \leq x \leq 1$ (1 : oggetto preso totalmente, 0 oggetto totalmente non preso)

Peso (non negativo):
$$
P = \langle p_1, p_2, \dots, p_n\rangle
$$


Valore:

$$
V = \langle v_1, v_2, \dots, v_n\rangle
$$

### Massimizzare il valore degli oggetti

Scegliere una combinazione di coefficienti di $X$ tale che:

$$
\max \sum_{i=1}^n x_i \cdot v_i
$$

Rispettando il vincolo

$$
\sum_{i=1}^n x_i \cdot p_i \leq K
$$

## Formulazione ricorsiva del problema 
Per la massimizzazione del valore

$$
Z(k,n)=
\begin{cases}
0 & \quad \text{se $n = 0$}\\ 
0 & \quad \text{se $k = 0$}\\
-\infty & \quad \text{se $k < 0$}\\ 
\max(v(n) + Z(k-p(n), n-1), Z(k, n-1)) & \quad \text{altrimenti}
\end{cases}
$$

<br/>
<br/>
<br/>

# Zaino 0-1 e frazionario a confronto

Quando il problema permette che $x$ sia un valore reale nell'intervallo $[0,1]$, il problema viene detto "zaino frazionario".


Se il problema limita i valori di $x$ a 0 o a 1, allora si parla di zaino intero o, appunto, 0-1.

## Sottostruttura ottima del problema dello zaino

Sia {*x*<sub>1</sub>\*, *x*<sub>2</sub>\*, …, *x*<sub>*n*</sub>\*} una
soluzione ottima al problema.  
Consideriamo un sottoproblema:

-   di variabili
    {*x*<sub>1</sub>, …, *x*<sub>*j* − 1</sub>, *x*<sub>*j* + 1</sub>, …, *x*<sub>*n*</sub>}

-   limite di peso *W* − *x*<sub>*j*</sub>*w*<sub>*j*</sub>

Supponiamo che la restrizione
{*x*<sub>1</sub>\*, …, *x*<sub>*j* − 1</sub>\*, *x*<sub>*j* + 1</sub>\*, …, *x*<sub>*n*</sub>\*}
non sia ottima per il suo sottoproblema (per assurdo).  
Ciò implica l’esistenza di un’altra soluzione
{*x*<sub>1</sub>′, …, *x*<sub>*j* − 1</sub>′, *x*<sub>*j* + 1</sub>′, …, *x*<sub>*n*</sub>′}
ottima di peso è minore della soluzione
{*x*<sub>1</sub>\*, …, *x*<sub>*j* − 1</sub>\*, *x*<sub>*j* + 1</sub>\*, …, *x*<sub>*n*</sub>\*},
ovvero

$$\sum_{i=1, i \neq j}^n{v_i x_i'}\ >\sum_{i=1, i \neq j}^n{v_i x_i^*}, \\\sum_{i=1, i \neq j}^n{w_i x_i'} \leq W - x_j^*w_j$$

Allora
{*x*<sub>1</sub>′, *x*<sub>2</sub>′, …, *x*<sub>*j* − 1</sub>′, *x*<sub>*j*</sub><sup>\*</sup>, *x*<sub>*j* + 1</sub>′, …, *x*<sub>*n*</sub>′}
è una soluzione ottima, al problema originario, migliore di
{*x*<sub>1</sub><sup>\*</sup>, …, *x*<sub>*j*</sub>, …, *x*<sub>*n*</sub><sup>\*</sup>}.
Infatti:

$$\sum_{i=1, i \neq j}^n{v_i x_i'} + v_j x_j^*  \ >\sum_{i=1, i \neq j}^n{v_i x_i^* + v_j x_j^*} = \sum_{i=1}^n v_ix_i^*$$

$$\sum_{i=1, i \neq j}^n{w_i x_i'} + w_j x_j^*  \leq W - w_j x_j^* + w_j x_j^* = W$$
Osserviamo che:

-   Nel caso dello zaino (0-1), *x*<sub>*i*</sub><sup>\*</sup> ∈ {0, 1}.

-   Nel caso dello zaino frazionario,
    *x*<sub>*i*</sub><sup>\*</sup> ∈ \[0, 1\]

Non avendo specificato un determinato un valore per $x$, possiamo usare la stessa dimostrazione per entrambi i problemi

<br/>

## Zaino frazionario - Scelta greedy

Gode della proprietà di scelta greedy: la scelta greedy è sempre l'elemento con il rapporto valore - peso più alto.

Ordineremo quindi l'array di oggetti in ordine decrescente di rapporto valore - peso.


La proprietà di scelta greedy + facilmente dimostrabile sostituendo la scelta greedy all'interno di una soluzione ottima che, per ipotesi, non contiene la scelta greedy. Per comodità, supponiamo anche che $x_2$ sia parte della scelta greedy, e quindi $x_1 = 0, \ x_2 > 0$ .

Creiamo adesso una soluzione in cui i valori di $x_1$ e di $x_2$ sono invertiti. A parità di peso, otterremo una soluzione migliore della nostra soluzione ottima di partenza (per ipotesi), il che è un assurdo.

Il problema dello zaino frazionario deve quindi godere della scelta greedy, in quanto è possibile costruire una scelta globalmente ottima facendo la scelta greedy.

La sottostruttura ottima viene dimostrata tra lo zaino frazionario e lo zaino 0-1 in maniera analoga.


## Zaino intero - Scelta greedy

Basta una singola istanza del problema in cui la scelta greedy non genera una soluzione ottima, per dimostrare che il problema dello zaino intero non gode della proprietà di scelta greedy. 