#include "headers/Renderer.hpp"

Renderer* Renderer::renderer = NULL;

Renderer::Renderer(int argc, char** argv)
{
	Renderer::renderer = this;
	this->process = NULL;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);

	glutInitWindowSize(SCR_WIDTH, SCR_HEIGHT);
	glutCreateWindow(" ");
	glutFullScreen();
	
	this->init();
	
	glutDisplayFunc(Renderer::display);
	glutReshapeFunc(Renderer::reshape);
	glutIdleFunc(Renderer::idle);
	
	glutMainLoop();
}

Renderer::~Renderer()
{
}

void Renderer::setProcess(void (* process)(void))
{
	this->process = process;
}

void Renderer::init(void)
{
	glDisable(GL_DEPTH_TEST);
	
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	
	glShadeModel(GL_SMOOTH);
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	glDisable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
   
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void Renderer::reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(SCR_WIDTH, 0, 0, SCR_HEIGHT, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Renderer::display(void)
{
	renderer->draw();
}

void Renderer::idle()
{
	glutPostRedisplay();
}

void Renderer::draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	if(this->process != NULL)
	{
		this->process();
	}

	glutSwapBuffers();
}
