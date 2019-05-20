/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent   : public Component
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent();

//    enum Windows
//    {
//        dialog,
//        document,
//        alert,
//        numWindows
//    };
    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    TextButton sendButton   { "Update" };
    TextButton updateButton   { "settings" };
    Label balanceLabel {"Balance"};
    Label userLabel {"curUser"};
    TextEditor sendBox {"..."};
    TextEditor targetBox {"..."};
    Image icon;
    
    
private:
    //==============================================================================
    // Your private member variables go here...
    


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};


//class ColourSelectorWindow   : public DocumentWindow,
//private ChangeListener
//{
//public:
//    ColourSelectorWindow (const String& name, Colour backgroundColour, int buttonsNeeded)
//    : DocumentWindow (name, backgroundColour, buttonsNeeded)
//    {
//        selector.setCurrentColour (backgroundColour);
//        selector.setColour (ColourSelector::backgroundColourId, Colours::transparentWhite);
//        selector.addChangeListener (this);
//        setContentOwned (&selector, false);
//    }
//
//    ~ColourSelectorWindow()
//    {
//        selector.removeChangeListener (this);
//    }
//
//    void closeButtonPressed()
//    {
//        delete this;
//    }
//
//private:
//    ColourSelector selector  { ColourSelector::showColourAtTop
//        | ColourSelector::showSliders
//        | ColourSelector::showColourspace };
//
//    void changeListenerCallback (ChangeBroadcaster* source)
//    {
//        if (source == &selector)
//            setBackgroundColour (selector.getCurrentColour());
//    }
//
//    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ColourSelectorWindow)
//};
