#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS

#include "variable.h"

#include <iostream>
#include <fstream>
using namespace std;

void scoreBG(){
	int hb = iLoadImage("BackgroundIMG//hsBG.png");
	iShowImage(0, 0, 1100, 500, hb);
}


void saveScore(int new_score){

	ifstream infile;
	infile.open("Score_store.bin");

	for (int i = 0; i < 5; i++){
		infile >> score[i];
	}
	if (score[4] < new_score){
		score[4] = new_score;
	}
	for (int i = 0; i < 4; i++){
		for (int j = i + 1; j < 5; j++){
			if (score[i]<score[j]){
				int tem = score[i];
				score[i] = score[j];
				score[j] = tem;
			}
		}
	}
	infile.close();

	ofstream outfile;
	outfile.open("Score_store.bin");

	for (int i = 0; i < 5; i++){
		outfile << score[i]<<endl;
	}
	outfile.close();
}

void showScore(){
	
	int sx = 650, sy = 320;
	
	ifstream infile;
	infile.open("Score_store.bin");
	for (int i = 0; i<5; i++){
		infile >> score_str[i];
	}
	iSetColor(255, 255, 255);
	iText(sx, sy, score_str[0], GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iText(sx, sy-50, score_str[1], GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iText(sx, sy-100, score_str[2], GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iText(sx, sy-140, score_str[3], GLUT_BITMAP_TIMES_ROMAN_24);
	iSetColor(255, 255, 255);
	iText(sx, sy-190, score_str[4], GLUT_BITMAP_TIMES_ROMAN_24);

	infile.close();
}

#endif