#include <SFML/Graphics.hpp>
using namespace std;
#include<iostream>
#include<vector>


const int mapHeight = 21, mapWidth = 19; //map size
const int spriteHeight = 25, spriteWidth = 25;//sprite size
bool isAlive = true;//condition of game 



// A is blue border , space is circle or point, B is empty space , C is pacman himself , D is enemy 
string gameMap[mapHeight] = {
"AAAAAAAAAAAAAAAAAAA",
"A        A        A",
"A AA AAA A AAA AA A",
"A        A        A",
"A AA A AAAAA A AA A",
"A    A   A   A    A",
"AAAA AAA A AAA AAAA",
"BBBA A       A ABBB",
"AAAA A AAAAA A AAAA",
"BBBB   ABBBA   BBBB",
"AAAA A AAAAA A AAAA",
"BBBA A       A ABBB",
"AAAA A AAAAA A AAAA",
"A        A        A",
"A AA AAA A AAA AA A",
"A  A     C     A  A",
"AA A A AAAAA A A AA",
"A    A   A   A    A",
"A AAAAAA A AAAAAA A",
"A                 A",
"AAAAAAAAAAAAAAAAAAA",
};

#include"Player.h"
#include"Hero.h"
#include"Enemy.h"
#include"Text.h"

int main()
{

    //Render window
    sf::Vector2f windowSize = sf::Vector2f(475, 525);
    sf::RenderWindow window(sf::VideoMode(windowSize.x, windowSize.y), "PacMan");

    //load textures
    sf::Texture texture = sf::Texture();
    texture.loadFromFile("assets/title.png");
    sf::Sprite sprites = sf::Sprite(texture);

    sf::Texture winTexture = sf::Texture();
    winTexture.loadFromFile("assets/youwin.png");
    sf::Sprite winSprite = sf::Sprite(winTexture);

    sf::Texture gameOverTexture = sf::Texture();
    gameOverTexture.loadFromFile("assets/youlose.png");
    sf::Sprite gameOverSprite = sf::Sprite(gameOverTexture);

    //creating text for score
    Text text = Text("assets/text.ttf");

    //creating hero
    Player* pacman = new Hero();


    //creating enemies
    vector<Player*> enemies = vector<Player*>();
    Player* enemy = new Enemy();
    Player* enemy2 = new Enemy();
    Player* enemy3 = new Enemy();
    enemies.push_back(enemy);
    enemies.push_back(enemy2);
    enemies.push_back(enemy3);





    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();


            //while pacman dont get all stars he can move
            if (pacman->getCountOfStars() < 173) {
                pacman->newCordinatX = pacman->cordinatX;
                pacman->newCordinatY = pacman->cordinatY;


                if (event.key.code == sf::Keyboard::Right)
                    pacman->rotate = 1;
                if (event.key.code == sf::Keyboard::Left)
                    pacman->rotate = 2;
                if (event.key.code == sf::Keyboard::Up)
                    pacman->rotate = 3;
                if (event.key.code == sf::Keyboard::Down)
                    pacman->rotate = 4;
                else if (event.key.code == sf::Keyboard::Escape)
                    window.close();
            }
        }
        //while pacman dont get all stars and also he dont eaten he can move
        if (pacman->getCountOfStars() < 173 && isAlive) {
            pacman->update();
            enemies[0]->update();
            enemies[1]->update();
            enemies[2]->update();
        }

        window.clear(sf::Color::Black);

        //creating map
        for (int i = 0; i < mapHeight; i++) {
            for (int k = 0; k < mapWidth; k++)
            {
                if (gameMap[i][k] == 'A')
                    sprites.setTextureRect(sf::IntRect(0, 0, spriteWidth, spriteHeight));
                if (gameMap[i][k] == 'C')
                    sprites.setTextureRect(sf::IntRect(spriteWidth * int(pacman->getFrame()), spriteHeight * pacman->rotate, spriteWidth, spriteHeight));
                if (gameMap[i][k] == ' ')
                    sprites.setTextureRect(sf::IntRect(spriteWidth, 0, spriteWidth, spriteHeight));
                if (gameMap[i][k] == 'D')
                    sprites.setTextureRect(sf::IntRect(spriteWidth * 5, spriteHeight * enemy->rotate, spriteWidth, spriteHeight));
                if (gameMap[i][k] == 'B')
                    continue;

                sprites.setPosition(k * spriteHeight, i * spriteWidth);
                window.draw(sprites);
            }
        }
        text.TextFunc(&window, pacman);

        if (pacman->getCountOfStars() == 173)
        {
            window.clear(sf::Color::Magenta);
            winSprite.setPosition(75, windowSize.y / 2);
            window.draw(winSprite);
        }

        if (!isAlive) {
            window.clear(sf::Color::Black);
            gameOverSprite.setPosition(75, windowSize.y / 2);
            window.draw(gameOverSprite);
        }

        window.display();
    }
    cout << "Thanx for playing! -_-" << endl;
    return 0;
}