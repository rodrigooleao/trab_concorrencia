#include <vector>
#include <iostream>
#include <pthread.h>
#include <cstdio>
#include <utility>

#define TAMBUCKET 1024
#define fhash(i) (i*2654435761) % TAMBUCKET

typedef struct{
    pthread_mutex_t lock;
    vector<int> l;
}lista;

class meuhash{

    vector<int, lista> hash;
	public:
		int get(int chave);
		void put(int chave);
};
