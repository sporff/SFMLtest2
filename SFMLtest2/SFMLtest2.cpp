// SFMLtest2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>




int main()
{
	// Create the main window
	sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

	sf::Vertex line[] =
	{
		sf::Vertex(sf::Vector2f(10, 10)),
		sf::Vertex(sf::Vector2f(150, 150))
	};


	Rack rack;
	std::cout << rack.NodeListSize() << std::endl;
	
	RackNodeKey newNodeKeyA = rack.AddNode(RackNode::MakeKey(72, 49));
	RackNodeKey newNodeKeyB = rack.AddNode(RackNode::MakeKey(103, 1007));
	rack.AddNode(RackNode::MakeKey(1, 2));
	rack.AddNode(RackNode::MakeKey(3, 4));
	std::cout << "Node Keys: " << newNodeKeyA << ", " << newNodeKeyB << std::endl;
	std::cout << "Node list size: " << rack.NodeListSize() << std::endl;

	//RackNode *newNode = rack.GetNode(newNodeKey);
	//RackNodePairKey newKey = newNode->GetKey();
	//std::cout << RackNode::UnpackKeyRow(newKey) << ", " << RackNode::UnpackKeyColumn(newKey) << std::endl;

	RackEdgeKey edgeKey = rack.AddEdge( newNodeKeyA, newNodeKeyB );
	rack.AddEdge(newNodeKeyA, newNodeKeyB);
	rack.AddEdge(newNodeKeyA, newNodeKeyB);
	rack.AddEdge(newNodeKeyA, newNodeKeyB);
	RackEdge* newEdge = rack.GetEdge(edgeKey);
	std::cout << newEdge->GetKey() << ": " << newEdge->GetNode(0) << ", " << newEdge->GetNode(1) << std::endl;
	std::cout << "Edge list size: " << rack.EdgeListSize();




	while (window.isOpen())
	{
		// Process events
		sf::Event event;
		while (window.pollEvent(event))
		{
			// Close window: exit
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// Clear screen
		window.clear();

		window.draw(line, 2, sf::Lines);

		// Update the window
		window.display();
	}
	return EXIT_SUCCESS;


}

