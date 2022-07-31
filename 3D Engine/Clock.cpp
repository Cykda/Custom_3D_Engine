#include "Clock.h"

Clock::Clock(float MaxElapsedTime)
{
	this->MaxElapsedTime = MaxElapsedTime;
	this->CurrentElapsedTime = 0.f;
}

void Clock::update(float deltaTime)
{

	if (!this->Trigger)
	{

		this->CurrentElapsedTime += deltaTime;
		if (this->CurrentElapsedTime >= this->MaxElapsedTime)
		{
			this->Trigger = true;
		}
	}



}

void Clock::reset(bool state)
{
	this->Trigger = state;
	this->CurrentElapsedTime = 0.f;
}

bool Clock::doTriggered()
{
	return this->Trigger;
}
