


typedef struct {
    int** rectangle;
    int rectangleSize;
    
} SubrectangleQueries;


SubrectangleQueries* subrectangleQueriesCreate(int** rectangle, int rectangleSize, int* rectangleColSize) {
    SubrectangleQueries* subrectangleQueries = (SubrectangleQueries*) malloc(sizeof(SubrectangleQueries));
    subrectangleQueries->rectangle = rectangle;
    subrectangleQueries->rectangleSize = rectangleSize;
    
    return subrectangleQueries;
    
}

void subrectangleQueriesUpdateSubrectangle(SubrectangleQueries* obj, int row1, int col1, int row2, int col2, int newValue) {
  for(int i=row1;i<=row2;i++){
      for(int j=col1;j<=col2;j++){
          obj->rectangle[i][j]=newValue;
      }
  }
}

int subrectangleQueriesGetValue(SubrectangleQueries* obj, int row, int col) {
  return obj->rectangle[row][col];
}

void subrectangleQueriesFree(SubrectangleQueries* obj) {
    for(int i=0;i<obj->rectangleSize;i++){
        free(obj->rectangle[i]);
    }
    free(obj->rectangle);
    free(obj);
}

/**
 * Your SubrectangleQueries struct will be instantiated and called as such:
 * SubrectangleQueries* obj = subrectangleQueriesCreate(rectangle, rectangleSize, rectangleColSize);
 * subrectangleQueriesUpdateSubrectangle(obj, row1, col1, row2, col2, newValue);
 
 * int param_2 = subrectangleQueriesGetValue(obj, row, col);
 
 * subrectangleQueriesFree(obj);
*/
