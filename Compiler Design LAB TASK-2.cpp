#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string keywords[] = {
    "auto","break","case","char","const","continue","default","do","double",
    "else","enum","extern","float","for","goto","if","inline","int","long",
    "namespace","new","operator","private","protected","public","register",
    "return","short","signed","sizeof","static","struct","switch","template",
    "this","throw","try","typedef","union","unsigned","virtual","void",
    "volatile","while","class","bool","catch","using","true","false"
};
int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

bool isKeyword(string s)
{
    for (int i = 0; i < keywordCount; i++)
    {
        if (s == keywords[i])
            return true;
    }
    return false;
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

int main()
{
    cout << "TEXT FILE IDENTIFIER CHECKER" << endl;
    cout << endl;

    ifstream inputFile("sample.txt");
    if (inputFile.is_open())
    {
        string s;
        cout << "Reading file contents:" << endl;
        while (inputFile >> s)
        {
            cout << s << " ";
        }
        cout << endl << endl;

        inputFile.clear();
        inputFile.seekg(0);

        cout << "Checking for identifiers:" << endl;
        while (inputFile >> s)
        {
            if (isKeyword(s))
                cout << "'" << s << "' -> KEYWORD" << endl;
            else if (isIdentifier(s))
                cout << "'" << s << "' -> IDENTIFIER" << endl;
            else
                cout << "'" << s << "' -> NOT IDENTIFIER" << endl;
        }

        inputFile.close();
    }
    else
    {
        cout << "Unable to open file" << endl;
    }

    cout << endl;
    return 0;
}
