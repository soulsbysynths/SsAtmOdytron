//SSAtmAtmegatron.ino   Atmegatron Arduino sketch
//Copyright (C) 2015  Paul Soulsby
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

#include <Ody.h>
#include <OdyEngineBase.h>
#include <AtmHardwareBase.h>
#include <OdyAudio.h>
#include <OdyOscillator.h>
#include <OdyNoise.h>
#include <OdyPatch.h>
#include <SsHelpers.h>
#include <Envelope.h>
#include <OdyAmplifier.h>
#include <OdyFilter.h>
#include <OdyHpf.h>
#include <OdyLfo.h>
#include <Portamento.h>
#include <OdyPitch.h>
#include <Midi.h>
#include <LedRgb.h>
#include <LedCircular.h>
#include <Led.h>
#include <AnalogueControl.h>
#include <Switch.h>
#include <RotaryEncoder.h>

Ody odytron;

void setup()
{
	odytron.initialize();
}

void loop()
{
	odytron.poll();
}

