#include "Logger.h"

using namespace std;

Logger::Logger()
{

}

Logger::~Logger()
{
	//file.close();
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
	//boost::unique_lock< boost::shared_mutex > lock(mutex);
	//cout << s.size() << s << "write" <<endl;
	//cout << "pisze" << endl;
	//boost::this_thread::sleep(boost::posix_time::milliseconds(600));
	//cout << "skon_pisac" << endl;
	boost::gregorian::date current_date(boost::gregorian::day_clock::local_day());
	if(!file.is_open()) cout << "debug" << endl;
	cout << "[" << current_date << "]\t" << s << endl;
	file << "[" << current_date << "]\t" << s << endl;
	mutex.unlock();
}

string Logger::read()
{
	// no exclusive access
	//boost::shared_lock< boost::shared_mutex > lock(mutex);
	mutex.lock_shared();
	cout << "czytam" << endl;
	string s;
	file >> s;
	//boost::this_thread::sleep(boost::posix_time::milliseconds(200));
	cout << "skon czytac" << endl;
	mutex.unlock_shared();
	return s;
}

bool Logger::canWrite()
{
	bool mutex_free = mutex.try_lock();
	if(mutex_free) mutex.unlock();
	return mutex_free;
}