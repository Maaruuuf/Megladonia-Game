#include "iGraphics.h"
#define SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS



#include <iostream>
#include <fstream>
using namespace std;

#pragma warning (disable : 4996)


int FISHNUMBER = 60;
int FISHNUMBER2 =  20;
bool musicOn = true;
int showSecond[3];
int showThird[3];
char readHighScore[3];
int loadScore;
int arr[4];
int q=0;
int k = 0;
char a,c,e,s;
char h,about,in,gameOver;
int sound = 1; 
int b = 0;
int b1 = 0;
int sharkCordinateX = 100;
int sharkCordinateY = 350;
int sharkIndex = 0; 
int life2 = 100;  // Initial value of life
int redLifeIndex=1;

char scoreShow[3];
char x;


int explosion = 0;



void burstf()																						//burst image shown
{
	b++;
	if (b>2)
	{
		b = 0;

	}
}


int l = 0;

/*void lifef()																				//bdtank life
{
	if (l < 11)
	{
		l--;
	}
	else if (l == 11)
	{
		int gameState = 0;
	}
}*/




//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::Idraw Here::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
struct buttonCordinate
{
	int x;
	int y;

}bCordinate[3];



//bool musicOn = true;
int r, g, b2;
int bcIndex = 0;
int gameState = -1;
//int sound = 1;





char shark[11][1000] = { "D:\\MEGLADONIA\\MEGLADONIA\\button456\\frame1.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\frame2.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\frame3.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\frame4.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\frame5.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\frame6.bmp","D:\\MEGLADONIA\\MEGLADONIA\\button456\\eating1.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\eating2.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\eating3.bmp","D:\\MEGLADONIA\\MEGLADONIA\\button456\\frame7.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\frame8.bmp" };
char sharkStand[200] = "D:\\MEGLADONIA\\MEGLADONIA\\button456\\frame1.bmp";
//char gameover[200] = { "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\GAMEOVER.bmp" };


char button[10][600] = { "D:\\MEGLADONIA\\MEGLADONIA\\button456\\button1.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\button6.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\button3.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\buton5.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\button4.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\button2.bmp" };


char burst[3][100] = { "D:\\MEGLADONIA\\MEGLADONIA\\button456\\Menu\\brust1.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\Menu\\brust2.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\Menu\\brust3.bmp" };

char bc[1][200] = { "D:\\MEGLADONIA\\MEGLADONIA\\button456\\menu.bmp" };
char play[200] = "D:\\MEGLADONIA\\MEGLADONIA\\button456\\play.bmp";
char life[11][100] = { "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\11.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\10.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\9.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\8.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\7.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\6.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\5.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\4.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\3.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\2.bmp", "D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\1.bmp" };

bool marked[50];

bool redlife[11];

int myScore = 0;
char myScoreText[10];

void score()
{
	sprintf_s(myScoreText, 10, "%d", myScore);
	iSetColor(255, 255, 0);
	//iFilledRectangle(15, 570, 150, 25);
	iSetColor(255, 0, 0);
	iText(75, 814, "Score:", GLUT_BITMAP_TIMES_ROMAN_24);
	iText(155, 814, myScoreText, GLUT_BITMAP_TIMES_ROMAN_24);
	
	//	myScoreCopy = myScore;
}








bool standPos = true;
int standCounter = 0;






struct food
{
	int fishX;
	int fishY;
	int fishIndex;
	bool fishShow;

};

food enemy[50];
food enemy1[20];






