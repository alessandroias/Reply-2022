#include <stdio.h>
#include <stdlib.h>

#include <pthread.h>

typedef struct seatsP
{
    unsigned tc;
    unsigned S;
    unsigned D;

    unsigned *initial;
    unsigned *buffer;
    unsigned *newSeats;
} seatsP_t;

void copyArray(unsigned *src, unsigned *dest, unsigned n)
{
    for (unsigned i = 0; i < n; i++)
        dest[i] = src[i];
}

void fillArray(unsigned *dest, unsigned n)
{
    for (unsigned i = 0; i < n; i++)
        dest[i] = i;
}

void showArray(unsigned *vect, unsigned n)
{
    for (unsigned i = 0; i < n; i++)
        printf(" %u", vect[i]);
}

void solveSeating(void *args)
{
    seatsP_t seat = * (seatsP_t *) args;

    unsigned si;
    unsigned *temp;

    fillArray(seat.initial, seat.S);
    fillArray(seat.buffer, seat.S);

    for (unsigned d = 0; d < seat.D; d++)
    {
        for (si = 0; si < seat.S; si++)
            seat.buffer[seat.newSeats[si]] = seat.initial[si];

        copyArray(seat.buffer, seat.initial, seat.S);
    }
}

int main(int argc, char const *argv[])
{

    FILE *fp;

    fp = fopen(argv[1], "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Ouch.");
        exit(1);
    }

    unsigned T;
    unsigned tc;

    pthread_t *PTs;
    seatsP_t *Ts;

    fscanf(fp, "%u", &T);

    Ts = malloc(sizeof(seatsP_t) * T);
    PTs = malloc(sizeof(pthread_t) * T);

    for (tc = 0; tc < T; tc++)
    {
        Ts[tc].tc = tc;
        fscanf(fp, "%u %u\n", &Ts[tc].S, &Ts[tc].D);


        Ts[tc].initial = malloc(sizeof(int) * Ts[tc].S);
        Ts[tc].buffer = malloc(sizeof(int) * Ts[tc].S);
        Ts[tc].newSeats = malloc(sizeof(int) * Ts[tc].S);
        for (unsigned s = 0; s < Ts[tc].S; s++) {
            fscanf(fp, "%u", &Ts[tc].newSeats[s]);
        }

        // Start Threading
        pthread_create(&PTs[tc], NULL, (void *) solveSeating, (void *) &Ts[tc]);
    }

    for (tc = 0; tc < T; tc++)
        pthread_join(PTs[tc], NULL);

    
    for (tc = 0; tc < T; tc++) {
        printf("Case #%u:", Ts[tc].tc + 1);
        showArray(Ts[tc].initial, Ts[tc].S);
        printf("\n");

        free(Ts[tc].initial);
        free(Ts[tc].buffer);
        free(Ts[tc].newSeats);
    }

    fclose(fp);

    return 0;
}
