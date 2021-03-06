// ----------------------------------------------------
// j1PerfTimer.cpp
// Slow timer with microsecond precision
// ----------------------------------------------------

#include "j1PerfTimer.h"
#include "SDL\include\SDL_timer.h"

uint64 j1PerfTimer::frequency = 0;

// ---------------------------------------------
j1PerfTimer::j1PerfTimer()
{
	// TODO 2: Fill Constructor, Start(),ReadMs() and ReadTicks() methods
	// they are simple, one line each!
	frequency = SDL_GetPerformanceFrequency(); //Inicialitzem la frequencia
	Start();
}

// ---------------------------------------------
void j1PerfTimer::Start()
{
	started_at = SDL_GetPerformanceCounter(); //Inicialitzem la started_at
	
}

// ---------------------------------------------
double j1PerfTimer::ReadMs() const
{
	return (double)((SDL_GetPerformanceCounter()-started_at)/frequency)*1000000;
	//Es resten els cicles que portes pels cicles en els que has inicialitzat el started_at i es dvideix per la frequencia
	//SDL_GetPerformanceCounter (retorna cicles)
	//SDL_GetPerformanceCounter (retorna frecuencia)
}

// ---------------------------------------------
uint64 j1PerfTimer::ReadTicks() const
{
	return (double)(SDL_GetPerformanceCounter()-started_at/frequency);
}


