#include<math.h>

// need hashmap in the future
struct Node {
    double keyM;
    double keyB;
    int count;

};

struct Node* searchNode(struct Node* nodes[], int size, double m, double b){
    for(int i=0;i<size;i++){
        
        // comparison between double has issue due to float
        if(nodes[i] != NULL){
          if( (nodes[i]->keyM == m || abs(nodes[i]->keyM - m) < 0.000001) && abs(nodes[i]->keyB - b)<0.000001 ){
            return nodes[i];  
          }
        } 
    }
    
    return NULL;
}

int maxPoints(int** points, int pointsSize, int* pointsColSize){
    int totalSize;
    if(pointsSize < 2){
        totalSize = 1;
    } else{
        totalSize = pointsSize*(pointsSize-1)/2;
    }
    
    struct Node* lines[totalSize];
    int len = 0;
    int maxCount = 0;
    
    for(int i=0;i<pointsSize;i++){
        for(int j=i+1;j<pointsSize;j++){
            int xdiff = points[i][0] - points[j][0];
            double m,b;
            if(xdiff == 0){
                // no same point
                m = INFINITY;
                b = points[i][0];
            } else{
                m = (double)(points[i][1] - points[j][1])/(double) xdiff;
                // using record to avoid duplicated calculating b in the future
                b = points[i][1] - m*points[i][0];
            }
            
            if(abs(m-0.64)<0.0001 && abs(b+1.45)<0.0001){
                printf("(%d,%d)-(%d,%d)=>(%3.2lf,%3.2lf)\n",points[i][0],points[i][1],points[j][0],points[j][1],m,b);
            }
            
            struct Node* node = searchNode(lines, len, m, b);
            if(node == NULL){
                len++;
                node = (struct Node*) malloc(sizeof(struct Node));
                node->keyM = m;
                node->keyB = b;
                node->count = 1;
                lines[len-1] =node;
            } else{
                node->count++;
            }
            if(node->count > maxCount){
                maxCount = node->count;
            }
        }
    }
    
    for(int i=0;i<len;i++){
        //printf("%4.2lf, %4.2lf, %4d\n",lines[i]->keyM, lines[i]->keyB, lines[i]->count);
    }
    //printf("%d", maxCount);
    
    // maxCount = c(n,2)
    return (int) (1+sqrt(1+8*maxCount))/2;
}



