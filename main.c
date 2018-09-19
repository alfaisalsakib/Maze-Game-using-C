#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,x=0,y=0,m,n;
    char maze[12][12];
    int moveCount = 0;

    for(i=0;i<12;i++)
    {
        for(j=0;j<12;j++)
        {
            maze[i][j] = '0';
        }
    }

    // Block:1 input the maze values from file
    FILE *fptr1;
    fptr1 = fopen("Maze.txt","r");
    char c;

    for(m=0;m<12;m++)
    {
        for(n=0;n<12 && (c = fgetc(fptr1)) != EOF;n++)
        {
            maze[m][n] = c;
        }
        printf("\n");
    }

    fclose(fptr1);
    printf("\n");
    // Block:1 input the maze values from file

    // Block:2 print the maze values from file to console
    printf("%42s","<< Maze Puzzle >>\n");

    FILE *fptr;
    fptr = fopen("mazePath.txt","r");

    char path[150];
    while( fgets(path,sizeof path,fptr) != NULL)
    {
        fputs(path,stdout);
    }
    fclose(fptr);
    printf("\n");

    // Block:2 print the maze values from file to console

    // Block:3 User input at will
    maze[y][x] = '>';

    int direction;

    printf("Please Press ::\nR > Right\nL > Left\nU > Up\nD > Down\n");
    while((direction = getchar()) != EOF)
    {
        moveCount++;
        switch(direction)
        {
        case 'r':
        case 'R':
            {
                x++;
                if(maze[y][x] == '0' || x > 11)
                {
                    printf("<<< Ops! wall !!!! >>>\n");
                    x--;
                }
                else
                    maze[y][x] = '>';

                printf("Your Current Progress :: \n");
                    for(i=0;i<12;i++)
                    {
                        for(j=0;j<12;j++)
                        {
                            printf("%c ",maze[i][j]);
                        }
                        printf("\n");
                    }
                break;
            }
        case 'l':
        case 'L':
            {
                x--;
                if(maze[y][x] == '0' || x < 0)
                {
                    printf("<<< Ops! Wall !!!! >>>\n");
                    x++;
                }
                else
                    maze[y][x] = '<';

                printf("Your Current Progress :: \n");
                    for(i=0;i<12;i++)
                    {
                        for(j=0;j<12;j++)
                        {
                            printf("%c ",maze[i][j]);
                        }
                        printf("\n");
                    }
                break;
            }
        case 'U':
        case 'u':
            {
                y--;
                if(maze[y][x] == '0' || y < 0)
                {
                    printf("<<< Ops! Wall !!!! >>>\n");
                    y++;
                }
                else
                    maze[y][x] = '^';

                printf("Your Current Progress :: \n");
                    for(i=0;i<12;i++)
                    {
                        for(j=0;j<12;j++)
                        {
                            printf("%c ",maze[i][j]);
                        }
                        printf("\n");
                    }
                break;
            }
        case 'D':
        case 'd':
            {
                y++;
                if(maze[y][x] == '0' || y > 11)
                {
                    printf("<<< Ops! Wall !!!!\n >>>");
                    y--;
                }
                else
                    maze[y][x] = 'v';

                printf("Your Current Progress :: \n");
                    for(i=0;i<12;i++)
                    {
                        for(j=0;j<12;j++)
                        {
                            printf("%c ",maze[i][j]);
                        }
                        printf("\n");
                    }
                break;
            }
        case '\n':
        case '\t':
        case ' ':
            break;
        case 'p':
        case 'P':
            {
                printf("Your Current Progress :: \n");
                maze[y][x] = '*';
                for(i=0;i<12;i++)
                {
                    for(j=0;j<12;j++)
                    {
                        printf("%c ",maze[i][j]);
                    }
                    printf("\n");
                }
                break;
            }
        default:
            {
                printf("%c is invalid direction \n",direction);
            }
        }

        if(maze[11][11] == '>' && (direction == 'r' || direction == 'R'))
            break;
    }

    // Block:3 User input at will

    printf("\n");

    if(maze[11][11] == '>' && (direction == 'r' || direction == 'R'))
    {
        printf("<<< Congratulation, you have successfully solve the puzzle >>>\n");
        printf("Your entered direction ::\n");
        for(i=0;i<12;i++)
        {
            for(j=0;j<12;j++)
            {
                printf("%c ",maze[i][j]);
            }
            printf("\n");
        }

        printf("You used %d movement to solve the puzzle.\n",moveCount/2);
        printf("Your score :: %.2f\n",((60.0/moveCount)*100));
        printf("<<< Thank you >>>\n\n");
    }
    else
    {
        printf("<<< Ops!! You Lost >>>\n");
        printf("<<< you could not able to solve the puzzle >>>\n");
        printf("<<< Game Over >>>\n");
    }

    return 0;
}
