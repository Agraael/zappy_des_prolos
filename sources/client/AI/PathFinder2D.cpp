/*
** EPITECH PROJECT, 2021
** PathFinder_A
** File description:
** Created by kraken, 13/06/18
*/

#include "PathFinder2D.hpp"
#include "linux_color.hpp"

static inline unsigned int nbDigit(int nb) noexcept
{
	unsigned int res = 0;
	do {
		++res;
		nb /= 10;
	} while (nb);
	return res;
}

static inline void nodeCout(int digitX, int digitY, AI::IGraph::Node& node) noexcept
{
	static auto sign = [](int nb){if (nb > 0) return "+"; else if(nb < 0) return "-"; else return " ";};

	std::cout.fill('0');
	std::cout << "[" << sign(node.point.coord.x) << std::setw(digitX) << std::abs(node.point.coord.x)
		<< "," << sign(node.point.coord.y) << std::setw(digitY) << std::abs(node.point.coord.y) << "]";
}

static inline void nodeEmptyCout(int digitX, int digitY) noexcept
{
	std::cout << "[" << std::string(digitX + 1 , ' ') << "," << std::string(digitY + 1, ' ') << "]";
}

void AI::PathFinder2D::dump() const
{
	auto digitX = nbDigit(_graph->getWidth());
	auto digitY = nbDigit(_graph->getHeight());
	auto startX = (_graph->isCentered()) ? (-_graph->getWidth() + 1) : (0);
	auto startY = (_graph->isCentered()) ? (-_graph->getHeight() + 1) : (0);

	for (auto y = startY; y < _graph->getHeight(); ++y) {
		for (auto x = startX; x < _graph->getWidth(); ++x) {
			auto find = _graph->getNodeAt(x, y);
			Linux::color(Linux::TermColor::BOLD_ON);
			if (find == std::nullopt)
				nodeEmptyCout(digitX, digitY);
			else {
				AI::IGraph::NodePtr elem(find.value());
				if (elem == _start)
					Linux::color(Linux::TermColor::GREEN_BG);
				else if (elem == _end)
					Linux::color(Linux::TermColor::RED_BG);
				else if (elem->point.bObstacle)
					Linux::color(Linux::TermColor::MAGENTA_BG);
				else if ((std::find_if(_path.begin(), _path.end(), [x, y](IGraph::Coord2D const& s) {
					return s.x == x && s.y == y;
				})) != _path.end())
					Linux::color(Linux::TermColor::YELLOW_BG);
				else if (elem->bVisited)
					Linux::color(Linux::TermColor::BLUE_BG);
				nodeCout(digitX, digitY, *elem.get());
			}
			Linux::color(Linux::TermColor::RESET);
			std::cout << "  ";
		}
		std::cout << std::endl << std::endl;
	}
}

float AI::PathFinder2D::distance(IGraph::Coord2D& lhs, IGraph::Coord2D& rhs)
{
	IGraph::Coord2D lhs_revert{lhs.x + _graph->isCentered(), lhs.y + _graph->getHeight()};

	auto calc = static_cast<float>((lhs.x - rhs.x)*(lhs.x - rhs.x) + (lhs.y - rhs.y)*(lhs.y - rhs.y));
	auto calcRevert = static_cast<float>((lhs_revert.x - rhs.x)*(lhs_revert.x - rhs.x) + (lhs_revert.y - rhs.y)*(lhs_revert.y - rhs.y));
	if (_graph->isBorderless() && calcRevert < calc)
		return std::sqrt(calcRevert);
	return std::sqrt(calc);
}

