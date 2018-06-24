/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** Created by kraken, 21/06/18
*/

#include <zconf.h>
#include "ZappyAi.hpp"
#include "linux_color.hpp"

#define VNAME(x) #x

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

std::map<clientSpace::tilesType, size_t> const& AI::ZappyAi::getInventory() const
{
	return _inventory;
}


void AI::ZappyAi::dump()
{
	for (auto y = 0; y < _graph->getHeight(); ++y) {
		for (auto x = 0; x < _graph->getWidth(); ++x) {
			auto find = _graph->getZappyNodeAt(x, y);
			Linux::color(Linux::TermColor::BOLD_ON);
			if (find == std::nullopt)
				std::cout << "[ ]";
			else {
				ZappyGraph::ZappyNodePtr elem(find.value());
				if (elem->unknown)
					Linux::color(Linux::TermColor::BLACK_FG);
				if (elem->point.coord == _postion)
					Linux::color(Linux::TermColor::RED_BG);
				else if (std::find(elem->elements.begin(), elem->elements.end(), clientSpace::tilesType::PLAYER) != elem->elements.end())
					Linux::color(Linux::TermColor::BLUE_BG);
				else if ((std::find_if(_pathPos.begin(), _pathPos.end(), [x, y](IGraph::Coord2D const& s) {
					return s.x == x && s.y == y;
				})) != _pathPos.end())
					Linux::color(Linux::TermColor::YELLOW_BG);
				std::cout << "[";
				if (elem->elements.empty())
					std::cout << " ";
				else
					std::cout << "o";
				std::cout << "]";
			}
			Linux::color(Linux::TermColor::RESET);
			std::cout << " ";
		}
		std::cout << std::endl << std::endl;
	}
	std::cout << _postion.x << "," << _postion.y << std::endl;
	if (_orientation == PathFinder2D::Direction::NORTH)
		std::cout << "NORTH" << std::endl;
	if (_orientation == PathFinder2D::Direction::SOUTH)
		std::cout << "SOUTH" << std::endl;
	if (_orientation == PathFinder2D::Direction::EAST)
		std::cout << "EAST" << std::endl;
	if (_orientation == PathFinder2D::Direction::WEST)
		std::cout << "WEST" << std::endl;
	for (auto& item : _inventory) {
		switch (item.first) {
			case clientSpace::tilesType::FOOD : std::cout << "FOOD: "; break;
			case clientSpace::tilesType::DERAUMERE : std::cout << "DERAUMERE: " ; break;
			case clientSpace::tilesType::LINEMATE : std::cout << "LINEMATE :"; break;
			case clientSpace::tilesType::MENDIANE : std::cout << "MENDIANE :"; break;
			case clientSpace::tilesType::PHIRAS : std::cout << "PHIRAS :"; break;
			case clientSpace::tilesType::SIBUR : std::cout << "SIBUR :"; break;
			case clientSpace::tilesType::THYSTAME : std::cout << "THYSTANE :"; break;
			default: std::cout << "unknown: ";
		}
		std::cout << item.second << std::endl;
	}
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

	auto orientation = _orientation;
	AI::IGraph::Coord2D currentPos = path[0];
	for (auto& item : path) {
		auto resPos = item;
		resPos.x = item.x - currentPos.x;
		resPos.y = item.y - currentPos.y;

		auto find = directionMove.at(resPos);
		if (find == AI::PathFinder2D::Direction::NONE)
			_actionQueue.push(MoveAction::DO_NOTHING);
		else {
			if (find != orientation) {
				_actionQueue.push(actionMove.at(orientation).at(find));
				orientation = find;
			}
			_actionQueue.push(actionMove.at(orientation).at(find));
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
	objectifLvl1();
	while (666) {
		_decisionTree.Do(1, testing);
		if (testing) {
			dump();
			usleep(500000);
			std::cout << "\033c" <<std::endl;
		}
	}
}

void AI::ZappyAi::resetDecisionTree()
{
	_decisionTree.reset();
}

bool AI::ZappyAi::moveForward()
{
	bool res {false};

	if (not _pathQueue.empty() && not _actionQueue.empty()) {
		res = _comm.forward();
		if (res) {
			_postionOld = _postion;
			_postion = _pathQueue.front();
			_pathQueue.pop();
			_actionQueue.pop();
		}
	}
	return res;
}

bool AI::ZappyAi::turnLeft()
{
	bool res {false};

	if (not _pathQueue.empty() && not _actionQueue.empty()) {
		res = _comm.left();
		if (res) {
			_orientation = PathFinder2D::directionRotate90(_orientation, false);
			_actionQueue.pop();
		}
	}
	return res;
}

bool AI::ZappyAi::turnRight()
{
	bool res {false};

	if (not _pathQueue.empty() && not _actionQueue.empty()) {
		res = _comm.right();
		if (res) {
			_orientation = PathFinder2D::directionRotate90(_orientation, true);
			_actionQueue.pop();
		}
	}
	return res;
}

bool AI::ZappyAi::turnBack()
{
	bool res {false};

	if (not _pathQueue.empty() && not _actionQueue.empty()) {
		res = _comm.right();
		if (res)
			_orientation = PathFinder2D::directionRotate90(_orientation, true);
		else
			return false;
		res = _comm.right();
		if (res)
			_orientation = PathFinder2D::directionRotate90(_orientation, true);
		else
			return false;
		_actionQueue.pop();
	}
	return res;
}

bool AI::ZappyAi::look()
{
	static const std::map<PathFinder2D::Direction, std::pair<IGraph::Coord2D, IGraph::Coord2D>> cordMap = {
		{PathFinder2D::Direction::NORTH, {{0,-1}, {+1,0}}},
		{PathFinder2D::Direction::SOUTH, {{0,+1}, {-1,0}}},
		{PathFinder2D::Direction::EAST, {{+1,0}, {0,-1}}},
		{PathFinder2D::Direction::WEST, {{0,+1}, {-1,0}}},
	};
	auto res = _comm.look();
	IGraph::Coord2D start  = _postion;
	IGraph::Coord2D cursor  = start;
	auto cnt = 1;
	auto i = 0;
	for (auto& vec : res) {
		if (i == cnt) {
			cnt += 2;
			i = 0;
			start = start + cordMap.at(_orientation).first;
			start = start - cordMap.at(_orientation).second;
			cursor = start;
		}
		auto copy = cursor;
		if (copy.x >= _graph->getWidth())
			copy.x -= _graph->getWidth();
		if (copy.x < 0)
			copy.x += _graph->getWidth();
		if (copy.y >= _graph->getHeight())
			copy.y -= _graph->getHeight();
		if (copy.y < 0)
			copy.y += _graph->getHeight();
		auto find = _graph->getZappyNodeAt(copy.x, copy.y);
		if (find != std::nullopt) {
			ZappyGraph::ZappyNodePtr node = find.value();
			node->unknown = false;
			node->elements.clear();
			for (auto& item : vec)
				if (item != clientSpace::tilesType::NOTHING && item != clientSpace::tilesType::PLAYER)
					node->elements.push_back(item);
		}
		cursor = cursor + cordMap.at(_orientation).second;
		i++;
	}
	return true;
}

void AI::ZappyAi::decisionTreeLvl1()
{
	resetDecisionTree();
	_decisionTree.addDecision(1, FunctorSucceedObjectif(*this), "Did i acheive my goal ?");
	_decisionTree.addDecision(9, FunctorIsActionQueue(*this), "Do i have any path to do ?");
	_decisionTree.addDecision(2, FunctorMakeRandomPath(*this), "Did i Found a new random Path ?");
	_decisionTree.addDecision(3, FunctorDoPathAction(*this), "Did i succeed my next action ?");
	_decisionTree.addDecision(4, FunctorLook(*this), "Did succeed to look arround me ?");
	_decisionTree.addDecision(5, FunctorMyPosIsNotEmpty(*this), "Is there something at my position ?");
	_decisionTree.addDecision(6, FunctorIfplayerOnMyPos(*this), "Is there any player at my position ?");
	_decisionTree.addDecision(7, FunctorTake(*this), "Did i succeed taking some object at my position ?");
	_decisionTree.addDecision(8, FunctorDoINeedIt(*this), "Do i need those item ?");
	_decisionTree.addDecision(10, FunctorEvolve(*this), "Did my evolution succeed ?");
	_decisionTree.addDecision(11, FunctorLevelUp(*this), "LEVEL UP");

	_decisionTree.addChoice(1, 10 , true);
	_decisionTree.addChoice(1, 9 , false);
	_decisionTree.addChoice(10, 9 , false);
	_decisionTree.addChoice(10, 11 , true);
	_decisionTree.addChoice(9, 3 , true);
	_decisionTree.addChoice(9, 2 , false);
	_decisionTree.addChoice(2, 3 , true);
	_decisionTree.addChoice(3, 4 , true);
	_decisionTree.addChoice(4, 5 , true);
	_decisionTree.addChoice(5, 8 , true);
	_decisionTree.addChoice(8, 7 , true);
}

void AI::ZappyAi::objectifLvl1()
{
	_objectif.clear();
	_objectif[clientSpace::LINEMATE] = 1;
}

bool AI::ZappyAi::CheckObjectif()
{
	for (auto& item : _objectif) {
		if (_inventory.find(item.first) == _inventory.end())
			return false;
		if (_inventory.at(item.first) < item.second)
			return false;
	}
	return true;
}

void AI::ZappyAi::objectifLvl2()
{
	_objectif.clear();
	_objectif[clientSpace::LINEMATE] = 1;
	_objectif[clientSpace::DERAUMERE] = 1;
	_objectif[clientSpace::SIBUR] = 1;
}

void AI::ZappyAi::decisionTreeLvl2()
{
	resetDecisionTree();
	_decisionTree.addDecision(1, FunctorSucceedObjectif(*this), "Did i acheive my goal ?");
	_decisionTree.addDecision(9, FunctorIsActionQueue(*this), "Do i have any path to do ?");
	_decisionTree.addDecision(2, FunctorMakeRandomPath(*this), "Did i Found a new random Path ?");
	_decisionTree.addDecision(3, FunctorDoPathAction(*this), "Did i succeed my next action ?");
	_decisionTree.addDecision(4, FunctorLook(*this), "Did succeed to look arround me ?");
	_decisionTree.addDecision(5, FunctorMyPosIsNotEmpty(*this), "Is there something at my position ?");
	_decisionTree.addDecision(6, FunctorIfplayerOnMyPos(*this), "Is there any player at my position ?");
	_decisionTree.addDecision(7, FunctorTake(*this), "Did i succeed taking some object at my position ?");
	_decisionTree.addDecision(8, FunctorDoINeedIt(*this), "Do i need those item ?");
	_decisionTree.addDecision(10, FunctorEvolve(*this), "Did my evolution succeed ?");
	_decisionTree.addDecision(11, FunctorLevelUp(*this), "LEVEL UP");

	_decisionTree.addChoice(1, 6 , true);
	_decisionTree.addChoice(6, 10 , true);
	_decisionTree.addChoice(6, 9 , false);
	_decisionTree.addChoice(1, 9 , false);
	_decisionTree.addChoice(10, 9 , false);
	_decisionTree.addChoice(10, 11 , true);
	_decisionTree.addChoice(9, 3 , true);
	_decisionTree.addChoice(9, 2 , false);
	_decisionTree.addChoice(2, 3 , true);
	_decisionTree.addChoice(3, 4 , true);
	_decisionTree.addChoice(4, 5 , true);
	_decisionTree.addChoice(5, 8 , true);
	_decisionTree.addChoice(8, 7 , true);

}

/// ---------------- decision functor ------------------------

bool AI::ZappyAi::FunctorIsActionQueue::operator()()
{
	return !_ai._actionQueue.empty();
}

bool AI::ZappyAi::FunctorMakeRandomPath::operator()()
{
	_ai._pathPos = _ai._pathFinder.randomPath(_ai._postion, (_ai._graph->getHeight() + _ai._graph->getWidth()) / 4,_ai._orientation);
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
	}
	return res;
}

bool AI::ZappyAi::FunctorLook::operator()()
{
	return _ai.look();
}

bool AI::ZappyAi::FunctorMyPosIsNotEmpty::operator()()
{
	auto find = _ai._graph->getZappyNodeAt(_ai._postion.x, _ai._postion.y);
	if (find == std::nullopt)
		return false;
	ZappyGraph::ZappyNodePtr node = find.value();
	return not node->elements.empty();
}

bool AI::ZappyAi::FunctorIfplayerOnMyPos::operator()()
{
	auto find = _ai._graph->getZappyNodeAt(_ai._postion.x, _ai._postion.y);
	if (find == std::nullopt)
		return false;
	ZappyGraph::ZappyNodePtr node = find.value();
	return std::find(node->elements.begin(), node->elements.end(), clientSpace::tilesType::PLAYER) != node->elements.end();
}

bool AI::ZappyAi::FunctorTake::operator()()
{
	if (not _ai._comm.takeObject())
		return false;
	auto find = _ai._graph->getZappyNodeAt(_ai._postion.x, _ai._postion.y);
	if (find == std::nullopt)
		return false;
	ZappyGraph::ZappyNodePtr node = find.value();
	for (auto& item : node->elements)
		++_ai._inventory[item];
	node->elements.clear();
	return true;
}

bool AI::ZappyAi::FunctorDoINeedIt::operator()()
{
	auto find = _ai._graph->getZappyNodeAt(_ai._postion.x, _ai._postion.y);
	if (find == std::nullopt)
		return false;
	ZappyGraph::ZappyNodePtr node = find.value();
	bool res {false};
	for (auto& item : node->elements) {
		if (item == clientSpace::tilesType::FOOD)
			return true;
		if (_ai._objectif.find(item) != _ai._objectif.end()) {
			auto find2 = _ai._inventory.find(item);
			if (find2 != _ai._inventory.end()) {
				if (_ai._inventory.at(item) < _ai._objectif.at(item))
					return true;
			}
			else
				return true;
		}
	}
	return res;
}

bool AI::ZappyAi::FunctorSucceedObjectif::operator()()
{
	return _ai.CheckObjectif();
}

bool AI::ZappyAi::FunctorEvolve::operator()()
{
	return _ai._comm.incantation();
}

bool AI::ZappyAi::FunctorLevelUp::operator()()
{
	_ai._level += 1;
	if (_ai._level == 2) {
		_ai.objectifLvl2();
		_ai.decisionTreeLvl2();
	}
	return true;
}
