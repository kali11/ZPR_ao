#include "Logger.h"

using namespace std;

Logger::Logger()
{

}

Logger::~Logger()
{
	if(file.is_open()) file.close();
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
	// exclusive access
	mutex.lock();
	file.seekp(ios_base::end);
	boost::posix_time::ptime now  = boost::posix_time::second_clock::local_time();
	cout << "[" << now << "]\t" << s << endl;
	file << "[" << now << "]\t" << s << endl;
	mutex.unlock();
}

void Logger::read(boost::promise<string> *prom)
{
	// no exclusive access
	mutex.lock_shared();
	file.seekg(ios_base::beg);
	string s;
	cout << "read" << endl;
	file >> s;
	prom->set_value(s);
	mutex.unlock_shared();

}

bool Logger::canWrite()
{
	bool mutex_free = mutex.try_lock();
	if(mutex_free) mutex.unlock();
	return mutex_free;
}