
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class StringSpliter
{
public:

	static vector<string> split(const string &s, char delim);
private:
	static void split(const string &s, char delim, vector<string> &elems);
};



