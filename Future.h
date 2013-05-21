#ifndef FUTURE
#define FUTURE

template <class T> class Future
{
private:
	
public:
	Future();
	~Future();
	T get();
	bool isReady();
};
#endif