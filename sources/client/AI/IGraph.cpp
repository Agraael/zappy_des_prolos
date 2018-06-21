/*
** EPITECH PROJECT, 2021
** PathFinder_A
** File description:
** Created by kraken, 14/06/18
*/

#include "IGraph.hpp"

void AI::IGraph::Node::clean() noexcept
{
	fGlobalGoal = INFINITY;
	fLocalGoal = INFINITY;
	bVisited = false;
	parent = nullptr;
}

void AI::IGraph::Node::reset()noexcept
{
	vecNeighbours.clear();
	clean();
}

bool AI::IGraph::Coord2D::operator==(AI::IGraph::Coord2D const& rhs) const
{
	return std::tie(x, y) == std::tie(rhs.x, rhs.y);
}

bool AI::IGraph::Coord2D::operator!=(AI::IGraph::Coord2D const& rhs) const
{
	return !(rhs == *this);
}