void enemyMovement()
{
	if (gameState == 0)
	{

		for (int i = 0; i < FISHNUMBER; i++){

			//printf("%d ", i);
			if (enemy[i].fishShow)
			{
				iShowImage(enemy[i].fishX, enemy[i].fishY, 60, 45, a);


				if (((sharkCordinateX + 157 >= enemy[i].fishX) && (sharkCordinateX <= enemy[i].fishX + 157) &&            //if collision is done
					(enemy[i].fishY + 10 >= sharkCordinateY) && (enemy[i].fishY <= sharkCordinateY + 10)))
				{



					explosion = 1;
					//lifef();


					iShowBMP2(enemy[i].fishX, enemy[i].fishY, burst[b], 0);
					enemy[i].fishX = 300 + 1.5 * (rand() % 100) + rand() % 130;
					enemy[i].fishY = enemy[i].fishY + 1000 + iScreenHeight + rand() % rand();
					marked[i] = true;
				}





			}

		}
		for (int reset = 0; reset < 50; reset++){
			if (marked[reset]){
				marked[reset] = false;
				enemy[reset].fishX = iScreenWidth + rand() % 300;
				enemy[reset].fishY = 200 + rand() % 300;

			}

		}


	}

	if (gameState == 0){
		

		for (int i = 0; i < FISHNUMBER2; i++)
		{
			if (enemy[i].fishShow)
			{
				iShowImage(enemy[i].fishX, enemy[i].fishY, 60, 45, e);

				if (((sharkCordinateX + 157 >= enemy[i].fishX) && (sharkCordinateX <= enemy[i].fishX + 157) &&            //if collision is done
					(enemy[i].fishY + 40 >= sharkCordinateY) && (enemy[i].fishY <= sharkCordinateY + 40)))
				{
					explosion = 2;
					//lifef();

					iShowBMP2(enemy[i].fishX, enemy[i].fishY, burst[b], 0);
					enemy[i].fishX = 300 + 1.5 * (rand() % 100) + rand() % 130;
					enemy[i].fishY = enemy[i].fishY + 1000 + iScreenHeight + rand() % rand();
					marked[i] = true;

				}
			}
		}
		for (int reset = 0; reset < 50; reset++){
			if (marked[reset]){
				marked[reset] = false;
				enemy[reset].fishX = iScreenWidth + rand() % 300;
				enemy[reset].fishY = 200 + rand() % 300;
			}



		}
	}
}










void iDraw()
{
	
	iClear();

	

	iSetColor(r, g, b);
	iShowBMP(0, 0, bc[bcIndex]);

	

	if (gameState == -1)
	{
		/*homeMenu
		iShowBMP(0, 0, bc[bcIndex]);
		for (int i = 0; i < 3; i++)
		{
			iShowBMP2(bCordinate[1].x, bCordinate[i].y, button[i], 255);

		}*/
		iShowImage(0, 0, 1600, 850, c);
	
	}
	else if (gameState == 0)
	{
		


		iShowBMP(0, 0, play);

			enemyMovement();
			score();
			
	
		iSetColor(255, 255, 255);
		iText(1205, 830, "Shark Life  ", GLUT_BITMAP_TIMES_ROMAN_24);
		//iShowBMP2(1200, 760, life[q],0);
		/*if (!redlife[0]){
			iShowBMP2(1200, 760, life[0],0);
		}
		if (!redlife[1]){
			iShowBMP2(1200, 760, life[1], 0);
		}
		if (!redlife[2]){
			iShowBMP2(1200, 760, life[2], 0);
		}
		if (!redlife[3]){
			iShowBMP2(1200, 760, life[3], 0);
		}
		if (!redlife[4]){
			iShowBMP2(1200, 760, life[4], 0);
		}
		if (!redlife[5]){
			iShowBMP2(1200, 760, life[5], 0);
		}
		if (!redlife[6]){
			iShowBMP2(1200, 760, life[6], 0);
		}
		if (!redlife[7]){
			iShowBMP2(1200, 760, life[7], 0);
		}
		if (!redlife[8]){
			iShowBMP2(1200, 760, life[8], 0);
		}
		if (!redlife[9]){
			iShowBMP2(1200, 760, life[9], 0);
		}
		if (!redlife[10]){
			iShowBMP2(1200, 760, life[10], 0);
		}*/
		iShowBMP2(1200, 760, life[redLifeIndex], 0);
		if (explosion == 1)													//explosion 1 
		{
			//redlife[redLifeIndex] = false;

			/*if (redLifeIndex <9){ redLifeIndex++; }
			else{
				gameState = 6;
			}*/
			iShowBMP2(sharkCordinateX, sharkCordinateY, burst[b], 0); //explosion code here
			burstf();
			myScore = myScore+50;
			//burst2f();
			explosion = 0;

		}
		if (explosion == 2)													//explosion 1 
		{
			//redlife[redLifeIndex] = false;

			if (redLifeIndex < 9){ redLifeIndex++; }
			else{
				gameState = 6;
			}
			iShowBMP2(sharkCordinateX, sharkCordinateY, burst[b], 0); //explosion code here
			burstf();
			//myScore++;
			//burst2f();
			explosion = 0;
		}



		if (!standPos){
			iShowBMP2(sharkCordinateX, sharkCordinateY, shark[sharkIndex], 0);
			standCounter++;
			if (standCounter >= 20){

				standCounter = 0;
				sharkIndex = 0;
				standPos = true;
			}
		}
		else
		{
			iShowBMP2(sharkCordinateX, sharkCordinateY, sharkStand, 0);
		}

	}
	else if (gameState == 1)
	{
		iShowImage(0, 0, 1600, 850, in);
	}
	else if (gameState == 2)
	{
		iShowImage(0, 0, 1600, 850, s);
		
	}
	else if (gameState == 3)
	{
		iShowImage(0, 0, 1600, 850, h);
		iText(321, 580, "1750", GLUT_BITMAP_TIMES_ROMAN_24);

		

	}
	else if (gameState == 4)
	{
		iShowImage(0, 0, 1600, 850, about);
	}
	else if (gameState == 5)
	{
		exit(0);
	}
	else if (gameState == 6){

		iShowImage(0, 0, 1600, 850, gameOver);
	}
	else if (gameState == 7){

		iShowImage(0, 0, 750, 450, x);
	}


}




