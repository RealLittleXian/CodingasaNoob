// Claude-3.7-Sonnet-Reasoning

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 100

// 定义方向：右(R)、下(D)、左(L)、上(U)
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char dir[4] = {'R', 'D', 'L', 'U'};

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point pos;
    int g;  // 从起点到当前点的距离
    int h;  // 当前点到终点的估计距离
    int f;  // f = g + h
} AStarNode;

// DFS相关变量
bool visited[MAX_SIZE][MAX_SIZE];
bool keyFound = false;
int keyPathLen = 0;

// DFS找钥匙
void dfs(char **maze, int height, int width, int x, int y, int steps) {
    // 如果找到钥匙
    if (maze[x][y] == '$') {
        keyFound = true;
        keyPathLen = steps;
        return;
    }
    
    // 按右(R)、下(D)、左(L)、上(U)的顺序探索
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if (nx >= 0 && nx < height && ny >= 0 && ny < width && 
            (maze[nx][ny] == '0' || maze[nx][ny] == '$') && !visited[nx][ny]) {
            
            visited[nx][ny] = true;
            printf("->%c", dir[i]);
            
            dfs(maze, height, width, nx, ny, steps + 1);
            
            // 如果找到钥匙，则结束
            if (keyFound) return;
            
            // 回溯
            visited[nx][ny] = false;
            printf("->%c", dir[(i + 2) % 4]); // 输出回退方向
        }
    }
}

/* 使用DFS算法找到钥匙'$'，输出每次移动的方向以及最后的路径长度 */
void findKey(char **maze, int width, int height, int startX, int startY) {
    memset(visited, 0, sizeof(visited));
    keyFound = false;
    keyPathLen = 0;
    
    visited[startX][startY] = true;
    dfs(maze, height, width, startX, startY, 0);
    
    printf("\n%d\n", keyPathLen);
}

/* 返回两点之间的曼哈顿距离 */
int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

// 比较A*节点的函数，用于优先队列排序
int compareAStarNodes(const void *a, const void *b) {
    AStarNode *nodeA = (AStarNode *)a;
    AStarNode *nodeB = (AStarNode *)b;
    
    if (nodeA->f != nodeB->f) {
        return nodeA->f - nodeB->f; // 优先选择f值较小的
    }
    if (nodeA->pos.x != nodeB->pos.x) {
        return nodeB->pos.x - nodeA->pos.x; // f值相同时，优先选择x值较大的
    }
    return nodeB->pos.y - nodeA->pos.y; // x值也相同时，优先选择y值较大的
}

/* 使用A*算法寻找出口'#'，输出每次扩展的点以及最后的路径 */
void findDoor(char **maze, int width, int height, int startX, int startY, int endX, int endY) {
    AStarNode openList[MAX_SIZE * MAX_SIZE];
    int openCount = 0;
    bool closedList[MAX_SIZE][MAX_SIZE] = {false};
    Point parent[MAX_SIZE][MAX_SIZE]; // 存储每个点的父节点坐标
    
    // 初始化起点
    AStarNode startNode = {
        .pos = {startX, startY},
        .g = 0,
        .h = manhattan(startX, startY, endX, endY),
        .f = manhattan(startX, startY, endX, endY) // f = g + h
    };
    
    openList[openCount++] = startNode;
    bool pathFound = false;
    
    while (openCount > 0 && !pathFound) {
        // 按照代价函数排序
        qsort(openList, openCount, sizeof(AStarNode), compareAStarNodes);
        
        // 取出代价最小的节点
        AStarNode current = openList[0];
        
        // 移除当前节点
        for (int i = 0; i < openCount - 1; i++) {
            openList[i] = openList[i + 1];
        }
        openCount--;
        
        int x = current.pos.x;
        int y = current.pos.y;
        
        // 输出当前扩展的点
        printf("->(%d,%d)", x, y);
        
        // 如果找到出口
        if (x == endX && y == endY) {
            pathFound = true;
            break;
        }
        
        closedList[x][y] = true;
        
        // 探索四个方向
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 检查是否在迷宫范围内，是否可通行
            if (nx >= 0 && nx < height && ny >= 0 && ny < width && 
                (maze[nx][ny] == '0' || maze[nx][ny] == '#') && !closedList[nx][ny]) {
                
                int ng = current.g + 1;
                bool inOpenList = false;
                
                // 检查是否已在openList中
                for (int j = 0; j < openCount; j++) {
                    if (openList[j].pos.x == nx && openList[j].pos.y == ny) {
                        inOpenList = true;
                        // 如果新路径更短，则更新
                        if (ng < openList[j].g) {
                            openList[j].g = ng;
                            openList[j].f = ng + openList[j].h;
                            parent[nx][ny] = (Point){x, y};
                        }
                        break;
                    }
                }
                
                // 如果不在openList中，则添加
                if (!inOpenList) {
                    AStarNode newNode = {
                        .pos = {nx, ny},
                        .g = ng,
                        .h = manhattan(nx, ny, endX, endY),
                        .f = ng + manhattan(nx, ny, endX, endY)
                    };
                    openList[openCount++] = newNode;
                    parent[nx][ny] = (Point){x, y};
                }
            }
        }
    }
    
    // 如果找到路径，输出路径
    if (pathFound) {
        printf("\n");
        
        // 回溯路径
        int x = endX, y = endY;
        Point path[MAX_SIZE * MAX_SIZE];
        int pathSize = 0;
        
        while (!(x == startX && y == startY)) {
            path[pathSize++] = (Point){x, y};
            Point p = parent[x][y];
            x = p.x;
            y = p.y;
        }
        path[pathSize++] = (Point){startX, startY};
        
        // 输出路径（逆序）
        for (int i = pathSize - 1; i >= 0; i--) {
            printf("->(%d,%d)", path[i].x, path[i].y);
        }
    }
}

int main() {
    int height, width;
    scanf("%d %d", &height, &width);
    
    char **maze = (char **)malloc(height * sizeof(char *));
    for(int i = 0; i < height; i++) {
        maze[i] = (char *)malloc((width + 1) * sizeof(char)); // +1 for null terminator
        scanf("%s", maze[i]);
    }
    
    int startX = -1, startY = -1;
    int keyX = -1, keyY = -1;
    int endX = -1, endY = -1;
    
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maze[i][j] == '*') {
                startX = i;
                startY = j;
            } else if (maze[i][j] == '$') {
                keyX = i;
                keyY = j;
            } else if (maze[i][j] == '#') {
                endX = i;
                endY = j;
            }
        }
    }
    
    findKey(maze, width, height, startX, startY);
    findDoor(maze, width, height, keyX, keyY, endX, endY);
    
    for(int i = 0; i < height; i++) {
        free(maze[i]);
    }
    free(maze);
    
    return 0;
}