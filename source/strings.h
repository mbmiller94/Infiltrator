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
 * @file  strings.h
 * @brief Various functions for string manipulation.
 */

#ifndef STRINGS_H_
#define STRINGS_H_

#include "infiltrator.h"

namespace Infiltrator
{
    namespace Strings
    {
        // Converts a string to all lowercase letters.
        void ToLower(std::string& text);

        // Converts a string to all uppercase letters.
        void ToUpper(std::string& text);

        // Checks if a string is empty or whitespace.
        bool IsEmptyOrSpace(const std::string& text);
    }
}

#endif // !STRINGS_H_
