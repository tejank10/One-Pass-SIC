#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <cstring>
using namespace std;

class OPTAB
{
	protected:
		map<string, string> table;

	public:
		OPTAB();
		friend class ASSEMBLER;
};

OPTAB :: OPTAB()
{
	ifstream fin;
	fin.open("OPTAB.txt");
	string buffer;

	while(getline(fin, buffer))
	{
		int prev = 0, pos = buffer.find_first_of(" \t", prev);
		string opcode;

		do
		{
			if(prev == 0)
				opcode = buffer.substr(prev, pos - prev);
			prev = pos + 1;
			pos = buffer.find_first_of(" \t", prev);
		}while(pos < buffer.size());

		if(prev < buffer.size())
			table[opcode] = buffer.substr(prev, buffer.size()-prev);
	}

	fin.close();
}
