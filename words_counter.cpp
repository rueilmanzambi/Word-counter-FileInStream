//////////////////////////////////////
//                                  //
// Rueil Manzambi                   //
// Project B: C++ Standard Library  //
//                                  //
//////////////////////////////////////


#include <iostream>
#include <fstream>
#include <iterator>
#include <map>
#include <string>
#include <iomanip>


using namespace std;

string get_next(istream &in);

int main()
{
    map<string,int> words;
    ifstream fin("sampletextfile.txt");

    string str;
    string empty ="";

    while((str=get_next(fin))!=empty )
            ++words[str];

    for (int i = 0; i < 43; i++) // output formatting
        cout <<'_';
    cout << endl;

    cout << "|" << setw(26) <<"" << "|" << setw(15) <<"|" << endl;  // output formatting
    cout << "|    Words                 |  Occurences  |" << endl;
    for (int i = 0; i < 43; i++)
    {
        if (i==0 || i== 42 || i == 27)
            cout << "|";
        else
            cout <<'_';
    }
    cout << endl;

    for (map<string, int>::iterator it = words.begin(); it!=words.end(); ++it)
    {
        cout << "| "; // output formatting and printing map elements
        cout<<it->first;
        cout << setw(25 - ((it->first).length())) <<"";
        if (it->second > 999)
            cout << "|    ";
        else if (it->second > 99)
            cout << "|     ";
        else if (it->second > 9)
            cout << "|      ";
        else
            cout << "|       ";
        cout << it->second << "      |" <<endl;
        for (int i = 0; i < 43; i++)
        {
          if (i==0 || i== 42 || i == 27)
              cout << "|";
          else
              cout << "_";
        }
        cout <<endl;
    }
    return 0;
}

string get_next(istream &in)
{
    char c;
    string s="";
    c=in.get();
    while(!isalpha(c) && !in.eof()) // only taking letters in account
        c=in.get();

    while(isalpha(c))
    {
        s.push_back(tolower(c)); // all to lower, case insensitive
        c=in.get();
    }
    return s;
}

