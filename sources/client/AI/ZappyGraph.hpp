/*
** EPITECH PROJECT, 2021
** PathFinder_A
** File description:
** Created by kraken, 14/06/18
*/

#ifndef PATHFINDER_A_GRAPH_HPP
#define PATHFINDER_A_GRAPH_HPP

#include <iomanip>
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <cmath>
#include <list>
#include "IGraph.hpp"
#include "CommunicateToServer.hpp"

namespace AI
{
//	enum class ZappyElement {
//		FOOD,
//		LINEMATE, DERAUMERE, SIBUR, MENDIANE, PHIRAS, THYSTAME,
//		PLAYER
//	};

	class ZappyGraph
		: public IGraph
	{
	public:

		struct ZappyNode
			: IGraph::Node {
			std::size_t age {0};
			bool unknown {true};
			std::vector<clientSpace::tilesType> elements {};
		};

		using ZappyNodePtr = std::shared_ptr<ZappyNode>;
		using ZappyNodeVec = std::vector<ZappyNodePtr>;
		using ZappyNodeVecPtr = std::shared_ptr<ZappyNodeVec>;

		ZappyGraph(int width, int height);
		~ZappyGraph() final = default;
		ZappyGraph(ZappyGraph const&) = delete;
		ZappyGraph& operator=(ZappyGraph const&) = delete;

		void cleanNodes() final;
		int getWidth() const final;
		int getHeight() const final;
		bool isCentered() const final;
		bool isBorderless() const final;
		std::optional<NodePtr> getNodeAt(int x, int y) final;
		std::optional<ZappyNodePtr> getZappyNodeAt(int x, int y);

		void resetGraph(int width, int height, bool);
		void deleteGraph();
	private:
		int _width {0};
		int _height {0};
		bool _diagonal {false};
		bool _borderless {false};
		ZappyNodeVecPtr _nodes {nullptr};

		void setLink();
		bool checkNodes();
	};
}

#endif //PATHFINDER_A_GRAPH_HPP
