#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

void ex1(int argc, char* argv[]){
    for(int i = 0 ; i < argc ; i++){
        printf("address %p, de %zu\n", (void *)argv[i], strlen(argv[i]));
    }
}

void ex2(int argc, char* argv[]){
    signed char d;
    unsigned char c = 150;

    memcpy(&d, &c, 1);

    printf("%hhi\n", d);
}

void ex3(int argc, char* argv[]){
    signed char * q;
    unsigned char c = 150;
    unsigned char *p;

    p = &c;
    memcpy(&q, &p, sizeof(p));
    printf("%hhu\n", *p);
    printf("%hhi\n", *q);
}

void acces_seq(int *tab, int n){
    uint64_t tic, toc;
    unsigned int _pid;

    tic = __rdtscp(&_pid);
    for(int i=0; i<n; i++){
        tab[i] = i;
    }
    toc = __rdtscp(&_pid);

    printf("SEQ: %lu\n", (toc-tic)/CLOCKS_PER_SEC);
}

void acces_alea(int *tab, int n){
    uint64_t tic, toc;    
    unsigned int _pid;

    tic = __rdtscp(&_pid);
    for(int i=0; i<n; i++){
        tab[rand() % n] = i;
    }
    toc = __rdtscp(&_pid);

    printf("ALE: %lu\n", (toc-tic)/CLOCKS_PER_SEC);

}

int power(int base, int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
 }


int main(){

    srand(time(NULL)); //random initialize

    int n= 1000;
    int *tab = (int *)malloc(n*sizeof(int));
    acces_seq(tab, n);
    acces_alea(tab, n);

    for(int i = 6; i<10; i++){
        printf("n = %d", n);
        int n = power(10, i);
        int *tab = (int *)malloc(n*sizeof(int));
        acces_seq(tab, n);
        acces_alea(tab, n);
    }


    free(tab);
    return 0;
}