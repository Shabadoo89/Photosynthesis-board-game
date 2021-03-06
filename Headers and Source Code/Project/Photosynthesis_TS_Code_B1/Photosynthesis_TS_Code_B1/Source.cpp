/*
Date Format: mm/dd/yyyy
Date Created: 3-2-2019

Last Updated: 4-8-2019

Author: Elena Reveles (assigned at birth name: Daniel)

Objective: The objective of this project is to write a code that manages the turn sequence (TS) for the
digital version of the board game Photosynthesis. As the program get's updated I will update the build version as well.
The naming convention of the project is name of game_abbreviation for what the code does_Code_Build version.
*/

#include <iostream>
#include <string>

using namespace std;

char player_select_screen(); //This function only serves to select the amount of players that will be playing
void _2pl_function(bool &);  //This function runs as a cause of the player_select_screen() function
void _3pl_function(bool &);  //This function runs as a cause of the player_select_screen() function
void _4pl_function(bool &);  //This function runs as a cause of the player_select_screen() function
void start_game(char);		 //This starts the game.

/*The first additional lines of code will be pseudo_code. In other words the code may stay in the main function
or it may move to a function of its own within the same source file or to a different header file.

Typical turn sequence.
1. Photosynthesis Phase: The player with the First Player Token moves the Sun Segment clockwise, to the next angle on the hexegonal
	board. (note: this step is skipped during the first round of the game) Light points are accumulated based on the position of the sun.

2. Life Cycle Phase: After all players have collected their Light points, whoever holds the First Player Token starts taking their actions.
	Here is a list of the possible actions. The player can buy trees or seedlings from their waiting section with the Light points accrued
	during the photosynthesis phase. They can also plant seeds, depending on the placement of their trees. They can also grow their trees and/or
	cultivate them. All these actions require them to spend their Light points except for planting a seed. These actions do not need to be 
	taken in any particular order, although strategy may require otherwise.

The notes taken here are not the end all be all for the rules. Please consult the "Rules" section of the GitHub for a complete description of
how the game is supposed to work.*/

/*
Update 3-20-2019:
I have been working on a turn simulator during school and work hours. I ended up writing a better version during that time so I will post the progress
I have made so far here. Please refer to Turn Simulator Source Code in C:\Users\Shabadoo\Desktop\GitHub Projects\Photosynthesis Game\Photosynthesis-board-game\Documents and Flowcharts\Build Documentation
for further updates.
*/

/*
Update 7-6-2019:
The turn sequence has practically been finished for all modes. The next step is to start writing the code that will decide the details in the process.
I need to start writing the sequence in which stuff can be done. So maybe creating a menu that takes care of the planting and buying and extracting.
*/

int main()
{
	//substitute for plDecide
	char plDecide = player_select_screen();

	start_game(plDecide);

	cout << "This signifies the end of the game" << endl;
	cout << "Thank you for playing...Goodbye\n";

	system("pause");
	return 0;
}

char player_select_screen()
{
	char plDecide;

	while (true)
	{
		cout << "Player select screen\n\n";
		cout << "Minimum 2 players required\n\n";

		cout << "A: 2 Player\n";
		cout << "B: 3 Player\n";
		cout << "C: 4 Player\n";
		cin >> plDecide;

		if (plDecide == 'A' || plDecide == 'a')
			return plDecide;
		else if (plDecide == 'B' || plDecide == 'b')
			return plDecide;
		else if (plDecide == 'C' || plDecide == 'c')
			return plDecide;
		else
			cout << "Please enter a valid response\n";
	};

	return plDecide;
}

