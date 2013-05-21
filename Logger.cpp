#include "Logger.h"

using namespace std;

Logger::Logger()
{

}

Logger::~Logger()
{
	file.close();
}

void Logger::openFile(string filename)
{
	// open if file exists
	file.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);

	//if file doesn't exists, create new one
	if(!file.is_open())
	{
		file.clear();
		file.open(filename, ios_base::out);
	}
}

void Logger::write(string s)
{
	cout << s.size() << "write" <<endl;
	//file << s;
}

string Logger::read()
{
	//string s;
	//s << file;
	//return s;
	return NULL;
}

ostream& operator<<(ostream& out, const string& str)
{
	return out;
}