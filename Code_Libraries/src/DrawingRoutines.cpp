#include <GL/glew.h>
#include <GL/freeglut.h>
#include "DrawingRoutines.h"
#include "Utils.h"
using namespace std;

void drawButton(void* font, char* string, bool picking, float num, GameAssets assets, map<std::string, int> textureIds) {

	if (picking) {
		glDisable(GL_TEXTURE_2D);//Disabling Texture2D
		glDisable(GL_BLEND);//Disabling BLENDING
		glPushMatrix();
			glBegin(GL_POLYGON);
			glColor3f(0.1 + num, 0.1 * num, 0.1 * 3 * num); // We manage the color for picking, differentiating them with the help of the variable num
				glVertex3f(-1.4, (-1 * num) - 1, -5.0);
				glVertex3f(1.4, (-1 * num) - 1, -5.0);
				glVertex3f(1.4, (-1 * num) - 0.3, -5.0);
				glVertex3f(-1.4, (-1 * num) - 0.3, -5.0);
			glEnd();
		glPopMatrix();

		glEnable(GL_BLEND);//Enabling BLENDING
		glEnable(GL_TEXTURE_2D);//Enabling TEXTURING 2D
	}
	else
	{
		//First, show the text
		glDisable(GL_BLEND);// Disabling blending to avoid text transparency
		glColor4f(0, 0, 0, 0);
		glRasterPos3f(-0.7, (-1 * num) - 0.7, -5.0);
		char* c;
		for (c = string; *c != '\0'; c++) {
			glutBitmapCharacter(font, *c);
		}
		glEnable(GL_BLEND);

		//Then, load the button texture and apply it to the rectangle
		glColor3f(1, 1, 1);
		glPushMatrix();
			//glBindTexture(GL_TEXTURE_2D, assets.getButton());
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["button.png"]));
			glBegin(GL_POLYGON);
				glTexCoord2f(0.0, 0.0); glVertex3f(-1.4, (-1 * num) - 1, -5.0);
				glTexCoord2f(1.0, 0.0); glVertex3f(1.4, (-1 * num) - 1, -5.0);
				glTexCoord2f(1.0, 1.0); glVertex3f(1.4, (-1 * num) - 0.3, -5.0);
				glTexCoord2f(0.0, 1.0); glVertex3f(-1.4, (-1 * num) - 0.3, -5.0);
			glEnd();
		glPopMatrix();
	}
}

