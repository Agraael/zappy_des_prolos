/*
** EPITECH PROJECT, 2021
** PathFinder_A
** File description:
** Created by kraken, 13/06/18
*/

#ifndef PATHFINDER_A_PATHFINDER_HPP
#define PATHFINDER_A_PATHFINDER_HPP

#include <iomanip>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>
#include <list>
#include <random>
#include <optional>
#include <functional>
#include <unordered_map>
#include "IGraph.hpp"

namespace AI
{
	class PathFinder2D
	{
	public:
		enum class Direction
		{
			NORTH,
			SOUTH,
			EAST,
			WEST,
			NORTH_EAST,
			NORTH_WEST,
			SOUTH_EAST,
			SOUTH_WEST,
			NONE,
		};

		PathFinder2D() = default;
		~PathFinder2D() = default;
		PathFinder2D(PathFinder2D const&) = delete;
		PathFinder2D& operator=(PathFinder2D const&) = delete;

		void dump() const;
		float distance(IGraph::Coord2D& lhs, IGraph::Coord2D& rhs);
		std::vector<IGraph::Coord2D> const& findPath(IGraph::Coord2D const& start, IGraph::Coord2D const& end);
		std::vector<AI::IGraph::Coord2D> const& randomPath(IGraph::Coord2D const& start, unsigned int stepNb, Direction originDirection = Direction::NONE);
		std::shared_ptr<IGraph> const& getGraph() const;
		void setGraph(std::shared_ptr<IGraph> const& graph);

		static AI::PathFinder2D::Direction directionRotate90(AI::PathFinder2D::Direction direc, bool right);
		static AI::PathFinder2D::Direction directionRotate180(AI::PathFinder2D::Direction direc);
	private:
		std::shared_ptr<IGraph> _graph{nullptr};
		IGraph::NodePtr _start{nullptr};
		IGraph::NodePtr _end{nullptr};
		std::vector<IGraph::Coord2D> _path{};

		void clean();
		bool checkGraph();
		AI::IGraph::NodePtr& canMoveDirection(AI::IGraph::NodePtr& node, AI::PathFinder2D::Direction direc);
	};
}

#endif //PATHFINDER_A_PATHFINDER_HPP
