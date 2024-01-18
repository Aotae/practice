#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

#define ROWS 4
#define COLS 4

void transposeMatrix(float** mat,int rows, int cols);
void displayMatrix(float** mat, int rows, int cols);
void createMatrix();
int main(int argc, char* argv[]){
    int option, rows, cols;
    bool transpose = false;
    printf("This is a test file for WSL 2 \n");
    printf("This file is also for preparation of my Intel Open Source Software Development Internship interview.\n");
    while((option = getopt(argc,argv,"abc:t"))!=-1){
        switch(option){
            case 'a':
                printf("Option a\n");
                break;
            case 'b':
                printf("Option b\n");
                break;
            case 'c':
                printf("Option c, %s\n",optarg);
                break;
            case 't':
                printf("Option t: Transpose a Matrix\n");
                transpose = true;
                break;
            case '?':
                if (optopt == 'c') {
                    fprintf(stderr, "Option -%c requires an argument.\n", optopt);
                } else {
                    fprintf(stderr, "Unknown option -%c\n", optopt);
                }
                return EXIT_FAILURE;
            default:
                abort();
        }
    }
    for (int i = optind; i < argc; ++i) {
        printf("Non-option argument: %s\n", argv[i]);
    }
    if(transpose){
        printf("Please input matrix size Rows, Cols\n");
        scanf("%d %d", &rows, &cols);
        float ** matrix = (float**)malloc(rows*sizeof(float*));
        for(int i = 0; i<rows; i++){
            matrix[i] = (float*)malloc(cols*sizeof(float));
        }
        bool correct;
        char YoN;
        printf("Please input your elements:\n");
        while(!correct){
            for(int i = 0; i < rows; ++i){
                for(int j =0; j < cols; ++j){
                    scanf("%f",&matrix[i][j]);
                }
            }
            printf("Is this matrix correct? Y/N: \n");
            displayMatrix(matrix,rows,cols);
            scanf(" %c",&YoN);
            if(YoN == 'Y'){
                correct = true;
            }else{
                correct = false;
                printf("Please re input \n");
            }
        }
        transposeMatrix(matrix, rows, cols);
        printf("Transposed: \n");
        displayMatrix(matrix, rows, cols);

    }

}

void transposeMatrix(float **mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = i + 1; j < cols; ++j) {
            // Swap mat[i][j] and mat[j][i]
            float temp = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = temp;
        }
    }
}

void displayMatrix(float** mat, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%.2f\t", mat[i][j]);
        }
        printf("\n");
    }
}