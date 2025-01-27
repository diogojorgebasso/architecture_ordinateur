#include <stdlib.h>

void a(int*tab, int*l, int*u){
    register int i, lo, up,v;
    lo = tab[0];
    up = tab[0];
    for(i=1;i<sizeof(tab)/sizeof(tab[0]); i++){
        v=tab[i];
        if(v<lo){
            lo=v;
        }
        if(v>up){
            up=v;
        }
    }
    *l = lo;
    *u=up;
    return;
}

void b(int*tab, int*l, int*u){
    register int i,lo,up,v1,v2;
    lo = tab[0];
    up = tab[0];
    for(i=1;i<sizeof(tab)/sizeof(tab[0]); i+=2){
        v1=tab[i];
        v2=tab[i+1];
        if(v1<v2){
            if(v1<lo){
                lo=v1;
            }
            if(v2>up){
                up=v2;
            }
        } else{
            if(v2<lo){
                lo=v2;
            }
            if(v1>up){
                up=v1;
            }
        }
    }
    *l = lo;
    *u=up;
    return;
}

int compte(int n, int *tab){
    int s;

    for(int i=0; i<n; ++i){
        if(tab[i]<50) s+=1;
        return s;
    }
}

int main(){
    int size = 10;
    int *tab = malloc(size*sizeof(int));
    compte(size, tab);
    return 0;
}