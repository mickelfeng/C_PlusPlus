#include <iostream>
#include <string>
using namespace std;

void strcpys(char* ls1, const char* ls2) {
	char* temp = const_cast<char*>(ls2);
	
	do{
		*ls1 = *temp;
		ls1++; temp++;
	} while (*temp);

	*ls1 = '\0';
}


class String {
public:
	String(const char* initValue = "");
	String(const String& rhs);

	const char& operator[](int index) const;
	char& operator[](int index);

	
	void Show_Stirng(void) {
		this->value->Show_Value();
	}
	
	String& operator=(const String& rhs);

	~String();
private:

	struct StringValue {
		int   refCount;
		char* data;
        bool  shareable;   // 表示是否可以共享的 flag
        
		void Show_Value(void) {
			cout << "date: " << data << ", refCount: " << refCount << endl;
		}

		StringValue(const char* initValue);
		~StringValue();
	};

	StringValue* value;
};


String::StringValue::StringValue(const char* initValue) 
:refCount(1),
 shareable(true)
{
	data = new char[strlen(initValue) + 1];
	strcpys(data, initValue);
}

String::StringValue::~StringValue() {
	delete[] data;
}


String::String(const char* initValue)
:value(new StringValue(initValue))
{}

String::String(const String& rhs)
{
    if(rhs.value->shareable){
        value = rhs.value;
        value->refCount++;
    }else{
        value = new StringValue(rhs.value->data);
    }
	
}

String& String::operator=(const String& rhs) {
	if (value == rhs.value) {
		return *this;
	}

	if ((value->refCount -- ) == 0) {
		delete value;
	}

	value = rhs.value;
	++value->refCount;
	
	return  *this;
}

String::~String() {
	value->refCount -= 1;
	if ((value->refCount) == 0)
		delete value;
}

const char& String::operator[](int index) const {
	return value->data[index];
}

char& String::operator[](int index) {
	if (value->refCount > 1) {
		value->refCount--;
		value = new StringValue(value->data);
	}
    value->shareable = false;  // flag to false
	return value->data[index];
}




int main(void) {

	String* as = new String("one");

	as->Show_Stirng();

	String* bs = new String(*as);

	bs->Show_Stirng();


	delete as;
	delete bs;

	return 0;
}
