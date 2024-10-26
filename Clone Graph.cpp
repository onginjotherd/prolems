#include <unordered_map>
#include <queue>
#include <vector>

class Node
{
public:
	int val;
	std::vector<Node*> neighbors;
	Node() : val(0), neighbors(std::vector<Node*>()) {}
	Node(int _val) : val(_val), neighbors(std::vector<Node*>()) {}
	Node(int _val, std::vector<Node*> _neighbors) : val(_val), neighbors(_neighbors) {}
};

Node* cloneGraph(Node* node)
{
	if (!node) return nullptr;

	std::unordered_map<Node*, Node*> copies;
	std::queue<Node*> toVisit;
	toVisit.push(node);
	copies[node] = new Node(node->val);

	while (!toVisit.empty())
	{
		Node* curr = toVisit.front();
		toVisit.pop();

for (Node * neighbor : curr->neighbors)
		{
			if (copies.find(neighbor) == copies.end())
			{
				copies[neighbor] = new Node(neighbor->val);
				toVisit.push(neighbor);
			}
			copies[curr]->neighbors.push_back(copies[neighbor]);
		}
	}

	return copies[node];
}
