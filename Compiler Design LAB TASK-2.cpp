#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
using namespace std;

struct Symbol {
    string lexeme;
    string tokenType;
};


string keywords[] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","inline","int","long",
    "namespace","new","operator","private","protected","public","register",
    "return","short","signed","sizeof","static","struct","switch","template",
    "this","throw","try","typedef","union","unsigned","virtual","void",
    "volatile","while","class","bool","catch","using","true","false"
};
string parenthesis[] = {"(", ")", "{", "}", "[", "]"};
string operators[] = { "+", "-", "*", "/", "=", "==", "!=", "<", ">", "<=", ">=" };
string separators[] = { ";", ",", ":" };

int keywordCount = sizeof(keywords) / sizeof(keywords[0]);
int parenthesisCount = sizeof(parenthesis) / sizeof(parenthesis[0]);
int operatorCount = sizeof(operators) / sizeof(operators[0]);
int separatorCount = sizeof(separators) / sizeof(separators[0]);

bool isStringLiteral(string s) {
    return s.length() >= 2 && s.front() == '"' && s.back() == '"';
}

bool isKeyword(string s) {
    if (!isStringLiteral(s)) {
        for (int i = 0; i < keywordCount; i++) {
            if (s == keywords[i]) return true;
        }
        return false;
    }
}

bool isParenthesis(string s) {
    if (!isStringLiteral) {
        for (int i = 0; i < parenthesisCount; i++) {
            if (s == parenthesis[i]) return true;
        }
        return false;
    }  
}

bool isOperator(string s) {
    if (!isStringLiteral) {
        for (int i = 0; i < operatorCount; i++) {
            if (s == operators[i]) return true;
        }
        return false;
    }  
}

bool isSeparator(string s) {
    if (!isStringLiteral) {
        for (int i = 0; i < separatorCount; i++) {
            if (s == separators[i]) return true;
        }
        return false;
    }
}

bool isIdentifier(string s)
{
    if (isKeyword(s))
        return false;
    if (!((s[0] >= 'A' && s[0] <= 'Z') || (s[0] >= 'a' && s[0] <= 'z') || s[0] == '_'))
        return false;
    for (int i = 1; i < s.length(); i++)
    {
        if (!((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9') || s[i] == '_'))
            return false;
    }
    return true;
}

bool isConstant(string s) {
    if (!isStringLiteral(s) && !isKeyword(s) && !isOperator(s) && !isSeparator(s) && !isParenthesis(s)) {
        return true;
    }
}


int main() {
    cout << "LEXICAL ANALYZER & SYMBOL TABLE" << endl;

    ifstream inputFile("sample.txt");
    if (!inputFile.is_open()) {
        cout << "Unable to open file" << endl;
        return 0;
    }


    string word;
    while (inputFile >> word) {
       
    }

    inputFile.close();



    return 0;
}
