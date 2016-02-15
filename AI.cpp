#include "AI.h"

#include <vector>
#include <cstdlib>
#include <iostream>

void AI::doTurn(World *world)
{
    if(this->start == 0)
    {
        this->myID = world->getMyId();
        if(this->myID == 1)
            this->enemyID = 0;
        else
            this->enemyID = 1;
        ++start;
    }
    int neighbStatus;
//    Node *temp;
    std::vector<Node*> freeNeighbours;
    std::vector<Node*> myNeighbours;
    std::vector<Node*> enemyNeighbours;
	std::vector<Node*>& myNodes = world->getMyNodes();
	for(auto& source : myNodes)
	{
		/** Get neighbours **/
		const std::vector<Node*>& neighbours = source->getNeighbours();
        neighbStatus = 3;
		if (neighbours.size() > 0)
		{
            for(auto& ni : neighbours)
            {
                if(ni->getOwner() == this->enemyID)
                {
                    neighbStatus = 1;
                    break;
                }
                else if ( ni->getOwner() == -1)
                    neighbStatus = 2;
            }
            if(neighbStatus == 3)
                myNeighbours.push_back(source);
            else if (neighbStatus == 1)
                enemyNeighbours.push_back(source);
            else
                freeNeighbours.push_back(source);
		}
	}

    if( (world->getFreeNodes().size() / static_cast<double>(world->getFreeNodes().size() + world->getMyNodes().size() + world->getOpponentNodes().size())) > 0.5 )
    {
        //Fast phase
    }
    else
    {
        //Normal phase
    }
}
