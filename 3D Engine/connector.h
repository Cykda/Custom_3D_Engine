#pragma once
class Connector
{
public:
	Connector(int p1, int p2)
	{
		this->p1 = p1;
		this->p2 = p2;
	}

	int p1 = 0;
	int p2 = 0;
};