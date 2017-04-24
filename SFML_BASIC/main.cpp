//////////////////////////////////////////////////////////// 
// Headers 
//////////////////////////////////////////////////////////// 
#include "stdafx.h" 
#ifdef _DEBUG 
#pragma comment(lib,"sfml-graphics-d.lib") 
#pragma comment(lib,"sfml-audio-d.lib") 
#pragma comment(lib,"sfml-system-d.lib") 
#pragma comment(lib,"sfml-window-d.lib") 
#pragma comment(lib,"sfml-network-d.lib") 
#else 
#pragma comment(lib,"sfml-graphics.lib") 
#pragma comment(lib,"sfml-audio.lib") 
#pragma comment(lib,"sfml-system.lib") 
#pragma comment(lib,"sfml-window.lib") 
#pragma comment(lib,"sfml-network.lib") 
#endif 
#pragma comment(lib,"opengl32.lib") 
#pragma comment(lib,"glu32.lib") 
 
#include "SFML/Graphics.hpp" 
#include "SFML/Graphics/Shader.hpp"
#include "SFML/OpenGL.hpp" 
#include <gl/GLU.h>
#include <iostream> 
#define _USE_MATH_DEFINES
#include <math.h>

#include "Camera.h"
float CalcCylinderX(float, float, float[], float[]);
float CalcCylinderY(float, float, float[], float[]);
float CalcCylinderZ(float, float, float[], float[]);

void floor() {
	sf::Texture texLidwa;
	sf::Texture texLidrw;
	if (!texLidwa.loadFromFile("wood_ash.jpg")) {}
	if (!texLidrw.loadFromFile("rosewood.jpg")) {}
	glEnable(GL_TEXTURE_2D);
	glClear(GL_COLOR_BUFFER_BIT);
	double size = 3;
	for (int j = 0; j<50; j++)
	{
		//xsize = 0;
		for (int i = 0; i<50; i++)
		{
			if ((i + j) % 2 == 0)
			{
				sf::Texture::bind(&texLidwa);//select this texture for OpenGL rendering
				glBegin(GL_QUADS);
				glTexCoord2f(0, 0);
				glVertex3f(-50.0 + i*size, 0.0, -50.0 + j*size);
				glTexCoord2f(0, 1);
				glVertex3f(-50.0 + (i + 1)*size, 0.0, -50.0 + j*size);
				glTexCoord2f(1, 1);
				glVertex3f(-50.0 + (i + 1)*size, 0.0, -50.0 + (j + 1)*size);
				glTexCoord2f(1, 0);
				glVertex3f(-50.0 + i*size, 0.0, -50.0 + (j + 1)*size);
				glEnd();
			}
			else
			{
				sf::Texture::bind(&texLidrw);//select this texture for OpenGL rendering
				glBegin(GL_QUADS);
				glTexCoord2f(0, 0);
				glVertex3f(-50.0 + i*size, 0.0, -50.0 + j*size);
				glTexCoord2f(0, 1);
				glVertex3f(-50.0 + (i + 1)*size, 0.0, -50.0 + j*size);
				glTexCoord2f(1, 1);
				glVertex3f(-50.0 + (i + 1)*size, 0.0, -50.0 + (j + 1)*size);
				glTexCoord2f(1, 0);
				glVertex3f(-50.0 + i*size, 0.0, -50.0 + (j + 1)*size);
				glEnd();
			}
		}
	}
	glFlush();
};

