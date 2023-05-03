# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <cctype>
# include <iostream>
# include <iomanip>
# include <string>
# include <vector>
# include <sstream>

using namespace std ;
static int uTestNum = - 1 ;

enum Type {
  INT, STRING, DOT, FLOAT, NIL, T, QUOTE, SYMBOL, LEFTPAREN, RIGHTPAREN, NO_TYPE
}; // enum Type

bool isNum( char ch ) {
  if ( ch >= '0' && ch <= '9' )
    return true ;
  else
    return false ;
} // isNum()


class TokenNode {

  public :
  char token ;
  Type type ;
  TokenNode * leftNode ;
  TokenNode * rightNode ;
  void identifyType() ;
  void printType() ;
}; // class TokenNode

void ReadSExp() ;
main() {
  char ch = '\0' ;
  char token = '\0' ;
  string str ;
  cout << "Welcome to OurScheme!" << endl ;
  uTestNum = cin.get() ;
  ch = cin.get() ;
  token = cin.get() ;
  do {
    cout << "> " ;
    if ( token != '\0' ) {
      TokenNode * temp ;
      temp = new TokenNode ;
      str.push_back( token ) ;
    } // if
    else cout << "error message" << endl ;
      cout << str << endl ;
    cout << "Welcome to OurScheme!" << endl ;
    token = cin.get() ;
  } while ( token != EOF && token != 'q' ) ; // main()

  cout << "Thanks for using OurScheme!" << endl ;
}

void TokenNode::identifyType() {
  char nextToken = cin.peek() ;
  if ( this -> token >= '0' && this -> token <= '9' )
    this -> type = INT ;
  else if ( this -> token != ' ' || this -> token != '\n' ) {
    if ( nextToken != ' ' || nextToken != '\n' )
      this -> type = STRING ;
  } // else if
  else if ( this -> token == '.' )
    this -> type = DOT ;
  else if ( isNum( this -> token ) && isNum( nextToken ) )
    ;
} // identifyType()