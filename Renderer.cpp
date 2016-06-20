#include "Renderer.hpp"

Renderer* Renderer::current;

Renderer::Renderer(int argc, char** argv)
{
	Renderer::current = this;
	this->process = NULL;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);

	glutInitWindowSize(SCR_WIDTH, SCR_HEIGHT);
	glutCreateWindow(" ");
	//glutFullScreen();

	if (glewInit() == GLEW_OK && GLEW_VERSION_2_1)
	{
		this->init();

		glutDisplayFunc(Renderer::display);
		glutReshapeFunc(Renderer::reshape);
		glutIdleFunc(Renderer::idle);
	}
	else
	{
		cout << "Failed to initialize GLEW\n";
	}
}

Renderer::~Renderer()
{
}

void Renderer::start(void)
{
	glutMainLoop();
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
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

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
	current->draw();
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
