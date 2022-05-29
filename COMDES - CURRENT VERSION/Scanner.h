#include <string>
#include <iostream>
#include "CharMap.h"
#include "KeywordList.h"
using namespace std;
class Scanner
{
	public:
		enum TOKEN_CODE{ERR, WORD,DIGIT, SYMBOL, STRDELIMITER, STR, EOF_TOKEN};
		//constructors
		Scanner();
		Scanner(string);
		
		//public member functions
		void accept(string);
		TOKEN_CODE next_token();
		string token_string();
		string lexeme_string();
		
	private:
		CharMap table;
		string source;
		string lexeme;
		TOKEN_CODE token;
		int cchar_ptr;
		char cchar;
		
		//private member functions
		void skip_whitespace();
		char get_source_char();
		char prefix_char();
		
		void word_or_string();
		void get_word_token();
		void get_digit_token();
		void get_symbol_token();
		
		//void get_strdelimiter();
		void get_str_token();
		
		
		void get_token();
		void get_eof_token();
};

//implementation
Scanner::Scanner()
{
	source="";
}
Scanner::Scanner(string s)
{
	accept(s);
}
void Scanner::accept(string s)
{
	source = s;
	cchar_ptr = 0;
	cchar = get_source_char();
}

string Scanner::lexeme_string()
{
	return lexeme;
}

Scanner::TOKEN_CODE Scanner::next_token()
{
	skip_whitespace();
	
	//check first non-whitespace
	switch(table.type(cchar)) 
	{
		case CharMap::LETTER:
			get_word_token();
			break;
		case CharMap::SYMBOL:
			get_word_token();
			break;
		case CharMap::DIGIT:
			get_digit_token();
			break;
		case CharMap::SSYMBOL:
			get_symbol_token();
			break;
		case CharMap::STRDELIMITER:
			get_str_token();
			break;
		case CharMap::EOF_TYPE:
			get_eof_token();
			break;
	}
	return token;
}	
void Scanner::skip_whitespace()
{
	while(table.type(cchar)==
	CharMap::WHITESPACE)
	cchar = get_source_char();
}

char Scanner::get_source_char()
{
	char c;
	if (cchar_ptr + 1 <= source.size())
	c = source.at(cchar_ptr++);
	else
	c = CharMap::EOF_CHAR;
	return c;
}

void Scanner::get_word_token()
{
	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
	lexeme = cchar;
	for(;;){
		cchar = get_source_char();
		if(table.type(cchar)== CharMap::LETTER||table.type(cchar)== CharMap::SYMBOL && table.type(cchar) != CharMap::WHITESPACE){
			lexeme+=cchar; //append chars
		}
		else{
			break;
		}
	}
	
	token=WORD;
}
void Scanner::get_digit_token()
{
	lexeme = cchar;
	cchar = get_source_char();
	token=DIGIT;
}
void Scanner::get_symbol_token()
{
	lexeme = cchar;
	cchar = get_source_char();
	token=SYMBOL;
}

//Added by Joshua
void Scanner::get_str_token()
{
	lexeme = "";
	
	for(;;){
		cchar = get_source_char();
		if(table.type(cchar) != CharMap::STRDELIMITER){
			lexeme += cchar;
		}else if (table.type(cchar) == CharMap::STRDELIMITER){
			cchar = get_source_char();
			break;
		}
		else{
			break;
		}
	}
	token=STR;
}

void Scanner::get_eof_token()
{
	lexeme = ""; token = EOF_TOKEN;
}
string Scanner::token_string()
{
	string msg[]={"error","word","digit","symbol","strdelimiter","string","eof"};
	string s = msg[token];
	return s;
}
