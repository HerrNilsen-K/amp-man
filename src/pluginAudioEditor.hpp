//
// Created by karl on 1/8/23.
//

#ifndef AMP_MAN_PLUGINAUDIOEDITOR_HPP
#define AMP_MAN_PLUGINAUDIOEDITOR_HPP

#include "pluginProcessor.hpp"

//==============================================================================
class AudioPluginEditor  : public juce::AudioProcessorEditor
{
public:
    explicit AudioPluginEditor (AudioPluginProcessor&);
    ~AudioPluginEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    AudioPluginProcessor& processorRef;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioPluginEditor)
};

#endif //AMP_MAN_PLUGINAUDIOEDITOR_HPP
