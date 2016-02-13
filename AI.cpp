#include "AI.h"

#include <vector>
#include <cstdlib>
#include <iostream>

void AI::doTurn(World *world)
{
	/** Fill this method. We've presented a stupid AI as an example! **/
	std::vector<Node*>& myNodes = world->getMyNodes();
	for(auto& source : myNodes)
	{
		/** Get neighbours **/
		const std::vector<Node*>& neighbours = source->getNeighbours();
		if (neighbours.size() > 0)
		{
			/** Select a random neighbour **/
			if(source->getArmyCount() > 15)
			{
				Node *destination = neighbours[(int)(rand() % neighbours.size())];
				Node *destination1 = neighbours[(int)(rand() % neighbours.size())];
				/** Move half of the nodes army to the neighbour node **/
				if(destination->getOwner() == -1 || destination->getOwner() == world->getMyId())
					world->moveArmy(source, destination, source->getArmyCount() / 3);
				if(destination1->getOwner() == -1 || destination1->getOwner() == world->getMyId())
					world->moveArmy(source, destination1, source->getArmyCount() / 3);
			}
			else
			{
				Node *destination = neighbours[(int)(rand() % neighbours.size())];
				for(auto& ni : neighbours)
				{
					if(ni->getOwner() == -1)
					{
						destination = ni;
						break;
					}
				}
				world->moveArmy(source, destination, (source->getArmyCount() / 3) * 2);
			}
		}
	}
}
