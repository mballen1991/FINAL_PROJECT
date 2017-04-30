#include <ncurses.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

using namespace std;

int main(int argc, char *argv[])
{
        string input;
		
		
		string parsed[10];
        while(input != "1")
        {
                cout << "1730sh:~/cs1730/Allen-Torell-p4/";
                cout << "$";
				getline(cin, input);
				
				int stringCounter = 0;
				string subString = "";
				int quoteCounter = 0;
				int quoteCheck = 0;
				
				for ( int i = 0; i < input.length(); i++)
				{
					if ( input[i] == '"')
					{
						quoteCounter++;
					}
				}
				
				for ( int i = 0; i < input.length(); i ++ )
				{
					
					if ( input[i] == '"' || quoteCheck == 1)
					{
						subString.push_back(input[i]);
						if ( input[i] == '"')
						{
							quoteCounter--;
						}
						quoteCheck = 1;
						if ( quoteCounter == 0 || i == input.length()-1)
						{
							parsed[stringCounter] = subString;
							stringCounter++;
							subString = "";
							quoteCheck = 0;
						}
					}
					else
					{
					
						if ( input[i] == ' ' || i == input.length()-1)
						{
							
							if ( i == input.length()-1)
							{
								subString.push_back(input[i]);
							}
							
							
							parsed[stringCounter] = subString;
							stringCounter ++;
							subString = "";
						}
						else
						{
							subString.push_back(input[i]);
						}
					}
				
				}
				
				for ( int i = 0; i < stringCounter; i ++ )
				{
					cout << parsed[i] << endl;
				}
				fill_n(parsed, 10, 0);
        }
}

