/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SaturationAudioProcessorEditor::SaturationAudioProcessorEditor (SaturationAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 400);
    
    Mix.setSliderStyle(juce::Slider::LinearBarVertical);
    Mix.setRange(0.0, 127.0, 1.0);
    Mix.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    Mix.setPopupDisplayEnabled(true, false, this);
    Mix.setTextValueSuffix(" Mix");
    Mix.setValue(1.0);
    Mix.addListener (this);
    addAndMakeVisible(&Mix);
    
    /*
    Frequency.setSliderStyle(juce::Slider::LinearBarVertical);
    Frequency.setRange(0.0, 127.0, 1.0);
    Frequency.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    Frequency.setPopupDisplayEnabled(true, false, this);
    Frequency.setTextValueSuffix(" Frequency");
    Frequency.setValue(1.0);
    Frequency.addListener (this);
    addAndMakeVisible(&Frequency);
    */
     
    Drive.setSliderStyle(juce::Slider::LinearBarVertical);
    Drive.setRange(0.0, 5000.0, 1.0);
    Drive.setTextBoxStyle(juce::Slider::NoTextBox, false, 90, 0);
    Drive.setPopupDisplayEnabled(true, false, this);
    Drive.setTextValueSuffix(" Drive");
    Drive.setValue(1.0);
    Drive.addListener (this);
    addAndMakeVisible(&Drive);
    
}

SaturationAudioProcessorEditor::~SaturationAudioProcessorEditor()
{
}

//==============================================================================
void SaturationAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (juce::Colours::beige);
    g.setColour (juce::Colours::blue);
    g.setFont (15.0f);
    g.drawFittedText ("Super Duper Overdrive Plug-In", 0, 0, getWidth(), getHeight()-300, juce::Justification::centred, 1);
    g.drawFittedText ("Mix", 100-15, 120, 50, 20, juce::Justification::centred, 1);
    //g.drawFittedText ("Frequency", 200-15, 120, 50, 20, juce::Justification::centred, 1);
    g.drawFittedText ("Drive", 300-30, 120, 50, 20, juce::Justification::centred, 1);
}

void SaturationAudioProcessorEditor::resized()
{
    Mix.setBounds (100, 150, 20, getHeight() - 200);
    Frequency.setBounds (200, 150, 20, getHeight() - 200);
    Drive.setBounds (285, 150, 20, getHeight() - 200);
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}


void SaturationAudioProcessorEditor::sliderValueChanged (juce::Slider* slider)
{
    audioProcessor.mixVal = Mix.getValue();
    //audioProcessor.freqVal = Frequency.getValue();
    audioProcessor.driveVal = Drive.getValue();
}
