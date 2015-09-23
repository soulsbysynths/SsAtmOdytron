/* 
* OdyFilter.cpp
*
* Created: 23/09/2015 18:30:22
* Author: Paul Soulsby
*/


#include "OdyFilter.h"

// default constructor
OdyFilter::OdyFilter()
{
} //OdyFilter

// default destructor
OdyFilter::~OdyFilter()
{
} //~OdyFilter
void OdyFilter::setType(FiltType newType)
{
	type_ = newType;
	buf0_ = 0;
	buf1_ = 0;
}
void OdyFilter::refresh(unsigned char kbrd, char fmA, char fmB)
{
	int tmpFc = fc_;
	tmpFc += (fmAAmount_ * fmA) >> 4;
	tmpFc += (fmBAmount_ * fmB) >> 4;
	tmpFc = constrainInt(tmpFc);
	switch (type_)
	{
		case FILT_KARLSEN:
		unsigned long lcut = (TWOPI_SCALED * ((unsigned long)tmpFc<<4)) / SF;
		if(lcut>127){
			calcFc_ = 127;
		}
		else{
			calcFc_ = (char)lcut;
		}
		calcQ_ = q_ >> 1;
		break;
		case FILT_SIMPLE:
		calcFc_ = (char)map((long)tmpFc,0,255,3,120); //fc_calc >> 1;
		calcQ_ = (char)map(q_,0,255,127,3 + ((127-calcFc_)>>2));
		break;
		case FILT_MOZZI:
		calcFc_ = tmpFc>>1;
		char qBS = q_ >> 1;
		calcQ_ = qBS+cMultcc(qBS, SHIFTED_1 - calcFc_);
		break;
	}
}
char OdyFilter::processSample(char sample)
{
	switch (type_)
	{
		case FILT_KARLSEN:
		int resoclip;
		if (buf1_ > 127){
			resoclip = 127;
		}
		else{
			resoclip = buf1;
		}
		int in = sample - iMultic(resoclip,calcQ_);
		buf0_ += iMultic(in,calcFc_) - iMultic(buf0_,calcFc_);
		buf1_ += iMultic(buf0_,calcFc_) - iMultic(buf1_,calcFc_);
		return buf1_;
		break;
		case FILT_SIMPLE:
		buf0_ = buf0_ - iMulticc(buf0_,calcQ_,calcFc_) - iMultic(buf1_,calcFc_) + iMultic(sample,calcFc_);
		buf1_ = buf1_ - iMulticc(buf1_,calcQ_,calcFc_) + iMultic(buf0_,calcFc_);
		return buf1_;
		break;
		case FILT_MOZZI:
		buf0_ = buf0_ + iMultic(sample,calcFc_) - iMultic(buf0_,calcFc_) + iMultiic(buf0_,calcQ_,calcFc_) - iMultiic(buf1_,calcQ_,calcFc_);
		buf1_ = buf1_ + iMultic(buf0_,calcFc_) - iMultic(buf1_,calcFc_);
		return buf1_;
		break;
	}
}