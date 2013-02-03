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
 * @file  infiltrator.cpp
 * @brief Main application entry point.
 */

#include "infiltrator.h"
#include "console.h"
#include "game.h"

// Psuedo-random number Genrator.
boost::random::mt19937 Infiltrator::NumGenerator;

using namespace std;
using namespace boost;
using namespace Infiltrator;

int main(int argc, char *argv[])
{
	// Get the output handle for windows console functions.
	#if defined(_WIN32) || defined(_WIN64)
		Console::Initialize();
	#endif

	cout << "        _____   ______________  __________  ___  __________  ____    " << endl <<
            "       /  _/ | / / ____/  _/ / /_  __/ __ \\/   |/_  __/ __ \\/ __ \\" << endl <<
            "       / //  |/ / /_   / // /   / / / /_/ / /| | / / / / / / /_/ /   " << endl <<
            "     _/ // /|  / __/ _/ // /___/ / / _, _/ ___ |/ / / /_/ / _, _/    " << endl <<
            "    /___/_/ |_/_/   /___/_____/_/ /_/ |_/_/  |_/_/  \\____/_/ |_|    " << endl << endl <<
		    "              Copyright (C)2013 Michael Brandon Miller               " << endl << endl;

	Game::Run();
	
	return 0;
}

