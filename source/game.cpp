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
#include "strings.h"

using namespace std;

namespace Infiltrator
{
    // Stores command identifiers, callbacks, and descriptions.
    Game::CommandMapType Game::CommandMap;

    // Identifies what network the power shell is connected to.
    string Game::NetworkKey;

    // Initializes the main game loop.
    void Game::Run(void)
    {
        // Set initial network location.
        NetworkKey = "127";

        InitCommands();
        ShowObjective();
    }

    // Initializes all command identifiers, callbacks, and descriptions.
    void Game::InitCommands(void)
    {
        CommandMap["help"] = make_pair(&ShowCommands, "Shows this list of commands.");
    }

    // Waits for the user to input a command for processing.
    // Returns 'false' if ProcessCommand() fails.
    bool Game::WaitForCommand(void)
    {
        cout << "@pSH~" + NetworkKey + " > ";

        string input;
        cin >> input;
        cout << endl;

        return ProcessCommand(input);
    }

    // Processes user command input and executes the callback.
    bool Game::ProcessCommand(const std::string& input)
    {
        if (Strings::IsEmptyOrSpace(input)) {
            Console::Error("You must enter a command.");
        } else if (CommandMap.find(input) == CommandMap.end()) {
            Console::Error("'" + input + "' is not a recognized command.");
        } else {
            CommandMap[input].first();
            return true;
        }

        return false;
    }

    // Shows the hacking mission objective.
    void Game::ShowObjective(void)
    {
        Console::TypeText("You are a hacker for hire. Your current client, Evan Smith, has set up");
        Console::TypeText("a bank account under an alias. He has hired you to hack into the banks");
        Console::TypeText("mainframe and funnel money from an account into the dummy account.");
        Console::Sleep(2000);
        cout << endl;
        Console::TypeText("The bank is privately owned meaning tight security, heavily encrypted network");
        Console::TypeText("connections, and strictly guarded accounts. You both stand to make millions.");
        Console::Sleep(2000);
    }

    // Shows the game command help list.
    void Game::ShowCommands(void)
    {
        CommandMapType::const_iterator it;
        CommandMapType::const_iterator end = CommandMap.end();

        Console::TypeText("-------------------- POWER SHELL COMMANDS --------------------", WHITE, true, true);

        for (it = CommandMap.begin(); it != end; ++it) {
            cout << "> " << it->first << " - ";
            Console::TypeText(it->second.second, WHITE, true, true);
            cout << endl;
        }
    }
}
