#ifndef LOGGER
#define LOGGER
#include <fstream>
#include <iostream>

using namespace std;

/**
* Class responsible for performing operations on logfile
*
*/
class Logger
{
public:
	/**
	* Class constructor
	*/
	Logger();
	~Logger();
	/**
	* read entire log file

	* @return string
	*/
	string read();

	/**
	* write given string at the end of the log file.
	* This method should be synchronized!
	*
	* @param string
	*/
	void write(string s);

	/**
	* open log file. If file doesn't exists, create one
	*
	* @param string
	*/
	void openFile(string filename);

	friend ostream& operator<<(ostream& out, const string& str);
private:
	bool closeFile();

	fstream file;
};

#endif