#include <stdio.h>
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))

int returnMax(int* array, size_t size)
{
    int max = array[0];
    for(size_t i = 1; i < size; i++)
        {
        if(max < array[i]){
            max = array[i];
        }
    }
    return max;
}

int returnMin(int* array, size_t size)
{
    int min = array[0];
    for(size_t i = 1; i < size; i++)
        {
        if(min > array[i]){
            min = array[i];
        }
    }
    return min;
}

float returnAverage(int* array, int size)
{
    int total = 0;
    for(size_t i = 0; i < size; i++)
    {
        total += array[i];
    }
    float average = (float)total / size;
    return average;
}

int returnHighScore(int subject_size, int student_size, int array[subject_size][student_size])
{
    int high_score = 0;
    int total_score[5] = {0, 0, 0, 0, 0};
    for(int i = 0; i < student_size; i++)
    {
        for(int k = 0; k < subject_size; k++)
        {
            total_score[i] += array[k][i];
        }

        if(high_score < total_score[i])
            {
                high_score = total_score[i];
            }
    }
    return high_score;
}

int main(void){

    char students [5] = {"ABCDE"};

    int score [2][5] = {
        {72, 88, 72, 81, 68},
        {48, 39, 91, 82, 78}
    };

    int math [5] = {score[0][0], score[0][1], score[0][2], score[0][3], score[0][4]};
    int physics [5] = {score[1][0], score[1][1], score[1][2], score[1][3], score[1][4]};

    for(int i = 0; i < SIZE_OF_ARRAY(students); i++)
    {
        char student = students[i];
        int math_score = score[0][i];
        int physics_score = score[1][i];
        printf("%c\n数学 :%d点\n物理 :%d点\n\n", student, math_score, physics_score);
    }

    printf("数学の最高点: %d点\n", returnMax(math, SIZE_OF_ARRAY(math)));
    printf("数学の最低点: %d点\n", returnMin(math, SIZE_OF_ARRAY(math)));
    printf("数学の平均点: %.1f点\n", returnAverage(math, SIZE_OF_ARRAY(math)));
    printf("物理の最高点: %d点\n", returnMax(physics, SIZE_OF_ARRAY(math)));
    printf("物理の最低点: %d点\n", returnMin(physics, SIZE_OF_ARRAY(physics)));
    printf("物理の平均点: %.1f点\n",  returnAverage(physics, SIZE_OF_ARRAY(physics)));
    printf("数学と物理の合計が最も高い生徒の点数: %d点\n", returnHighScore(SIZE_OF_ARRAY(score), SIZE_OF_ARRAY(score[0]), score));

    return 0;
}