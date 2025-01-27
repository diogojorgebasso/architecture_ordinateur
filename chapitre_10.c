#include <stdio.h>
#include <stdint.h>
#include "printing_timing.c"


struct bloc{
    double *adr;
    uint64_t haut,larg,saut; // haut - altura (n linhas); larg (n colunas); saut 
};

void function1(int N){
    uint64_t dum = 0;
    uint64_t *tab = malloc(N*N*sizeof(uint64_t));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dum += tab[i*N+j];
        }
    }
}

void function2(int N){
    uint64_t dum = 0;
    uint64_t *tab = malloc(N*N*sizeof(uint64_t));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            dum += tab[j*N+i];
        }
    }
}

void reset(struct bloc B){
    for(int i=0; i<B.haut; i++){
        for(int j=0; j<B.larg; j++){
            B.adr[i + j*(B.larg + B.saut)] = 0;
        }
    }
}

void affiche(struct bloc B){
        for(int i=0; i<B.haut * B.larg; i++){
            printf("%f\n", B.adr[i]);
    }
}

void init(struct bloc B){
    for(int i=0; i<B.haut*B.larg; i++){
        B.adr[i] = (double) i+1;
    }
}

void transpose_tuile(struct bloc S, struct bloc D, uint64_t T){

}

void transpose(struct bloc S, struct bloc D){
    register uint64_t i,j;
    double* pS = S.adr;
    double* pD;
    for (i=0; i<S.haut; i++){
        pD = D.adr+i;
        for (j=0; j<S.larg; j++){
            *pD = *pS;
            pS += 1;
            pD += D.larg+D.saut;
        }
        pS += S.saut;
    }
}

int main(void){
    int L=12;
    int C=8;

    for(int i=100; i<2500; i+=50){
        print_timing(i, function1, 5, 100);
        print_timing(i, function2, 5, 100);
        printf("\n");
    }

    double *mem = malloc(L*C*sizeof(double));
    struct bloc M ={mem, L, C, 0};
    struct bloc S1 = {M.adr+208, 5, 4, 8};
    struct bloc S2 = {M.adr+167, 5, 4, 8};

    struct bloc S3 = {M.adr, n, n, 0};
    
    return 0;
}

