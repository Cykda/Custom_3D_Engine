#pragma once


class Clock
{
public:
	
	Clock(float MaxElapsedTime);
	
	void update(float deltaTime);
	void reset(bool state);
	bool doTriggered();
	~Clock() = default;
private:
	float MaxElapsedTime;
	float CurrentElapsedTime;
	bool Trigger = false;
};