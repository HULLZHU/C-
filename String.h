#ifndef STRING_H_
#define STRING_H_

#include<iostream>
#include<cstring>
using namespace std;
namespace STRING {
	class String
	{
	private:
		char *str;
		int len;
		static int num_strings;
		static const int CINLIMIT = 80;
	public:
		//constructors and methods
		String(const char *s);//constructor
		String();
		String(const String &);
		~String();
		int length()const { return len; };
		char *strval()const { return str; };
		//overloaded operator methods
		String &operator = (const String &);
		String &operator = (const char*);
		char &operator[](int i);
		const char & operator[](int i)const;
		//overloaded operator friends
		friend bool operator<(const String &st, const String &st2);
		friend bool operator>(const String &st, const String &st2);
		friend bool operator==(const String &st, const String & st2);
		friend ostream& operator<<(ostream & os, const String &st);
		friend istream& operator>>(istream &is, String &st);
		//static function
		static int howmany();
	};

	//initialize static class member
	int String::num_strings = 0;

	//static method
	int String::howmany()
	{
		return num_strings;
	};

	//class methods
	String::String(const char *s)
	{
		len = std::strlen(s);
		str = new char[len + 1];
		strcpy(str, s);
		num_strings++;
	};

	String::String()
	{
		len = 4;
		str = new char[1];
		str[0] = '\0';
		num_strings++;
	};

	String::String(const String &st)
	{
		num_strings++;
		len = st.length();
		str = new char[len + 1];//allocate space
		strcpy(str, st.strval());
	};

	String::~String()
	{
		--num_strings;
		delete[] str;
	};

	//overloaded operator methods
	String &String::operator=(const String &st)
	{
		if (this == &st)
			return *this;
		delete[] str;
		len = st.length();
		str = new char[len + 1];
		strcpy(str,st.strval());
		return *this;
	};

	String &String::operator=(const char *s)
	{
		delete[] str;
		len = strlen(s);
		str = new char[len + 1];
		strcpy(str, s);
		return *this;
	};

	//read-write char access for non-constant String
	char &String::operator[](int i)
	{
		return str[i];
	};

	//read-only char access for const String
	const char& String::operator[](int i)const
	{
		return str[i];
	};

	//overloaded operator friends
	bool operator<(const String &st1, const String &st2)
	{
		return (std::strcmp(st1.strval(), st2.strval()));
	};

	bool operator>(const String&st1, const String &st2)
	{
		return st2.strval() < st1.strval();
	};

	bool operator==(const String & st1, const String &st2)
	{
		return (strcmp(st1.strval(), st2.strval()) == 0);
	};

	ostream &operator<<(ostream &os, const String &st)
	{
		os << st.strval();
		return os;
	};

	//quick and dirty input
	istream &operator>>(istream &is, String &st)
	{
		char temp[String::CINLIMIT];

		is.get(temp, String::CINLIMIT);

		if (is)
			st = temp;

		while (is && is.get() != '\n')
			continue;
		return is;
	};
}
#endif
