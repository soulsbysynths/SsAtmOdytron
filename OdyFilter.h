/* 
* OdyFilter.h
*
* Created: 23/09/2015 18:30:22
* Author: Paul Soulsby
*/


#ifndef __ODYFILTER_H__
#define __ODYFILTER_H__


class OdyFilter
{
//variables
public:
	enum FiltType : unsigned char
	{
		FILT_KARLSEN,
		FILT_SIMPLE,
		FILT_MOZZI
	};
protected:
private:
	static const unsigned char SHIFTED_1 = 127;
	unsigned char fc_ = 255;
	unsigned char q_;
	FiltType type_ = FILT_KARLSEN;
	unsigned char fmAAmount_ = 0;
	unsigned char fmBAmount_ = 0;
	bool fmAWave_ = false;
	bool fmBWave_ = false;
	char calcFc_ = 25;
	char calcQ_ = 127;
	int buf1_,buf0_;
//functions
public:
	OdyFilter();
	~OdyFilter();
	void setFc(unsigned char newFc){fc_ = newFc;}
	unsigned char getFc(){return fc_;}
	void setQ(unsigned char newQ){q_ = newQ;}
	unsigned char getQ(){return q_;}
	void setType(FiltType newType);
	FiltType getType(){return type_;}
	void setFmAAmount(unsigned char newAmt){fmAAmount_ = newAmt;}
	unsigned char getFmAAmount(){return fmAAmount_;}
	void setFmBAmount(unsigned char newAmt){fmBAmount_ = newAmt;}
	unsigned char getFmBAmount(){return fmBAmount_;}
	void setFmAWave(bool sineWave){fmAWave_ = sineWave;}
	bool getFmAWave(){return fmAWave_;}
	void setFmBWave(bool arEnv){fmBWave_ = ar;}
	bool getFmBWave(){return fmBWave_;}	
	void refresh(unsigned char kbrd, char fmA, char fmB);
	char processSample(char sample);	
protected:
private:
	OdyFilter( const OdyFilter &c );
	OdyFilter& operator=( const OdyFilter &c );

}; //OdyFilter

#endif //__ODYFILTER_H__