void _2pl_function(bool &check)
{
	cout << "2 player mode\n\n";
	int turn_counter = 1;
	int day_counter = 0;
	do
	{

		bool stuff = 1;

		cout << "Turn: " << turn_counter << endl;
		cout << "Day:  " << day_counter + 1 << endl;
		cout << "Player 1, take your turn: " << endl;

		do
		{ //The content of this loop will most likely be absorbed into the header file for the player objects or it's own class object
			char action_point; //This will decide what to do

			cout << "What would you like to do?\n";
			cout << "A: Plant\nB: Grow\nC: Buy\n";
			cin >> action_point;

			if (action_point == 'a' || action_point == 'A')
			{
				cout << "Where would you like to plant the seedling?\n";
				stuff = 0;
			}
			else if (action_point == 'b' || action_point == 'B')
			{
				cout << "Which tree would you like to grow?\n";
				stuff = 0;
			}
			else if (action_point == 'c' || action_point == 'C')
			{
				cout << "Which tree/seedling would you like to buy?\n";
				stuff = 0;
			}
			else
				cout << "Please choose a correct answer\n";

		} while (stuff); //We are going to reuse this boolean for both loops.

		stuff = 1;

		do
		{
			string shit;
			cout << "Blah blah blah\n";
			cout << "Doing some stuff\n\n"; //this will be commented out once the 
			cout << "Would you like to stop doing some stuff?\n";
			cin >> shit;

			if (shit == "y" || shit == "Y")
				stuff = 0;
			else if (shit == "exit" || shit == "end") //these will be taken out completely or moved to a spot that is more convenient
				exit;
			else
				cout << "Okay, let's keep doing stuff.\n";
		} while (stuff); //This is player 1 stuff


		stuff = 1;
		cout << "Player 2, take your turn: \n";
		do
		{
			string shit;
			cout << "Blah blah blah\n";
			cout << "Doing some stuff\n\n";
			cout << "Would you like to stop doing some stuff?\n";
			cin >> shit;

			if (shit == "y" || shit == "Y")
				stuff = 0;
			else if (shit == "exit" || shit == "end") //these will be taken out completely or moved to a spot that is more convenient
				exit;
			else
				cout << "Okay, let's keep doing stuff.\n";
		} while (stuff); //This is player 2 stuff

						 /*	day_counter = 3;
						 turn_counter = 6;*/ //you left off here bozo 3/18/2019

		if (turn_counter == 6)
		{
			day_counter++;
			turn_counter = 1;
		}
		else
			turn_counter++;

		if (day_counter == 3)
			check = false; //This is changing the value in the start_game function. Please be aware.
	} while (check);
	check = true; //testing this as of 3/27/2019. Theoretically this should allow the current loop to iterate if chosen yes.
	//testing is successful for the reset flag. Will implement in the 3 player and 4 player modes.
}

void _3pl_function(bool &check) //This will have the same code as 2 player mode but with additional players
{
	cout << "3 Player mode";
	int turn_counter = 1;
	int day_counter = 0;
	do
	{

		bool stuff = 1;

		cout << "Turn: " << turn_counter << endl;
		cout << "Day:  " << day_counter + 1 << endl;
		cout << "Player 1, take your turn: " << endl;
		do
		{
			string shit;
			cout << "Blah blah blah\n";
			cout << "Doing some stuff\n\n";
			cout << "Would you like to stop doing some stuff?\n";
			cin >> shit;

			if (shit == "y" || shit == "Y")
				stuff = 0;
			else if (shit == "exit" || shit == "end") //these will be taken out completely or moved to a spot that is more convenient
				exit;
			else
				cout << "Okay, let's keep doing stuff.\n";
		} while (stuff); //This is player 1 stuff


		stuff = 1;
		cout << "Player 2, take your turn: \n";
		do
		{
			string shit;
			cout << "Blah blah blah\n";
			cout << "Doing some stuff\n\n";
			cout << "Would you like to stop doing some stuff?\n";
			cin >> shit;

			if (shit == "y" || shit == "Y")
				stuff = 0;
			else if (shit == "exit" || shit == "end") //these will be taken out completely or moved to a spot that is more convenient
				exit;
			else
				cout << "Okay, let's keep doing stuff.\n";
		} while (stuff); //This is player 2 stuff

		stuff = 1;
		cout << "Player 3, take your turn: \n";
		do
		{
			string shit;
			cout << "Blah blah blah\n";
			cout << "Doing some stuff\n\n";
			cout << "Would you like to stop doing some stuff?\n";
			cin >> shit;

			if (shit == "y" || shit == "Y")
				stuff = 0;
			else if (shit == "exit" || shit == "end") //these will be taken out completely or moved to a spot that is more convenient
				exit;
			else
				cout << "Okay, let's keep doing stuff.\n";
		} while (stuff); //This is player 3 stuff

		if (turn_counter == 6)
		{
			day_counter++;
			turn_counter = 1;
		}
		else
			turn_counter++;

		if (day_counter == 3)
			check = false; //This is changing the value in the start_game function. Please be aware.
	} while (check);
	check = true; //Resetting flag to continue loop in start_game function
}