void drawArrow(string side, bool picking, GameAssets assets, map<std::string, int> textureIds) {

	if (picking) {
		glDisable(GL_TEXTURE_2D);//Disabling Texture2D
		glDisable(GL_BLEND);//Disabling BLENDING
		if (side == "right") {// Draw the arrows on the right side
			//Left arrow
			glPushMatrix();
				glBegin(GL_POLYGON);
					glColor3f(0.1,0.98,0.112); //We manage the color for picking, differentiating them with the help of the variable num
					glVertex3f(2, -2, -5.0);
					glVertex3f(2.5, -2, -5.0);
					glVertex3f(2.5, -1.5, -5.0);
					glVertex3f(2, -1.5, -5.0);
				glEnd();
			glPopMatrix();

			//Right arrow
			glPushMatrix();

				glBegin(GL_POLYGON);
					glColor3f(0.12, 0.88, 0.51);
					glVertex3f(5, -2, -5.0);
					glVertex3f(5.5, -2, -5.0);
					glVertex3f(5.5, -1.5, -5.0);
					glVertex3f(5, -1.5, -5.0);
				glEnd();
			glPopMatrix();
		}
		else if (side == "left") {
			//Left arrow
			glPushMatrix();
				glBegin(GL_POLYGON);
					glColor3f(0.88,0.44,0.55);
					glVertex3f(-5.5, -2, -5.0);
					glVertex3f(-5, -2, -5.0);
					glVertex3f(-5, -1.5, -5.0);
					glVertex3f(-5.5, -1.5, -5.0);
				glEnd();
			glPopMatrix();

			//Right arrow
			glPushMatrix();
				glBegin(GL_POLYGON);
					glColor3f(0.95,0.11,0.65);
					glVertex3f(-2.5, -2, -5.0);
					glVertex3f(-2, -2, -5.0);
					glVertex3f(-2, -1.5, -5.0);
					glVertex3f(-2.5, -1.5, -5.0);
				glEnd();
			glPopMatrix();
		}

		glEnable(GL_BLEND);//Enabling BLENDING
		glEnable(GL_TEXTURE_2D);//Enabling TEXTURING 2D
	}

	else { // We'm not in picking mode and We have to draw polygons by mapping the textures
		if (side == "right") {// Draw the arrows on the right side

			//Left arrow
			glPushMatrix();
				//glBindTexture(GL_TEXTURE_2D, assets.getArrow());
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["arrow.png"]));
				glBegin(GL_POLYGON);
					glTexCoord2f(0.0, 0.0); glVertex3f(2, -2, -5.0);
					glTexCoord2f(1.0, 0.0); glVertex3f(2.5, -2, -5.0);
					glTexCoord2f(1.0, 1.0); glVertex3f(2.5, -1.5, -5.0);
					glTexCoord2f(0.0, 1.0); glVertex3f(2, -1.5, -5.0);
				glEnd();
			glPopMatrix();

			//Right arrow
			glPushMatrix();
				glTranslatef(5.25, -1.75, 0); // Move it back to the original position
				glRotatef(180, 0, 0, 1); //Rotate
				glTranslatef(-5.25, 1.75, 0); // TRanslate to centre

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["arrow.png"]));
				glBegin(GL_POLYGON);
					glTexCoord2f(0.0, 0.0); glVertex3f(5, -2, -5.0);
					glTexCoord2f(1.0, 0.0); glVertex3f(5.5, -2, -5.0);
					glTexCoord2f(1.0, 1.0); glVertex3f(5.5, -1.5, -5.0);
					glTexCoord2f(0.0, 1.0); glVertex3f(5, -1.5, -5.0);
				glEnd();
			glPopMatrix();
		}
		else if (side == "left") {
			//Left arrow
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["arrow.png"]));
				glBegin(GL_POLYGON);
					glTexCoord2f(0.0, 0.0); glVertex3f(-5.5, -2, -5.0);
					glTexCoord2f(1.0, 0.0); glVertex3f(-5, -2, -5.0);
					glTexCoord2f(1.0, 1.0); glVertex3f(-5, -1.5, -5.0);
					glTexCoord2f(0.0, 1.0); glVertex3f(-5.5, -1.5, -5.0);
				glEnd();
			glPopMatrix();

			//Right arrow
			glPushMatrix();
				glTranslatef(-2.25, -1.75, 0); 
				glRotatef(180, 0, 0, 1); 
				glTranslatef(2.25, 1.75, 0);

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["arrow.png"]));
				glBegin(GL_POLYGON);
					glTexCoord2f(0.0, 0.0); glVertex3f(-2.5, -2, -5.0);
					glTexCoord2f(1.0, 0.0); glVertex3f(-2, -2, -5.0);
					glTexCoord2f(1.0, 1.0); glVertex3f(-2, -1.5, -5.0);
					glTexCoord2f(0.0, 1.0); glVertex3f(-2.5, -1.5, -5.0);
				glEnd();
			glPopMatrix();
		}
	}
}

