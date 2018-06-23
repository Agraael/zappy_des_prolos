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
#include "CommunicateToServer.hpp"

namespace AI
{
	class ZappyAi
	{
	public:
		ZappyAi(int width, int height, clientSpace::CommunicateToServer& comm);
		~ZappyAi() = default;
		ZappyAi(ZappyAi const&) = delete;
		ZappyAi& operator=(ZappyAi const&) = delete;
		std::shared_ptr<ZappyGraph> const& getGraph() const;
		PathFinder2D::Direction getOrientation() const;
		IGraph::Coord2D const& getPostion() const;
		size_t getLevel() const;
		std::map<ZappyElement, size_t> const& getInventory() const;

		enum class MoveAction {
			MOVE_FORWARD, TURN_RIGHT, TURN_LEFT, TURN_BACK, DO_NOTHING
		};

		void dump();
		void run(bool testing);

	private:
		clientSpace::CommunicateToServer& _comm;
		std::shared_ptr<ZappyGraph> _graph;
		PathFinder2D _pathFinder;
		DecisionTree _decisionTree;
		PathFinder2D::Direction _orientation = PathFinder2D::Direction::NORTH;
		IGraph::Coord2D _postion {0,0};
		IGraph::Coord2D _postionOld {0,0};
		size_t _level {1};
		std::map<ZappyElement, size_t> _inventory {};
		std::queue<MoveAction> _actionQueue {};
		std::queue<IGraph::Coord2D> _pathQueue {};
		std::vector<IGraph::Coord2D> _pathPos {};

		void decisionTreeLvl1();

		void setLevel1Decisions();
		void translatePathToAction(std::vector<IGraph::Coord2D> const& path);
		void pathToQueue(std::vector<IGraph::Coord2D> const& path);

		bool moveForward();
		bool turnLeft();
		bool turnRight();
		bool turnBack();
		bool look();

	public:
		/// ---------------- decision functor ------------------------
		class DecisionFunctor {
		public:
			explicit DecisionFunctor(ZappyAi& ai) : _ai(ai){};
			virtual ~DecisionFunctor() = default;
			virtual bool operator() () = 0;
		protected:
			ZappyAi& _ai;
		};

		class FunctorIsActionQueue : public DecisionFunctor {
		public:
			explicit FunctorIsActionQueue(ZappyAi& ai) : DecisionFunctor(ai){};
			bool operator() () final;
		};
		class FunctorMakeRandomPath : public DecisionFunctor {
		public:
			explicit FunctorMakeRandomPath(ZappyAi& ai) : DecisionFunctor(ai){};
			bool operator() () final;
		};
		class FunctorDoPathAction : public DecisionFunctor {
		public:
			explicit FunctorDoPathAction(ZappyAi& ai) : DecisionFunctor(ai){};
			bool operator() () final;
		};
		class FunctorLook : public DecisionFunctor {
		public:
			explicit FunctorLook(ZappyAi& ai) : DecisionFunctor(ai){};
			bool operator() () final;
		};
	};
}

#endif //ZAPPY_ZAPPYAI_HPP
