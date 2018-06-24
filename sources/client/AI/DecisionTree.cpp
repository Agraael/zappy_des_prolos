/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** Created by kraken, 21/06/18
*/

#include <iostream>
#include "DecisionTree.hpp"

void AI::DecisionTree::addDecision(std::size_t id, AI::DecisionTree::DecisionFunc func, std::string const& description)
{
	_nodeMap[id].Action = func;
	_nodeMap[id].description = description;
}

void AI::DecisionTree::addChoice(std::size_t id_node, std::size_t id_choise, bool choice)
{
	if (_nodeMap.find(id_node) == _nodeMap.end())
		throw std::runtime_error("DecisionTree error: no node with id " + std::to_string(id_node));
	if (choice == true)
		_nodeMap[id_node].TrueId = id_choise;
	else
		_nodeMap[id_node].FalseId = id_choise;
}

bool AI::DecisionTree::Do(std::size_t start_id, bool verbose)
{
	if (_nodeMap.find(start_id) == _nodeMap.end())
		throw std::runtime_error("DecisionTree error: no node with id " + std::to_string(start_id));
	bool res = _nodeMap[start_id].Action();
	if (verbose)
		std::cout << "Node id: " << start_id << " > " << _nodeMap[start_id].description << " " << ((res) ? ("yes") : ("no")) << std::endl;
	if (res == true && _nodeMap[start_id].TrueId != 0)
		return Do(_nodeMap[start_id].TrueId, verbose);
	else if (res == false && _nodeMap[start_id].FalseId != 0)
		return Do(_nodeMap[start_id].FalseId, verbose);
	else
		return res;
}

void AI::DecisionTree::reset()
{
	_nodeMap.clear();
}
