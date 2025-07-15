#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

using namespace juce;

class NewProjectAudioProcessorEditor : public juce::AudioProcessorEditor, 
                                       public Slider::Listener
{
public:
    NewProjectAudioProcessorEditor (NewProjectAudioProcessor&);
    ~NewProjectAudioProcessorEditor() override;

    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(Slider* slider) override;

private:
    NewProjectAudioProcessor& audioProcessor;
    Slider gainSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (NewProjectAudioProcessorEditor)
};