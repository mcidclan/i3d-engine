#include "headers/RenderingManager.hpp"

GLuint RenderingManager::buffers[RM_SHAPE_NUMBER];

RenderingManager::RenderingManager()
{
	unsigned int i;

	this->currentfont = NULL;
	this->currentshader = NULL;

	i = 0;
	while(i < RM_SHAPE_NUMBER)
	{
		RenderingManager::buffers[i] = 0;
		i++;
	}
}

RenderingManager::RenderingManager(void*)
{
	cout << "Could be called by a root ScriptSheet.\n";
}

RenderingManager::~RenderingManager()
{
	utils::dynamicDelete(this->texts);
	utils::dynamicDelete(this->fonts);
	utils::dynamicDelete(this->shapes);
	utils::dynamicDelete(this->shaders);
}

void RenderingManager::draw(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	this->drawShapes();
	this->drawText();
}

void RenderingManager::drawText(void)
{
	map<string, RenderText*>::const_iterator a, b;

	a = this->texts.begin();
	b = this->texts.end();

	while(a != b)
	{
		a->second->draw();
		a++;
	}
}

void RenderingManager::drawShapes(void)
{
	unsigned int i;
	
	i = 0;
	while(i < this->shapes.size())
	{
		this->shapes[i]->draw();
		i++;
	}
}

RenderText* RenderingManager::getRenderText(char const* const name)
{
	return this->texts[name];
}

void RenderingManager::setCurrentFont(unsigned int const id)
{
	this->currentfont = fonts[id];
}

void RenderingManager::addNewFont(char const* const filename)
{
	FTGLPixmapFont* font;

	font = new FTGLPixmapFont(filename);

	if(!font->Error())
	{
		this->fonts.push_back(font);
		this->currentfont = this->fonts.back();
	}
	else cout << "An error has occurred during font file loading.\n";
}

void RenderingManager::addNewRenderText(char const* const name)
{
	RenderText* rendertext;

	if(this->currentfont != NULL)
	{
		rendertext = new RenderText(this->currentfont);
		this->texts[name] = rendertext;
	}
	else cout << "Please set current text font.\n";
}

void RenderingManager::setCurrentShaderProgram(unsigned int const id)
{
	this->currentshader = this->shaders[id];
}

void RenderingManager::addNewShaderProgram(ShaderSources& shadersource)
{
	unsigned int i;
	ShaderProgram* shaderprogram;
	
	i = 0;
	shaderprogram = new ShaderProgram();

	while(i < shadersource.size())
	{
		GLuint type;
		unsigned int linenumber;

		type = shadersource.getType(i);
		linenumber = shadersource.getLineNumber(i);

		shaderprogram->addSource(type, shadersource.at(i), linenumber);
		i++;
	}

	this->shaders.push_back(shaderprogram);
	this->currentshader = shaderprogram;

	cout << "A new ShaderProgram was added.\n";
}

void RenderingManager::addNewBufferedShape(ShapeType const type)
{
	if(this->currentshader != NULL)
	{
		RenderShape* shape;

		shape = this->getNewBufferedShape(type);
		shape->setShaderProgram(this->currentshader);
		this->shapes.push_back(shape);
	}
	else cout << "Please set current shader program.\n";
}

RenderShape* RenderingManager::getNewBufferedShape(ShapeType const type)
{
	RenderShape* shape;

	shape = this->getNewShape(type);

	if(shape != NULL)
	{
		if(!RenderingManager::buffers[type])
		{
			glGenBuffers(1, &RenderingManager::buffers[type]);
			glBindBuffer(GL_ARRAY_BUFFER, RenderingManager::buffers[type]);
			glBufferData(GL_ARRAY_BUFFER, shape->getDataSize(),
			shape->getData(), GL_STATIC_DRAW);
		}
		shape->setBufferId(RenderingManager::buffers[type]);
	}
	return shape;
}

RenderShape* RenderingManager::getNewShape(ShapeType const type)
{
	switch(type)
	{
		case RM_SHAPE_TRIANGLE: return new RenderTriangle();
		case RM_SHAPE_RECTANGLE: return new RenderRectangle();
		case RM_SHAPE_NUMBER: return NULL;
	}
	return NULL;
}
