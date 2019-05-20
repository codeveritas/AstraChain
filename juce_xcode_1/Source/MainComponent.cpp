/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"
#include <iostream>


//==============================================================================
MainComponent::MainComponent()
{
    setSize (500, 350);
    addAndMakeVisible(sendButton);
    addAndMakeVisible(updateButton);
    addAndMakeVisible(balanceLabel);
    addAndMakeVisible(sendBox);
    addAndMakeVisible(userLabel);
    addAndMakeVisible(targetBox);

    //addAndMakeVisible();
    
    //showWindowsButton.onClick = [this] { showAllWindows(); };
    
    //addAndMakeVisible(showWindowsButton);
    
}

MainComponent::~MainComponent()
{
}

//==============================================================================
void MainComponent::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
//    g.drawLine(10, 50, 490, 50);
    g.setColour (Colours::darkgrey);
    g.fillRect(0, 0, 500, 50);
//    g.setFont (Font (16.0f));
//    g.drawText ("Hello World!", getLocalBounds(), Justification::centred, true);
}

void MainComponent::resized()
{
    Rectangle<int> buttonSize (0, 0, 108, 28);
    // update button

    Rectangle<int> area (400,
                         10,
                         80, buttonSize.getHeight());
    updateButton.setBounds(area.reduced (2));
    //send button
    area.setBounds(275,
                   200,
                   buttonSize.getWidth(), buttonSize.getHeight());
    sendButton.setBounds(area.reduced (2));
    // balance label
    balanceLabel.setText("0.0001 BTC", dontSendNotification);
    balanceLabel.setFont(Font (24.0f));
    area.setBounds(70,
                   100,
                   buttonSize.getWidth() + 25, buttonSize.getHeight());
    balanceLabel.setBounds(area.reduced (2));

    // send edit box
    sendBox.setText("BTC", dontSendNotification);
    area.setBounds(275,
                   150,
                   buttonSize.getWidth(), buttonSize.getHeight());
    sendBox.setBounds(area.reduced (2));
    
    // target edit box
//    targetBox.setColour(Label::textColourId, Colours::black);
    targetBox.setColour(TextEditor::textColourId, Colours::white);
    targetBox.setText("targetuser", dontSendNotification);
    area.setBounds(275,
                   100,
                   buttonSize.getWidth(), buttonSize.getHeight());
    targetBox.setBounds(area.reduced (2));
    
    // current user
    userLabel.setColour(Label::textColourId, Colours::white);
    userLabel.setText("testuser", dontSendNotification);
    area.setBounds(320,
                   10,
                   buttonSize.getWidth(), buttonSize.getHeight());
    userLabel.setBounds(area.reduced (2));
    
    // std::cout << getWidth() / 23 <<  " " << getHeight() / 23 << std::endl;
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
