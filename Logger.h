#ifndef LOGGER
#define LOGGER
#include <iostream>
#include <fstream>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/date.hpp>

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
	*
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

	/**
	* check if we can write to the log
	* @return bool
	*/
	bool canWrite();

private:

	bool closeFile();

	fstream file;
	boost::shared_mutex mutex;
};

#endif