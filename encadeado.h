
#define TAMBUCKET 1024
#define fhash(i) (i*2654435761) % TAMBUCKET


class meuhash{

	int hash[TAMBUCKET];
    pthread_mutex_t locks[64];	
    
	public:
		int get(int chave);
		void put(int chave);
};
