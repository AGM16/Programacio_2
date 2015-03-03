#ifndef STRINGCLASS
#define STRINGCLASS

#define STRING_LENGHT 3000

using namespace std;

class StringClass{

public:

	char* c_word;
	int in_length;



	//Constructors
	StringClass();
	StringClass(const char* b);
	
	//StringClass(const char* b,...);
	StringClass(const StringClass& b);

	//DESTRUCTOR
	~StringClass();

	//OPERATORS
	bool operator==(const char* b)const;
	bool operator!=(const char* b)const;

	bool operator==(const StringClass& b)const;
	bool operator!=(const StringClass& b)const;

	const StringClass& operator=( const char* b);
	const StringClass& operator=( StringClass& b);

	const StringClass& operator+=(const char* b);
	const StringClass& operator+=(const StringClass& b);

	//Methods
	int Length()const;
	int Capacity()const;
	char* Getc_Word()const{ return c_word; }
	void Clear();
	void Create_Mem(StringClass& b, int in_length);

};
#endif