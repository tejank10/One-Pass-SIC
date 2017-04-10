#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
#define LABEL 0
#define OPCODE 1
#define OPERANDS 2

class line
{
	public:
		vector<string> statement;
		int ptr;

		line(const string);
		void operator= (const string);
}; 

line :: line(const string inputLine)
{
	string buffer = inputLine;
	statement.push_back(" ");
	statement.push_back(" ");
	statement.push_back(" ");

	int prev = 0, ind = 0;
	ptr = buffer.find_first_of(" \t", prev);
	do
	{
		if(ptr - prev > 0)
			statement[ind++] = buffer.substr(prev, ptr - prev);
		else if(ptr == 0)
			ind++;
		prev = ptr + 1;
		ptr = buffer.find_first_of(" \t", prev);
	}while(ptr < buffer.size());	

		if(ptr >= buffer.size() and buffer[buffer.size() - 1] != ' ')
			statement[ind++] = buffer.substr(prev, buffer.size() - prev);
}

void line :: operator= (const string inputLine)
{
	string buffer = inputLine;
	int prev = 0, ind = 0;
	statement[LABEL] = statement[OPERANDS] = statement[OPERANDS] = " ";
	ptr = buffer.find_first_of(" \t", prev);
	do
	{
		if(ptr - prev > 0)
			statement[ind++] = buffer.substr(prev, ptr - prev);
		else if(ptr == 0)
			ind++;
		prev = ptr + 1;
		ptr = buffer.find_first_of(" \t", prev);
	}while(ptr < buffer.size() && ind < 3);	

		if(ptr >= buffer.size() and buffer[buffer.size() - 1] != ' ')
			statement[ind++] = buffer.substr(prev, buffer.size() - prev);
}

