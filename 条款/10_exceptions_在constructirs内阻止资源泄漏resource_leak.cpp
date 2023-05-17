#include <iostream>			    
#include <string>
#include <list>
#include <memory>
using namespace std;

template<class T>
class Auto_ptr {
public:
	Auto_ptr(T* const  ptr) :ptr(ptr) {}

	~Auto_ptr() { delete ptr; }
private:
	T* const ptr;
};

class Image {
public:
	Image(const string& imageDateFileName) {};
};

class AudioClip {
public:
	AudioClip(const string& audioDateFileName) {};
};

class PhoneNumber {
public:
//	PhoneNumber(const string& PhoneNumbers) {};
};

class BookEntry {
public:
	BookEntry(const string& name,
		  	  const string& address = "",
			  const string& imageFileName = "",
			  const string& audioClipFileName = "");


	~BookEntry() {}

private:
	string theName;
	string theAddress;
	list<PhoneNumber> thePhones;

	const auto_ptr<Image> theImage;
	const auto_ptr<AudioClip> theAudioClip;
};


BookEntry::BookEntry(const string& name,
					const string& address,
					const string& imageFileName,
					const string& audioClipFileName)
:theName(name), theAddress(address),
theImage(imageFileName != "" 
		 ? new Image(imageFileName)
		 : 0 ),
theAudioClip(audioClipFileName != ""
			? new AudioClip(audioClipFileName)
			: 0)
{ }


void testBookEntryClass() {
	BookEntry* pd = new BookEntry("a", "b", "c", "e");


	delete pd;
}




int main(void) { 

	try {
		testBookEntryClass();
	}catch(...) {
		cout << "exception" << endl;
	}



	system("pause");
	return 0;
}