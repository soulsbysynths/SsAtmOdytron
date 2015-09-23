//Ody.h  Odytron class (add this object to Arduino sketch)
//Copyright (C) 2015  Paul Soulsby info@soulsbysynths.com
//
//This program is free software: you can redistribute it and/or modify
//it under the terms of the GNU General Public License as published by
//the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
//This program is distributed in the hope that it will be useful,
//but WITHOUT ANY WARRANTY; without even the implied warranty of
//MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//GNU General Public License for more details.
//
//You should have received a copy of the GNU General Public License
//along with this program.  If not, see <http://www.gnu.org/licenses/>.


#ifndef __ODY_H__
#define __ODY_H__

#include "AtmEngineBase.h"
#include "AtmHardwareBase.h"
#include "AtmEngine.h"
#include "AtmHardware.h"

class Ody
{
//variables
public:
protected:
private:

//functions
public:
	Ody();
	~Ody();
protected:
private:
	Ody( const Ody &c );
	Ody& operator=( const Ody &c );

}; //Ody

#endif //__ODY_H__
