#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

void readFile(const char* filename)
{
    stack<char> brackets;
    ifstream inputFile;

    inputFile.open("brackets.txt", ios::in);

    if( !inputFile.is_open() )
    {
        cerr << "Could not open file" << endl;
    }

    char symbol;
    while( inputFile.get( symbol ) )
    {
        if( symbol == '(')
        {
            brackets.push( symbol );
        }

        if( symbol == ')' )
        {
            brackets.pop();
        }
    }

    if( brackets.empty() )
    {
        cout << "The brackets are correctly closed." << endl;
    }
    else
    {
        cout << "The brackets are not correctly closed." << endl;
    }
}

int main()
{
    readFile("brackets.txt");

    return 0;
}
