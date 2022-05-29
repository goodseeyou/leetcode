#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define DBL_EPSILON 2.2204460492503131e-016
#define DBL_EPSILON 2.2204460492503131e-010
// need hashmap in the future
struct Node
{
    double m;
    double b;
    int count;
};

struct Node *searchNode(struct Node *nodes[], int size, double m, double b)
{
    for (int i = 0; i < size; i++)
    {
        if (nodes[i] != NULL)
        {
            if (((fabs(nodes[i]->m - m) < DBL_EPSILON) || (nodes[i]->m == INFINITY && m == INFINITY)) && (fabs(nodes[i]->b - b) < DBL_EPSILON))
            {
                // printf("(%lf,%lf) == (%lf,%lf) => (%lf,%lf)\n", nodes[i]->m, nodes[i]->b, m, b, fabs(nodes[i]->m - m), fabs(nodes[i]->b - b));
                return nodes[i];
            }
            else
            {
                // printf("(%lf,%lf) != (%lf,%lf)\n", nodes[i]->m, nodes[i]->b, m, b);
            }

            // if (INFINITY == nodes[i]->m || (fabs(nodes[i]->m) > 5.0) || fabs(nodes[i]->b) > 10.0)
            // {
            //     continue;
            // }
            // char *nm = (char *)malloc(sizeof(char) * 100);
            // char *nb = (char *)malloc(sizeof(char) * 100);
            // sprintf(nm, "%3.9lf", nodes[i]->m);
            // sprintf(nb, "%3.9lf", nodes[i]->b);
            // char *ms = (char *)malloc(sizeof(char) * 100);
            // char *bs = (char *)malloc(sizeof(char) * 100);
            // sprintf(ms, "%3.9lf", m);
            // sprintf(bs, "%3.9lf", b);
            // if (strcmp(nm, ms) == 0 && strcmp(nb, bs) == 0)
            // {
            //     free(nm);
            //     free(nb);
            //     free(ms);
            //     free(bs);
            //     printf("string equal (%5.9lf,%5.9lf)==(%5.9lf,%5.9lf) => diff(%lf,%lf)\n", nodes[i]->m, nodes[i]->b, m, b, fabs(nodes[i]->m - m), fabs(nodes[i]->b - b));
            //     printf("m diff %d, b diff %d\n", (fabs(nodes[i]->m - m) < DBL_EPSILON), (fabs(nodes[i]->b - b) < DBL_EPSILON));
            //     return nodes[i];
            // }
            // free(nm);
            // free(nb);
            // free(ms);
            // free(bs);
        }
    }

    return NULL;
}

int maxPoints(int **points, int pointsSize, int *pointsColSize)
{
    int totalSize;
    if (pointsSize < 2)
    {
        totalSize = 1;
    }
    else
    {
        totalSize = pointsSize * (pointsSize - 1) / 2;
    }

    struct Node *lines[totalSize];
    int len = 0;
    int maxCount = 0;
    int processedCount = 0;

    for (int i = 0; i < pointsSize; i++)
    {
        for (int j = i + 1; j < pointsSize; j++)
        {
            processedCount++;
            int xdiff = points[i][0] - points[j][0];
            double m, b;
            if (xdiff == 0)
            {
                // becauase there is no same points
                m = INFINITY;
                b = points[i][0];
            }
            else
            {
                m = (double)(points[i][1] - points[j][1]) / (double)xdiff;
                // using record to avoid duplicated calculating b in the future
                b = points[i][1] - m * points[i][0];
            }

            // printf("(%d,%d)-(%d,%d) m=%3.3lf, b=%3.3lf\n", points[i][0], points[i][1], points[j][0], points[j][1], m, b);

            struct Node *node = searchNode(lines, len, m, b);
            if (node == NULL)
            {
                // printf("new node, len:%d, m:%lf, b:%lf\n", len, m, b);
                len++;
                node = (struct Node *)malloc(sizeof(struct Node));
                node->m = m;
                node->b = b;
                node->count = 1;
                lines[len - 1] = node;
            }
            else
            {
                node->count++;
            }
            if (node->count > maxCount)
            {
                maxCount = node->count;
            }
            // char *ms = malloc(sizeof(char) * 10);
            // char mm[10] = "3.043";
            // char *bs = malloc(sizeof(char) * 10);
            // char bb[10] = "9.000";
            // sprintf(ms, "%1.3lf", m);
            // sprintf(bs, "%2.3lf", b);
            // if (strcmp(ms, mm) == 0 && strcmp(bs, bb) == 0)
            // {
            //     printf("%d,%d\n", node->count, maxCount);
            //     printf("(%d,%d)-(%d,%d) m=%3.3lf, b=%3.3lf\n", points[i][0], points[i][1], points[j][0], points[j][1], m, b);
            // }
            // free(ms);
            // free(bs);
        }
    }

    for (int i = 0; i < len; i++)
    {
        // printf("%4.2lf, %4.2lf, %4d\n",lines[i]->m, lines[i]->b, lines[i]->count);
    }

    // maxCount = c(n,2)
    printf("points(%d), processed(%d), len(%d), max c(n,2) = %d\n", pointsSize, processedCount, len, maxCount);
    return (int)(1 + sqrt(1 + 8 * maxCount)) / 2;
}
