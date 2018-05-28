#include "encadeado.h"


meuhash::meuhash(){
    for( int i = 0 ; i < TAMBUCKET ; i++){
        lista L;
        pthread_mutex_init(L.lock, NULL);
        hash.push_back(L);
    }
}

int meuhash::get( int chave){
    int index = fhash(chave);
    int result;

    pthread_mutex_lock(hash[index].lock);

    if (hash[index].l.size() == 0) result = -1;
    else {
        result = hash[index].l[0]; //eu nao sei qual elemento da lista é pra ir pro result. Tem que tirar esse elemento da lista?
    }

    pthread_mutex_unlock(hash[index].lock);

    return result;
}

void meuhash::put( int chave){
    int index = fhash(chave);

    pthread_mutex_lock(hash[index].lock);

    hash[index].l.push_back(chave);

    pthread_mutex_unlock(hash[index].lock);
}