void dice() {
	sf::Texture tex;
	if (!tex.loadFromFile("dice2.png")) {}
	GLdouble aaa[] = { 1, 1, 1 };
	GLdouble aab[] = { 1, 1, -1 };
	GLdouble abb[] = { 1, -1, -1 };
	GLdouble aba[] = { 1, -1, 1 };
	GLdouble baa[] = { -1, 1, 1 };
	GLdouble bab[] = { -1, 1, -1 };
	GLdouble bba[] = { -1, -1, 1 };
	GLdouble bbb[] = { -1, -1, -1 };


	
	
	
	sf::Texture::bind(&tex);


	

	glColor3d(1, 1, 1);

	//front 4
	glBegin(GL_QUADS);
	glTexCoord2d(0.25, 0.333);
	glVertex3dv(aaa);

	glTexCoord2d(0.5, 0.333);
	glVertex3dv(baa);

	glTexCoord2d(0.5, 0);
	glVertex3dv(bba);

	glTexCoord2d(0.25, 0);
	glVertex3dv(aba);

	glEnd();
	// left side 2
	glBegin(GL_QUADS);
	glTexCoord2d(0, 0.6666);
	glVertex3dv(abb);

	glTexCoord2d(0, 0.333);
	glVertex3dv(aba);

	glTexCoord2d(0.25, 0.333);
	glVertex3dv(aaa);

	glTexCoord2d(0.25, 0.666);
	glVertex3dv(aab);
	glEnd();

	//top 1
	glBegin(GL_QUADS);
	glTexCoord2d(0.25, 0.666);
	glVertex3dv(aab);

	glTexCoord2d(0.5, 0.666);
	glVertex3dv(bab);

	glTexCoord2d(0.5, 0.3333);
	glVertex3dv(baa);

	glTexCoord2d(0.25, 0.333);
	glVertex3dv(aaa);

	glEnd();
	//back 3
	glBegin(GL_QUADS);





	glTexCoord2d(0.25, 0.6666);
	glVertex3dv(aab); glTexCoord2d(0.5, 0.6666);
	glVertex3dv(bab); glTexCoord2d(0.5, 1);
	glVertex3dv(bbb); glTexCoord2d(0.25, 1);
	glVertex3dv(abb);


	glEnd();
	//right side 5
	glBegin(GL_QUADS);
	glTexCoord2d(0.5, 0.666);
	glVertex3dv(bab);

	glTexCoord2d(0.75, 0.666);
	glVertex3dv(bbb);

	glTexCoord2d(0.75, 0.333);
	glVertex3dv(bba);

	glTexCoord2d(0.5, 0.333);
	glVertex3dv(baa);

	glEnd();
	//bottom 6
	glBegin(GL_QUADS);
	glTexCoord2d(0.75, 0.666);
	glVertex3dv(bbb);

	glTexCoord2d(1.0, 0.666);
	glVertex3dv(abb);

	glTexCoord2d(1.0, 0.333);
	glVertex3dv(aba);

	glTexCoord2d(0.75, 0.333);
	glVertex3dv(bba);

	glEnd();
}


float CalcCylinderX(float t, float phi, float pt1[3], float pt2[3]) {
	return pt1[0] * (1 - t) + pt2[0] * t;
}

float CalcCylinderY(float t, float phi, float pt1[3], float pt2[3]) {
	float r = pt1[1] * (1 - t) + pt2[1] * t;
	return r*cos(phi);
}

float CalcCylinderZ(float t, float phi, float pt1[3], float pt2[3]) {
	float r = pt1[1] * (1 - t) + pt2[1] * t;
	return r*sin(phi);
}

void NormalVector(GLfloat pt1[3], GLfloat pt2[3], GLfloat pt3[3], GLfloat n[3]) {

	GLfloat v1[3], v2[3]; // vectors
						  // calculate two vectors lying on the surface
	for (int i = 0; i<3; i++) {
		v1[i] = pt2[i] - pt1[i];
		v2[i] = pt3[i] - pt2[i];
	}
	// cross product of two vectors
	n[0] = v1[1] * v2[2] - v2[1] * v1[2];
	n[1] = v1[2] * v2[0] - v2[2] * v1[0];
	n[2] = v1[0] * v2[1] - v2[0] * v1[1];

}

void bottle() {
	const double r = 1.0, PI = 3.141, r2 = 0.4;
	const int sides = 400;
	const float xAxes = 1.5f;
	GLfloat normal[3];

	sf::Texture tex;
	if (!tex.loadFromFile("jd.jpg")) {}
	sf::Texture::bind(&tex);
	glEnable(GL_TEXTURE_2D);//tell OpenGL to use textures when drawing

	float dt = 0.1, dphi = 0.01, TWO_PI = 3.141 * 2;
	const int NUM_OF_POINTS = 7;
	float allValues[][3] = { { -xAxes, 1.5, 0 },	//0
	{ 2.0, 1.5, 0 },	//1
	{ 4, 0.5, 0 },		//2
	{ 5.5, 0.5, 0 },	//3
	{ 5.5, 0.4, 0 },	//4
	{ 5.6, 0.4, 0 },	//5
	{ 5.6, 0.5, 0 },	//6
	{ 5.7, 0.5, 0 },	//7
	};
	
	float	ypospt = 0.2f, allquads = 1.f,
		width = .006, increaseby = .25;

	glCullFace(GL_FRONT);
	glBegin(GL_QUADS);
	
	for (int i = 0; i<NUM_OF_POINTS; i++) {
		
		for (float t = 0; t <= 1; t += dt) {
			float	tp0 = 0, tp1 = 0, tp2 = 0, tp3 = 0;
			if (i == 0 && t > 0.2f && t < 0.7f) {
				allquads -= increaseby;
				ypospt += .1f;
			}
			for (float phi = 0; phi<TWO_PI; phi += dphi) {
				GLfloat cylPoints[][3] = { { CalcCylinderZ(t, phi, allValues[i], allValues[i + 1]),
					CalcCylinderX(t, phi, allValues[i], allValues[i + 1]),
					CalcCylinderY(t, phi, allValues[i], allValues[i + 1]) },				//0
					{
						CalcCylinderZ(t, phi + dphi, allValues[i], allValues[i + 1]),
						CalcCylinderX(t, phi + dphi, allValues[i], allValues[i + 1]),
						CalcCylinderY(t, phi + dphi, allValues[i], allValues[i + 1]) },		//1
						{
							CalcCylinderZ(t + dt, phi + dphi, allValues[i], allValues[i + 1]),
							CalcCylinderX(t + dt, phi + dphi, allValues[i], allValues[i + 1]),
							CalcCylinderY(t + dt, phi + dphi, allValues[i], allValues[i + 1]) },	//2
							{
								CalcCylinderZ(t + dt, phi, allValues[i], allValues[i + 1]),
								CalcCylinderX(t + dt, phi, allValues[i], allValues[i + 1]),
								CalcCylinderY(t + dt, phi, allValues[i], allValues[i + 1]) } };			//3
				NormalVector(cylPoints[2], cylPoints[3], cylPoints[0], normal);
				glNormal3fv(normal);
				if ((i == 0) && ((t == ypospt) && (ypospt<0.7f))) {
					glTexCoord2f(tp0, allquads);					glVertex3fv(cylPoints[3]);//tp0
					glTexCoord2f(tp1, allquads);					glVertex3fv(cylPoints[2]);//tp1
					glTexCoord2f(tp2 + width, allquads + increaseby);	glVertex3fv(cylPoints[1]);//tp2
					glTexCoord2f(tp3 + width, allquads + increaseby);	glVertex3fv(cylPoints[0]);//tp3
					tp0 += width;	tp1 += width;
					tp2 += width;	tp3 += width;
				}
				else {
					glVertex3fv(cylPoints[3]);
					glVertex3fv(cylPoints[2]);
					glVertex3fv(cylPoints[1]);
					glVertex3fv(cylPoints[0]);
				}
			}
		}
	}
	glEnd();

	
}

