#include "PluginProcessor.h"
#include "PluginEditor.h"

using namespace juce;

NewProjectAudioProcessorEditor::NewProjectAudioProcessorEditor (NewProjectAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    gainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    
	gainSlider.setRange(0.0, 1.0, 0.01);
	gainSlider.setValue(0.5);
	gainSlider.setTextBoxStyle(Slider::TextEntryBoxPosition::TextBoxBelow, false, 40, 20);
	gainSlider.setColour(Slider::thumbColourId, Colours::white);
	gainSlider.setColour(Slider::trackColourId, Colours::grey);
	gainSlider.setColour(Slider::backgroundColourId, Colours::black);

	gainSlider.addListener(this);
	addAndMakeVisible(gainSlider);
    setSize (500, 500);
}

NewProjectAudioProcessorEditor::~NewProjectAudioProcessorEditor()
{
}

void NewProjectAudioProcessorEditor::paint (juce::Graphics& g)
{
    g.fillAll (Colours::purple);
}

void NewProjectAudioProcessorEditor::resized()
{
	gainSlider.setBounds(getWidth()/2, getHeight()/2, 80, 150);

}

void NewProjectAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	gainSlider.setBounds(getWidth() / 2, getHeight() / 2, 80, 150);

	if (slider == &gainSlider)
	{
		audioProcessor.gain = gainSlider.getValue();
	}
}