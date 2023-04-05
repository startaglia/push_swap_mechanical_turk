* PUSH SWAP 
	Push swap é progetto su un ordinamento in ordine crescente di X numeri nel minor numero di mosse possibili. Il goal é trovare ed implementare l'algoritmo piu efficiente. Per ordinare questi numeri si hanno a disposizione due pile, la pila A e la pila B. I entrano direttamente nella pila A ed é questa che deve essere ordinata, la pila B verrá utilizzata come pila ausiliaria per compiere le operazione. Questi numeri si passsano da terminale, non possono essere doppi, possono essere negativi o positivi e devono essere ordinati con mosse specifiche.
      - SA (swap A) Swappa i primi due elementi nella pila A; es:[3,4,6,9,1] --> SA --> [4,3,6,9,1] (NB. 3 e 4 sono i primi due numeri inseriti).
      - SB (swap B).
      - SS (SA and SB at the same time)
      - PA (push A) Pusha un numero in una pila; es:PILA B[1,2,34,5,6] --> PA -->[1] (NB. é stato preso il primo numero della pila B ed é stato pushato nella pila A)
      - PB (push B).
      - RA (rotate A) Prende il primo elemento di una pila e lo mette per ultimo; es:[3,2,5,7,1] --> RA --> [2,5,7,1,3]
      - RB (rotate B).
      - RR (RA and RB at the same time).
      - RRA (reverse rotate A) É l'operazione inversa di rotate, quindi prende l'ultimo elemento di una pila e lo mette come primo; es:[2,5,7,1,3] --> RRA --> [3,2,5,7,1] 
      - RRB (reverse rotate B).
      - RRR (rra and rrb at the same time).
	Quando i numeri vengono acquisiti da terminale all' inizio non sono contate come mosse.
	Il numero massimo di mosse che si possono utilizzare per ordinare é 11 volte il numero di numeri in input.
	Il programma verrá testato con il checker che trovo nel sub.
	Per la scelta dell'algoritmo devo considerare il numero di elementi in input.
	QUICKSORT e MEGASORT sono due algoritmi efficienti per un numero elevato di elementi. 
	BUBBLE SORT e INSERTION SORT sono algoritmi efficienti per un numero basso di elementi.

* VISUALIZER
  - Per girare il visualizer (di default sta sul Turk Alghoritm) dare i comandi:
  > pip3 install push_swap_gui
  > python3 -m push_swap_gui

* DAILY GOALS
  - TUE 21/03
    - FARE LE MOSSE RA, RB, RR, RRA, RRB, RRR											                                    OK
    - SISTEMARE LA FUNZIONE CHE STAMPA LE STACK VICINE                                                KO          
    - FARE LA FUNZIONE CHE CONTROLLA SE I NUMERI CHE ENTRANO
      IN A SONO GIA ORDINATI                                                                          OK
    - FARE UNA FUNZIONE CHE CONTROLLA SE I NUMERI CHE ENTRANO IN A
      SONO > 3, SE SONO <= 3 DEVE FARE ALTRO                                                          OK
    - FARE LA FUNZIONE CHE TROVA IL NUMERO PIU GRANDE DEGLI INPUT DI A                                OK
    - FARE LA FUNZIONE CHE TROVA IL NUMERO PIU PICCOLO DEGLI INPUT DI A                               OK
    - FARE LA FUNZIONE CHE TROVA IL NUMERO PIU GRANDE DEGLI INPUT DI B                                OK
    - FARE LA FUNZIONE CHE TROVA IL NUMERO PIU PICCOLO DEGLI INPUT DI B                               OK
  
  - WED 22/03
    - FARE LA FUNZIONE CHE TROVA LA POSIZIONE DOVE DEVE ANDARE IL NUMERO
      CHE PUSHO IN B                                                                                  
    - FARE FUNZIONE CHE TROVA L'INDICE DEL PRIMO NUMERO PIU GRANDE IN B                               OK
    - FARE FUNZIONE CHE TROVA L'INDICE DEL PRIMO NUMERO PIU PICCOLO IN B                              OK
  
  -THU 23/03
    - FARE FUNZIONE CHE CONTROLLA SE IL NUMERO CHE VIENE E' IL NUOVO PIU GRANDE
      O IL NUOVO PIU PICCOLO DI B                                                                     OK
    - FARE FUNZIONE CHE CONTROLLA SE IL NUMERO CHE VIENE DA A HA BISOGNO
      SOLO DI UN PUSH                                                                                 OK
    - FARE FUNZIONE CHE TROVA LA METÁ DEI NUMERI PRESENTI IN UNA STACK                                OK
  -FRY 24/03
    - FARE FUNZIONE CHE ORDINA I NUMERI SE SONO 3 O MENO DI 3                                         OK
    - FARE FUNZIONE CHE GESTISCE IL CASO IN CUI SONO TUTTI E DUE NELLA METÁ SUPERIORE                 OK
  -TUE 28/03
    - FARE FUNZIONE CHE GESTISCE IL CASO IN CUI SONO TUTTI E DUE NELLA METÁ INFERIORE                 OK             
    - FARE FUNZIONE CHE GESTISCE IL CASO IN CUI SONO IN DUE METÁ DIVERSE                              OK
  -WED 29/03
    - FARE FUNZIONE CHE PRENDE IL NUMERO PIÚ ECONOMICO                                                OK
  - MON 3/04
    - FARE FUNZIONE CHE ESEGUE LE MOSSE                                                               OK
    
    
    - FARE FUNZIONE CHE ORDINA A

