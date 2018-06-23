/*
** EPITECH PROJECT, 2021
** PathFinder_A
** File description:
** Created by kraken, 14/06/18
*/

#include "ZappyGraph.hpp"

AI::ZappyGraph::ZappyGraph(int width, int height)
	: _width(width), _height(height), _diagonal(false), _borderless(true)
{
	resetGraph(width, height, _diagonal);
}

void AI::ZappyGraph::resetGraph(int width, int height, bool diagonal)
{
	_diagonal = diagonal;
	_nodes.reset();
	_nodes = std::make_shared<ZappyGraph::ZappyNodeVec>(width * height);
	_width = width;
	_height = height;
	std::generate(_nodes->begin(), _nodes->end(), [n = 0, this]() mutable{
		auto elem = std::make_shared<ZappyNode>();
		elem->point.coord.x = n % _width;
			elem->point.coord.y = n / _width;
		n++;
		return std::move(elem);
	});
	setLink();
}

void AI::ZappyGraph::setLink()
{
	checkNodes();
	for (auto y = 0; y < _height; ++y) {
		for (auto x = 0; x < _width; ++x) {
			if(y > 0)
				_nodes->at(y*_width + x)->vecNeighbours.push_back(_nodes->at((y - 1) * _width + (x + 0)));
			if(y < _height - 1)
				_nodes->at(y*_width + x)->vecNeighbours.push_back(_nodes->at((y + 1) * _width + (x + 0)));
			if (x > 0)
				_nodes->at(y*_width + x)->vecNeighbours.push_back(_nodes->at((y + 0) * _width + (x - 1)));
			if(x < _width - 1)
				_nodes->at(y*_width + x)->vecNeighbours.push_back(_nodes->at((y + 0) * _width + (x + 1)));

			if (_borderless) {
				if (y == 0) {
					_nodes->at(y * _width + x)->vecNeighbours.push_back(_nodes->at((_height - 1) * _width + x));
				}
				if (y == _height - 1) {
					_nodes->at(y * _width + x)->vecNeighbours.push_back(_nodes->at((0) * _width + x));
				}
				if (x == 0) {
					_nodes->at(y * _width + x)->vecNeighbours.push_back(_nodes->at(y * _width + (_width - 1)));
				}
				if (x == _width - 1) {
					_nodes->at(y * _width + x)->vecNeighbours.push_back(_nodes->at(y * _width + 0));
				}
			}
		}
	}
}

void AI::ZappyGraph::cleanNodes()
{
	checkNodes();
	std::for_each(_nodes->begin(), _nodes->end(), [](ZappyNodePtr& elem){
		elem->clean();
	});
}

std::optional<AI::IGraph::NodePtr> AI::ZappyGraph::getNodeAt(int x, int y)
{
	checkNodes();
	if (x >= _width || x < 0 || y >= _height || y < 0)
		return {std::nullopt};
	return  {_nodes->at(y *_width + x)};
}

void AI::ZappyGraph::deleteGraph()
{
	_nodes.reset();
}

bool AI::ZappyGraph::checkNodes()
{
	if(_nodes == nullptr) {
		throw std::runtime_error("No nodes graph !");
		return false;
	}
	return true;
}

int AI::ZappyGraph::getWidth() const
{
	return _width;
}

int AI::ZappyGraph::getHeight() const
{
	return _height;
}
bool AI::ZappyGraph::isCentered() const
{
	return false;
}

bool AI::ZappyGraph::isBorderless() const
{
	return _borderless;
}

std::optional<AI::ZappyGraph::ZappyNodePtr> AI::ZappyGraph::getZappyNodeAt(int x, int y)
{
	checkNodes();
	if (x >= _width || x < 0 || y >= _height || y < 0)
		return {std::nullopt};
	return  {_nodes->at(y *_width + x)};
}
