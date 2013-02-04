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

#pragma once

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "infiltrator.h"

namespace Infiltrator
{
	/**
	 * Console text and background coloring constants.
	 */
	enum Color {
		WHITE, RED, GREEN, BLUE
	};

	/**
	 * Manages console input and output.
	 */
	class Console
	{
	public:
		// Pauses execution for the specified interval.
		static void Sleep(long milliseconds);

		// Displays the progress percentage of a task.
		static void PerformTask(const std::string& task_desc, const std::string& task_finish,
		                        int randomness, int speed, bool type_desc = true, bool type_finish = true);
		
		// Outputs the specified text with the given color.
		static void WriteText(const std::string& text, Color text_color = WHITE, bool new_line = true);

		// Outputs the specified text with a type-writer effect and the given color.
		static void TypeText(const std::string& text, Color text_color = WHITE, bool new_line = true, bool fast = false);

#if defined(_WIN32) || defined(_WIN64)
		// Initializes the console handle.
		static void Initialize(void);

		// Gets the handle to the console window output.
		static void* GetOutputHandle(void);

	private:
		// Stores the handle to the console window output.
		static void* OutputHandle;
#endif
	};
}

#endif // !CONSOLE_H_
