/* PROGRAM TO PROCESS EXAM SCORES OF A GROUP OF STUDENTS */
/* CSC 301 -> STRUCTURED PROGRAMMING */
/* NAME -> ODUKOYA SEYITAN VICTOR */
/* MATRIC NUMBER -> 20141622 */

#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// FUNCTION TO RETURN THE SUFFIX OF NUMBER POSITION e.g "st" for "1" as in "1st"
char *positionSuffix(int num)
{
	switch (num)
	{
	case 1:
		return "st";
		break;
	case 2:
		return "nd";
		break;
	case 3:
		return "rd";
		break;
	default:
		return "th";
	}
}

void printAnimate(char *textToAnimate)
{
	int i = 0;
	int j = strlen(textToAnimate);
	for (i = 0; i < j; i++)
	{
		putchar(textToAnimate[i]);
		fflush(stdout);
		Sleep( 20 );
	}
}

int main()
{
	printf("******************************************************************************************************************************************************");
	printAnimate("******************************************************************************************************************************************************");
	printAnimate("*\t\t\t\t|\tPROGRAM TO PROCESS THE EXAM SCORES OF A GROUP OF STUDENTS\t|\t\t\t\t\t     *");
	printAnimate("*\t\t\t\t|\t\t CSC 301 ASSIGNMENT (STRUCTURED PROGRAMMING) \t\t|\t\t\t\t\t     *");
	printAnimate("*\t\t\t\t|\t\t STUDENT'S NAME  : ODUKOYA SEYITAN VICTOR \t\t|\t\t\t\t\t     *");
	printAnimate("*\t\t\t\t|\t\t MATRIC NUMBER   : 20141622 \t\t\t\t|\t\t\t\t\t     *");
	printAnimate("*\t\t\t\t|\t\t LECTURER'S NAME : MRS C.0.TINUBU \t\t\t|\t\t\t\t\t     *");
	printAnimate("******************************************************************************************************************************************************");
	printf("******************************************************************************************************************************************************");


	// COLLECTING AND ASSIGNING THE NUMBER OF STUDENTS
	//int noOfStudents = 6;
	int noOfStudents;
	printAnimate("******|\tEnter the NUMBER OF STUDENTS : ");
	scanf("%d", &noOfStudents);
	// COLLECTING AND ASSIGNING THE NUMBER OF EXAM SCORES
	//int noOfExamScores = 6;
	int noOfExamScores;
	printAnimate("\n******|\tEnter the NUMBER OF EXAM SCORES : ");
	scanf("%d", &noOfExamScores);


	//...
	// USING ALREADY ASSIGNED VALUES FROM CODE

	// student name
	/*char nameOfStudent [][10] =
	{
	"Adams",
	"John",
	"Davies",
	"Thomas",
	"Praise",
	"Richard"
	};
	*/

	// student scores
	/*
	float examScore [6][6]=
	{
	{45, 80, 80, 95, 55, 75},
	{60, 50, 70, 75, 55, 80},
	{0, 5, 0, 10, 5, 0},
	{25, 40, 65, 75, 85, 95},
	{90, 85, 100, 95, 90, 90},
	{50, 60, 50, 35, 65, 70}
	};
	*/


	//...
	// COLLECTING VALUES FROM COMMAND LINE INPUT

	int X = noOfStudents;
	int Y = noOfExamScores;

	// declaring two dimensional char array for the Students names
	//char nameOfStudent[X][10];
	int **nameOfStudent = malloc(X * sizeof(int*));
	for (int i = 0; i < 10; i++)
	{
		nameOfStudent[i] = malloc(sizeof(int*) * 10);
	}

	// declaring two dimensional floating point array for the scores
	// float examScore[X][Y];
	float **examScore = malloc(X * sizeof(int*));
	for (int i = 0; i < Y; i++)
	{
		examScore[i] = malloc(sizeof(int*) * Y);
	}

	//variable string to be passed to the printAnimate function
	char textToPrint[150];

	printf("\n");
	// collecting data from cli
	int i, j;
	for (i = 0; i < noOfStudents; i++)
	{
		//collect student name
		int k = i + 1;

		sprintf(textToPrint, "\n******|\tEnter the NAME of %d%s STUDENT : ", (k), positionSuffix(k));
		printAnimate(textToPrint);
		scanf("%s", nameOfStudent[i]);
		sprintf(textToPrint, "\n******| %s\:\n", nameOfStudent[i]);
		printAnimate(textToPrint);

		//collect student scores
		for (j = 0; j < noOfExamScores; j++)
		{
			int l = j + 1;
			
			sprintf(textToPrint, "******| Enter %d%s score : ", (l), positionSuffix(l) );
			printAnimate(textToPrint);
			scanf("%f", &examScore[i][j]);
		}
		printf("\n");
	}


	// DECLARATION AND INITIALIZATION OF CLASS AVERAGE AND STUDENT AVERAGE TO ZERO
	float classAverage = 0;
	float sumOfStudentAverage = 0;


	// TO TEST PRINTING OUT OF NAMES AND SCORES
	/*for (i = 0; i < noOfStudents; i++)
	{
		printf("%s : \n", nameOfStudent[i]);
		printf("Scores: ");
		for (j = 0; j < noOfExamScores; j++)
		{
			printf("%f ", examScore[i][j]);
		}
		printf("\n");
	}*/

	printf("******************************************************************************************************************************************************");
	printAnimate("*     NAMES \t|\tSCORES\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t     *");
	printf("******************************************************************************************************************************************************");

	//TO PRINT SCORES, STUDENT AVERAGE  AND CLASS AVERAGE
	for (i = 0; i < noOfStudents; i++)
	{
		sprintf(textToPrint, "*     %s", nameOfStudent[i]);
		printAnimate(textToPrint);
		//printf("Scores = ");
		float sum = 0;

		for (j = 0; j < noOfExamScores; j++)
		{
			float score = examScore[i][j];
			printf("\t|\t");
			printf("%4.4f", score);
			/*if (j < (noOfExamScores - 1))
			{
				printf(" ");
			}*/
			sum += score;
		}
		float studentAverage = sum / noOfExamScores;
		printf("\n%s\'s Average = %f \n\n", nameOfStudent[i], studentAverage);
		sumOfStudentAverage += studentAverage;
	}

	classAverage = sumOfStudentAverage / noOfStudents;
	printf("The Average Score of all the Students is: %f\n", classAverage);

	scanf("%s");

	return 0;
}