std::vector<AI::IGraph::Coord2D> const& AI::PathFinder2D::findPath(IGraph::Coord2D const& start, IGraph::Coord2D const& end)
{
	auto heuristic = [this](IGraph::NodePtr& a, IGraph::NodePtr& b) {return distance(a->point.coord, b->point.coord);};
	std::list<IGraph::NodePtr> listNotTestedNodes;

	this->clean();
	// Reset Navigation IGraph - default all node states
	auto findS = _graph->getNodeAt(start.x, start.y);
	auto findE = _graph->getNodeAt(end.x, end.y);
	if (findS == std::nullopt || findE == std::nullopt)
		return _path;
	_start = findS.value();
	_end = findE.value();
	if (_start->point.bObstacle || _end->point.bObstacle)
		return _path;
	_start->fLocalGoal = 0.0f;
	_start->fGlobalGoal = heuristic(_start, _end);
	listNotTestedNodes.push_back(_start);
	IGraph::NodePtr currentNode = _start;

	while(not listNotTestedNodes.empty() && currentNode != _end) { // Find absolutely shortest path remove // && currentNode != _end)
		// Sort Untested nodes by global goal, so lowest is first
		listNotTestedNodes.sort([](const IGraph::NodePtr& lhs, const IGraph::NodePtr& rhs){ return lhs->fGlobalGoal < rhs->fGlobalGoal; });
		// Front of listNotTestedNodes is potentially the lowest distance node. Our
		// list may also contain nodes that have been visited, so ditch these...
		while(!listNotTestedNodes.empty() && listNotTestedNodes.front()->bVisited)
			listNotTestedNodes.pop_front();
		if (listNotTestedNodes.empty())
			break;
		currentNode = listNotTestedNodes.front();
		currentNode->bVisited = true;

		for (auto nodeNeighbour : currentNode->vecNeighbours)
		{
			if (!nodeNeighbour->bVisited && nodeNeighbour->point.bObstacle == 0)
				listNotTestedNodes.push_back(nodeNeighbour);

			// Calculate the neighbours potential lowest parent distance
			float fPossiblyLowerGoal = currentNode->fLocalGoal + distance(currentNode->point.coord, nodeNeighbour->point.coord);
			if (fPossiblyLowerGoal < nodeNeighbour->fLocalGoal)
			{
				nodeNeighbour->parent = currentNode;
				nodeNeighbour->fLocalGoal = fPossiblyLowerGoal;
				nodeNeighbour->fGlobalGoal = nodeNeighbour->fLocalGoal + heuristic(nodeNeighbour, _end);
			}
		}
	}
	if (_end != nullptr) {
		IGraph::NodePtr p = _end;
		while (p->parent != nullptr) {
			_path.emplace_back(p->point.coord);
			p = p->parent;
		}
		if (not _path.empty())
			_path.emplace_back(_start->point.coord);

	}
	std::reverse(_path.begin(), _path.end());
	return _path;
}

void AI::PathFinder2D::clean()
{
	_graph->cleanNodes();
	_path.clear();
	_start = nullptr;
	_end = nullptr;
}

bool AI::PathFinder2D::checkGraph()
{
	if (_graph == nullptr) {
		throw std::runtime_error("PathFinder no graph !");
		return false;
	}
	return true;
}

std::shared_ptr<AI::IGraph> const& AI::PathFinder2D::getGraph() const
{
	return _graph;
}

void AI::PathFinder2D::setGraph(std::shared_ptr<AI::IGraph> const& graph)
{
	_graph = graph;
}

AI::PathFinder2D::Direction AI::PathFinder2D::directionRotate90(AI::PathFinder2D::Direction direc, bool right) {
	if (direc == AI::PathFinder2D::Direction::NORTH)
		return (right) ? (AI::PathFinder2D::Direction::EAST): (AI::PathFinder2D::Direction::WEST);
	if (direc == AI::PathFinder2D::Direction::SOUTH)
		return (right) ? (AI::PathFinder2D::Direction::WEST): (AI::PathFinder2D::Direction::EAST);
	if (direc == AI::PathFinder2D::Direction::EAST)
		return (right) ? (AI::PathFinder2D::Direction::SOUTH): (AI::PathFinder2D::Direction::NORTH);
	if (direc == AI::PathFinder2D::Direction::WEST)
		return (right) ? (AI::PathFinder2D::Direction::NORTH): (AI::PathFinder2D::Direction::SOUTH);
	return AI::PathFinder2D::Direction::NONE;
}

AI::PathFinder2D::Direction AI::PathFinder2D::directionRotate180(AI::PathFinder2D::Direction direc) {
	if (direc == AI::PathFinder2D::Direction::NORTH)
		return AI::PathFinder2D::Direction::SOUTH;
	if (direc == AI::PathFinder2D::Direction::SOUTH)
		return AI::PathFinder2D::Direction::NORTH;
	if (direc == AI::PathFinder2D::Direction::EAST)
		return AI::PathFinder2D::Direction::WEST;
	if (direc == AI::PathFinder2D::Direction::WEST)
		return AI::PathFinder2D::Direction::EAST;
	return AI::PathFinder2D::Direction::NONE;
}

