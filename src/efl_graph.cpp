//============================================================================
// Name        : efl_graph.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Window.h"
#include "MainContent.h"
#include "DrawingContent.h"
#include "WindowListener.h"

#include <Elementary.h>
#include <iostream>
using namespace std;

EAPI_MAIN int elm_main(int argc, char **argv)
{
	Window window;
	WindowListener windowListener;

	window.create();

	window.setListener( &windowListener );
	window.setMaxSize( 800, 600 );
	window.setVisibility(true);

	MainContent mainContent( window.getEvasObject() );

	DrawingContent drawingContent( window.getEvasObject(), mainContent.getLayout() );

	srand( time ( 0 ) );

	elm_run();
	return 0;
}
ELM_MAIN()
