#pragma once
#include <chrono>

class TimeClock
{
public:
	TimeClock() : timestamp(clock_t::now())
	{

	}
	void Reset()
	{
		timestamp = clock_t::now();
	}
	float GetElapsedSeconds() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - timestamp).count();
	}
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<float, std::ratio<1>>;
	std::chrono::time_point<clock_t>timestamp;
};