void drawCrosshair() {

	glDisable(GL_TEXTURE_2D);

	glPointSize((GLfloat)2);
	/*glBegin(GL_POINTS);
		glColor3f(0, 0, 0);
		glVertex3f(0, 0, -1);
	glEnd();*/


	glLineWidth((GLfloat)1.5);
	glBegin(GL_LINES);
		glColor3f(1,0,0);
		glVertex3f(0, 0.01, -1);
		glVertex3f(0, 0.06, -1);
		glVertex3f(0, -0.01, -1);
		glVertex3f(0, -0.06, -1);
		glVertex3f(-0.01, 0, -1);
		glVertex3f(-0.06, -0, -1);
		glVertex3f(0.06, -0, -1);
		glVertex3f(0.01, 0, -1);
	glEnd();

	glLineWidth((GLfloat)4);
	glBegin(GL_LINES);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0, 0.01, -1);
		glVertex3f(0, 0.06, -1);
		glVertex3f(0, -0.01, -1);
		glVertex3f(0, -0.06, -1);
		glVertex3f(-0.01, 0, -1);
		glVertex3f(-0.06, -0, -1);
		glVertex3f(0.06, -0, -1);
		glVertex3f(0.01, 0, -1);
	glEnd();

	glEnable(GL_TEXTURE_2D);
}

void drawGameInterface(int score, int level, int difficulty, int elapsedTime, int ammo,
	int selectedWeapon, int selectedWeather, vector<string> weapons,
	GameAssets assets, map<std::string, int> textureIds) {
	
	glPushMatrix();
		glDisable(GL_BLEND);
		glDisable(GL_LIGHTING);
		drawText("TIME " + to_string(elapsedTime), -0.05, 0.665, -1.0);
		
		drawText("SCORE " + to_string(score), -0.45, 0.665, -1.0);

		drawText("LEVEL " + to_string(level), -0.25, 0.665, -1.0);

		drawText("AMMO " + to_string(ammo) + "/" + to_string(12 * (3 - difficulty)),
			0.15, 0.665, -1.0);

		glEnable(GL_BLEND);
		glEnable(GL_LIGHTING);
	glPopMatrix();


	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["game_interface.png"]));
		glBegin(GL_QUADS);
			glColor3f(0, 0, 0);
			glTexCoord2f(0.0, 0.0); glVertex3f(-0.55, 0.63, -1);
			glTexCoord2f(1.0, 0.0); glVertex3f(0.55, 0.63, -1);
			glTexCoord2f(1.0, 1.0); glVertex3f(0.55, 0.72, -1);
			glTexCoord2f(0.0, 1.0); glVertex3f(-0.55, 0.72, -1);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds[weapons[selectedWeapon]]));
		glBegin(GL_QUADS);
			glTexCoord2f(0.0, 0.0); glVertex3f(-0.25, -0.75, -1);
			glTexCoord2f(1.0, 0.0); glVertex3f(1.23, -0.75, -1);
			glTexCoord2f(1.0, 1.0); glVertex3f(1.23, -0.05, -1);
			glTexCoord2f(0.0, 1.0); glVertex3f(-0.25, -0.05, -1);
		glEnd();
	glPopMatrix();


}

