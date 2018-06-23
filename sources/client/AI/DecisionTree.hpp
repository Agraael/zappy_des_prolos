/*
** EPITECH PROJECT, 2021
** zappy
** File description:
** Created by kraken, 21/06/18
*/

#ifndef ZAPPY_DECISIONTREE_HPP
#define ZAPPY_DECISIONTREE_HPP

#include <unordered_map>
#include <functional>

namespace AI
{
	class DecisionTree
	{
	public:
		DecisionTree() = default;
		~DecisionTree() = default;
		DecisionTree(DecisionTree const&) = delete;
		DecisionTree& operator=(DecisionTree const&) = delete;

		using DecisionFunc = std::function<bool(void)>;
		struct DecisionNode {
			DecisionFunc Action {nullptr};
			size_t TrueId {0};
			size_t FalseId {0};
			std::string description {};
		};

		void addDecision(std::size_t id, DecisionFunc func, std::string const& description);
		void addChoice(std::size_t id_node, std::size_t id_choise, bool choice);
		bool Do(std::size_t start_id, bool verbose);
		void reset();
	private:
		std::unordered_map<std::size_t, DecisionNode> _nodeMap {};
	};
}

#endif //ZAPPY_DECISIONTREE_HPP
