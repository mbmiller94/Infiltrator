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
	void Console::WriteText(string text, Color text_color, bool new_line)
	{
		if (text_color != WHITE) {
			WORD attrib;

			switch (text_color) {
				case RED:   attrib = FOREGROUND_RED;   break;
				case GREEN: attrib = FOREGROUND_GREEN; break;
				case BLUE:  attrib = FOREGROUND_BLUE;  break;
			}
		
			SetConsoleTextAttribute(OutputHandle, attrib);
		}

		cout << text;
	
		// Set text attributes to default.
		if (text_color != WHITE)
			SetConsoleTextAttribute(OutputHandle, 0x07);

		if (new_line) cout << endl;
	}

	// Outputs the specified text with a typing effect and the given color.
	void Console::TypeText(string text, Color text_color, bool new_line, bool fast)
	{
		string::const_iterator end = text.end();
		RandRange range(fast ? -3 : -75, 40);

		if (text_color != WHITE) {
			WORD attrib;

			switch (text_color) {
				case RED:   attrib = FOREGROUND_RED;   break;
				case GREEN: attrib = FOREGROUND_GREEN; break;
				case BLUE:  attrib = FOREGROUND_BLUE;  break;
			}
		
			SetConsoleTextAttribute(OutputHandle, attrib);
		}

		for (string::const_iterator it = text.begin(); it != end; ++it) {
			cout << *it;

			// Sleep for anywhere from 25-140ms or if on fast mode from 2-45ms.
			Sleep((fast ? 5 : 100) + range(NumGenerator));
		}
	
		// Set text attributes to default.
		if (text_color != WHITE)
			SetConsoleTextAttribute(OutputHandle, 0x07);

		if (new_line) cout << endl;
	}

#else // Mac/Unix/Linux Implementation

	// Outputs the specified text with a typing effect and the given color.
	void Console::WriteText(string text, Color text_color, bool new_line)
	{
		int color_code;

		if (text_color != WHITE) {
			switch (text_color) {
				case RED:   color_code = 31; break;
				case GREEN: color_code = 32; break;
				case BLUE:  color_code = 34; break;
			}

			cout << "\033[1;" << color_code << "m" << text;
		} else {
			cout << text;
		}

		if (new_line) cout << endl;
	}

	// Outputs the specified text with a typing effect and the given color.
	void Console::TypeText(string text, Color text_color, bool new_line, bool fast)
	{
		int color_code;
		string::const_iterator end = text.end();
		random::uniform_int_distribution<> range(fast ? -3 : -75, 40);

		if (text_color != WHITE) {
			switch (text_color) {
				case RED:   color_code = 31; break;
				case GREEN: color_code = 32; break;
				case BLUE:  color_code = 34; break;
			}
		}

		for (string::const_iterator it = text.begin(); it != end; ++it) {
			if (text_color != WHITE) {
				cout << "\033[1;" << color_code << "m" << *it;
			} else {
				cout << *it;
			}

			// Sleep for anywhere from 25-140ms or if on fast mode from 2-45ms.
			Sleep((fast ? 5 : 100) + range(NumGenerator));
		}

		if (new_line) cout << endl;
	}

#endif

}
