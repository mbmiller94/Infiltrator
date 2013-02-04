///////////////////////////////////////////////////////////////////////////////
//          _____   ______________  __________  ___  __________  ____        //
//         /  _/ | / / ____/  _/ / /_  __/ __ \/   |/_  __/ __ \/ __ \       //
//         / //  |/ / /_   / // /   / / / /_/ / /| | / / / / / / /_/ /       //
//       _/ // /|  / __/ _/ // /___/ / / _, _/ ___ |/ / / /_/ / _, _/        //
//      /___/_/ |_/_/   /___/_____/_/ /_/ |_/_/  |_/_/  \____/_/ |_|         //
//                                                                           //
//    Copyright (C)2013 Michael Brandon Miller                               //
//                                                                           //
//    Infiltrator is free software: you can redistribute it and/or modify    //
//    it under the terms of the GNU General Public License as published by   //
//    the Free Software Foundation, either version 3 of the License, or      //
//    (at your option) any later version.                                    //
//                                                                           //
//    Infiltrator is distributed in the hope that it will be useful,         //
//    but WITHOUT ANY WARRANTY; without even the implied warranty of         //
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the          //
//    GNU General Public License for more details.                           //
//                                                                           //
//    You should have received a copy of the GNU General Public License      //
//    along with Infiltrator. If not, see <http://www.gnu.org/licenses/>.    //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

/**
 * @file  game.h
 * @brief Manages the games main execution loop.
 */

#include "game.h"
#include "console.h"

using namespace std;

namespace Infiltrator
{
	// Initializes the main game loop.
	void Game::Run(void)
	{
		ShowObjective();
	}

	// Shows the hacking missions objective.
	void Game::ShowObjective(void)
	{
		Console::PerformTask("Doing something...", "Finished doing something.", 0, 10);
		Console::TypeText("You are a hacker for hire. Your current client, Evan Smith, has set up");
		Console::TypeText("a bank account under an alias. He has hired you to hack into the banks");
		Console::TypeText("mainframe and funnel money from an account into the dummy account.");
		Console::Sleep(1000);
		cout << endl;
		Console::TypeText("The bank is a private bank that is tightly secured, all network");
		Console::TypeText("connections are heavily encrypted, and the accounts strictly guarded.");
		Console::TypeText("You both stand to make millions.");
		Console::Sleep(1000);
		
	}
}
