#ifndef TIMER_H
#define TIMER_H

#include <chrono>
#include <string>
#include <cmath>

class Timer
{
public:
	Timer(){start();}
	~Timer(){}
	
	void start(){m_start = std::chrono::high_resolution_clock::now();}

    double timeSec() const {return ((double)timeNanoSec())*1e-9;}

    unsigned long long timeNanoSec() const {return std::chrono::duration_cast<std::chrono::nanoseconds>(time()).count();}

	static std::string nanoSecToString(int nano)
	{
		int nanoseconds = nano;
    	int hours = std::trunc((double)nanoseconds*3.6e-12);
    	nanoseconds -= 3.6e12*hours;
    	int minutes = std::trunc((double)nanoseconds*60e-9);
    	nanoseconds -= 60e9*minutes;
    	int seconds = std::trunc((double)nanoseconds*1e-9);
    	nanoseconds -= 1e9*seconds;
    	int milliseconds = std::trunc((double)nanoseconds*1e-6);
    	return std::string(std::to_string(hours)+"h "+
    					   std::to_string(minutes)+"m "+
    					   std::to_string(seconds)+"s "+
    					   std::to_string(milliseconds)+"ms");
    }

	static std::string secToString(double sec)
	{
		int milliseconds = sec*1e3;
    	int hours = std::trunc((double)milliseconds/3.6e6);
    	milliseconds -= 3.6e6*hours;
    	int minutes = std::trunc((double)milliseconds/60e3);
    	milliseconds -= 60e3*minutes;
    	int seconds = std::trunc((double)milliseconds/1e3);
    	milliseconds -= 1e3*seconds;
    	return std::string(std::to_string(hours)+"h "+
    					   std::to_string(minutes)+"m "+
    					   std::to_string(seconds)+"s "+
    					   std::to_string(milliseconds)+"ms");
	}

private:

	std::chrono::high_resolution_clock::duration time() const {return std::chrono::high_resolution_clock::now()-m_start;}

private:

	std::chrono::high_resolution_clock::time_point m_start;

}; // class Timer


#endif // TIMER_H
