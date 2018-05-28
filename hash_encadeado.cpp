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
        for (int i=0; i<hash[index].l.size(); i++) {
            if (hash[index].l[i] == chave) result = hash[index].l[i];
        }
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