//KeywordList.h
#include <vector>
#include <string>
using namespace std;
class KeywordList
{
	public:
		KeywordList(); //constructor
		// the keyword's token codes
		enum KW_CODES {NOT_FOUND = -1,ADD,AND,ASK,BLN,DIV,EQL,GRE,
		GRT,INN,INT,LEE,LET,MOD,MUL,NON,OHR,PRT,PUT,STG,SUB,CODE,VARIABLE};
		
		// search 4 keyword, then return
		// the equivalent token
		KW_CODES search(string key);
	
	private:
		vector<string> kwlist;
		vector<KW_CODES> kwcodes;
};
KeywordList::KeywordList()
{
	//predefined list of keywords
	kwlist.push_back("ADD");
	kwlist.push_back("AND");
	kwlist.push_back("ASK");
	kwlist.push_back("BLN");
	kwlist.push_back("DIV");
	kwlist.push_back("EQL");
	kwlist.push_back("GRE");
	kwlist.push_back("GRT");
	kwlist.push_back("IN");
	kwlist.push_back("INT");
	kwlist.push_back("LEE");
	kwlist.push_back("LET");
	kwlist.push_back("MOD");
	kwlist.push_back("MUL");
	kwlist.push_back("NON");
	kwlist.push_back("OHR");
	kwlist.push_back("PRT");
	kwlist.push_back("PUT");
	kwlist.push_back("STG");
	kwlist.push_back("SUB");
	kwlist.push_back("code");
	kwlist.push_back("variable");
	

	//and the corresponding token codes

	kwcodes.push_back(ADD);
	kwcodes.push_back(AND);
	kwcodes.push_back(ASK);
	kwcodes.push_back(BLN);
	kwcodes.push_back(DIV);
	kwcodes.push_back(EQL);
	kwcodes.push_back(GRE);
	kwcodes.push_back(GRT);
	kwcodes.push_back(INN);
	kwcodes.push_back(INT);
	kwcodes.push_back(LEE);
	kwcodes.push_back(LET);
	kwcodes.push_back(MOD);
	kwcodes.push_back(MUL);
	kwcodes.push_back(NON);
	kwcodes.push_back(OHR);
	kwcodes.push_back(PRT);
	kwcodes.push_back(PUT);
	kwcodes.push_back(STG);
	kwcodes.push_back(SUB);
	kwcodes.push_back(CODE);
	kwcodes.push_back(VARIABLE);
}
KeywordList::KW_CODES
KeywordList::search(string key)
{
	//perform binary search
	int bottom = 0;
	int top = kwlist.size()- 1;
	int mid;
	
	bool found = false;
	while (bottom <= top && found==false)
	{
		mid = (bottom + top ) / 2;
		if (kwlist.at(mid)==key)
			found=true;
		else if (kwlist.at(mid) > key)
			top = mid - 1;
		else
			bottom = mid + 1;
	}
	if (found) //return the token code
		return kwcodes.at(mid);
	else
		return NOT_FOUND;
}
