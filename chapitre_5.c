#include <sys/mman.h>
#include <stdint.h>
#include <stdio.h>

uint32_t sommeA(uint32_t tab[], uint64_t taille){
    uint32_t resultat = 0;
    uint64_t i = 0;
    for(; i<taille; ++i){
        resultat += tab[i];
    }
    return resultat;
}

uint32_t sommeB(uint32_t *p, uint64_t taille){
    uint32_t resultat = 0;
    uint32_t *end = p + taille;
    for(; p<end; ++p){
        resultat += *p;
    }
    return resultat;
}

uint8_t matrice[2][3] = {1,2,3,4,5,6};

uint8_t matriceEnLigne(void){
    for(int i=0; i< 2; ++i){ 
        for(int j = 0; j<3; ++j){
            printf("%3d", matrice[i][j]);
        }
        printf("\n");
    }
}

uint8_t c0[2] = {1,4};
uint8_t c1[2] = {2,5};
uint8_t c2[2] = {3,6};

uint8_t *mat[3] = {c0, c1, c2};

void pointer(void){
    for(int i = 0; i<2; ++i){
        for(int j=0; j<3; j++){
            printf("%3d", mat[j][i]);
        }
        printf("\n");
    }
}


int main(void){
    matriceEnLigne();

    pointer();

    uint8_t *p = mmap(
        0x0000000001000000,
        0x4000,
        PROT_READ | PROT_WRITE,
        MAP_ANONYMOUS | MAP_PRIVATE,
        -1,
        0);
    printf("%p\n", p);

    p[0] = 17;
    printf("Escreveu: %d\n", p[0]);
    getchar();
    printf("Read: %d\n", p[0]);
    return getchar();
}

// OUTPUT : 0x1000000
