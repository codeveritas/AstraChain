/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.3

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "interface.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
interface::interface ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    settingsButton.reset (new TextButton ("settings button"));
    addAndMakeVisible (settingsButton.get());
    settingsButton->setButtonText (TRANS("Settings"));
    settingsButton->addListener (this);

    settingsButton->setBounds (424, 32, 150, 24);

    sendButton.reset (new TextButton ("send button"));
    addAndMakeVisible (sendButton.get());
    sendButton->setButtonText (TRANS("Send"));
    sendButton->addListener (this);

    sendButton->setBounds (368, 304, 150, 24);

    updateButton.reset (new TextButton ("update button"));
    addAndMakeVisible (updateButton.get());
    updateButton->setButtonText (TRANS("Update"));
    updateButton->addListener (this);

    updateButton->setBounds (80, 304, 150, 24);

    label_1.reset (new Label ("new label",
                              TRANS("Current balance is:\n")));
    addAndMakeVisible (label_1.get());
    label_1->setFont (Font (18.50f, Font::plain).withTypefaceStyle ("Regular"));
    label_1->setJustificationType (Justification::centredLeft);
    label_1->setEditable (false, false, false);
    label_1->setColour (TextEditor::textColourId, Colours::black);
    label_1->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label_1->setBounds (72, 152, 168, 40);

    label.reset (new Label ("new label",
                            TRANS("5.75 FKC")));
    addAndMakeVisible (label.get());
    label->setFont (Font (31.20f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (80, 208, 136, 24);

    targetEditor.reset (new TextEditor ("target text editor"));
    addAndMakeVisible (targetEditor.get());
    targetEditor->setMultiLine (false);
    targetEditor->setReturnKeyStartsNewLine (false);
    targetEditor->setReadOnly (false);
    targetEditor->setScrollbarsShown (true);
    targetEditor->setCaretVisible (true);
    targetEditor->setPopupMenuEnabled (true);
    targetEditor->setColour (TextEditor::backgroundColourId, Colours::grey);
    targetEditor->setText (TRANS("enter target"));

    targetEditor->setBounds (368, 152, 150, 24);

    sendEditor.reset (new TextEditor ("send text editor"));
    addAndMakeVisible (sendEditor.get());
    sendEditor->setMultiLine (false);
    sendEditor->setReturnKeyStartsNewLine (false);
    sendEditor->setReadOnly (false);
    sendEditor->setScrollbarsShown (true);
    sendEditor->setCaretVisible (true);
    sendEditor->setPopupMenuEnabled (true);
    sendEditor->setColour (TextEditor::backgroundColourId, Colours::grey);
    sendEditor->setText (TRANS("enter FKC"));

    sendEditor->setBounds (368, 216, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

interface::~interface()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    settingsButton = nullptr;
    sendButton = nullptr;
    updateButton = nullptr;
    label_1 = nullptr;
    label = nullptr;
    targetEditor = nullptr;
    sendEditor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void interface::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    {
        int x = -4, y = -4, width = 868, height = 92;
        Colour fillColour = Colour (0xff626262);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void interface::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void interface::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == settingsButton.get())
    {
        //[UserButtonCode_settingsButton] -- add your button handler code here..
        //[/UserButtonCode_settingsButton]
    }
    else if (buttonThatWasClicked == sendButton.get())
    {
        //[UserButtonCode_sendButton] -- add your button handler code here..
        //[/UserButtonCode_sendButton]
    }
    else if (buttonThatWasClicked == updateButton.get())
    {
        //[UserButtonCode_updateButton] -- add your button handler code here..
        //[/UserButtonCode_updateButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="interface" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44">
    <RECT pos="-4 -4 868 92" fill="solid: ff626262" hasStroke="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="settings button" id="80078d4445bca55a" memberName="settingsButton"
              virtualName="" explicitFocusOrder="0" pos="424 32 150 24" buttonText="Settings"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="send button" id="20e5d7898de5e2f7" memberName="sendButton"
              virtualName="" explicitFocusOrder="0" pos="368 304 150 24" buttonText="Send"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="update button" id="f0d9e36f695e143d" memberName="updateButton"
              virtualName="" explicitFocusOrder="0" pos="80 304 150 24" buttonText="Update"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="f5d8c27c8771dd39" memberName="label_1" virtualName=""
         explicitFocusOrder="0" pos="72 152 168 40" edTextCol="ff000000"
         edBkgCol="0" labelText="Current balance is:&#10;" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="18.5" kerning="0.0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="f8af13dbfff1c1b6" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="80 208 136 24" edTextCol="ff000000"
         edBkgCol="0" labelText="5.75 FKC" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="31.2"
         kerning="0.0" bold="0" italic="0" justification="36"/>
  <TEXTEDITOR name="target text editor" id="2efe8a0e98f12588" memberName="targetEditor"
              virtualName="" explicitFocusOrder="0" pos="368 152 150 24" bkgcol="ff808080"
              initialText="enter target" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="send text editor" id="f2c6a3771fcf6510" memberName="sendEditor"
              virtualName="" explicitFocusOrder="0" pos="368 216 150 24" bkgcol="ff808080"
              initialText="enter FKC" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

