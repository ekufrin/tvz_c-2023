/*PRVI ZADATAK KOLOKVIJ
Zadatak: Potrebno je ucitati broj N, koji oznacava broj radijatora u stanu. Nakon toga slijedi N decimalnih brojeva koji oznacavaju
temperaturu pojedniog radijatora. Potrebno je ispisati temperaturnu razliku izmedu radijatora
koji je najblize bojleru i radijatora koji je najdalje.
Test case #1:
Najdalje je radijator koji ima temperaturu 30.2, a najbliže radijator koji ima temperaturu 41.1
Primjer ulaza:
5
34.1 35.2 30.2 37.7 41.1
Primjer izlaza:
Razlika je 10.9 C.
Test case #2:
Primjer ulaza:
1
33.3
Primjer izlaza:
Razlika je 0.0 C.
*/

int main() {

int N;
float radtemp[10];
scanf("%d", &N);
for (int i = 0; i < N; i++) {
	scanf("%f", &radtemp[i]);
}
float najmanja = radtemp[0];
for (int i = 0; i < N; i++) {
	if (najmanja > radtemp[i]) {
		najmanja = radtemp[i];
	}
}
float najvisa = radtemp[0];
for (int i = 0; i < N; i++) {
	if (najvisa < radtemp[i]) {
		najvisa = radtemp[i];
	}
}
float razlika = najvisa - najmanja;
printf("Razlika je %.1f C.", razlika);
return 0;
}
