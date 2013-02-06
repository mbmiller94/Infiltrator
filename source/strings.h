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
