#include <string>
#include <windows.h>
#include <iostream>
#include <fstream>
#include <map>
#include "Scanner.h"
#include "Parser.h"

using namespace std;

bool check_existence(string);
int ExeExpression(Scanner);


int main(){
	HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
	string s,data,lex, prev_string;
	
	ifstream infile; 
	infile.open("VARTEST.go"); 
	
    if (!infile) {
        cout << "Unable to open file";
        exit(1); // terminate with error
    }
    int i =0;
    while(infile) {
    	getline (infile, data);
        s = s + data;
    }
    infile.close();
    
    Parser p;
	Scanner scan;
	scan.accept(s);
	
	Scanner::TOKEN_CODE t;
	
	
	
	//variable side
	do {
		bool isKeyword;
		t = scan.next_token();
		
		lex =  scan.lexeme_string();
		isKeyword = check_existence(lex);
		
		if(lex != "variable"){
			if(prev_string != ""){
				p.insert_to_hashmap(lex, prev_string);
				prev_string="";	
			}
			if(isKeyword){
				prev_string = lex;
			}
		}
		
	} while (lex != "code");
	
	
	//code side
	do {
		bool isKeyword;
		string token;
		t = scan.next_token();
		
		lex =  scan.lexeme_string();
		isKeyword = check_existence(lex);
		
		if(isKeyword){
			
			//If PUT
			if(lex == "PUT"){
				string STG_VAL, VAR_NAME, VAR_TYPE;
				int INT_VAL;
				bool BLN_VAL, VAR_EXIST;
	
				while(scan.lexeme_string() != ";"){
					t = scan.next_token();
					lex =  scan.lexeme_string();
					
					//convert
					if(t == Scanner::DIGIT){
						lex = scan.lexeme_string();
						INT_VAL = lex[0] - '0';
						
						
					}else if(t == Scanner::STR){
						lex = scan.lexeme_string();
						STG_VAL = lex;
						
					} 
					
					if(lex == "IN"){
						
						t = scan.next_token();
						
						VAR_EXIST = p.general_lookup(scan.lexeme_string());
						
						if(VAR_EXIST){
							
							VAR_NAME = scan.lexeme_string();
							
						}else{
							
							cout<<"Variable does not exist"<<endl;
						}
					}
					
				} // end of while loop

				//checking what Variable Data Type
				VAR_TYPE = p.lookup(VAR_NAME);
				
				//inserting the values
				if(VAR_TYPE == "INT"){
					p.insert_to_HashINT(VAR_NAME,INT_VAL);
				}else if(VAR_TYPE == "STG"){
					p.insert_to_HashSTG(VAR_NAME, STG_VAL);
				}
			} // end of IF PUT
			
			
			
			
			//if PRT
			else if(lex == "PRT"){
	
				while(scan.lexeme_string() != ";"){
					t = scan.next_token();
					lex = scan.lexeme_string();
					
					if(check_existence(lex)){
						int result = ExeExpression(scan);
						cout<<result<<endl;
						
						
					}else{
						string type = p.lookup(lex);
						if(type != "0"){
							p.print(type, lex);
						}
						
					}
					
					
					
				}
				
			}
		}
		
		
	} while (t != Scanner::EOF_TOKEN);
	
	
	//end of Main
	return 0;
}
	
//For keyword List
bool check_existence(string lex){
	//HANDLE h = GetStdHandle( STD_OUTPUT_HANDLE );
		
	KeywordList kw;
	KeywordList::KW_CODES t;
		
	//search "write"
	t = kw.search(lex);
		
	//display result
	if (t == KeywordList::NOT_FOUND){
		//SetConsoleTextAttribute(h, 4);
		//cout <<lex<< " is not found..."<<endl;
		return false;
	}else{
		//SetConsoleTextAttribute(h, 2);
		//cout <<lex<< " is alright!"<<endl;
		return true;
	}
}


int ExeExpression(Scanner scan){
	Scanner::TOKEN_CODE t;
	string lex;
	int leftOprand, rightOperand;
	
	
	
	Parser p;
	
	if(lex == "ADD" || lex == "SUB" || lex == "MUL" || lex == "DIV" || lex == "MOD"){
		
		lex = scan.lexeme_string();
		t = scan.next_token();
		
		leftOprand = ExeExpression(scan);
		cout<<"Left: "<<leftOprand<<endl;
		rightOperand = ExeExpression(scan);
		cout<<"Right: "<<rightOperand<<endl;
		
		if(lex == "ADD" ){
			return leftOprand + rightOperand;
		}else if(lex == "SUB" ){
			return p.FACILE_SUB(leftOprand, rightOperand);
		}else if(lex == "MUL"){
			return p.FACILE_MUL(leftOprand, rightOperand);
		}else if(lex == "DIV"){
			return p.FACILE_DIV(leftOprand, rightOperand);
		}else if(lex == "MOD"){
			return p.FACILE_MOD(leftOprand, rightOperand);
		}
	
	}
	
	if(p.general_lookup(lex)){
		return p.get_INT_hashval(lex);
	}else{
		//lex = scan.lexeme_string();
		cout<<"Lex is: "<<lex<<endl;
		return lex[0] - '0';
	}

}