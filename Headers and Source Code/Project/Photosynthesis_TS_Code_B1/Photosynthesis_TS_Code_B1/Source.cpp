/*
Date Format: mm/dd/yyyy
Date Created: 3-2-2019

Last Updated: 3-3-2019

Author: J. Daniel Reveles (aka Elena Reveles preferred name)

Objective: The objective of this project is to write a code that manages the turn sequence (TS) for the
digital version of the board game Photosynthesis. As the program get's updated I will update the build version as well.
The naming convention of the project is name of game_abbreviation for what the code does_Code_Build version.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	//The first additional lines of code will be pseudo_code. In other words the code may stay in the main function
	//or it may move to a function of its own within the same source file or to a different header file.

	//Typical turn sequence.
	//1. Photosynthesis Phase: The player with the First Player Token moves the Sun Segment clockwise, to the next angle on the hexegonal
	//	board. (note: this step is skipped during the first round of the game) Light points are accumulated based on the position of the sun.

	//2. Life Cycle Phase: After all players have collected their Light points, whoever holds the First Player Token starts taking their actions.
	//	Here is a list of the possible actions. The player can buy trees or seedlings from their waiting section with the Light points accrued
	//	during the photosynthesis phase. They can also plant seeds, depending on the placement of their trees. They can also grow their trees and/or
	//	cultivate them. All these actions require them to spend their Light points except for planting a seed. These actions do not need to be 
	//	taken in any particular order, although strategy may require otherwise.

	//The notes taken here are not the end all be all for the rules. Please consult the "Rules" section of the GitHub for a complete description of
	//how the game is supposed to work.

	string pl_decision; //This variable will hold the value of what it is the player wants to do. So far this variable works regardless of 
						//which player it is.

	bool repeat = 1;

	do
	{
		cout << "Player, what would you like to do?\n";
		cin >> pl_decision;

		if (pl_decision == "buy" || pl_decision == "Buy") //possible conditions: buy, plant, grow, harvest, end turn
		{
			string pl_buy;
			cout << "What would you like to buy?\n";

			//creating a 2 dimensional array to list what I can currently buy
			string items[4] = { "Seeds", "Sm Trees", "Med Trees", "Lrg Trees" }; //Initializing the array
			int amt_and_price[2][4]; //The first row will display the amount and the second row will display the price for the item

			int num_init = 0;

			for (int i = 0; i < 4; i++)
				cout << items[i] << "\t";

			cout << endl;

			//This loop will be used to initialize the array
			for (int i = 0; i < 2; i++) //This steps through the rows of the array
			{
				for (int j = 0; j < 4; j++) //This steps through the columns of the array
				{
					amt_and_price[i][j] = num_init;
					num_init++;
				}
			} //The end result of this array should be 0, 1, 2, 3,... n

			for (int i = 0; i < 2; i++) //This steps through the rows of the array
			{
				for (int j = 0; j < 4; j++) //This steps through the columns of the array
					cout << amt_and_price[i][j] << "\t\t";

				cout << "\n";
			}

			string prch_decision; //This will hold the decision made by the player
			cin >> prch_decision;

			//create a list of items to be purchased. label them 1-n and label each one with a price. The price may come from the object class
			//but list it here anyways for demonstration purposes. Most likely need to create a two dimensional array for this.
		}
		else if (pl_decision == "plant" || pl_decision == "Plant") //This will enter the plant phase
		{
			string pl_plant;
			cout << "What would you like to plant?\n";
			cin >> pl_plant;
			//create a list of items to be planted. label them 1-n and label each one. The price may come from the object class
			//but list it here anyways for demonstration purposes. Most likely need to create a two dimensional array for this.
		}
		else if (pl_decision == "grow" || pl_decision == "Grow") //This will enter the grow phase
		{
			string pl_grow;
			cout << "Which tree/seedling would ou like to grow?\n";
			cin >> pl_grow;
			//create a list of items to be grown. label them 1-n and label each one with a price. The price may come from the object class
			//but list it here anyways for demonstration purposes. Most likely need to create a two dimensional array for this.
		}
		else if (pl_decision == "harvest" || pl_decision == "Harvest") //This will enter the harvest phase
		{
			string pl_harvest;
			cout << "Which tree would you like to harvest?\n";
			cin >> pl_harvest;
			//create a list of items to be harvested. label them 1-n and label each one with a price. The price may come from the object class
			//but list it here anyways for demonstration purposes. Most likely need to create a two dimensional array for this.
		}
		else if (pl_decision == "end" || pl_decision == "End") //This ends the player's turn
		{
			char pl_end;
			cout << "Are you sure you want to end your turn?\n";
			cin >> pl_end;

			if (pl_end == 'y' || pl_end == 'Y') //This is just for reassurance.
				repeat = 0;//end the loop and break out of these if statements
		}
	} while (repeat); //Section updated on 3-3-2019. Not fully expanded since I moved to working on the set up section.

	return 0;
}