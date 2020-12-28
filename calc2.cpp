/*


*/

#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include <forward_list>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <array>
#include <regex>
#include<random>
#include<stdexcept>

using namesapace std;

// function declarations
Token get_token();
double expression();
double term();
double primary();
void error(string s);

// class declaration
class Token {
	public:
		char kind;
		double value;
		Token(char ch)    // make a Token from a char
        		:kind(ch), value(0) { }
    		Token(char ch, double val)     // make a Token from a char and a double
        		:kind(ch), value(val) { }
};

void error(string s) {
	throw runtime_error(s);
}

double expression() {
	double left = term();
	Token t = get_token();
	while(true) {
		switch(t.kind) {
			case '+':
				left += term();
				t = get_token();
				break;
			case '-':
				left -= term();
				t.get_token();
				break;
			default:
				return left;
		}
	}
}

double term() {
	double left = primary();
	Token t = get_token();
	while(true) {
		switch(t.kind) {
			case '*':
				left *= primary();
				t = get_token();
				break;
			case '/':
				{
					double d = primary();
					if(d == 0) {
						error("divide by zero");
					}
					left /= d;
					t = get_token();
					break;
				}
			default:
				return left;
		}
	}
}

double primary() {
	Token t.get_token();
	switch(t.kind) {
		case '(':
			double d = expression();
			t = get_token();
			if (t.kind != ')') {
				error("')' expected");
				return d;
			}
		case '8':
			return t.value;
		default:
			error("primary expected");
	}
}

Token get_token()    // read a token from cin
{
    char ch;
    cin >> ch;    // note that >> skips whitespace (space, newline, tab, etc.)

    switch (ch) {
        //not yet   case ';':    // for "print"
        //not yet   case 'q':    // for "quit"
    case '(': case ')': case '+': case '-': case '*': case '/':
        return Token(ch);        // let each character represent itself
    case '.':
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
    {
        cin.putback(ch);         // put digit back into the input stream
        double val;
        cin >> val;              // read a floating-point number
        return Token('8', val);   // let '8' represent "a number"
    }
    default:
        error("Bad token");
    }
}

//------------------------------------------

int main()
try {
    while (cin)
        cout << expression() << '\n';
    keep_window_open("~0");
}
catch (exception& e) {
    cerr << e.what() << endl;
    keep_window_open("~1");
    return 1;
}
catch (...) {
    cerr << "exception \n";
    keep_window_open("~2");
    return 2;
}



