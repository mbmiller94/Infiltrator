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
 * @file  infiltrator.h
 * @brief Includes widely-used headers and defines globals.
 */

#ifndef INFILTRATOR_H_
#define INFILTRATOR_H_

#include <string>
#include <iostream>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

namespace Infiltrator
{
    // Pseudo-random number Generator.
    extern boost::random::mt19937 NumGenerator;

    // Random number generation range type.
    typedef boost::random::uniform_int_distribution<> RandRange;
}

#endif // !INFILTRATOR_H_
