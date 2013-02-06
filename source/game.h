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

#pragma once

#ifndef GAME_H_
#define GAME_H_

#include "infiltrator.h"

#include <map>
#include <utility>
#include <boost/bind.hpp>
#include <boost/function.hpp>

namespace Infiltrator
{
    class Game
    {
    public:
        // Callback type for game command functions.
        typedef boost::function<void(void)> Command;

        // Initializes all command identifiers, callbacks, and descriptions.
        static void InitCommands(void);

        // Processes user command input and executes the callback.
        static bool ProcessCommand(const std::string& input);

        // Initializes the main game loop.
        static void Run(void);

        // Shows the hacking missions objective.
        static void ShowObjective(void);

        // Shows the game command help list.
        static void ShowCommands(void);

    private:
        // Stores command identifiers, callbacks, and descriptions.
        static std::map<std::string, std::pair<Command, std::string>> CommandMap;
    };
}

#endif // !GAME_H_
