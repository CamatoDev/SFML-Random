#include <SFML/Graphics.hpp>
#include <random>

int main()
{
	unsigned int width = 640;
	unsigned int height = 480;
	sf::RenderWindow window(sf::VideoMode(width, height), "Second SFML");

	float rayon = 20;
	sf::CircleShape shape(rayon);
	shape.setOrigin(rayon, rayon);
	shape.setFillColor(sf::Color::Green);
	shape.setPosition(width / 2.0, height / 2.0);

	sf::Vector2f speed;
	float speed_const = 2.0f;
	speed.x = speed_const;
	speed.y = speed_const;

	bool pause = false;

	bool running = true;

	sf::Clock clock;

	// Déclaration du générateur de nombres aléatoires
	std::random_device rd;
	std::mt19937 gen(rd());

	// Définition de la distribution
	std::uniform_int_distribution<> dis(-50, 50);

	while (running)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				running = false;
			}

			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Space) {
					pause = !pause;
				}
			}
		}
		// Génération d'un nombre aléatoire
		int random_number1 = dis(gen);
		int random_number2 = dis(gen);
		sf::Vector2f move;
		move.x = random_number1;
		move.y = random_number2;

		sf::Vector2f newPosition = shape.getPosition();
		newPosition = newPosition + move;
			if (clock.getElapsedTime().asMilliseconds() > 1000. / 5.0) {
				

				//shape.setPosition(sf::Vector2f(0 + rayon, 0 + rayon));

				if (newPosition.x >= 0 + rayon || newPosition.x <= width - rayon) {
					if (newPosition.y >= 0 + rayon || newPosition.y <= height - rayon) {
						shape.setPosition(newPosition);
						shape.setFillColor(sf::Color::Red);
						clock.restart();
					}
				}
				
			}

		window.clear();
		window.draw(shape);
		window.display();
	}
	return 0;
}