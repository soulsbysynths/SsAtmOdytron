/* 
* OdyPatch.h
*
* Created: 23/09/2015 13:55:47
* Author: Paul Soulsby
*/


#ifndef __ODYPATCH_H__
#define __ODYPATCH_H__

#include <math.h>
#include <stdlib.h>
#include "OdyPatchBase.h"
#include "SsHelpers.h"

#ifndef bitRead
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#endif
#ifndef bitSet
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#endif
#ifndef bitClear
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#endif
#ifndef bitWrite
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))
#endif
#define HIGH 0x1
#define LOW  0x0

class OdyPatch
{
//variables
public:
	static const unsigned char PATCH_SIZE = 22;
protected:
private:
	unsigned char funcValue_c_[10] = {0};
	unsigned char optionValue_c_[2] = {0};
	unsigned char ctrlValue_[6] = {0};
	AtmPatchBase* base_ = NULL;
//functions
public:
	OdyPatch();
	~OdyPatch();
protected:
private:
	OdyPatch( const OdyPatch &c );
	OdyPatch& operator=( const OdyPatch &c );
	void setFunctionValue(unsigned char func, unsigned char newValue);
	unsigned char getFunctionValue(unsigned char func);
	void setOptionValue(unsigned char func, bool newValue);
	bool getOptionValue(unsigned char func);
	void setCtrlValue(unsigned char ctrl, unsigned char newValue);
	unsigned char getCtrlValue(unsigned char ctrl);
	void readPatch(unsigned char patchNum);
	void writePatch(unsigned char patchNum);
}; //OdyPatch

#endif //__ODYPATCH_H__
