#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects

}

Level::~Level()
{
	input = nullptr;
}

// handle user input
void Level::handleInput()
{
	//keyboard tasks
	if (input->isKeyDown(sf::Keyboard::W))
	{
		input->setKeyUp(sf::Keyboard::W);
	std::cout << "The W key was pressed!  ";
	}

	if (input->isKeyDown(sf::Keyboard::J) && input->isKeyDown(sf::Keyboard::K) && input->isKeyDown(sf::Keyboard::L))
	{
		input->setKeyUp(sf::Keyboard::J);
		input->setKeyUp(sf::Keyboard::K);
		input->setKeyUp(sf::Keyboard::L);
		std::cout << "J,K and L were pressed\n";
	}

	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}

	//mouse tasks
	if (input->isKeyDown(sf::Keyboard::Q))
	{
		//reposition mouse
		sf::Mouse::setPosition(sf::Vector2i(400, 300), *window);

	}

	

	std::cout << "Mouse X; \n" << input->getMouseX() << "Mouse Y; \n" << input->getMouseY();




	if (!font.loadFromFile("font/arial.ttf")) {
		std::cout << "Error loading font\n";
	}

	std::string getMouseX("Mouse X: ");
	std::string getMouseY("Mouse Y: ");
	text.setFont(font);
	text.setCharacterSize(15);
	text.setString(getMouseX);
	text.setString(getMouseY);
	text.setPosition(200, 0);
	text.setFillColor(sf::Color::Red);

}

// Update game objects
void Level::update()
{

}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(text);
	
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}