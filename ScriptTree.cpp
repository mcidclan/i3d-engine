#include "headers/ScriptTree.hpp"

ScriptTree* ScriptTree::current;

ScriptTree::ScriptTree()
{
	this->current = this;
}

ScriptTree::~ScriptTree()
{
}

void ScriptTree::draw(void)
{
	ScriptTree::current->currentsheet->draw();
}

void ScriptTree::setCurrentScriptSheet(vector<unsigned int>* const tie)
{
	this->currentsheet = this->root->getScriptSheet(0, tie);
}

void ScriptTree::addNewScriptSheet(void(* const init)(void),
vector<unsigned int>* const tie)
{
		this->root->addNewScriptSheet(init, tie);
}
