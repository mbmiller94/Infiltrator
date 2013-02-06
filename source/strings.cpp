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
 * @file  strings.cpp
 * @brief Various functions for string manipulation.
 */

#include "strings.h"

#include <ctype.h>
#include <algorithm>

namespace Infiltrator
{
    namespace Strings
    {
        // Converts a string to all lowercase letters.
        void ToLower(std::string& text)
        {
            std::transform(text.begin(), text.end(), text.begin(), ::tolower);
        }

        // Converts a string to all uppercase letters.
        void ToUpper(std::string& text)
        {
            std::transform(text.begin(), text.end(), text.begin(), ::toupper);
        }

        // Checks if a string is empty or whitespace.
        bool IsEmptyOrSpace(const std::string& text)
        {
            std::string::const_iterator it = text.begin();

            do {
                if (it == text.end())
                    return true;
            } while (*it >= 0 && *it <= 0x7F && isspace(*(it++)));

            return false;
        }
    }
}
