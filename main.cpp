#include <iostream>

void initializegrid(int *A, int R, int C, int needleX, int needleY, int xpos, int ypos) {

	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			*(A+i*C+j) = 0;
		}
	}

	*(A+ypos*C+xpos) = 1;
	*(A+needleY*C+needleX)= 2;
}

void drawboard(int *A, int R, int C) {


	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if(*(A+i*C+j) == 1) {
				std::cout << " P " ;
			} else if(*(A+i*C+j) == 2) {
				std::cout << " N ";
			} else std::cout << " * " ;
		
		}

		std::cout << std::endl;
	}
}

std::string getNeedlePosition(int xpos, int ypos, int needleX, int needleY) {

	std::string pos;

	if(needleX < xpos && needleY < ypos) pos = "UL";
	else if(needleX > xpos && needleY < ypos) pos = "UR";
	else if(needleX == xpos && needleY < ypos) pos = "U";
	else if(needleX < xpos && needleY == ypos) pos = "L";
	else if(needleX > xpos && needleY == ypos) pos = "R";
	else if(needleX == xpos && needleY > ypos ) pos = "D";
	else if(needleX < xpos && needleY > ypos) pos = "DL";
	else if(needleX > xpos && needleY > ypos) pos = "DR";


	return pos;
}

	

int main() {

	std::cout << "Enter Rows of grid: ";
	int R;
	std::cin >> R;
	std::cout << "Enter Cols of grid: ";
	int C;
	std::cin >> C;

	int A[R][C];

	int needleX = rand() % C;
	int needleY = rand() % R;
	int xpos = rand() % C;
	int ypos = rand() % R;

	initializegrid((int*)A, R, C, needleX, needleY, xpos, ypos);
	drawboard((int*)A, R, C);


	int left = 0;
	int width = C;
	int top = 0;
	int height = R;

	int counter = 0;

	while(true) {

		std::cout << "left: " << left << " width: " << width << " top: " << top << " height: " << height << std::endl;
		//std::string needleposition;

		std::string needleposition = getNeedlePosition(xpos, ypos, needleX, needleY);
		//std::cout << "Enter needle direction : ";
		//std::cin >> needleposition;



		if(needleposition == "U") {
			left = xpos;
			width = xpos;
			height = ypos - 1;

			xpos = (left + width) / 2;
			ypos = (top + height) / 2;

		} else if(needleposition == "UL") {
			width = xpos - 1;
			height = ypos - 1;

			xpos = (left + width) / 2;
			ypos = (top + height) / 2;

		} else if(needleposition == "UR") {
			left = xpos + 1;
			height = ypos - 1;


			xpos = (left + width) / 2;
			ypos = (top + height) / 2;
		} else if(needleposition == "R") {

			left = xpos + 1;
			height = ypos;
			top = ypos;

			xpos = (left + width) / 2;
			ypos = (top + height) / 2;
		} else if(needleposition == "L") {
			width = xpos - 1;
			top = ypos;
			height = ypos;

			xpos = (left + width) / 2;
			ypos = (top + height) / 2;
		} else if(needleposition == "D") {
			left = xpos;
			width = xpos;
			top = ypos + 1;

			xpos = (left + width) / 2;
			ypos = (top + height) / 2;
		} else if (needleposition == "DL") {
			width = xpos - 1;
			top = ypos + 1;

			xpos = (left + width) / 2;
			ypos = (top + height) / 2;
		} else if(needleposition == "DR") {
			top = ypos + 1;
			left = xpos + 1;

			xpos = (left + width) / 2;
			ypos = (top + height) / 2;
		}

		++counter;
		A[ypos][xpos] = 1;

		


		if(xpos == needleX && ypos == needleY) {
			std::cout << "NEEDLE FOUND! AT POSIIION: " << "[" << xpos << " , " << ypos << "]" << std::endl;
			drawboard((int*)A, R, C);
			break;
		} else {
			std::cout << "TURN #: " << counter << std::endl;
			std::cout << "NEEDLE DIERECTION: " << needleposition << std::endl;
			std::cout << "POSITION TAKEN:  " << "[" << xpos << "," << ypos << "]" << std::endl;
			
 		}

 		drawboard((int*)A, R, C);



	}



	return 0;
}