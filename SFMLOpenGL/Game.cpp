#include <Game.h>

Game::Game() : window(VideoMode(800, 600), "OpenGL")
{
}

Game::~Game() {}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning) {

		cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
}

void Game::update()
{
	cout << "Update up" << endl;
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			glTranslatef(0, 0.1f, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			glTranslatef(0, -0.1f, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			glTranslatef(-0.1f, 0, 0);
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			glTranslatef(0.1f, 0, 0);
		}

		// X Axis
		if (Keyboard::isKeyPressed(Keyboard::X))
		{
			glRotatef(1.0f, 0.1f, 0, 0);
		} 
		else if (Keyboard::isKeyPressed(Keyboard::C))
		{
			glRotatef(1.0f, -0.1f, 0, 0);
		}

		// Y Axis
		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			glRotatef(1.0f, 0, 0.1f, 0);
		}
		else if (Keyboard::isKeyPressed(Keyboard::D))
		{
			glRotatef(1.0f, 0, -0.1f, 0);
		}

		// Z Axis
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			glRotatef(1.0f, 0, 0, 0.1f);
		}
		else if (Keyboard::isKeyPressed(Keyboard::E))
		{
			glRotatef(1.0f, 0, 0, -0.1f);
		}

		// scale on P
		if (Keyboard::isKeyPressed(Keyboard::P))
		{
			glScalef(0.99f, 0.99f, 1);
		}
		else if (Keyboard::isKeyPressed(Keyboard::O))
		{
			glScalef(1.01f, 1.01f, 1);
		}
}

void Game::draw() 
{ 
	cout << "Draw up" << endl;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(1, 1, 1);
	glBegin(GL_LINES); {
		glVertex3f(2.0, 2.0, -60.0);
		glVertex3f(-2.0, -2.0, -60.0);

		glVertex3f(-2.0, -2.0, -60.0);
		glVertex3f(2.0, -2.0, -60.0);

		glVertex3f(2.0, -2.0, -60.0);
		glVertex3f(2.0, 2.0, -60.0);

	} glEnd();

	glBegin(GL_POLYGON); {
	glColor3f(0, 1, 0);
	glVertex3f(0.0, 1.0, -75.0);

	glColor3f(0, 0, 1);
	glVertex3f(-1.0, -1.0, -75.0);

	glColor3f(1, 0, 0);
	glVertex3f(1.0, -1.0, -75.0);

	} glEnd();
	glBegin(GL_TRIANGLES); {
		glColor3f(0, 1, 0);
		glVertex3f(0.0, 1.0, -90.0);

		glColor3f(0, 0, 1);
		glVertex3f(-1.0, -1.0, -90.0);

		glColor3f(1, 0, 0);
		glVertex3f(1.0, -1.0, -90.0);

	} glEnd();

	glBegin(GL_TRIANGLE_STRIP); {
		glColor3f(0, 1, 0);
		glVertex3f(0.0, 1.0, -105.0);

		glColor3f(0, 0, 1);
		glVertex3f(-1.0, -1.0, -105.0);

		glColor3f(1, 0, 0);
		glVertex3f(1.0, -1.0, -105.0);

	} glEnd();
	
	glColor3f(1, 0, 0);
	glPointSize(10.0f);
	glBegin(GL_POINTS);
	{	
		glVertex3f(0.0, 5.0, -10.0);
	} glEnd();

	glColor3f(1, 0, 0);
	glPointSize(10.0f);
	glBegin(GL_LINE_LOOP);
	{
		glVertex3f(0.0, 5.0, -30.0);
		glVertex3f(0.0, 2.0, -30.0);
		glVertex3f(2.0, 0.0, -30.0);
		
	} glEnd();

	glColor3f(1, 0, 0);
	glPointSize(10.0f);
	glBegin(GL_TRIANGLE_FAN);
	{
		glVertex3f(0.0, 5.0, -30.0);
		glVertex3f(0.0, 2.0, -30.0);
		glVertex3f(2.0, 0.0, -30.0);
		glVertex3f(-2.0, 0.0, -30.0);
		glVertex3f(2.0, 5.0, -30.0);

	} glEnd();

	glBegin(GL_QUADS);
	{
		glVertex3f(0.0, 0.0, -30.0);
		glVertex3f(0.0, 1.0, -30.0);
		glVertex3f(1.0, 1.0, -30.0);
		glVertex3f(1.0, 0.0, -30.0);

	} glEnd();

	glBegin(GL_QUAD_STRIP);
	{
		glVertex3f(0.0, 0.0, -45.0);
		glVertex3f(1.0, 0.0, -45.0);
		glVertex3f(0.0, 1.0, -45.0);
		glVertex3f(1.0, 1.0, -45.0);

	} glEnd();

	window.display();
}

void Game::unload()
{
	cout << "Cleaning up" << endl;
}

