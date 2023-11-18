/*
Kada je u predstavljanju kandidata u televizijskoj emisiji Ljubav je na selu ugledao Sandru, Kristijan se odmah u nju zaljubio. Pisao je Sandri i ona ga je pozvala kod sebe na farmu. No na Kristijanovu nesreću Sandra je pozvala još dva dečka, Denisa i Marina. Kako bi vidjela tko je od njih trojice najbolji radnik na farmi Sandra im je zadala zadatak branja kukuruza: onaj tko ubere najviše kukuruza u najkraćem vremenu dobit će pusu od Sandre i neće biti izbačen s farme; s time da Sandra u ukupnom rezultatu tolerira razliku od 3 kukuruza.

Kristijan vas je zamolio da mu napišete program koji će mu na temelju segmenta kukuruzišta (kojeg se domogao kodiranjem snimki fotografiranih svojim dronom) predložiti najbolji red u koji se treba stati kako bi osvojio Sandrinu ljubav. Segment je velik 3x20 i u svakom redu u segmentu mogu se nalaziti:

·       kukuruz 'I' – za čije branje mu je potrebno 5 sekundi
·       trava '.' – na kojoj nema kukuruza i prolazi se u roku 1 sekunde
·       blato ',' – na kojem nema kukuruza, ali su potrebne 2 sekunde da ga se prohoda
Ukoliko postoje redovi s istim brojem kukuruza koje je moguće ubrati u istom vremenu, Kristijan preferira biti u prvom rubnom redu. 

U svakom slučaju red se, kako god izgledao, mora proći od početka do kraja.



NAPOMENA: Segment kukuruza potrebno je pohraniti kao 2D polje.

TEST CASEOVI:

Test case #1
U ovom slučaju u svakom redu se može ubrati 20 kukuruza u roku od 100 sekundi. Kako Kristijan preferira prvi rubni red preporuka je da se pozicionira u 1. red.
Primjer ulaza:
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
IIIIIIIIIIIIIIIIIIII
Primjer izlaza:
Pozicioniraj se u 1. red!
Test case #2
U ovom slučaju za branje istog broja kukuruza u 1. i 3. redu potrebno je jednako vremena, te kako Kristijan preferira 1. rubni red potrebno je reći mu da se pozicionira u 1. red.
Primjer ulaza:
IIIIII..IIIIIII,IIII
I,I..I,,III..II,,,II
IIII,IIIIIIIII..IIII
Primjer izlaza:
Pozicioniraj se u 1. red!
Test case #3
U ovom slučaju za branje 10 kukuruza u 1. redu potrebno je 65 sekundi.
Za branje 9 kukuruza u 2. redu potrebno je 59 sekundi.
Za branje 12 kukuruza u 3. redu potrebno je 70 sekundi. 
S obzirom da Sandra ne pravi razliku ukoliko je ubrano 3 kukuruza manje ili više, pobjednički red je 2. red u kojem se u najkraćem vremenu ubire podjednako (s tolerancijom od 3) kukuruza kao u ostala 2 reda.
Primjer ulaza:
IIIII,,,II..,,III...
II.,,,..III...III..I
III..I.I.IIIIII,,I..
Primjer izlaza:
Pozicioniraj se u 2. red!
Test case #4
U ovom slučaju u 1. redu nalazi se 9 kukuruza za čije branje je potrebno 65 sekundi.
U 2. redu nalazi se 20 kukuruza za čije branje je potrebno 100 sekundi.
U 3. redu nalazi se 14 kukuruza za čije branje je potrebno 80 sekundi.
Kristijan će pobjediti ako se pozicionira u 2. red.
Primjer ulaza:
II..IIII,,,,III,,,,,
IIIIIIIIIIIIIIIIIIII
IIIIIII..III,,,,IIII
Primjer izlaza:
Pozicioniraj se u 2. red!
Test case #5
U ovom slučaju u svakom redu može se ubrati jedan kukuruz, ali to je najbrže ostvarivo u 3. redu.
Primjer ulaza:
I........,,,........
I,,,,,,,,,,,,,,,,,,,
I...................
Primjer izlaza:
Pozicioniraj se u 3. red!

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdlib.h>
#include <stdio.h>

int main()
{
    char field[3][21];

    int scores[3][2];

    int i, j, best_score = 0, best_time = 0, best_row = 1;

    for (i = 0; i < 3; i++) {
        scanf("%20s", field[i]);
    }

    for (i = 0; i < 3; i++) {
        scores[i][0] = 0;
        scores[i][1] = 0;

        for (j = 0; j < 20; j++) {

            // scores[i][0] -> vrijeme
            // scores[i][1] -> broj ubranih kukuruza
            switch (field[i][j]) {
                case 'I':
                    scores[i][0] += 5;
                    scores[i][1]++;
                    break;
                case '.':
                    scores[i][0]++;
                    break;
                case ',':
                    scores[i][0] += 2;
                    break;
                default:
                    break;
            }
        }

        // Dobij maksimalni broj kukuruza koji se moze ubrati
        if (scores[i][1] > best_score) {
            best_score = scores[i][1];
            best_time = scores[i][0];
            best_row = i + 1;
        }
    }

    for (i = 0; i < 3; i++) {
        if (scores[i][1] >= (best_score - 3) && scores[i][0] <= best_time) {

            // Ako je broj ubranih kukuruza i vrijeme isto ko u prvom redu, ne mijenjaj red
            if (scores[i][1] == best_score && scores[i][0] == best_time && best_row == 1) continue;

            best_time = scores[i][0];
            best_row = i + 1;
        }
    }

    printf("Pozicioniraj se u %d. red!", best_row);

    return 0;
}
