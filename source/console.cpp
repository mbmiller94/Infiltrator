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
 * @file  console.h
 * @brief Manages console input and output.
 */

#include "console.h"
#include "strings.h"

#include <boost/thread/thread.hpp>

// For platform-dependent methods.
#if defined(_WIN32) || defined(_WIN64)
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#endif

using namespace std;
using namespace boost;

namespace Infiltrator
{
    // Pauses game execution for the specified interval.
    void Console::Sleep(long milliseconds)
    {
        this_thread::sleep(posix_time::milliseconds(milliseconds));
    }

    // Displays an error message to the user.
    void Console::Error(const string& message)
    {
        TypeText("ERROR: " + message, RED, true, true);
    }

    // Displays the progress percentage of a task.
    void Console::PerformTask(const string& task_desc, const string& task_finish,
                              int randomness, int speed, bool type_desc, bool type_finish)
    {
        // Integral parameter ranges.
        randomness = abs(randomness);
        randomness = max(randomness, 1);
        speed      = max(speed, randomness + 1);

        RandRange range(-randomness, randomness);

        // Type the task description and wait for 750ms.
        if (type_desc) {
            TypeText(task_desc + "\r", WHITE, false, true);
            Sleep(750);
        }
        
        // Output the task progress.
        for (int i = 0; i <= 100; i++) {
            cout << task_desc << " (Progress: " << i << "%)\r";
            Sleep(speed + range(NumGenerator));
        }
        
        if (!Strings::IsEmptyOrSpace(task_finish)) {
            // Output the task completion message.
            if (type_finish)
                TypeText(task_finish, WHITE, false, true);
            else
                cout << task_finish;

            int prog_len   = 17;                                 // Task progress text length.
            int desc_len   = (int)task_desc.length() + prog_len; // Task description length.
            int finish_len = (int)task_finish.length();          // Task completion message length.

            // Erase any text left over on the line from the previous string.
            if (finish_len < desc_len) {
                int space_count = desc_len - finish_len;
                
                for (int i = 0; i < space_count; i++)
                    cout << " ";
            }
        }
        
        cout << endl;
    }

#if defined(_WIN32) || defined(_WIN64) // Windows Implementation

    // Stores the handle to the console output window.
    void* Console::OutputHandle;

    // Gets the handle to the console window output.
    void* Console::GetOutputHandle(void) { return OutputHandle; }

    // Initializes the console handle.
    void Console::Initialize(void)
    {
        OutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    // Outputs the specified text with a typing effect and the given color.
    void Console::WriteText(const string& text, Color text_color, bool new_line)
    {
        if (text_color != WHITE) {
            WORD attrib;

            switch (text_color) {
                case RED:   attrib = FOREGROUND_RED;   break;
                case GREEN: attrib = FOREGROUND_GREEN; break;
                case BLUE:  attrib = FOREGROUND_BLUE;  break;
            }
        
            // Set the text color.
            SetConsoleTextAttribute(OutputHandle, attrib);
        }

        cout << text;
    
        // Set text color to default.
        if (text_color != WHITE)
            SetConsoleTextAttribute(OutputHandle, 0x07);

        if (new_line) cout << endl;
    }

    // Outputs the specified text with a typing effect and the given color.
    void Console::TypeText(const string& text, Color text_color, bool new_line, bool fast)
    {
        string::const_iterator end = text.end();

        // Character delay randomness.
        RandRange range(fast ? -3 : -75, 40);

        if (text_color != WHITE) {
            WORD attrib;

            switch (text_color) {
                case RED:   attrib = FOREGROUND_RED;   break;
                case GREEN: attrib = FOREGROUND_GREEN; break;
                case BLUE:  attrib = FOREGROUND_BLUE;  break;
            }
        
            // Set text color.
            SetConsoleTextAttribute(OutputHandle, attrib);
        }

        for (string::const_iterator it = text.begin(); it != end; ++it) {
            cout << *it;

            // Sleep for anywhere from 25-140ms or if on fast mode from 2-45ms.
            Sleep((fast ? 5 : 100) + range(NumGenerator));
        }
    
        // Set text color to default.
        if (text_color != WHITE)
            SetConsoleTextAttribute(OutputHandle, 0x07);

        if (new_line) cout << endl;
    }

#else // Mac/Unix/Linux Implementation

    // Outputs the specified text with a typing effect and the given color.
    void Console::WriteText(const string& text, Color text_color, bool new_line)
    {
        int color_code;

        if (text_color != WHITE) {
            // Get the ANSI escape code color.
            switch (text_color) {
                case RED:   color_code = 31; break;
                case GREEN: color_code = 32; break;
                case BLUE:  color_code = 34; break;
            }

            // Output the text with the specified color.
            cout << "\033[1;" << color_code << "m" << text;
        } else {
            // Output the text with the default color.
            cout << text;
        }

        if (new_line) cout << endl;
    }

    // Outputs the specified text with a typing effect and the given color.
    void Console::TypeText(const string& text, Color text_color, bool new_line, bool fast)
    {
        int color_code;
        string::const_iterator end = text.end();

        // Character delay randomness.
        RandRange range(fast ? -3 : -75, 40);

        if (text_color != WHITE) {
            // Get the ANSI escape code color.
            switch (text_color) {
                case RED:   color_code = 31; break;
                case GREEN: color_code = 32; break;
                case BLUE:  color_code = 34; break;
            }
        }

        for (string::const_iterator it = text.begin(); it != end; ++it) {
            if (text_color != WHITE) {
                // Output the text with the specified color.
                cout << "\033[1;" << color_code << "m" << *it;
            } else {
                // Output the text with the default color.
                cout << *it;
            }

            // Sleep for anywhere from 25-140ms or if on fast mode from 2-45ms.
            Sleep((fast ? 5 : 100) + range(NumGenerator));
        }

        if (new_line) cout << endl;
    }

#endif

}
