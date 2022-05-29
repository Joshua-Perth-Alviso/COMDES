class CharMap
{
	/*
	0 - whitespace 
	1 - Letter 
	2 - Digits 
	3 - Symbols (non-alphanumeric)
	4 - Special Symbols - Facile
	5 - EOF type
	*/
	public:
		static const char EOF_CHAR = 127;
		enum CHAR_TYPE {WHITESPACE, LETTER,
		DIGIT, SSYMBOL, STRDELIMITER, SYMBOL,
		EOF_TYPE};
		CharMap();
		CHAR_TYPE type(char);

	private:
		 static const int ALL_CHARS = 256;
		 CHAR_TYPE char_table[ALL_CHARS];

};

CharMap::CharMap()
{
	 int i;
	 //initialize all to symbol
	 for(i=0;i<ALL_CHARS;i++)
	 char_table[i]= SYMBOL;
	
	 //letters
	 for(i='A';i<='Z';i++)
	 char_table[i]=LETTER;

	 for(i='a';i<='z';i++)
	 char_table[i]=LETTER;

	 //digits
	 for(i='0';i<='9';i++)
	 char_table[i]=DIGIT;
	
	 //special symbol characters
	 char_table[';']=SSYMBOL;
	 char_table['{']=SSYMBOL;
	 char_table['}']=SSYMBOL;
	 
	  //String Delimiter
	 char_table['$']=STRDELIMITER;
	 
	 //whitespaces	`
	 char_table[' ']=WHITESPACE;
	 char_table['	']=WHITESPACE;

	 //temporary EOF char
	 char_table[EOF_CHAR]=EOF_TYPE;
}
	
CharMap::CHAR_TYPE CharMap::type(char c)
{
	return char_table[c];
}


