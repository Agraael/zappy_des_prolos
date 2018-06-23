/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** Created by kraken, 21/06/18
*/

#include "ZappyAi.hpp"

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

void AI::ZappyAi::translatePathToAction(std::vector<AI::IGraph::Coord2D> path)
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
			std::cout << "do nothing" << std::endl;
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

void AI::ZappyAi::setLevel1Decisions()
{
	_decisionTree.reset();
}

bool AI::ZappyAi::ActionIsActionQueue::operator()()
{
	return !_ai._actionQueue.empty();
}

bool AI::ZappyAi::ActionMakeRandomPath::operator()()
{
	_ai.translatePathToAction(_ai._pathFinder.randomPath(_ai._postion, 10,_ai._orientation));
	return !_ai._actionQueue.empty();
}
