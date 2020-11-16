/*************************************************************
 * File: velocity.h
 * Author: Lance Bunch
 *
 * Description: Contains the definition of the Velocity class
 *************************************************************/
#ifndef velocity_h
#define velocity_h

class Velocity
{
private:
	float Dx;
	float Dy;

public:
	//Default Constructor
	Velocity();
	//Non-Default Constuctor
	Velocity(float Dx, float Dy);

	//Accessors
	float getDx() const { return Dx; }
	float getDy() const { return Dy; }

	//Mutators
	void setDx(const float Dx);
	void setDy(const float Dy);
};


#endif