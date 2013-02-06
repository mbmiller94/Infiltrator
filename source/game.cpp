/////////////////////////////////////////////////////////////////////////
//       _____   ______________  __________  ___  __________  ____     //
//      /  _/ | / / ____/  _/ / /_  __/ __ \/   |/_  __/ __ \/ __ \    //
//      / //  |/ / /_   / // /   / / / /_/ / /| | / / / / / / /_/ /    //
//    _/ // /|  / __/ _/ // /___/ / / _, _/ ___ |/ / / /_/ / _, _/     //
//   /___/_/ |_/_/   /___/_____/_/ /_/ |_/_/  |_/_/  \____/_/ |_|      //
//                                                                     //
//    Copyright (C)2013 Michael Brandon Miller                         //
//                                                                     //
//    This file is part of Infiltrator, distributed under the          //
//    GNU General Public License v3. See 'license.txt' for terms.      //
//                                                                     //
/////////////////////////////////////////////////////////////////////////

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
        Console::WriteText("@pSH~" + NetworkKey, BLUE, false);
        cout << " > ";

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
