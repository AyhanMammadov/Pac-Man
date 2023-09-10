#pragma once
class Enemy : public Player {
public:
	Enemy()
	{
		this->cordinatX = rand() % 20; //random cordinats for enemy
		this->cordinatY = rand() % 18;//random cordinats for enemy
		this->rotate = 1;
		this->frame = 0;
		this->speed = 0;
	}


	float getFrame() override {
		return this->frame;
	}


	//logic and moving
	void update() override {
		this->frame += 0.01;
		if (this->frame > 5)
			this->frame = 0;


		this->speed++;
		if (this->speed >= 200) {

			this->rotate = rand() % 4 + 1;

			this->newCordinatX = this->cordinatX;
			this->newCordinatY = this->cordinatY;

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

		if ((gameMap[this->newCordinatY][this->newCordinatX] == ' ') || (gameMap[this->newCordinatY][this->newCordinatX] == 'B') || (gameMap[this->newCordinatY][this->newCordinatX] == 'C')) {
			if (gameMap[this->newCordinatY][this->newCordinatX] == 'B')
				gameMap[this->cordinatY][this->cordinatX] = 'B';
			else if (gameMap[this->newCordinatY][this->newCordinatX] == ' ')
				gameMap[this->cordinatY][this->cordinatX] = ' ';
			else if (gameMap[this->newCordinatY][this->newCordinatX] == 'C')
				isAlive = false;

			gameMap[this->newCordinatY][this->newCordinatX] = 'D';


			this->cordinatX = this->newCordinatX;
			this->cordinatY = this->newCordinatY;


		}

		if (this->newCordinatY == 9 && (this->newCordinatX == 0 || this->newCordinatX == 19)) {
			if (this->newCordinatX == 0)
				this->newCordinatX = 18;
			else
				this->newCordinatX = 1;

			gameMap[this->cordinatY][this->cordinatX] = 'B';
			gameMap[this->newCordinatY][this->newCordinatX] = 'D';

			this->cordinatX = this->newCordinatX;
			this->cordinatY = this->newCordinatY;
		}
	}
};
