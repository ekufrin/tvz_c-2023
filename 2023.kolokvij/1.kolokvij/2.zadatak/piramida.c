/*DRUGI ZADATAK KOLOKVIJ
Zadatak: upises C(character), broj N i program ce napravit Nx(N-1) matricu al da izgleda ko trokut tipa nesto ovako:

TEST CASE #1
Ulaz:
*
3

Izlaz:
*
**
*

TEST CASE #2
Ulaz:
+
5

Izlaz:
+
++
+++
++
+

*/
int main() {
    float N;
    char C;
    scanf("%c", &C);
    scanf("%f", &N);

       for (int i = 1; i < N/2+1; i++) {
           for (int j = 0; j < i; j++) {
               printf("%c", C);
           }
           printf("\n");
    }
       for (int i = N / 2; i > 0; i--) {
           for (int j = 0; j < i; j++) {
               printf("%c", C);
           }
           printf("\n");
       }
       return 0;
}