void _4pl_function(bool &check) //This will have the same code as 2 player mode but with additional players
{
	cout << "4 player mode";
	int turn_counter = 1;
	int day_counter = 0;
	do
	{

		bool stuff = 1;

		cout << "Turn: " << turn_counter << endl;
		cout << "Day:  " << day_counter + 1 << endl;
		cout << "Player 1, take your turn: " << endl;
		do
		{
			string shit;
			cout << "Blah blah blah\n";
			cout << "Doing some stuff\n\n";
			cout << "Would you like to stop doing some stuff?\n";
			cin >> shit;

			if (shit == "y" || shit == "Y")
				stuff = 0;
			else if (shit == "exit" || shit == "end") //these will be taken out completely or moved to a spot that is more convenient
				exit;
			else
				cout << "Okay, let's keep doing stuff.\n";
		} while (stuff); //This is player 1 stuff


		stuff = 1;
		cout << "Player 2, take your turn: \n";
		do
		{
			string shit;
			cout << "Blah blah blah\n";
			cout << "Doing some stuff\n\n";
			cout << "Would you like to stop doing some stuff?\n";
			cin >> shit;

			if (shit == "y" || shit == "Y")
				stuff = 0;
			else if (shit == "exit" || shit == "end") //these will be taken out completely or moved to a spot that is more convenient
				exit;
			else
				cout << "Okay, let's keep doing stuff.\n";
		} while (stuff); //This is player 2 stuff

		stuff = 1;
		cout << "Player 3, take your turn: \n";
		do
		{
			string shit;
			cout << "Blah blah blah\n";
			cout << "Doing some stuff\n\n";
			cout << "Would you like to stop doing some stuff?\n";
			cin >> shit;

			if (shit == "y" || shit == "Y")
				stuff = 0;
			else if (shit == "exit" || shit == "end") //these will be taken out completely or moved to a spot that is more convenient
				exit;
			else
				cout << "Okay, let's keep doing stuff.\n";
		} while (stuff); //This is player 3 stuff

		stuff = 1;
		cout << "Player 4, take your turn: \n";
		do
		{
			string shit;
			cout << "Blah blah blah\n";
			cout << "Doing some stuff\n\n";
			cout << "Would you like to stop doing some stuff?\n";
			cin >> shit;

			if (shit == "y" || shit == "Y")
				stuff = 0;
			else if (shit == "exit" || shit == "end") //these will be taken out completely or moved to a spot that is more convenient
				exit;
			else
				cout << "Okay, let's keep doing stuff.\n";
		} while (stuff); //This is player 4 stuff

		if (turn_counter == 6)
		{
			day_counter++;
			turn_counter = 1;
		}
		else
			turn_counter++;

		if (day_counter == 3)
			check = false; //This is changing the value in the start_game function. Please be aware.
	} while (check);
	check = true; //Resetting flag to continue loop in start_game function
}

void start_game(char plDecide)
{
	bool check = true;
	char rematch_;

	while (check)
	{
		if (plDecide == 'A' || plDecide == 'a')
			_2pl_function(check);
		else if (plDecide == 'B' || plDecide == 'b')
			_3pl_function(check);
		else
			_4pl_function(check);

		bool rematch_bound_checking = true;
		do
		{
			cout << "Would you like a rematch?\n";
			cin >> rematch_;
			if (rematch_ == 'n' || rematch_ == 'N')
			{
				cout << "Bouncing the fucc outa here!!!\n";
				rematch_bound_checking = false;
				check = false;
			}
			else if (rematch_ == 'y' || rematch_ == 'Y')
			{
				cout << "Here we go again\n\n";
				cout << check << endl;
				rematch_bound_checking = false;
			}
			else
				cout << "Please enter a valid response\n";
		} while (rematch_bound_checking);
	};
}