/*function iMouseMove() is called when the user presses and drags the mouse.
(mx, my) is the position where the mouse pointer is.
*/


void iMouseMove(int mx, int my)
{

}
//*******************************************************************ipassiveMouse***********************************************************************//
void iPassiveMouseMove(int mx, int my)
{

}

void iMouse(int button, int state, int mx, int my)
{

	/*if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		for (int i = 0; i < 3; i++)
		{
			if (mx >= bCordinate[i].x && mx <= bCordinate[i].x + 389 && my >= bCordinate[i].y && my <= bCordinate[i].y + 90)
			{
				gameState = i;
			}
		}

	}*/
	printf("%d\n", mx);
	printf("%d\n", my);


	if (gameState == -1)
	{
		if (mx >= 76 && mx <= 376 && my >= 643 && my <= 686)
		{
			gameState = 0;
		}
		else if (mx >= 75 && mx <= 376 && my >= 534 && my <= 583)
		{
			gameState = 1;
		}
		else if (mx >= 75 && mx <= 376 && my >= 384 && my <= 478)
		{
			gameState = 2;
		}
		else if (mx >= 75 && mx <= 376 && my >= 347 && my <= 395)
		{
			gameState = 3;
		}
		else if (mx >= 75 && mx <= 376 && my >= 240 && my <= 291)
		{
			gameState = 4;																			//name input on
		}
		else if (mx >= 75 && mx <= 376 && my >= 146 && my <= 195)
		{
			gameState = 5;
		}
	}
	if (gameState == 1)
	{
		if (mx >= 28 && mx <= 207 && my >= 803 && my <= 839)
		{
			gameState = -1;
		}
	}if (gameState == 2)
	{
		if (mx >= 28 && mx <= 207 && my >= 803 && my <= 839)
		{
			gameState = -1;
		}
	}
	if (gameState == 3)
	{
		if (mx >= 28 && mx <= 207 && my >= 803 && my <= 839)
		{
			gameState = -1;
		}
	}if (gameState == 4)
	{
		if (mx >= 28 && mx <= 207 && my >= 803 && my <= 839)
		{
			gameState = -1;
		}
	}
	if (gameState == 2)
	{
		if (mx >= 508 && mx <= 646 && my >= 482 && my <= 564)
		{
			if (musicOn){
				musicOn = true;
				PlaySound(0, 0, 0);
			}
			
		}
	}
	if (gameState == 2)
	{
		if (mx >= 508 && mx <= 643 && my >= 586 && my <= 671)
		{
		if(musicOn){
			musicOn = true;
			PlaySound("D:\\MEGLADONIA\\MEGLADONIA\\beginning.wav", NULL, SND_LOOP | SND_ASYNC);
		}

		}
	}


	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/


void iKeyboard(unsigned char key)
{
	if (key == 'p')
	{
		iPauseTimer(0);
	

	}
	if (key == 'r')
	{
		iResumeTimer(0);
	}

}

/*
function iSpecialKeyboard() is called whenver user hits special keys like-
function keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_UP)
	{
		sharkCordinateY += 10;

		sharkIndex++;
		if (sharkIndex >= 8)
			sharkIndex = 0;
		standPos = false;
		
	}
	else  if (key == GLUT_KEY_DOWN)
	{
		sharkCordinateY -= 10;
		sharkIndex++;
		if (sharkIndex >= 8)
			sharkIndex = 0;
		standPos = false;

	}
	else if (key == GLUT_KEY_RIGHT)
	{
		sharkCordinateX += 10;

		sharkIndex++;
		if (sharkIndex >= 8)
			sharkIndex = 0;
		standPos = false;

	}
	else if (key == GLUT_KEY_LEFT)
	{
		sharkCordinateX -= 10;
		sharkIndex++;
		if (sharkIndex >= 8)
			sharkIndex = 0;
		standPos = false;
	}

	else if (key == GLUT_KEY_HOME)
	{

	}

}








void change()
{
	for (int i = 0; i < FISHNUMBER; i++)
	{
		enemy[i].fishX -= 10;
		if (enemy[i].fishX <= 0)
		{
			enemy[i].fishX = iScreenWidth + rand() % 300;
		}
		enemy[i].fishIndex++;
		if (enemy[i].fishIndex >= 10)
		{
			enemy[i].fishIndex = 0;
		}
	}
	for (int i = 0; i < FISHNUMBER2; i++)
	{
		enemy1[i].fishX -= 10;
		if (enemy1[i].fishX <= 0)
		{
			enemy1[i].fishX = iScreenWidth + rand() % 300;
		}
		enemy1[i].fishIndex++;
		if (enemy1[i].fishIndex >= 10)
		{
			enemy1[i].fishIndex = 0;
		}
	}


}






void setEnemeyVariable()
{
	for (int i = 0; i < FISHNUMBER; i++)
	{
		enemy[i].fishX = iScreenWidth + rand() % 300;
		enemy[i].fishY = 200 + rand() % 300;
		enemy[i].fishIndex = rand() % 10;
		enemy[i].fishShow = true;
	}
	for (int i = 0; i < FISHNUMBER2; i++)
	{
		enemy1[i].fishX = iScreenWidth + rand() % 300;
		enemy1[i].fishY = 300 + rand() % 500;
		enemy1[i].fishIndex = rand() % 10;
		enemy1[i].fishShow = true;
	}
}



void readScore(){
	FILE *fs;
	fs = fopen("Highscore.txt", "r");
	if (fs == NULL)
	{
		printf("File not found!");
	}
	//reading file------------------------------------------------------------------------
	int i = 0;
	while ((fscanf(fs, "%d", &loadScore)) != EOF){
		arr[i++] = loadScore;
	}



	//bubble sorting ---------------------------------------------------------------
	int temp;
	for (int i = 1; i<3; ++i)
	for (int j = 0; j<i; ++j)
	if (arr[j]>arr[i]){
		temp = arr[j];
		arr[j] = arr[i];
		arr[i] = temp;
	}
	//---------------------------------------------------------------------------------

	//fscanf(fs, "%d", &loadScore);
	int j = 2;
	//int tmp = loadScore;
	int tmp = arr[2];
	while (j >= 0){
		readHighScore[j] = tmp % 10 + '0';
		tmp = tmp / 10;
		j--;
	}


	j = 2;
	tmp = arr[1];
	while (j >= 0){
		showSecond[j] = tmp % 10 + '0';
		tmp = tmp / 10;
		j--;
	}
	j = 2;
	tmp = arr[0];
	while (j >= 0){
		showThird[j]= tmp % 10 + '0';
		tmp = tmp / 10;
		j--;
	}

	fclose(fs);
}











int main()

{
	if (musicOn)
	{
		PlaySound("D:\\MEGLADONIA\\MEGLADONIA\\beginning.wav", NULL, SND_LOOP | SND_ASYNC);
	}
	//iSetTimer(7000, sound_f);
	
	setEnemeyVariable();
	iSetTimer(150, change);
	int sum = 25;
	for (int i = 3; i >= 0; i--)
	{
		bCordinate[i].x = 25;
		bCordinate[i].y = sum;
		sum += 110;
	}
	

	iInitialize(1600, 850, "Megalodonia");
	a = iLoadImage("D:\\MEGLADONIA\\MEGLADONIA\\button456\\food2.png");
	e = iLoadImage("D:\\MEGLADONIA\\MEGLADONIA\\button456\\enemyfish.png");
	c = iLoadImage("D:\\MEGLADONIA\\MEGLADONIA\\button456\\MEGALODONIA_2.jpg");
	s = iLoadImage("D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\Settings.jpg");
	h = iLoadImage("D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\Highscore (1).jpg");
	about = iLoadImage("D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\About.jpg");
	in = iLoadImage("D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\Ins.jpg");
	gameOver = iLoadImage("D:\\MEGLADONIA\\MEGLADONIA\\button456\\GAMEOVER.jpg");
	x = iLoadImage("D:\\MEGLADONIA\\MEGLADONIA\\button456\\life\\Press_R_to_continue.jpg");



	

	iStart();





	return 0;
}