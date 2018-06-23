/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** Created by kraken, 21/06/18
*/

#ifndef ZAPPY_ZAPPYAI_HPP
#define ZAPPY_ZAPPYAI_HPP

#include <map>
#include <CommunicateToServer.hpp>
#include <queue>
#include "IGraph.hpp"
#include "PathFinder2D.hpp"
#include "ZappyGraph.hpp"
#include "DecisionTree.hpp"

namespace AI
{
	class ZappyAi
	{
	public:
		ZappyAi(int width, int height, serverSpace::CommunicateToServer& comm);
		~ZappyAi() = default;
		ZappyAi(ZappyAi const&) = delete;
		ZappyAi& operator=(ZappyAi const&) = delete;
		std::shared_ptr<ZappyGraph> const& getGraph() const;
		PathFinder2D::Direction getOrientation() const;
		IGraph::Coord2D const& getPostion() const;
		size_t getLevel() const;
		std::map<ZappyElement, size_t> const& getInventory() const;

		enum class MoveAction {
			MOVE_FORWARD, TURN_RIGHT, TURN_LEFT, TURN_BACK
		};

	private:
		serverSpace::CommunicateToServer& _comm;
		std::shared_ptr<ZappyGraph> _graph;
		PathFinder2D _pathFinder;
		DecisionTree _decisionTree;
		PathFinder2D::Direction _orientation = PathFinder2D::Direction::NORTH;
		IGraph::Coord2D _postion {0,0};
		size_t _level {1};
		std::map<ZappyElement, size_t> _inventory {};
		std::queue<MoveAction> _actionQueue {};

		void setLevel1Decisions();
		void translatePathToAction(std::vector<IGraph::Coord2D> path);

	public:
		/// ---------------- decisnion functor
		class DecisionFunctor {
		public:
			explicit DecisionFunctor(ZappyAi& ai) : _ai(ai){};
			virtual ~DecisionFunctor() = default;
			virtual bool operator() () = 0;
		protected:
			ZappyAi& _ai;
		};

		class ActionIsActionQueue : public DecisionFunctor {
		public:
			explicit ActionIsActionQueue(ZappyAi& ai) : DecisionFunctor(ai){};
			bool operator() () final;
		};
		class ActionMakeRandomPath : public DecisionFunctor {
		public:
			explicit ActionMakeRandomPath(ZappyAi& ai) : DecisionFunctor(ai){};
			bool operator() () final;
		};
	};
}

#endif //ZAPPY_ZAPPYAI_HPP