void drawEnvironment(GLfloat x_map_limit_right, GLfloat x_map_limit_left,
	GLfloat z_map_limit_back, GLfloat z_map_limit_front, 
	int selectedWeather, vector<string> weathers, int level,
	GameAssets assets, map<std::string, int> textureIds) {

	
	if(level%2==0){	

		if(selectedWeather==0){

			// RIGHT WALL
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wall.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_front);
					glTexCoord2f(18.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_back);
					glTexCoord2f(18.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
				glEnd();
			glPopMatrix();

			// LEFT WALL
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wall.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_back);
					glTexCoord2f(18.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_front);
					glTexCoord2f(18.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
				glEnd();
			glPopMatrix();

			// BACK WALL
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wall.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_back);
					glTexCoord2f(15.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_back);
					glTexCoord2f(15.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
				glEnd();
			glPopMatrix();

			// FRONT WALL
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wall.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_front);
					glTexCoord2f(15.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_front);
					glTexCoord2f(15.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/holes.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left+2, -2, z_map_limit_front + 0.2);
				glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right+2, -2, z_map_limit_front + 0.2);
				glTexCoord2f(10.0, 2.0);  glVertex3f(x_map_limit_right+2, 2.8, z_map_limit_front + 0.2);
				glTexCoord2f(0.0, 2.0);  glVertex3f(x_map_limit_left+2, 2.5, z_map_limit_front + 0.2);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbag.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 2.5);
				glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 2.5);
				glTexCoord2f(10.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 2.5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 2.5);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbag.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 7.5);
				glTexCoord2f(6.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 7.5);
				glTexCoord2f(6.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 7.5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 7.5);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbag.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 5);
				glTexCoord2f(8.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 5);
				glTexCoord2f(8.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 5);
				glEnd();

			glPopMatrix();

			// FRONT ROOF
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roof.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(1.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(1.0, 1.0);  glVertex3f(x_map_limit_right-2, 8, z_map_limit_front+2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left+2, 8, z_map_limit_front+2);
				glEnd();
			glPopMatrix();

			// RIGHT ROOF
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roof.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(3.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(3.0, 1.0);  glVertex3f(x_map_limit_right - 2, 8, z_map_limit_back-2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_right - 2, 8, z_map_limit_front+2);
				glEnd();
			glPopMatrix();

			// LEFT ROOF
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roof.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(3.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(3.0, 1.0);  glVertex3f(x_map_limit_left + 2, 8, z_map_limit_front+2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left + 2, 8, z_map_limit_back-2);
				glEnd();
			glPopMatrix();


			// BACK ROOF
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roof.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(1.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(1.0, 1.0);  glVertex3f(x_map_limit_left+2, 8, z_map_limit_back-2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_right-2, 8, z_map_limit_back-2);
				glEnd();
			glPopMatrix();


			// FLOOR
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/floor.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left-10, -2.5, z_map_limit_back+10);
					glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right+10, -2.5, z_map_limit_back+10);
					glTexCoord2f(10.0, 10.0);  glVertex3f(x_map_limit_right+10, -2.5, z_map_limit_front-10);
					glTexCoord2f(0.0, 10.0);  glVertex3f(x_map_limit_left-10, -2.5, z_map_limit_front-10);
				glEnd();
			glPopMatrix();
		}

		else{
			// RIGHT WALL
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wallnight.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_front);
					glTexCoord2f(18.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_back);
					glTexCoord2f(18.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
				glEnd();
			glPopMatrix();

			// LEFT WALL
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wallnight.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_back);
					glTexCoord2f(18.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_front);
					glTexCoord2f(18.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
				glEnd();
			glPopMatrix();

			// BACK WALL
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wallnight.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_back);
					glTexCoord2f(15.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_back);
					glTexCoord2f(15.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
				glEnd();
			glPopMatrix();

			// FRONT WALL
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wallnight.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_front);
					glTexCoord2f(15.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_front);
					glTexCoord2f(15.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/holes.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left+2, -2, z_map_limit_front + 0.2);
				glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right+2, -2, z_map_limit_front + 0.2);
				glTexCoord2f(10.0, 2.0);  glVertex3f(x_map_limit_right+2, 2.8, z_map_limit_front + 0.2);
				glTexCoord2f(0.0, 2.0);  glVertex3f(x_map_limit_left+2, 2.5, z_map_limit_front + 0.2);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbagnight.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 2.5);
				glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 2.5);
				glTexCoord2f(10.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 2.5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 2.5);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbagnight.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 7.5);
				glTexCoord2f(6.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 7.5);
				glTexCoord2f(6.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 7.5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 7.5);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbagnight.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 5);
				glTexCoord2f(8.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 5);
				glTexCoord2f(8.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 5);
				glEnd();

			glPopMatrix();

			// FRONT ROOF
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roofnight.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(1.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(1.0, 1.0);  glVertex3f(x_map_limit_right-2, 8, z_map_limit_front+2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left+2, 8, z_map_limit_front+2);
				glEnd();
			glPopMatrix();

			// RIGHT ROOF
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roofnight.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(3.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(3.0, 1.0);  glVertex3f(x_map_limit_right - 2, 8, z_map_limit_back-2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_right - 2, 8, z_map_limit_front+2);
				glEnd();
			glPopMatrix();

			// LEFT ROOF
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roofnight.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(3.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(3.0, 1.0);  glVertex3f(x_map_limit_left + 2, 8, z_map_limit_front+2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left + 2, 8, z_map_limit_back-2);
				glEnd();
			glPopMatrix();


			// BACK ROOF
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roofnight.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(1.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(1.0, 1.0);  glVertex3f(x_map_limit_left+2, 8, z_map_limit_back-2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_right-2, 8, z_map_limit_back-2);
				glEnd();
			glPopMatrix();


			// FLOOR
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/floornight.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left-10, -2.5, z_map_limit_back+10);
					glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right+10, -2.5, z_map_limit_back+10);
					glTexCoord2f(10.0, 10.0);  glVertex3f(x_map_limit_right+10, -2.5, z_map_limit_front-10);
					glTexCoord2f(0.0, 10.0);  glVertex3f(x_map_limit_left-10, -2.5, z_map_limit_front-10);
				glEnd();
			glPopMatrix();
		}
	}
	else{
		if(selectedWeather==0){

			// RIGHT WALL
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wall1.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_front);
					glTexCoord2f(18.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_back);
					glTexCoord2f(18.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
				glEnd();
			glPopMatrix();

			// LEFT WALL
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wall1.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_back);
					glTexCoord2f(18.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_front);
					glTexCoord2f(18.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
				glEnd();
			glPopMatrix();

			// BACK WALL
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wall1.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_back);
					glTexCoord2f(15.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_back);
					glTexCoord2f(15.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
				glEnd();
			glPopMatrix();

			// FRONT WALL
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wall1.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_front);
					glTexCoord2f(15.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_front);
					glTexCoord2f(15.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/holes.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left+2, -2, z_map_limit_front + 0.2);
				glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right+2, -2, z_map_limit_front + 0.2);
				glTexCoord2f(10.0, 2.0);  glVertex3f(x_map_limit_right+2, 2.8, z_map_limit_front + 0.2);
				glTexCoord2f(0.0, 2.0);  glVertex3f(x_map_limit_left+2, 2.5, z_map_limit_front + 0.2);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbag.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 2.5);
				glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 2.5);
				glTexCoord2f(10.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 2.5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 2.5);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbag.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 7.5);
				glTexCoord2f(6.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 7.5);
				glTexCoord2f(6.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 7.5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 7.5);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbag.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 5);
				glTexCoord2f(8.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 5);
				glTexCoord2f(8.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 5);
				glEnd();

			glPopMatrix();

			// FRONT ROOF
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roof1.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(1.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(1.0, 1.0);  glVertex3f(x_map_limit_right-2, 8, z_map_limit_front+2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left+2, 8, z_map_limit_front+2);
				glEnd();
			glPopMatrix();

			// RIGHT ROOF
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roof1.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(3.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(3.0, 1.0);  glVertex3f(x_map_limit_right - 2, 8, z_map_limit_back-2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_right - 2, 8, z_map_limit_front+2);
				glEnd();
			glPopMatrix();

			// LEFT ROOF
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roof1.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(3.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(3.0, 1.0);  glVertex3f(x_map_limit_left + 2, 8, z_map_limit_front+2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left + 2, 8, z_map_limit_back-2);
				glEnd();
			glPopMatrix();


			// BACK ROOF
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roof1.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(1.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(1.0, 1.0);  glVertex3f(x_map_limit_left+2, 8, z_map_limit_back-2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_right-2, 8, z_map_limit_back-2);
				glEnd();
			glPopMatrix();


			// FLOOR
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/floor1.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left-10, -2.5, z_map_limit_back+10);
					glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right+10, -2.5, z_map_limit_back+10);
					glTexCoord2f(10.0, 10.0);  glVertex3f(x_map_limit_right+10, -2.5, z_map_limit_front-10);
					glTexCoord2f(0.0, 10.0);  glVertex3f(x_map_limit_left-10, -2.5, z_map_limit_front-10);
				glEnd();
			glPopMatrix();
		}

		else{
			// RIGHT WALL
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wallnight1.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_front);
					glTexCoord2f(18.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_back);
					glTexCoord2f(18.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
				glEnd();
			glPopMatrix();

			// LEFT WALL
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wallnight1.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_back);
					glTexCoord2f(18.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_front);
					glTexCoord2f(18.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
				glEnd();
			glPopMatrix();

			// BACK WALL
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wallnight1.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_back);
					glTexCoord2f(15.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_back);
					glTexCoord2f(15.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
				glEnd();
			glPopMatrix();

			// FRONT WALL
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/wallnight1.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -2.5, z_map_limit_front);
					glTexCoord2f(15.0, 0.0);  glVertex3f(x_map_limit_right, -2.5, z_map_limit_front);
					glTexCoord2f(15.0, 5.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(0.0, 5.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/holes.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left+2, -2, z_map_limit_front + 0.2);
				glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right+2, -2, z_map_limit_front + 0.2);
				glTexCoord2f(10.0, 2.0);  glVertex3f(x_map_limit_right+2, 2.8, z_map_limit_front + 0.2);
				glTexCoord2f(0.0, 2.0);  glVertex3f(x_map_limit_left+2, 2.5, z_map_limit_front + 0.2);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbagnight.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 2.5);
				glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 2.5);
				glTexCoord2f(10.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 2.5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 2.5);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbagnight.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 7.5);
				glTexCoord2f(6.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 7.5);
				glTexCoord2f(6.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 7.5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 7.5);
				glEnd();

				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/sandbagnight.png"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
				glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, -3, z_map_limit_front + 5);
				glTexCoord2f(8.0, 0.0);  glVertex3f(x_map_limit_right, -3, z_map_limit_front + 5);
				glTexCoord2f(8.0, 1.0);  glVertex3f(x_map_limit_right, 0.5, z_map_limit_front + 5);
				glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left, 0.5, z_map_limit_front + 5);
				glEnd();

			glPopMatrix();

			// FRONT ROOF
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roofnight1.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(1.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(1.0, 1.0);  glVertex3f(x_map_limit_right-2, 8, z_map_limit_front+2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left+2, 8, z_map_limit_front+2);
				glEnd();
			glPopMatrix();

			// RIGHT ROOF
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roofnight1.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_front);
					glTexCoord2f(3.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(3.0, 1.0);  glVertex3f(x_map_limit_right - 2, 8, z_map_limit_back-2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_right - 2, 8, z_map_limit_front+2);
				glEnd();
			glPopMatrix();

			// LEFT ROOF
			glPushMatrix();
			glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roofnight1.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(3.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_front);
					glTexCoord2f(3.0, 1.0);  glVertex3f(x_map_limit_left + 2, 8, z_map_limit_front+2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_left + 2, 8, z_map_limit_back-2);
				glEnd();
			glPopMatrix();


			// BACK ROOF
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/roofnight1.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_right, 6, z_map_limit_back);
					glTexCoord2f(1.0, 0.0);  glVertex3f(x_map_limit_left, 6, z_map_limit_back);
					glTexCoord2f(1.0, 1.0);  glVertex3f(x_map_limit_left+2, 8, z_map_limit_back-2);
					glTexCoord2f(0.0, 1.0);  glVertex3f(x_map_limit_right-2, 8, z_map_limit_back-2);
				glEnd();
			glPopMatrix();


			// FLOOR
			glPushMatrix();
				glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["environment/floornight1.jpg"]));
				glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
				glBegin(GL_QUADS);
					glTexCoord2f(0.0, 0.0);  glVertex3f(x_map_limit_left-10, -2.5, z_map_limit_back+10);
					glTexCoord2f(10.0, 0.0);  glVertex3f(x_map_limit_right+10, -2.5, z_map_limit_back+10);
					glTexCoord2f(10.0, 10.0);  glVertex3f(x_map_limit_right+10, -2.5, z_map_limit_front-10);
					glTexCoord2f(0.0, 10.0);  glVertex3f(x_map_limit_left-10, -2.5, z_map_limit_front-10);
				glEnd();
			glPopMatrix();
		}
	}

	//SKY
	glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds[weathers[selectedWeather]]));
	glBegin(GL_QUADS);
		glTexCoord2f(0.0, 0.0);  glVertex3f(-400.0, 20, -400.0);
		glTexCoord2f(1.0, 0.0);  glVertex3f(400.0, 20, -400.0);
		glTexCoord2f(1.0, 1.0);  glVertex3f(400.0, 20, 400.0);
		glTexCoord2f(0.0, 1.0);  glVertex3f(-400.0, 20, 400.0);
	glEnd();

}