* TURK ALGORITHM
  - Si inizia con la stack A piena e la stack B vuota.
  - Dobbiamo riuscire ad avere i numeri nella stack B ordinati in ordine decrescente cosi quando li pusho tutti nella stack A vengono ordinati in ordine crescente
  - La stack B é da considerarsi come una lista circolare e non come una pila, quindi come se l'ultimo valore fosse in contatto con il primo.
  - Volta per volta devo trovare il numero piu' economico da portare in B, ovvero il numero utile che mi richiede il minor numero di mosse.
    - Prima cosa devo individuare dove dovrebbe andare il numero che arriva da A in B quindi trovare il numero subito piu piccolo e quello subito piu grande tra quelli presenti (creare due funzioni che controllano questo) e salvare l'indice.
    - Trovato l'indice calcolare il numero di mosse che servono per portare quell 'indice in cima + 1 (che sarebbe il push B che deve essere sempre l'ultima mossa).
    - Se il numero che ho appena pushato nella stack B é il nuovo numero piú grande o il nuovo numero piú piccolo devo metterlo vicino al vecchio numero piú grande.
    - Devo pushare in modo corretto e in ordine decrescente i numeri in B fino a quando in A non ne rimangono 3
      - Ci sono tre casi da considerare:
        1.0 Caso in cui il numero piú economico di A e il numero da spostare in alto in B si trovano tutti e due nella seconda metá.
          - Faccio il numero di numeri (non l'indice max!) della stack piu grande al momento meno l'indice del numero che devo spostare. Quel numero sará il numero di mosse totali che dovró fare per quella stack(ad esempio se la stack A ha 13 numeri e devo prendere il numero con indice 8 faccio 13 - 8 = 5. 5 sará alla fine il numero di mosse di cui avró bisogno per mettere il numero sopra pronto per essere pushato. Di queste 5 mosse ci saranno alcuni RRR)
          - Nella stack con meno numeri faccio la stessa operazione e quel numero che trovo sará il numero di RRR che dovró fare. (Esempio se devo prendere il numero con indice 5 nella stack B che ha 7 numeri faccio 7 - 5 = 2 che sarebbe il numero di mosse RRR. Considerando anche il risultato della stack di prima (5) faccio 5 - 2 = 3 e trovo il numero di mosse uniche della stack piu grande. Risultato finale in questo esempio (stiamo parlando della seconda metá) é 2 RRR e 3 RRA (la stack A qui é piú grande).
        2.0 Caso in cui i due numeri da spostare di trovano nella metá superiore.
          - In questo caso considero semplicemente l'indice del numero nella stack A e l'indice del numero nella stack B. Come prima li sottraggo e la differenza sará il numero di mosse uniche che dovró fare (quindi di RA). Ad esempio *se devo spostare in alto il numero di indice 3 nella stack A e il numero di indice 1 nella stack B faccio 3 - 1 = 2 che sará il numero di RA . Risultato finale sará 1 RR e 2 RA.
          Da notare che in entrambe i casi alla fine il numero di mosse totali é sempre il numero maggiore che ho trovato + 1 che sarebbe il pushb.
        3.0 Caso in cui i due numeri da spostare si trovano in metá diverse.
          - In questo caso semplicemente devo fare le mosse a seconda della metá in cui si trovano. Ad esempio se devo spostare in alto nella stack A il numero con indice 3 che sta nella metá superiore e in alto nella stack B il numero di indice 4 che si trova nella metá inferiore. Per la stack A saranno 3 RA, per la stack B saranno il numero di numeri in stack B , supponiamo 6, - l'indice 4, quindi (6 - 4). Risultato finale per portare i due numeri in alto sará 3 RA e 2 RRB
     - Considerati i casi c'é successivamente solo da aggiungere la mossa PB 
  - Ordino i 3 rimasti in A in ordine crescente
  - Pusho in A tutti i numeri che ho mettendoli peró nell'ordine corretto rispetto i 3 rimasti in A 


* PSEUDOCODE
  1. Imposta un ambiente di lavoro funzionante (Makefile).							              OK
  2. Acquisisci numeri e mettili in una stack.                                        OK
	2.0 Da gestire se nella stringa passo tra le virgolette piu numeri,
  	  deve considerarli tali (prendi le stringhe separate con split).				          OK
	2.1 Prendi con ATOI i numeri, e buttali dentro lo stack A.						              OK
	2.2 Controlla se nella stack A ci sono doppioni e che siano nel range
	  degli interi (-2147483648 e 2147483647)										                        OK
  3. Crea le funzioni che si occupano delle operazioni
   	 (SA, SB, PA, PB, SS, RA, RB, RR, RRA, RRB, RRR), le funzioni verranno
	 eseguite quando vengono chiamate da terminale.
	 3.0 SA																			OK
	 3.1 SB																			OK
	 3.2 SS																			OK
	 3.3 PA			WITH ROB <3											OK
	 3.4 PB			WITH RON <3											OK
	 3.5 RA																			OK
	 3.6 RB																			OK
	 3.7 RR																			OK
	 3.8 RRA																		OK
	 3.9 RRB																		OK
	 4.0 RRR																		OK
  4. Testa le funzioni con numeri casuali.
  5. Capisci quale algoritmo conviene utilizzare.(turk algorithm or LIS algorithm)


