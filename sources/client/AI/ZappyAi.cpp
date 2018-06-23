/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** Created by kraken, 21/06/18
*/

#include "ZappyAi.hpp"
#include "linux_color.hpp"

AI::ZappyAi::ZappyAi(int width, int height, clientSpace::CommunicateToServer& comm)
	: _comm(comm), _graph(std::make_shared<ZappyGraph>(width, height)), _pathFinder(), _decisionTree()
{
	_pathFinder.setGraph(_graph);
}

std::shared_ptr<AI::ZappyGraph> const& AI::ZappyAi::getGraph() const
{
	return _graph;
}

AI::PathFinder2D::Direction AI::ZappyAi::getOrientation() const
{
	return _orientation;
}

AI::IGraph::Coord2D const& AI::ZappyAi::getPostion() const
{
	return _postion;
}

size_t AI::ZappyAi::getLevel() const
{
	return _level;
}

std::map<AI::ZappyElement, size_t> const& AI::ZappyAi::getInventory() const
{
	return _inventory;
}


void AI::ZappyAi::dump()
{
	for (auto y = 0; y < _graph->getHeight(); ++y) {
		for (auto x = 0; x < _graph->getWidth(); ++x) {
			auto find = _graph->getNodeAt(x, y);
			Linux::color(Linux::TermColor::BOLD_ON);
			if (find == std::nullopt)
				std::cout << "[ ]";
			else {
				AI::IGraph::NodePtr elem(find.value());
				if (elem->point.coord == _postion)
					Linux::color(Linux::TermColor::RED_BG);
				else if ((std::find_if(_pathPos.begin(), _pathPos.end(), [x, y](IGraph::Coord2D const& s) {
					return s.x == x && s.y == y;
				})) != _pathPos.end())
					Linux::color(Linux::TermColor::YELLOW_BG);
				std::cout << "[ ]";
			}
			Linux::color(Linux::TermColor::RESET);
			std::cout << " ";
		}
		std::cout << std::endl << std::endl;
	}
	std::cout << _postion.x << "," << _postion.y << std::endl;
}

void AI::ZappyAi::translatePathToAction(std::vector<AI::IGraph::Coord2D>const & path)
{
	static const std::map<AI::PathFinder2D::Direction, std::map<AI::PathFinder2D::Direction, MoveAction>> actionMove = {
		{AI::PathFinder2D::Direction::NORTH,{
			{AI::PathFinder2D::Direction::NORTH, MoveAction::MOVE_FORWARD},
			{AI::PathFinder2D::Direction::EAST, MoveAction::TURN_RIGHT},
			{AI::PathFinder2D::Direction::WEST, MoveAction::TURN_LEFT},
			{AI::PathFinder2D::Direction::SOUTH, MoveAction::TURN_BACK},
		}},
		{AI::PathFinder2D::Direction::SOUTH,{
			{AI::PathFinder2D::Direction::NORTH, MoveAction::TURN_BACK},
			{AI::PathFinder2D::Direction::EAST, MoveAction::TURN_LEFT},
			{AI::PathFinder2D::Direction::WEST, MoveAction::TURN_RIGHT},
			{AI::PathFinder2D::Direction::SOUTH, MoveAction::MOVE_FORWARD},
		}},
		{AI::PathFinder2D::Direction::EAST,{
			{AI::PathFinder2D::Direction::NORTH, MoveAction::TURN_LEFT},
			{AI::PathFinder2D::Direction::EAST, MoveAction::MOVE_FORWARD},
			{AI::PathFinder2D::Direction::WEST, MoveAction::TURN_BACK},
			{AI::PathFinder2D::Direction::SOUTH, MoveAction::TURN_RIGHT},
		}},
		{AI::PathFinder2D::Direction::WEST,{
			{AI::PathFinder2D::Direction::NORTH, MoveAction::TURN_RIGHT},
			{AI::PathFinder2D::Direction::EAST, MoveAction::TURN_BACK},
			{AI::PathFinder2D::Direction::WEST, MoveAction::MOVE_FORWARD},
			{AI::PathFinder2D::Direction::SOUTH, MoveAction::TURN_LEFT},
		}},
	};

	static const std::unordered_map<AI::IGraph::Coord2D, AI::PathFinder2D::Direction, AI::IGraph::hashCoord2D> directionMove = {
		{{0, 0}, AI::PathFinder2D::Direction::NONE},
		{{0, -1}, AI::PathFinder2D::Direction::NORTH},
		{{0, +1}, AI::PathFinder2D::Direction::SOUTH},
		{{-1, 0}, AI::PathFinder2D::Direction::WEST},
		{{+1, 0}, AI::PathFinder2D::Direction::EAST},
		{{0, +(_graph->getHeight() - 1)}, AI::PathFinder2D::Direction::NORTH},
		{{0, -(_graph->getHeight() - 1)}, AI::PathFinder2D::Direction::SOUTH},
		{{+(_graph->getWidth() - 1), 0}, AI::PathFinder2D::Direction::WEST},
		{{-(_graph->getWidth() - 1), 0}, AI::PathFinder2D::Direction::EAST},
	};

	AI::IGraph::Coord2D currentPos = path[0];
	for (auto& item : path) {
		auto resPos = item;
		resPos.x = item.x - currentPos.x;
		resPos.y = item.y - currentPos.y;

		auto find = directionMove.at(resPos);
		if (find == AI::PathFinder2D::Direction::NONE)
			_actionQueue.push(MoveAction::DO_NOTHING);
		else {
			if (find != _orientation) {
				_actionQueue.push(actionMove.at(_orientation).at(find));
				_orientation = find;
			}
			_actionQueue.push(actionMove.at(_orientation).at(find));
		}
		currentPos = item;
	}
}

