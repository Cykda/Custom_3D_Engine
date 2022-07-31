#include "Parameters.h"

Parameters::Parameters(bool RotateX, bool RotateY, bool RotateZ)
{
	this->RotateX = RotateX;
	this->RotateY = RotateY;
	this->RorateZ = RotateZ;




}

Parameters::Parameters()
{
	this->RotateX = false;
	this->RotateY = false;
	this->RorateZ = false;

}
