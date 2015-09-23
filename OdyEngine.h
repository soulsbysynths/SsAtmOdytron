/* 
* OdyEngine.h
*
* Created: 23/09/2015 13:15:25
* Author: Paul Soulsby
*/


#ifndef __ODYENGINE_H__
#define __ODYENGINE_H__

#include "AtmAudio.h"
#include "AtmOscillator.h"
#include "OdyPatch.h"
#include "OdyPatchBase.h"
#include "Envelope.h"
#include "Amplifier.h"
#include "OdyEngineProgmem.h"
#include "OdyEngineBase.h"
#include "OdyEngineSettings.h"
#include "OdyFilter.h"
#include "MasterClock.h"
#include "Lfo.h"
#include "Portamento.h"
#include "AtmPitch.h"
#include "Midi.h"
#include "MidiBase.h"
#include "Arpeggiator.h"
#include "ArpeggiatorBase.h"
#include "Wavecrusher.h"
#include "Flanger.h"
#include "ClipDistortion.h"
#include "Pwm.h"

class OdyEngine : public MidiBase, ArpeggiatorBase, OdyPatchBase
{
//variables
public:
	static OdyEngine& getInstance()
	{
		static OdyEngine instance; // Guaranteed to be destroyed.
		// Instantiated on first use.
		return instance;
	}
	enum Ctrl : unsigned char
	{
		CTRL_VCO1,
		CTRL_VCO2,
		CTRL_LFO,
		CTRL_FC,
		CTRL_Q,
		CTRL_HPF
	};
	enum Func : unsigned char
	{
		FUNC_PORTAMENTO,
		FUNC_OSC0FMA,
		FUNC_OSC0FMB,
		FUNC_OSC1FMA,
		FUNC_OSC1FMB,
		FUNC_OSC1PW,
		FUNC_OSC1PWM,
		FUNC_OSCLEVEL2,
		FUNC_OSCLEVEL0,
		FUNC_OSCLEVEL1,
		FUNC_FILTFMA,
		FUNC_FILTFMB,
		FUNC_ENVR,
		FUNC_ENVS,
		FUNC_ENVD,
		FUNC_ENVA,
		FUNC_ENVR2,
		FUNC_ENVA2,
		FUNC_FILTTYPE
	};
	enum MidiCC : unsigned char
	{
		CC_PITCHLFO = 1,
		CC_PORTAMENTO = 5,
		CC_FILTERENV = 16,
		CC_DISTORTION = 17,
		CC_FILTCUTOFF = 74,
		CC_AMPENVR = 72,
		CC_AMPENVA = 73,
		CC_FILTRES = 71,
		CC_AMPENVD = 75,
		CC_LFOCLOCKDIV = 79,
		CC_PWM = 91,
		CC_AMPLFO = 92,
		CC_FILTLFO = 93,
		CC_PITCHENV = 94,
		CC_FLANGE = 95,
		CC_ALLNOTESOFF = 123
	};
protected:
private:
	static const unsigned char SYSEX_PROD_ID = 0;
	static const unsigned int MIDI_TICKSPERCYCLE = 1536;
	#define NP_CLASSIC 0
	#define NP_LOW 1
	#define NP_HIGH 2
	#define NP_LAST 3
	MasterClock masterClock_;
	Midi* midi_;
	AtmPatch* patch_;
	AtmOscillator* oscillator_;
	Func function_ = FUNC_WAVE;
	OdyEngineBase* base_ = NULL;
	AtmAudio* audio_;
	Envelope ampEnvelope_;
	Envelope filtEnvelope_;
	Amplifier amplifier_;
	OdyFilter filter_;
	Lfo lfo_;
	Portamento portamento_;
	AtmPitch pitch_;
	Arpeggiator* arpeggiator_;
	WaveCrusher wavecrusher_;
	Flanger* flanger_;
	ClipDistortion clipdistortion_;
	Pwm* pwm_;
	unsigned int frequency_ = 440;
	unsigned char totNotesOn_ = 0;
	unsigned char totNotesOnLast_ = 0;
	char pitchBend_ = 0;
	bool noteOn_[128] = {false};
	unsigned char noteLowest_ = 127;
	unsigned char noteHighest_ = 0;
	unsigned char sysexMesstype_ = SYSEX_PATCH;
	bool sysexMemdumping_ = false;
	unsigned char sysexMemdumpnum_ = 0;
	bool sysexComplete_ = false;
//functions
public:
	OdyEngine();
	~OdyEngine();
protected:
private:
	OdyEngine( const OdyEngine &c );
	OdyEngine& operator=( const OdyEngine &c );

}; //OdyEngine

#endif //__ODYENGINE_H__
