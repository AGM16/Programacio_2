#include"StringClass.h"
#include<string.h>
#include<assert.h>


//----------------------------------------------------------------------
//CONSTRUCTORS
//-----------------------------------------------------------------------
StringClass::StringClass()
{
	in_length = 1;
	c_word = new char[in_length];
	c_word[0] = '\0';

}

StringClass::StringClass(const char* b)
{
	in_length = strlen(b) + 1;
	c_word = new char[in_length];
	strcpy_s(c_word, in_length, b);

}

StringClass::StringClass(const StringClass& b)
{
	
	in_length = strlen(b.c_word) + 1;
	c_word = new char[in_length];
	strcpy_s(c_word, in_length + 1, b.c_word);
	

}



//-------------------------------------------------------------------------
//DESTRUCTOR
//-------------------------------------------------------------------------
StringClass::~StringClass()
{

	delete[]c_word;

}




//-------------------------------------------------------------------------
//OPERATORS
//-------------------------------------------------------------------------
bool StringClass::operator==(const char* b)const
{
	assert(b != NULL);
		
	if (strcmp(b, c_word) == 0){
		
		return true;
	}
	else
		return false;

}

bool StringClass::operator!=(const char* b) const
{
	assert(b != NULL);

	if (strcmp(c_word, b) == 0)
	{
		return false;
	}

	return true;
}


bool StringClass::operator==(const StringClass& b) const
{
	return strcmp(b.c_word, c_word) == 0;

}

bool StringClass::operator!=(const StringClass& b) const
{
	if (strcmp(c_word, b.c_word) == 0)
	{
		return false;
	}

	return true;
}

const StringClass& StringClass::operator=( const char* b)
{
	
	if (b != NULL)
	{
		 
		if ((strlen(b) + 1) > in_length)
		{
			delete[] c_word;
			c_word = new char[strlen(b) + 1];
		}
		else
			Clear();

		strcpy_s(c_word, strlen(b) + 1, b);
	}
	else
	{
		Clear();
	}

	return(*this);
}


const StringClass& StringClass::operator=( StringClass& b)
{
	 
		if ((strlen(b.c_word)  + 1) > in_length)
		{
			in_length = strlen(b.c_word);
			Create_Mem(*this, strlen(b.c_word) + 1);
		}
		else
		Clear();

		strcpy_s(c_word, b.in_length, b.c_word);
	
	    return (*this);

}


/*const StringClass& StringClass::operator+=(const char* b)
{
}

const StringClass& StringClass::operator+=(const StringClass& b)
{
}*/



//-------------------------------------------------------------------------
//METHODS
//-------------------------------------------------------------------------
int StringClass::Length()const
{

	return strlen(c_word);

}

int StringClass::Capacity()const
{

	return (sizeof(c_word) / sizeof(char));

}

void StringClass::Clear()
{
	if (c_word != NULL)
	{
		c_word[0] = '\0';
	}

	in_length = 0;
}

void StringClass::Create_Mem(StringClass& b, int in_length)
{
	 b.in_length = in_length;
	 b.c_word = new char[in_length];

}





