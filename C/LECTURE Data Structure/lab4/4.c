#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max_dis 100000

typedef char vextype[20];

typedef struct {
    int N, E;
    int** matrix;
    vextype* vertex;
} Graph;

Graph createGraph(int n);
int isConnected(Graph g);
void nodeDegree(Graph g, int* node_degree);
double clusteringCoefficient(Graph g);
int Diameter(Graph g);
int Radius(Graph g);
int dijkstra(Graph g, int start, int end, int* path);
void printPath(int d, int* diameter_path, Graph g);

Graph createGraph(int n) {
    Graph g;
    g.N = n;
    g.matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g.matrix[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            g.matrix[i][j] = max_dis;
        }
        g.matrix[i][i] = 0;
    }
    g.vertex = (vextype*)malloc(n * sizeof(vextype));
    return g;
}

int isConnected(Graph g) {
    int* visited = (int*)calloc(g.N, sizeof(int));
    int* queue = (int*)malloc(g.N * sizeof(int));
    int front = 0, rear = 0;
    int count = 0;

    queue[rear++] = 0;
    visited[0] = 1;
    count++;

    while (front < rear) {
        int u = queue[front++];
        for (int v = 0; v < g.N; v++) {
            if (u != v && g.matrix[u][v] != max_dis && !visited[v]) {
                visited[v] = 1;
                queue[rear++] = v;
                count++;
            }
        }
    }

    free(visited);
    free(queue);
    return count == g.N;
}

void nodeDegree(Graph g, int* node_degree) {
    for (int i = 0; i < g.N; i++) {
        int cnt = 0;
        for (int j = 0; j < g.N; j++) {
            if (i != j && g.matrix[i][j] != max_dis)
                cnt++;
        }
        node_degree[i] = cnt;
    }
}

double clusteringCoefficient(Graph g) {
    double sum = 0.0;
    for (int v = 0; v < g.N; v++) {
        int* neighbors = (int*)malloc(g.N * sizeof(int));
        int k = 0;
        for (int u = 0; u < g.N; u++) {
            if (u != v && g.matrix[v][u] != max_dis)
                neighbors[k++] = u;
        }
        if (k < 2) {
            free(neighbors);
            continue;
        }
        int max_possible = k * (k - 1) / 2;
        int actual = 0;
        for (int i = 0; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                if (g.matrix[neighbors[i]][neighbors[j]] != max_dis)
                    actual++;
            }
        }
        sum += (double)actual / max_possible;
        free(neighbors);
    }
    return sum / g.N;
}

int dijkstra(Graph g, int start, int end, int* path) {
    int n = g.N;
    int* dist = (int*)malloc(n * sizeof(int));
    int* prev = (int*)malloc(n * sizeof(int));
    int* visited = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        dist[i] = max_dis;
        prev[i] = -1;
    }
    dist[start] = 0;

    for (int count = 0; count < n; count++) {
        int u = -1, min_dist = max_dis;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min_dist) {
                min_dist = dist[i];
                u = i;
            }
        }
        if (u == -1) break;
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (u != v && g.matrix[u][v] != max_dis) {
                if (!visited[v] && dist[u] + g.matrix[u][v] < dist[v]) {
                    dist[v] = dist[u] + g.matrix[u][v];
                    prev[v] = u;
                }
            }
        }
    }

    int res = dist[end];
    if (res == max_dis) {
        free(dist);
        free(prev);
        free(visited);
        return -1;
    }

    int* temp_path = (int*)malloc(n * sizeof(int));
    int current = end, idx = 0;
    while (current != -1) {
        temp_path[idx++] = current;
        current = prev[current];
    }
    for (int i = 0; i < idx; i++)
        path[i] = temp_path[idx - 1 - i];

    free(temp_path);
    free(dist);
    free(prev);
    free(visited);
    return res;
}

int Diameter(Graph g) {
    int n = g.N;
    int** dist = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
        memcpy(dist[i], g.matrix[i], n * sizeof(int));
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int max_ecc = 0;
    for (int i = 0; i < n; i++) {
        int current_max = 0;
        for (int j = 0; j < n; j++)
            if (i != j && dist[i][j] > current_max)
                current_max = dist[i][j];
        if (current_max > max_ecc)
            max_ecc = current_max;
    }

    for (int i = 0; i < n; i++)
        free(dist[i]);
    free(dist);
    return max_ecc;
}

int Radius(Graph g) {
    int n = g.N;
    int** dist = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        dist[i] = (int*)malloc(n * sizeof(int));
        memcpy(dist[i], g.matrix[i], n * sizeof(int));
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    int min_ecc = max_dis;
    for (int i = 0; i < n; i++) {
        int current_max = 0;
        for (int j = 0; j < n; j++)
            if (i != j && dist[i][j] > current_max)
                current_max = dist[i][j];
        if (current_max < min_ecc)
            min_ecc = current_max;
    }

    for (int i = 0; i < n; i++)
        free(dist[i]);
    free(dist);
    return min_ecc;
}

void printPath(int d, int* path, Graph g) {
    int k = 0;
    printf("Path: ");
    while (path[k + 1] != -1) {
        printf("%s->", g.vertex[path[k]]);
        k++;
    }
    printf("%s\n", g.vertex[path[k]]);
}

int main() {
    int node_num, edge_num;
    scanf("%d %d", &node_num, &edge_num);
    Graph g = createGraph(node_num);
    for (int i = 0; i < node_num; i++)
        sprintf(g.vertex[i], "%d", i);
    for (int i = 0; i < edge_num; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g.matrix[u][v] = w;
        g.matrix[v][u] = w;
    }

    printf("connected: %d\n", isConnected(g));

    int* degree = (int*)malloc(g.N * sizeof(int));
    nodeDegree(g, degree);
    printf("degree distribution:\n");
    for (int i = 0; i < g.N; i++)
        printf("node%s:%d,", g.vertex[i], degree[i]);
    printf("\n");

    printf("clustering coefficient:%f\n", clusteringCoefficient(g));

    if (isConnected(g)) {
        int* path = (int*)malloc(g.N * sizeof(int));
        memset(path, -1, g.N * sizeof(int));
        int fare = dijkstra(g, 1, 3, path);
        printf("the minimum fare between 1 and 3: %d\n", fare);
        printf("Path: ");
        int k = 0;
        while (k < g.N && path[k + 1] != -1)
            printf("%s->", g.vertex[path[k++]]);
        printf("%s\n", g.vertex[path[k]]);
        free(path);

        printf("diameter:%d\n", Diameter(g));
        printf("radius:%d\n", Radius(g));
    }

    return 0;
}