AI::IGraph::NodePtr& AI::PathFinder2D::canMoveDirection(AI::IGraph::NodePtr& node, AI::PathFinder2D::Direction direc) {
	static std::shared_ptr<AI::IGraph::Node> error(nullptr);
	AI::IGraph::Coord2D newCoord = node->point.coord;

	static const std::unordered_map<AI::PathFinder2D::Direction, AI::IGraph::Coord2D> directionMap = {
		{AI::PathFinder2D::Direction::NORTH, {0,-1}},
		{AI::PathFinder2D::Direction::SOUTH, {0,+1}},
		{AI::PathFinder2D::Direction::EAST, {+1,0}},
		{AI::PathFinder2D::Direction::WEST, {-1,0}},
		{AI::PathFinder2D::Direction::NORTH_EAST, {+1,-1}},
		{AI::PathFinder2D::Direction::NORTH_WEST, {-1,-1}},
		{AI::PathFinder2D::Direction::SOUTH_EAST, {+1,+1}},
		{AI::PathFinder2D::Direction::SOUTH_WEST, {-1,+1}},
		{AI::PathFinder2D::Direction::NONE, {0,0}}
	};

	newCoord.x +=  directionMap.at(direc).x;
	newCoord.y +=  directionMap.at(direc).y;
	auto find = std::find_if(node->vecNeighbours.begin(), node->vecNeighbours.end(), [newCoord](AI::IGraph::NodePtr const& elem){
		return newCoord.x == elem->point.coord.x && newCoord.y == elem->point.coord.y;
	});
	if (find == node->vecNeighbours.end() && _graph->isBorderless()) {
		newCoord = node->point.coord;
		newCoord.x += (directionMap.at(direc).x + (directionMap.at(direc).x * (-_graph->getWidth())));
		newCoord.y += (directionMap.at(direc).y + (directionMap.at(direc).y * (-_graph->getHeight())));
		find = std::find_if(node->vecNeighbours.begin(), node->vecNeighbours.end(), [newCoord](AI::IGraph::NodePtr const& elem){
			return newCoord.x == elem->point.coord.x && newCoord.y == elem->point.coord.y;
		});
	}
	if (find == node->vecNeighbours.end())
		return error;
	if (find.base()->get()->point.bObstacle)
		return error;
	return *find;
}

std::vector<AI::IGraph::Coord2D> const& AI::PathFinder2D::randomPath(IGraph::Coord2D const& start, unsigned int step,
                                                                     Direction originDirection)
{
	static std::random_device rd{};
	static std::mt19937 gen{rd()};
	static std::uniform_int_distribution<int> d100{1,115};
	static std::uniform_int_distribution<int> d4{1,4};
	Direction direction;

	if (originDirection == Direction::NONE)
		switch (d4(gen)) {
			case 1: direction = Direction::NORTH; break;
			case 2: direction = Direction::SOUTH; break;
			case 3: direction = Direction::EAST; break;
			case 4: direction = Direction::WEST; break;
			default: direction = Direction::NONE; break;
		}
	else
		direction = originDirection;

	this->clean();
	auto findS = _graph->getNodeAt(start.x, start.y);
	if (findS == std::nullopt)
		return _path;
	_start = findS.value();
	if(_start->point.bObstacle)
		return _path;
	IGraph::NodePtr currentNode = _start;
	_path.emplace_back(currentNode->point.coord);

	for (unsigned int i = 0; i < step; ++i) {
		Direction move = direction;
		auto res = d100(gen);
		if (res < 30) {
			if (res >= 15 && canMoveDirection(currentNode, directionRotate90(direction, true)) != nullptr)
				move = directionRotate90(direction, true);
			else if (canMoveDirection(currentNode, directionRotate90(direction, false)) != nullptr)
				move = directionRotate90(direction, false);
		}
		auto nextNode = canMoveDirection(currentNode, move);
		if (nextNode == nullptr) {
			Direction stck = move;
			res = d4(gen);
			move = directionRotate90(stck, res >= 3);
			nextNode = canMoveDirection(currentNode, move);
			if (nextNode == nullptr) {
				move = directionRotate180(move);
				nextNode = canMoveDirection(currentNode, move);
				if (nextNode == nullptr) {
					move = directionRotate180(stck);
					nextNode = canMoveDirection(currentNode, move);
				}
			}
		}
		if (nextNode != nullptr)
			currentNode = nextNode;
		direction = move;
		_path.emplace_back(currentNode->point.coord);
	}
	return _path;
}
