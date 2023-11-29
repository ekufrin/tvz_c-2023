/*DRUGI ZADATAK KOLOKVIJ
Zadatak: Napisati program u C koji sa tipkovnice ucitava rezultate nogometnih utakmica u sljedecem formatu:
broj_tima1 broj_tima2 golovi_tima1 golovi_tima2 (na primjer 1 2 4 3)
Timova u skupini ima 5, oznaceni rednim brojevima od 1 do 5.

Ucitavanje zavrsava kada se upisu sve nule ili kada je broj prvog tima jednak broju drugog tima.

Napisati program koji ce napraviti i ispisati tablicu bodova skupine. Tablica izgleda ovako:
broj_tima Bodovi

Na kraju ispisati tim s najvi�e bodova porukom" Najvise bodova ima tim: _".
Ako ih ima vise - sve njih navesti, kao na primjer: " Najvise bodova ima tim: 3 4 5".

Napomena: pobjeda donosi 3 boda, nerijeseno 1, a poraz 0 bodova.
*/

int main() {
int points[5] = { 0 };
int team1, team2, goals1, goals2;

while (1) {

    scanf("%d %d %d %d", &team1, &team2, &goals1, &goals2);

    if (team1 == 0 || team2 == 0 || team1 == team2) {
        break;
    }
    if (goals1 > goals2) {           
        points[team1 - 1] += 3;
    }
    else if (goals1 < goals2) {
        points[team2 - 1] += 3;
    }
    else {
        points[team1 - 1] += 1;
        points[team2 - 1] += 1;
    }
}

// Ispis tablice bodova
printf("\nTablica bodova:\n");
printf("Broj_tima  Bodovi\n");
for (int i = 0; i < 5; i++) {
    printf("%5d  %7d\n", i + 1, points[i]);
}

// Pronalaženje tima s najviše bodova
int maxPoints = 0;
printf("\nNajvise bodova ima tim:");
for (int i = 0; i < 5; i++) {
    if (points[i] > maxPoints) {
        maxPoints = points[i];
    }
}

for (int i = 0; i < 5; i++) {
    if (points[i] == maxPoints) {
        printf(" %d", i + 1);
    }
}
printf("\n");

return 0;
}