int main() 
{ 
    // Create the main window 
	double r = 0;
	sf::ContextSettings Setting;
	Setting.depthBits = 24;
	Setting.antialiasingLevel = 2;
	Setting.stencilBits = 8;
	
    
    int width=600,height=600;
	sf::RenderWindow App(sf::VideoMode(width, height, 32), "SFML OpenGL", sf::Style::Close, Setting); 
    // Create a clock for measuring time elapsed     
    sf::Clock Clock; 

	aiVector3D position(0,6,-10);
	Camera camera;
    camera.Init(position); //create a camera
      
    //prepare OpenGL surface for HSR 
    glClearDepth(1.f); 
    glClearColor(0.3f, 0.3f, 0.6f, 0.f); //background colour
    glEnable(GL_DEPTH_TEST); 
    glDepthMask(GL_TRUE); 
   
    //// Setup a perspective projection & Camera position 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
     
    //set up a 3D Perspective View volume
    gluPerspective(90.f, (float)width/height, 1.f, 50.0f);//fov, aspect, zNear, zFar 
 

    // Start game loop 
    while (App.isOpen()) 
    { 
        // Process events 
        sf::Event Event; 
        while (App.pollEvent(Event)) 
        { 
            // Close window : exit 
            if (Event.type == sf::Event::Closed) 
                App.close(); 
   
            // Escape key : exit 
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape)) 
                App.close(); 
             
			//update the camera
			camera.Update(Event);
 
            
    
        } 
           
        //Prepare for drawing 
        // Clear color and depth buffer 
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   
        // Apply some transformations 
        //initialise the worldview matrix
		glMatrixMode(GL_MODELVIEW); 
		glEnable(GL_LIGHTING);
        glLoadIdentity(); 

		//get the viewing transform from the camera
		camera.ViewingTransform();

		floor();
		r += 0.5;
		/////Gl

		glPushMatrix();
		glTranslated(-1.5, 2, 0);
		glRotated(r*1.5, 1, 1, 1);
		dice();
		glPopMatrix();

		//Transparency
		GLfloat rgbvals[] = { 1.0f,0.3f,0.1f, 0.92 }; // (R,G,B, Transparency)
		GLfloat rgbvals2[] = { 1, 1, 1, 0.5 }; //bottle color

		glDepthMask(GL_FALSE);
	
		glEnable(GL_ALPHA_TEST);
		glAlphaFunc(GL_ALWAYS, GL_INVALID_ENUM);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		glPushMatrix();
		glTranslated(5, 1.5, 0);
		glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE, rgbvals2);
		bottle();
		glPopMatrix();

		
		
		glDepthMask(GL_TRUE);
		glDisable(GL_ALPHA_TEST);
		glDisable(GL_BLEND);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
		glDisable(GL_COLOR_MATERIAL);

		




		   
        // Finally, display rendered frame on screen 
        App.display(); 
    } 
   
    return EXIT_SUCCESS; 
}
