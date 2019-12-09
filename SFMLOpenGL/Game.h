#include <iostream>
//#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>


using namespace std;
using namespace sf;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();
	void updateText();

	 // Uncomment for Part 2
	 // ********************
	 const int primatives;

	GLuint index;
	Clock clock;
	Time elapsed;

	float rotationAngle = 0.0f;
	 // ********************

	// Uncomment for Part 2
	// ********************
	bool flip = false;
	int current = 1;
	// ********************

	bool m_keyHeld{ false };

};