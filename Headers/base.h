//
//  base.h
//  Graphbot
//
//  Created by Fernando Mendoza on 5/1/14.
//  Copyright (c) 2014 Fernando Mendoza. All rights reserved.
//

#ifndef __BASE_H
//Make sure to only declare these classes once
#define __BASE_H

#include "terminalwx.h"
#include "glpane.h"

class Graphbot: public wxApp { // MainApp is the class for our application
    // MainApp just acts as a container for the window, or frame in MainFrame
public:
    virtual bool OnInit();
};

class MainFrame: public wxFrame {// MainFrame is the class for our window
    // It contains the window and all objects in it
    public :
    MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);
    BasicGLPane * glPane;
    wxTextCtrl *codeGrounds;
    TerminalWx *terminal;
    void OnExit( wxCommandEvent& event );
    
    DECLARE_EVENT_TABLE()
};

enum{
    TEXT_Main = wxID_HIGHEST + 1, // declares an id which will be used to call our button
    TERMINAL_term = wxID_HIGHEST +1,
    GL_PANE_pane = wxID_HIGHEST + 1
};
#endif
