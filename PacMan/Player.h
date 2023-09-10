#pragma once
class Player {
protected:
	float frame = 0;//izobrojenie
	int speed = 0;//speed of moving


public:
	int cordinatX = 0, cordinatY = 0;
	int newCordinatX = 0, newCordinatY = 0;
	int rotate = 0; //poziciya po najatiyu klavish

	Player() {};

	virtual int getCountOfStars() {
		return -1;
	}

	virtual float getFrame() = 0;

	virtual void update() = 0;
};