/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.1.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
/*
* Copyright 2014 Xavier Hosxe
*
* Author: Xavier Hosxe (xavier <dot> hosxe
*                      (at) g m a i l <dot> com)
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <unordered_set>
class MidifiedFloatParameter;
class PanelEngine;
class PanelModulation;
class PanelArpAndFilter;

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
	An auto-generated component, created by the Introjucer.

	Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainTabs  : public Component,
                  public Button::Listener,
                  public Label::Listener,
                  public ComboBox::Listener
{
public:
    //==============================================================================
    MainTabs ();
    ~MainTabs();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void buildParameters(AudioProcessor *audioProcessor);
	void updateUI(std::unordered_set<String> &paramSet);
	void setPresetName(String presetName);
	void setPresetNamePtr(char* presetNamePtr);
	void setMidiOutBuffer(MidiBuffer *midiOutBuffer);
	void setMidiChannel(int newMidiChannel);
	MidifiedFloatParameter* getParameterFromName(String componentName);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void labelTextChanged (Label* labelThatHasChanged) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	int midiInfo;
	AudioProcessor* audioProcessor;
	PanelEngine* panelEngine;
	PanelModulation* panelModulation;
	PanelArpAndFilter* panelArpAndFilter;
	float pullButtonValue;
	float pushButtonValue;
	int currentMidiChannel;
	MidiBuffer *midiOutBuffer;
	char *presetNamePtr;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TabbedComponent> tabbedComponent;
    ScopedPointer<TextButton> pullButton;
    ScopedPointer<Label> presetNameLabel;
    ScopedPointer<TextButton> pushButton;
    ScopedPointer<ComboBox> midiChannelCombo;
    ScopedPointer<Label> versionLabel;
    ScopedPointer<TextButton> deviceButton;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainTabs)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
