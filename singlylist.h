#ifndef singlylist_h
#define singlylist_h

template<typename T>
	class node
	{ 
	private :
	T data;
	node<T> *Next;
	template<typename T>
	friend class sList;
	public :
	T& getD()const;
	node<T>* getN()const;
	};
template<typename T>
class sList
{
private :

	node<T> *head;
	int n;
	
public :
void print();

sList();

int sizE();

bool isEmpty();

node<T>* findItem(const T &item);
node<T>* getH()const;

void insert(T const & item);

T getFront();

bool removeF();
bool remove(T const & item);

~sList();

};

#endif