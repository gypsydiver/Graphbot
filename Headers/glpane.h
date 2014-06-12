//
//  glpane.h
//  Graphbot
//
//  Created by Fernando Mendoza on 5/1/14.
//  Copyright (c) 2014 Fernando Mendoza. All rights reserved.
//

#ifndef _glpane_
#define _glpane_

#include "wx/wx.h"
#include "wx/glcanvas.h"

class BasicGLPane : public wxGLCanvas
{
    wxGLContext*	m_context;
    
public:
    //static GLuint texturas[5];
	BasicGLPane(wxFrame* parent,wxWindowID id);
	virtual ~BasicGLPane();
    
	void resized(wxSizeEvent& evt);
    
	int getWidth();
	int getHeight();
    
	//void render(wxPaintEvent& evt);
    void render();
    void reset();
	void prepare2DViewport(int topleft_x, int topleft_y, int bottomrigth_x, int bottomrigth_y);
    
	DECLARE_EVENT_TABLE()
};
#endif