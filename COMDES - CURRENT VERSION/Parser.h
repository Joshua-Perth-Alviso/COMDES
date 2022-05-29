//Parser.h
#include <string>
#include <map>
using namespace std;

map<string,string> SymbolTable;
map<string,string> HashSTG;
map<string,int> HashINT;
map<string,bool> HashBLN;

class Parser{
	public:
		
		void insert_to_hashmap(string, string); //Inserting
		
		 //Inserting per Data Type
		void insert_to_HashINT(string, int);
		void insert_to_HashSTG(string, string);
		
		//Looking for hashmap Value Existence
		string lookup(string); 
		bool general_lookup(string);
		
		//getter
		int get_INT_hashval(string);
		
		//Arithmetic Operations
		int FACILE_ADD(int, int);
		int FACILE_SUB(int, int);
		int FACILE_MUL(int, int);
		int FACILE_DIV(int, int);
		int FACILE_MOD(int, int);
		
		
		//for printing
		void print(string, string);
	
};


//Symbol Table Functions
void Parser::insert_to_hashmap(string key, string hash){
	
	//Storing the Variables in a General Table
	SymbolTable.insert(pair<string, string>(key,hash));
	
	//Storing the Variables in a Hash Map per Data Type
	if(hash == "STG"){
		HashSTG.insert(pair<string, string>(key," "));
		
	}else if(hash == "INT"){
		HashINT.insert(pair<string, int>(key,0));
		
	}else if(hash == "BLN"){
		HashBLN.insert(pair<string, bool>(key,true));
	}
	
}


//Lookign for Variables Functions
bool Parser::general_lookup(string key){
	if(SymbolTable.find(key) != SymbolTable.end()){
		return true;
	}else{      
		return false;
	}
}

string Parser::lookup(string key){
	
	if(HashSTG.find(key) != HashSTG.end()){
		//cout<<key<<" is a STRING"<<endl;
		return "STG";
		
	}else if(HashINT.find(key) != HashINT.end()){
		//cout<<key<<" is an INTEGER"<<endl;
		return "INT";
		
	}else if(HashBLN.find(key) != HashBLN.end()){
		//cout<<key<<" is a BOOLEAN"<<endl;
		return "BLN";
		
	}else{      
		return "0";
	}
	
}

//Updating Values in Hashmap functions
void Parser::insert_to_HashINT(string key, int value){
	HashINT[key] = value;
}
void Parser::insert_to_HashSTG(string key, string value){
	HashSTG[key] = value;
}

//Printing
void Parser::print(string type, string var_name){
	
	if(type == "STG"){
		cout<<HashSTG[var_name]<<endl;
	}else if(type == "INT"){
		cout<<HashINT[var_name]<<endl;
	}
	
}

//Getter
int Parser::get_INT_hashval(string var_name){
	return HashINT[var_name];
}

//Arithmetic Operations
int Parser::FACILE_ADD(int exp1, int exp2){
	return exp1 + exp2;
}
int Parser::FACILE_SUB(int exp1, int exp2){
	return exp1 - exp2;
}
int Parser::FACILE_MUL(int exp1, int exp2){
	return exp1 * exp2;
}
int Parser::FACILE_DIV(int exp1, int exp2){
	return exp1 / exp2;
}
int Parser::FACILE_MOD(int exp1, int exp2){
	return exp1 % exp2;
}




