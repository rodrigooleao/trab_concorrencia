#include "aberto.h"


meuhash::meuhash(){
    for( int i = 0 ; i < TAMBUCKET ; i++){
        hash[i] = -1;
    }

    for( int i = 0 ; i < 64 ; i++){
        pthread_mutex_init( &locks[i], NULL);
    }
}
int meuhash::get( int chave){
    int index = fhash(chave);
    int lock_index = index/16;

    int result;

    pthread_mutex_lock(&locks[lock_index]);
    result = hash[index];
    pthread_mutex_unlock(&locks[lock_index]);

    return result;
}

void meuhash::put( int chave){
    int index = fhash(chave);
    int lock_index = index/16;
    int i = index;
    
    pthread_mutex_lock( &locks[lock_index] );

    if( hash[index] != -1){
        hash[index] = chave;
    }
    else{
        do{
            index = (index+1)%TAMBUCKET;

        }while( hash[index] != -1);

        hash[index] = chave;
    }

    pthread_mutex_unlock( &locks[lock_index] );
}