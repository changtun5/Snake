#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Snake");
	window.setFramerateLimit(60);
	window.setKeyRepeatEnabled(false);

	bool play = true;

	sf::Event event;

	sf::RectangleShape player;
	player.setSize(sf::Vector2f(50, 50));
	player.setFillColor(sf::Color::Green);
	player.setPosition(0, 0);

	int vX = 5;
	int vY = 0;

	// When paused
	int tempVX = 0;
	int tempVY = 0;

	bool rBut = false;
	bool lBut = false;
	bool uBut = false;
	bool dBut = false;

	bool escBut = false;

	while (play) {

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				play = false;
			}

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Right) {
					rBut = true;
				}
				else if (event.key.code == sf::Keyboard::Left) {
					lBut = true;
				}
				else if (event.key.code == sf::Keyboard::Up) {
					uBut = true;
				}
				else if (event.key.code == sf::Keyboard::Down) {
					dBut = true;
				}
				else if (event.key.code == sf::Keyboard::Escape) {
					escBut = !escBut;
					if (escBut) {
						std::cout << "Pause" << std::endl;
						tempVX = vX;
						tempVY = vY;
						vX = 0;
						vY = 0;
						while (escBut) {
							while (window.pollEvent(event)) {
								if (event.type == sf::Event::KeyPressed) {
									if (event.key.code == sf::Keyboard::Escape) {
										escBut = !escBut;
										vX = tempVX;
										vY = tempVY;
										tempVX = 0;
										tempVY = 0;
										break;
									}
								}
								if (event.type == sf::Event::Closed) {
									play = false;
									escBut = !escBut;
									break;
								}
							}
						}
					}
				}
			}

			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Right) {
					rBut = false;
				}
				else if (event.key.code == sf::Keyboard::Left) {
					lBut = false;
				}
				else if (event.key.code == sf::Keyboard::Up) {
					uBut = false;
				}
				else if (event.key.code == sf::Keyboard::Down) {
					dBut = false;
				}
			}
		}
		
		if (rBut && !escBut) {
			if (vX == 0) {
				vY = 0;
				vX = 5;
			}
		}

		if (lBut && !escBut) {
			if (vX == 0) {
				vY = 0;
				vX = -5; 
			}
		}

		if (uBut && !escBut) {
			if (vY == 0) {
				vX = 0;
				vY = -5;
			}
		}

		if (dBut && !escBut) {
			if (vY == 0) {
				vX = 0;
				vY = 5;
			}
		}

		player.setPosition(player.getPosition().x + vX, player.getPosition().y + vY);
		window.draw(player);
		
		window.display();


		window.clear();

	}

	return 0;
}