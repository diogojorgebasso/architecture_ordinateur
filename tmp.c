#include <stdio.h>
#include <stdint.h>
#include <x86intrin.h>
struct bloc{
    double *adr;
    uint64_t haut,larg,saut; // haut - altura (n linhas); larg (n colunas); saut 
};

void print_timing(struct bloc S, struct bloc D, void(*test)(struct bloc A, struct bloc B), int num_amorcage, int num_moyennage) {
	uint64_t tic, toc;
	unsigned int _pid;
	uint64_t list[num_moyennage];

	for (int i = 0; i < num_amorcage; ++i) {
		test(S, D);
	}

	for (int i = 0; i < num_moyennage; ++i) {
		tic = __rdtscp(&_pid);
		test(S,D);
		toc = __rdtscp(&_pid);
		uint64_t timing = toc - tic;
		list[i] = timing;
	}
	uint64_t sum = 0;
	for (int i = 0; i < num_moyennage; ++i) {
		sum += list[i];
	}
	uint64_t mean = (sum / num_moyennage);

	printf("%lu\n", mean);
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

void transpose_tuile(struct bloc S, struct bloc D, uint64_t T){
    transpose(S.adr);
}


int main(void){
    
    for(int i=100; i<2501; i+=50){
        double *mem = malloc(i*i*sizeof(double)); // nao importa os valores da matrix
        double *mem2 = malloc(i*i*sizeof(double));
        struct bloc S ={mem, i, i, 0};
        struct bloc D ={mem2, i, i, 0};
        print_timing(S, D, transpose, 5, 10);
    }
    
    return 0;
}

