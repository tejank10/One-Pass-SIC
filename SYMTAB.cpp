#include <iostream>
#include <vector>
#include <list>


using namespace std;

class SYMTAB
{
	protected:
		map<string, vector<int> >table;
	public:
		friend class ASSEMBLER;
};
