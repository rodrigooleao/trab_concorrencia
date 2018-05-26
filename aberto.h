#include <vector>
#include <pthread.h>
#include <cstdio>
#include <utility>
#include <unordered_map>

#define TAMBUCKET 1024
#define fhash(chave) (chave*2654435761) % TAMBUCKET

class meuhash{

    //int hash[TAMBUCKET];
    pthread_mutex_t locks[64];	
    int hash[TAMBUCKET];
    
	public:
        meuhash();
        
		int get(int chave);
		void put(int chave);
};