void AI::ZappyAi::pathToQueue(std::vector<AI::IGraph::Coord2D> const& path)
{
	for (auto& item : path) {
		_pathQueue.push(item);
	}
}

void AI::ZappyAi::run(bool testing)
{
	decisionTreeLvl1();
	while (666) {
		_decisionTree.Do(1, testing);
		if (testing) {
			dump();
			int x;
			std::cin >> x;
			std::cout << "\033c" <<std::endl;
		}
	}
}

void AI::ZappyAi::setLevel1Decisions()
{
	_decisionTree.reset();
}

bool AI::ZappyAi::moveForward()
{
	bool res {false};

	if (not _pathQueue.empty() && not _actionQueue.empty()) {
//		res = _comm.forward();
		res = true;
		if (res) {
			_postionOld = _postion;
			_postion = _pathQueue.front();
			_pathQueue.pop();
			_actionQueue.pop();
			std::cout << __func__ << std::endl;
		}
	}
	return res;
}

bool AI::ZappyAi::turnLeft()
{
	bool res {false};

	if (not _pathQueue.empty() && not _actionQueue.empty()) {
//		res = _comm.left();
		res = true;
		if (res) {
			_orientation = PathFinder2D::directionRotate90(_orientation, false);
			_actionQueue.pop();
			std::cout << __func__ << std::endl;
		}
	}
	return res;
}

bool AI::ZappyAi::turnRight()
{
	bool res {false};

	if (not _pathQueue.empty() && not _actionQueue.empty()) {
//		res = _comm.right();
		res = true;
		if (res) {
			_orientation = PathFinder2D::directionRotate90(_orientation, true);
			_actionQueue.pop();
			std::cout << __func__ << std::endl;
		}
	}
	return res;
}

bool AI::ZappyAi::turnBack()
{
	bool res {false};

	if (not _pathQueue.empty() && not _actionQueue.empty()) {
//		res = _comm.right();
		res = true;
		if (res)
			_orientation = PathFinder2D::directionRotate90(_orientation, true);
		else
			return false;
//		res = _comm.right();
		res = true;
		if (res)
			_orientation = PathFinder2D::directionRotate90(_orientation, true);
		else
			return false;
		_actionQueue.pop();
		std::cout << __func__ << std::endl;
	}
	return res;
}

bool AI::ZappyAi::look()
{
	return true;
}

void AI::ZappyAi::decisionTreeLvl1()
{
	_decisionTree.addDecision(1, FunctorIsActionQueue(*this), "Do i have any path to do ?");
	_decisionTree.addDecision(2, FunctorMakeRandomPath(*this), "Did i Found a new random Path ?");
	_decisionTree.addDecision(3, FunctorDoPathAction(*this), "Did i succeed my next action ?");
	_decisionTree.addDecision(4, FunctorLook(*this), "Look ?");

	_decisionTree.addChoice(1, 3 , true);
	_decisionTree.addChoice(1, 2 , false);
	_decisionTree.addChoice(2, 3 , true);
	_decisionTree.addChoice(3, 4 , true);
}

/// ---------------- decision functor ------------------------

bool AI::ZappyAi::FunctorIsActionQueue::operator()()
{
	return !_ai._actionQueue.empty();
}

bool AI::ZappyAi::FunctorMakeRandomPath::operator()()
{
	_ai._pathPos = _ai._pathFinder.randomPath(_ai._postion, 10,_ai._orientation);
	if (_ai._pathPos.empty())
		return false;
	_ai.translatePathToAction(_ai._pathPos);
	_ai.pathToQueue(_ai._pathPos);
	return true;
}

bool AI::ZappyAi::FunctorDoPathAction::operator()()
{
	auto action = _ai._actionQueue.front();
	bool res {false};

	switch (action) {
		case MoveAction::MOVE_FORWARD :
			res =  _ai.moveForward(); break;
		case MoveAction::TURN_LEFT :
			res =  _ai.turnLeft(); break;
		case MoveAction::TURN_RIGHT :
			res =  _ai.turnRight(); break;
		case MoveAction::TURN_BACK :
			res =  _ai.turnBack(); break;
		case MoveAction::DO_NOTHING :
			res = true;
			_ai._actionQueue.pop();
			_ai._pathQueue.pop();
			std::cout << "do nothing" << std::endl;
	}
	return res;
}

bool AI::ZappyAi::FunctorLook::operator()()
{
	return _ai.look();
}
