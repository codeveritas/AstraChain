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

#include "authorizeForm.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
authorizeForm::authorizeForm ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    loginButton.reset (new TextButton ("loginButton"));
    addAndMakeVisible (loginButton.get());
    loginButton->setButtonText (TRANS("login"));
    loginButton->addListener (this);

    loginButton->setBounds (120, 200, 150, 24);

    loginEditor.reset (new TextEditor ("login text editor"));
    addAndMakeVisible (loginEditor.get());
    loginEditor->setMultiLine (false);
    loginEditor->setReturnKeyStartsNewLine (false);
    loginEditor->setReadOnly (false);
    loginEditor->setScrollbarsShown (true);
    loginEditor->setCaretVisible (true);
    loginEditor->setPopupMenuEnabled (true);
    loginEditor->setColour (TextEditor::backgroundColourId, Colours::grey);
    loginEditor->setText (TRANS("login"));

    loginEditor->setBounds (120, 104, 150, 24);

    passwordEditor.reset (new TextEditor ("password text editor"));
    addAndMakeVisible (passwordEditor.get());
    passwordEditor->setMultiLine (false);
    passwordEditor->setReturnKeyStartsNewLine (false);
    passwordEditor->setReadOnly (false);
    passwordEditor->setScrollbarsShown (true);
    passwordEditor->setCaretVisible (true);
    passwordEditor->setPopupMenuEnabled (true);
    passwordEditor->setColour (TextEditor::backgroundColourId, Colours::grey);
    passwordEditor->setText (TRANS("enter password"));

    passwordEditor->setBounds (120, 152, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

authorizeForm::~authorizeForm()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    loginButton = nullptr;
    loginEditor = nullptr;
    passwordEditor = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void authorizeForm::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff323e44));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void authorizeForm::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void authorizeForm::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == loginButton.get())
    {
        //[UserButtonCode_loginButton] -- add your button handler code here..
        //[/UserButtonCode_loginButton]
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

<JUCER_COMPONENT documentType="Component" className="authorizeForm" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="400" initialHeight="400">
  <BACKGROUND backgroundColour="ff323e44"/>
  <TEXTBUTTON name="loginButton" id="f0d9e36f695e143d" memberName="loginButton"
              virtualName="" explicitFocusOrder="0" pos="120 200 150 24" buttonText="login"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTEDITOR name="login text editor" id="2efe8a0e98f12588" memberName="loginEditor"
              virtualName="" explicitFocusOrder="0" pos="120 104 150 24" bkgcol="ff808080"
              initialText="login" multiline="0" retKeyStartsLine="0" readonly="0"
              scrollbars="1" caret="1" popupmenu="1"/>
  <TEXTEDITOR name="password text editor" id="c21a27960a86407c" memberName="passwordEditor"
              virtualName="" explicitFocusOrder="0" pos="120 152 150 24" bkgcol="ff808080"
              initialText="enter password" multiline="0" retKeyStartsLine="0"
              readonly="0" scrollbars="1" caret="1" popupmenu="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

