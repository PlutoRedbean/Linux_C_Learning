#include <stdio.h>

#define MAX_ROW 5
#define MAX_COL 5

struct point { int row, col; } stack[512];
int top = 0;

void push(struct point p)
{
	stack[top++] = p;
}

struct point pop(void)
{
	return stack[--top];
}

int is_empty(void)
{
	return top == 0;
}

int maze[MAX_ROW][MAX_COL] = {
	0, 1, 0, 0, 0,
	0, 1, 0, 1, 0,
	0, 0, 0, 0, 0,
	0, 1, 1, 1, 0,
	0, 0, 0, 1, 0,
};

void print_maze(void)
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++) {
		for (j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		putchar('\n');
	}
	printf("*********\n");
}

struct point predecessor[MAX_ROW][MAX_COL] = {
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
	{{-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}, {-1,-1}},
};

void visit(int row, int col, struct point pre)
{
	struct point visit_point = { row, col };
	maze[row][col] = 2;
	predecessor[row][col] = pre;
	push(visit_point);
}

int DFS(struct point this_point)
{
    maze[this_point.row][this_point.col] = 2;
	if (this_point.row == MAX_ROW - 1 && this_point.col == MAX_COL - 1) {
        /* goal */
        printf("(%d, %d)\n", this_point.row, this_point.col);
        return 1;
    }

    struct point next_point;
    if (this_point.col+1 < MAX_COL && maze[this_point.row][this_point.col+1] == 0) {
        /* right */
        next_point.row = this_point.row;
        next_point.col = this_point.col + 1;
        if (DFS(next_point)) {
            printf("(%d, %d)\n", this_point.row, this_point.col);
            return 1;
        }
        return 0;
    }
    if (this_point.row+1 < MAX_ROW && maze[this_point.row+1][this_point.col] == 0) {
        /* down */
        next_point.row = this_point.row + 1;
        next_point.col = this_point.col;
        if (DFS(next_point)) {
            printf("(%d, %d)\n", this_point.row, this_point.col);
            return 1;
        }
        return 0;
    }
    if (this_point.col-1 >= 0 && maze[this_point.row][this_point.col-1] == 0) {
        /* left */
        next_point.row = this_point.row;
        next_point.col = this_point.col - 1;
        if (DFS(next_point)) {
            printf("(%d, %d)\n", this_point.row, this_point.col);
            return 1;
        }
        return 0;
    }
    if (this_point.row-1 >= 0 && maze[this_point.row-1][this_point.col] == 0) {
        /* up */
        next_point.row = this_point.row - 1;
        next_point.col = this_point.col;
        if (DFS(next_point)) {
            printf("(%d, %d)\n", this_point.row, this_point.col);
            return 1;
        }
        return 0;
    }

    printf("No path!\n");
    return 0;
}

int main(void)
{
	struct point p = { 0, 0 };

	maze[p.row][p.col] = 2;
	push(p);	
	
	while (!is_empty()) {
		p = pop();
		if (p.row == MAX_ROW - 1  /* goal */
		    && p.col == MAX_COL - 1)
			break;
		if (p.col+1 < MAX_COL     /* right */
		    && maze[p.row][p.col+1] == 0)
			visit(p.row, p.col+1, p);
		if (p.row+1 < MAX_ROW     /* down */
		    && maze[p.row+1][p.col] == 0)
			visit(p.row+1, p.col, p);
		if (p.col-1 >= 0          /* left */
		    && maze[p.row][p.col-1] == 0)
			visit(p.row, p.col-1, p);
		if (p.row-1 >= 0          /* up */
		    && maze[p.row-1][p.col] == 0)
			visit(p.row-1, p.col, p);
		print_maze();
	}
	
	if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
		printf("(%d, %d)\n", p.row, p.col);
		while (predecessor[p.row][p.col].row != -1) {
			p = predecessor[p.row][p.col];
			printf("(%d, %d)\n", p.row, p.col);
		}
	} else
		printf("No path!\n");

	/*------------------递归DFS-------------------*/
	// struct point start_point = {0, 0};
	// DFS(start_point);
    /*--------------------------------------------*/

	/*----------正序打印：存入数组后按正序打印--------*/
	// struct point trail[MAX_ROW * MAX_COL];
    // int i = 0;
	// if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1) {
	// 	while (predecessor[p.row][p.col].row != -1) {
	// 		p = predecessor[p.row][p.col];
    //         trail[i++] = p;
	// 	}
	// } else
	// 	{printf("No path!\n");}

    // for (int j = i - 1; j >= 0; j--) {
    //     printf("(%d, %d)\n", trail[j].row, trail[j].col);
    // }
    // printf("(%d, %d)\n", MAX_ROW - 1, MAX_COL - 1);
    /*--------------------------------------------*/
	/*--正序打印：从(0, 0)开始，找相邻非(-1, -1)打印---*/
    

        
	return 0;
}