void drawScoreboard(map<string, int> &scoreList, int playerScore, string playerName, GameAssets assets, map<std::string, int> textureIds) {
	//To order the map by value and to by key, we need to 
	//convert the map into a inversed multimap
	//Declare a multimap that orders key by descending order
	multimap<int, string, greater<int>> MM;

	// Insert every (key-value) pairs from
	// map M to multimap MM as (value-key) pairs
	for (auto& it : scoreList) {
		MM.insert({ it.second, it.first });
	}

	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["Textures/menu_background.jpg"]));
		glBegin(GL_POLYGON);
			glTexCoord2f(0.0, 0.0); glVertex3f(-6, -5, -5.01);
			glTexCoord2f(1.0, 0.0); glVertex3f(6, -5, -5.001);
			glTexCoord2f(1.0, 1.0); glVertex3f(6, 5, -5.01);
			glTexCoord2f(0.0, 1.0); glVertex3f(-6, 5, -5.01);
		glEnd();
	glPopMatrix();
	
	glPushMatrix();
		glDisable(GL_TEXTURE_2D);
		glBegin(GL_POLYGON);
			glColor4f(0.0, 0.0, 0.0, 0.7);
			glVertex3f(-1.2, -2.5, -5.001);
			glVertex3f(1.2, -2.5, -5.001);
			glVertex3f(1.2, 0.5, -5.001);
			glVertex3f(-1.2, 0.5, -5.001);
		glEnd();
		glEnable(GL_TEXTURE_2D);
	glPopMatrix();
	
	//Loading and drawing logo
	glPushMatrix();
	glBindTexture(GL_TEXTURE_2D, assets.getTexture(textureIds["scoreboard_logo.png"]));
		glBegin(GL_POLYGON);
			glColor3f(1,1,1);
			glTexCoord2f(0.0, 0.0); glVertex3f(-3, 1, -5.0);
			glTexCoord2f(1.0, 0.0); glVertex3f(3, 1, -5.0);
			glTexCoord2f(1.0, 1.0); glVertex3f(3, 3, -5.0);
			glTexCoord2f(0.0, 1.0); glVertex3f(-3, 3, -5.0);
		glEnd();
	glPopMatrix();

	glPushMatrix();
		glDisable(GL_BLEND);// Disabling blending to avoid text transparency
		glDisable(GL_LIGHTING);

		drawText("YOUR SCORE IS " + to_string(playerScore), -0.15, -0.18, -1.0);

		glEnable(GL_LIGHTING);
		glEnable(GL_BLEND);
	glPopMatrix();

}