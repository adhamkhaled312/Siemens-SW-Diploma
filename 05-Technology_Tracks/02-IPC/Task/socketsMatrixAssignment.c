#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ROW_COLUMN_COUNT 8

int main()
{
	int sockets[2]; //sockets
	int child;
	int MatrixA[ROW_COLUMN_COUNT][ROW_COLUMN_COUNT], MatrixB[ROW_COLUMN_COUNT][ROW_COLUMN_COUNT], MatrixResults[ROW_COLUMN_COUNT][ROW_COLUMN_COUNT];
	int BuffHalfMatrix[ROW_COLUMN_COUNT / 2 + 1][ROW_COLUMN_COUNT], BuffMatrixResults[ROW_COLUMN_COUNT][ROW_COLUMN_COUNT];
	int row, col, i, j, k;

	//create socket pair for parent and child
	if (socketpair(AF_UNIX, SOCK_STREAM, 0, sockets) < 0)
	{
		perror("opening stream socket pair");
		exit(1);
	}

	//Generate Matricies A and B
	srand(time(NULL));
	for (row = 0; row < ROW_COLUMN_COUNT; row++)
	{
		for (col = 0; col < ROW_COLUMN_COUNT; col++)
		{
			MatrixA[row][col] = rand() / 10000000;
			MatrixB[row][col] = rand() / 10000000;
			MatrixResults[row][col] = 0;
			sleep(0);
		}
	}

	//Print Generated Matricies
	printf("\nMatrix A-->\n\n");
	for (i = 0; i < ROW_COLUMN_COUNT; i++)
	{
		printf("\n");
		for (j = 0; j < ROW_COLUMN_COUNT; j++)
		{
			printf("%d ", MatrixA[i][j]);
		}
	}
	printf("\n\nMatrix B-->\n\n");
	for (i = 0; i < ROW_COLUMN_COUNT; i++)
	{
		printf("\n");
		for (j = 0; j < ROW_COLUMN_COUNT; j++)
		{
			printf("%d ", MatrixB[i][j]);
		}
	}
	printf("\n\n");

	// Create Child Process
	if ((child = fork()) == -1)
		perror("fork");
	else if (child)
	{ /* This is the parent. */

		//TODO: Calculate the first half of the multiplication here
		for(int i = 0; i < ROW_COLUMN_COUNT / 2; i++){
			for(int j = 0; j < ROW_COLUMN_COUNT; j++){
				for(int k = 0; k < ROW_COLUMN_COUNT; k++){
					MatrixResults[i][j] += MatrixA[i][k] * MatrixB[k][j];
				}
			}
		}
		//TODO: Read the results from the child process of the other half
		recv(sockets[1],BuffHalfMatrix,sizeof(BuffHalfMatrix),0);
		//Merge Results
		k = 0;
		for (i = ROW_COLUMN_COUNT / 2; i < ROW_COLUMN_COUNT; i++)
		{
			for (j = 0; j < ROW_COLUMN_COUNT; j++)
			{
				MatrixResults[i][j] = BuffHalfMatrix[k][j];
			}
			k++;
		}

		//Print Results in Parent
		printf("\n\nMatrixResults-->\n\n");
		for (i = 0; i < ROW_COLUMN_COUNT; i++)
		{
			printf("\n");
			for (j = 0; j < ROW_COLUMN_COUNT; j++)
			{
				printf("%d ", MatrixResults[i][j]);
			}
		}
		printf("\n\n\n");

		//TODO: Send Results to Child
		send(sockets[1],MatrixResults,sizeof(MatrixResults),0);

		close(sockets[1]);
	}
	else
	{ /* This is the child. */
		int tempBuff[ROW_COLUMN_COUNT / 2 + 1][ROW_COLUMN_COUNT];

		for (i = 0; i < ROW_COLUMN_COUNT / 2 + 1; i++)
		{
			for (j = 0; j < ROW_COLUMN_COUNT; j++)
			{
				tempBuff[i][j] = 0;
			}
		}

		//TODO: Calculate Results for the other half in child process
		for(int i = 0; i < ROW_COLUMN_COUNT / 2; i++){
			for(int j = 0; j < ROW_COLUMN_COUNT; j++){
				for(int k = 0; k < ROW_COLUMN_COUNT; k++){
					tempBuff[i][j] += MatrixA[i + ROW_COLUMN_COUNT/2][k] * MatrixB[k][j];
				}
			}
		}
		//TODO: Send it back to parent
		send(sockets[0],tempBuff,sizeof(tempBuff),0);
		//TODO: Read whole results here to print
		recv(sockets[0],BuffMatrixResults,sizeof(BuffMatrixResults),0);
		//Print Results in Child
		printf("\n\nMatrixResults at child-->\n\n");
		for (i = 0; i < ROW_COLUMN_COUNT; i++)
		{
			printf("\n");
			for (j = 0; j < ROW_COLUMN_COUNT; j++)
			{
				printf("%d ", BuffMatrixResults[i][j]);
			}
		}
		printf("\n");
		close(sockets[0]);
	}
}
