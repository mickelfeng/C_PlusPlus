#include <iostream>			    
#include <string>
#include <list>
#include <memory>
#include <complex>
using namespace std;

template<class BeingCounted>
class Counted {
public:
	class ToomanyObjects {};

	static int objects() { return numObjects; }
protected:
	 Counted();
	Counted(const Counted& rhs);
	~Counted() { --numObjects; }
private:
	static int numObjects;
	static const size_t maxObjects;
	void init();
};


template<class BeingCounted>
Counted<BeingCounted>::Counted() {
	init();
}

template<class BeingCounted>
Counted<BeingCounted>::Counted(const Counted&) {
	init();
}

template<class BeingCounted>
void Counted<BeingCounted>::init(){
	if (numObjects >= maxObjects)throw ToomanyObjects();

	++numObjects;
}


int main(void) {


	return 0;
}