#ifndef PERFCOUNTER_H
#define PERFCOUNTER_H

#include <windows.h>

namespace PerfCounter {
	typedef long long Ticks;

	enum Scale {
		Seconds = 1,
		Milliseconds = 1000,
		Microseconds = 1000000,
		Nanoseconds = 1000000000
	};

	static Ticks Frequency = 0ll;

	//long long TicksTo(Ticks ticks, Scale prescale);
	inline long long TicksTo(Ticks ticks, Scale prescale) {
		return ticks * prescale / Frequency;
	}

	class Counter {
	private:
		LARGE_INTEGER _buf = { 0 };

	public:
		Counter() {
			if (Frequency) return;
			QueryPerformanceFrequency(&_buf);
			Frequency = _buf.QuadPart;
		}

		~Counter() = default;

		Ticks Now() {
			QueryPerformanceCounter(&_buf);
			return _buf.QuadPart;
		}
	};
}

#endif/* PERFCOUNTER_H */
