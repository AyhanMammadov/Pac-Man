#pragma once
class Hero : public Player {
	int countOfStars = 0;

public:
	int gameScore = 0;
	Hero()
	{
		this->cordinatX = 9;
		this->cordinatY = 15;
		this->rotate = 1;
		this->frame = 0;
		this->speed = 0;
	}

	int getCountOfStars() {
		return countOfStars;
	}


	float getFrame() override {
		return this->frame;
	}

	void update() override {
		this->frame += 0.01;
		if (this->frame > 5)
			this->frame = 0;


		this->speed++;
		if (this->speed >= 150) {
			switch (this->rotate) {
			case 1:
				if (gameMap[this->cordinatY][this->newCordinatX + 1] != 'A')
					this->newCordinatX += 1;
				break;
			case 2:
				if (gameMap[this->cordinatY][this->newCordinatX - 1] != 'A')
					this->newCordinatX -= 1;
				break;
			case 3:
				if (gameMap[this->newCordinatY - 1][this->cordinatX] != 'A')
					this->newCordinatY -= 1;
				break;
			case 4:
				if (gameMap[this->newCordinatY + 1][this->cordinatX] != 'A')
					this->newCordinatY += 1;
				break;
			}
			this->speed = 0;
		}

		if ((gameMap[this->newCordinatY][this->newCordinatX] == ' ') || (gameMap[this->newCordinatY][this->newCordinatX] == 'B')) {
			if (gameMap[this->newCordinatY][this->newCordinatX] == ' ')
				this->countOfStars++;

			if (gameMap[this->newCordinatY][this->newCordinatX] == 'D')
				isAlive = false;


			gameMap[this->cordinatY][this->cordinatX] = 'B';

			gameMap[this->newCordinatY][this->newCordinatX] = 'C';


			this->cordinatX = this->newCordinatX;
			this->cordinatY = this->newCordinatY;
		}

		if (this->newCordinatY == 9 && (this->newCordinatX == 0 || this->newCordinatX == 19)) {
			if (this->newCordinatX == 0)
				this->newCordinatX = 18;
			else
				this->newCordinatX = 1;

			gameMap[this->cordinatY][this->cordinatX] = 'B';
			gameMap[this->newCordinatY][this->newCordinatX] = 'C';

			this->cordinatX = this->newCordinatX;
			this->cordinatY = this->newCordinatY;
		}
	}
};
