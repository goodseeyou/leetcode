int deepCheck(int** matrix, int** recordMatrix, int i, int j, int matrixSize, int matrixColSize){
    if(recordMatrix[i][j] != -1){
        return recordMatrix[i][j];
    }
    
    int maxValue = 0;
    
    if(j>0 && matrix[i][j] < matrix[i][j-1]){
        int tmpValue = deepCheck(matrix,recordMatrix, i,j-1,matrixSize,matrixColSize)+1;
        if(tmpValue > maxValue){
            maxValue = tmpValue;
        }
    }
    
    if(j<matrixColSize-1 && matrix[i][j] < matrix[i][j+1]){
        int tmpValue = deepCheck(matrix,recordMatrix, i,j+1,matrixSize,matrixColSize)+1;
        if(tmpValue > maxValue){
            maxValue = tmpValue;
        }
    }
    
    if(i>0 && matrix[i][j] < matrix[i-1][j]){
        int tmpValue = deepCheck(matrix,recordMatrix, i-1,j,matrixSize,matrixColSize)+1;
        if(tmpValue > maxValue){
            maxValue = tmpValue;
        }
    }
    
    if(i<matrixSize-1 &&  matrix[i][j] < matrix[i+1][j]){
        int tmpValue = deepCheck(matrix,recordMatrix, i+1,j,matrixSize,matrixColSize)+1;
        if(tmpValue > maxValue){
            maxValue = tmpValue;
        }
    }
    
    recordMatrix[i][j] = maxValue;
    return recordMatrix[i][j];
}

void freeMatrix(int** matrix, int matrixSize){
    for(int i=0;i<matrixSize;i++){
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(int** matrix, int matrixSize, int matrixColSize){
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<matrixColSize;j++){
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    int** recordMatrix = malloc(matrixSize * sizeof(int*));
    for(int i=0;i<matrixSize;i++){
        recordMatrix[i] = malloc(*matrixColSize * sizeof(int));
        for(int j=0;j<*matrixColSize;j++){
            recordMatrix[i][j] = -1;
        }
    }
    
    int maxValue = 0;
    for(int i=0;i<matrixSize;i++){
        for(int j=0;j<*matrixColSize;j++){
            int tmpValue = deepCheck(matrix, recordMatrix, i, j, matrixSize, *matrixColSize);
            if(tmpValue > maxValue){
                maxValue = tmpValue;
            }
        }
    }
    
    //printMatrix(recordMatrix, matrixSize, *matrixColSize);
    freeMatrix(recordMatrix, matrixSize);
    
    return maxValue+1;
}
