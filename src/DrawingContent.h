/*
 * DrawingContent.h
 *
 *  Created on: Mar 16, 2015
 *      Author: vostanin
 */

#ifndef DRAWINGCONTENT_H_
#define DRAWINGCONTENT_H_

#include "Animator.h"
#include <Evas.h>
#include <string>
#include <vector>
#include <Evas_GL.h>
using namespace std;

class DrawingContent
{

public:
	DrawingContent( Evas_Object *mainWindowObject, Evas_Object *mainLayout );
	virtual ~DrawingContent();

	Evas_Object * getDrawingCanvas();

	void update();

	unsigned int getCanvasWidth() const;
	unsigned int getCanvasHeight() const;

private:

	void createDrawingLayout();
	void createDrawingCanvas();
	void preDraw();
	void postDraw();
	void drawObjects();
	void clearObjects();

	string getVertexShader();
	string getFragmentShader();
	GLuint loadShader( GLenum type, const char *shader_src );
	int initShaders();
	void loadPng( string & filename, vector<unsigned char> & rgbContent, int & width, int & height );
	void initCanvasBackground();
	void drawCanvasBackground();

	static void on_init_gles( Evas_Object * glview );
	static void on_resize_gl( Evas_Object * glview );
	static void on_draw_gl( Evas_Object * glview );
    static void on_draw_dynamic_gl( Evas_Object * glview );

    static bool DynamicDrawTimer( void * userData );

    void checkError();

	Evas_Object * m_MainLayout;
	Evas_Object * m_DrawingLayout;

	Evas_Object * m_MainWindowObject;

	Evas_Object * m_DrawingCanvas;

	Evas_GL_API * m_glApi;

	Animator m_DynamicTimer;

	int m_CanvasWidth;
	int m_CanvasHeight;

	bool m_DrawDynamic;

	GLuint       	m_Program;
	GLuint       	m_vertexShader;
	GLuint       	m_fragmentShader;

	GLint       	m_positionIdx;
	GLint       	m_textureCoordsIdx;

	vector<unsigned char> m_rgbRawData;
	GLuint 			m_textureIdx;
	GLuint 			m_fragmentUniformTextureIdx;
	int 			m_BackgroundWidth;
	int 			m_BackgroundHeight;
};

#endif /* DRAWINGCONTENT_H_ */
