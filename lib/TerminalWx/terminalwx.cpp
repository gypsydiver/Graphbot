/*
TerminalWx - A wxWidgets terminal widget
Copyright (C) 2012-2013 Jeremy Salwen

License: wxWindows License Version 3.1 (See the file license3.txt)

*/

#include "terminalwx.h"
#include <stdlib.h>
#include <wx/log.h>
/**
    Constructor for the terminal widget.

    @param width The width of the terminal in characters
    @param height The height of the terminal in character

    @param name
        The terminal name, which is not displayed but stored
        internally, and might be changed by VT commands.

*/
TerminalWx::TerminalWx(wxWindow* parent, wxWindowID id,
                               const wxPoint& pos,
                               int width, int height,
                               const wxString& name):  wxTerm(parent,id,pos,width,height,name)
{
    //ctor
}

void runInput(wxString input_buffer);

/**
    Called whenever the user has input additional text.
        By default it does nothing.
*/

wxString input_buffer = "";

void TerminalWx::OnUserInput(wxString input) {
    wxString newlineWx = wxString::FromAscii('\r');
    wxString backSpace = wxString::FromUTF8("\x8");
    Reset();
    if(newlineWx.compare(input) == 0){
        DisplayChars("Graphbot>");
        //printf("buffer state: %s",input_buffer.ToStdString().c_str());
        runInput(input_buffer);
        input_buffer = "";
        //wxLogDebug("Return");
    }else if(backSpace.compare(input) == 0){
        input_buffer.RemoveLast();
        //buffer.Append("  ");
        DisplayChars("Graphbot>"+input_buffer+" ");
    }else{
        input_buffer.Append(input);
        DisplayChars("Graphbot>"+input_buffer+" ");
        //wxLogDebug("Normal characters");
        
    }
}

void TerminalWx::SendBack(int len,char* data) {
    OnUserInput(wxString(data,len));
}
void TerminalWx::SendBack(char* data) {
    OnUserInput(wxString(data));
}
/**
 *  Processes characters sent from the backend.
 *
 *  This function is thread safe and can be called from any thread at any time.
 *
*/
void TerminalWx::DisplayChars(const wxString& str) {
     this->QueueEvent(new TerminalInputEvent(str));
}

/**
 *  Processes characters sent from the backend
 *
 *  This function is not thread safe and can *only*
 *  safely be called from the main event loop
*/
void TerminalWx::DisplayCharsUnsafe(const wxString& str) {
     ProcessInput(str.length(),(unsigned char*)const_cast<char*>((const char*)str.mb_str()));
}

void TerminalWx::OnTerminalInput(TerminalInputEvent& evt) {
    DisplayCharsUnsafe(evt.GetString());
}

TerminalWx::~TerminalWx()
{
    //dtor
}


wxBEGIN_EVENT_TABLE(TerminalWx, wxTerm)

EVT_TERMINAL_INPUT(TerminalWx::OnTerminalInput)

wxEND_EVENT_TABLE()
