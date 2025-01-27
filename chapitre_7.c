#include <x86intrin.h>
#include <stdint.h>
#include <stdio.h>

void print_timing(int mon_arg, void (*ma_function)(int)){
    uint64_t tic,toc;
    unsigned int _pid;

    tic = __rdtscp(&_pid);

    ma_function(mon_arg);

    toc = __rdtscp(&_pid);
    printf("%d", (toc-tic) << 32 );
}

void test(int a){
    for(int i = 0; i<a; i++){
        printf("%d", a*a);
    }
    printf("\n");
}

int main(void){
    print_timing(12, &test);
    return 0;
}