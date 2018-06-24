/*
** EPITECH PROJECT, 2021
** PathFinder_A
** File description:
** Created by kraken, 14/06/18
*/

#ifndef PATHFINDER_A_IGRAPH_HPP
#define PATHFINDER_A_IGRAPH_HPP

#include <iomanip>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>
#include <optional>
#include <functional>
#include <list>

namespace AI
{
	template <class T>
	inline void hash_combine(std::size_t& seed, const T& v)
	{
		std::hash<T> hasher;
		seed ^= hasher(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
	}

	class IGraph
	{
	public:
		struct Coord2D {
			int x;
			int y;
			bool operator==(Coord2D const& rhs) const;
			bool operator!=(Coord2D const& rhs) const;
			Coord2D operator+ (Coord2D const& rhs);
			Coord2D operator- (Coord2D const& rhs);
		};

		struct Point {
			Coord2D coord;
			bool bObstacle;
		};

		struct Node {
			Point point {{0,0}, false};
			float fGlobalGoal {INFINITY};
			float fLocalGoal {INFINITY};
			bool bVisited {false};
			std::vector<std::shared_ptr<Node>> vecNeighbours {};
			std::shared_ptr<Node> parent {nullptr};

			void reset() noexcept;
			void clean() noexcept;
		};

		struct hashCoord2D
		{
			std::size_t operator()(IGraph::Coord2D const &p) const {
				std::size_t seed1(0);
				hash_combine(seed1, p.x);
				hash_combine(seed1, p.y);

				std::size_t seed2(0);
				hash_combine(seed2, p.y);
				hash_combine(seed2, p.x);

				return std::min(seed1, seed2);
			}
		};


		using NodePtr = std::shared_ptr<Node>;
		using NodeVec = std::vector<NodePtr>;
		using NodeVecPtr = std::shared_ptr<NodeVec>;

		virtual ~IGraph() = default;

		virtual void cleanNodes() = 0;
		virtual std::optional<NodePtr> getNodeAt(int x, int y) = 0;
		virtual int getWidth() const = 0;
		virtual int getHeight() const = 0;
		virtual bool isCentered() const = 0;
		virtual bool isBorderless() const = 0;
	private:
	};
}

#endif //PATHFINDER_A_IGRAPH_HPP
