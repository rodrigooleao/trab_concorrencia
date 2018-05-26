
#define TAMBUCKET 1024
#define fhash(i) (i*2654435761) % TAMBUCKET

typedef struct{
    pthread_mutex_t lock;
    vector<int> l;
}lista;

class meuhash{

	
    
	public:
		int get(int chave);
		void put(int chave);
};
