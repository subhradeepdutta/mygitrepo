#include <stdio.h>

int IsValid(int x, int y);
int MazeBackTrack(int x, int y, int pathlength);

int num_of_test_cases;
int maze_breadth, maze_length;
int pathlength;
int dest_x,dest_y;
int maze_array[100][100], track_visited[100][100];
int main()
{
	printf("Enter number of test cases");
	scanf("%d",&num_of_test_cases);
	while(num_of_test_cases--)
	{
		printf("Enter size of the maze");
		scanf("%d %d", &maze_length, &maze_breadth);
		pathlength = maze_length * maze_breadth;

		for(int i = 0; i<maze_length; i++)
		{
			for(int j = 0; j<maze_breadth; j++)
			{
				printf("Enter element a[%d][%d]\n",i,j );
				scanf("%d",(*(maze_array+i)+j));
				*(*(track_visited +i ) + j) = 0;
			}
		}
		printf("Enter the target indexes");
		scanf("%d %d", &dest_x,&dest_y);
		MazeBackTrack(0,0,0);
		if(pathlength < (maze_length*maze_breadth))
		{
			printf("%d\n",pathlength);
		}
		else
		{
			printf("-1\n");
		}


	}
	return (0);
}

int IsValid(int x, int y)
{
	if(x >= maze_length || x<0)
		return 0;
	if(y >= maze_breadth || y<0)
		return 0;
	return (1);
}

int MazeBackTrack(int x, int y, int path_length)
{
	if(IsValid(x,y) && *(*(maze_array + x)+y) == 1)
	{
		if(!*(*(track_visited + x)+y))
		{
			*(*(track_visited + x)+y) = 1;
			if(x == dest_x && y == dest_y)
			{
				if(path_length < pathlength)
					pathlength =  path_length;
				*(*(track_visited + x)+y) = 0;
				return;
			}
			MazeBackTrack(x+1,y,path_length+1);
			MazeBackTrack(x-1,y,path_length+1);
			MazeBackTrack(x,y-1,path_length+1);
			MazeBackTrack(x,y+1,path_length+1);
			*(*(track_visited + x)+y) = 0;
		}
		return;
	}
	return;

}