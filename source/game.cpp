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
	void Game::Run()
	{
		for (int i = 1; i <= 10; i++)
		{
			Console::TypeText("Preparing exploit code for injection.", WHITE, true, false);
			Console::Sleep(1500);
			
			for (i = 1; i <= 100; i++) {
				cout << "Compiling... " << i << "%\r";
				Console::Sleep(50);
			}

			cout << endl;

			for (i = 1; i <= 100; i++) {
				cout << "Extracting exploited data... " << i << "%\r";
				Console::Sleep(50);
			}

			cout << endl;

			for (i = 1; i <= 100; i++) {
				cout << "Decrypting... " << i << "%\r";
				Console::Sleep(50);
			}

			Console::TypeText("Decryption completed.");

			cout << endl << endl << "-------------------------------------------------" << endl << endl;
		}
	}
}
