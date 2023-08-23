#include "Matrix.h"
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

template<class T>

NUM getCost(Matrix& matrix, size_t x, size_t y, vector<bool>& colUsed);

void run(Matrix& matrix, vector<size_t>& assignedJobs);
int main()
{
    Matrix matrix;
    matrix.setMatrix(N);
    matrix.print();

    vector<size_t> assignedJobs;

    run(matrix, assignedJobs);
    cout << assignedJobs[0];
    return 0;
}
NUM getCost(Matrix& matrix, size_t x, size_t y, vector<bool>& colUsed)
{
    NUM pathCost = matrix.matrix[x++][y];

    for (size_t col = 0; col < matrix.size(); col++)
    {
        if (!colUsed.at(col))
        {
            NUM min =
            #if defined NUM_INT
                        INT_MAX;
            #endif
            #if defined NUM_DBL
                        DBL_MAX;
            #endif
            size_t row = x;
            for (; row < matrix.size(); row++)
            {
                if (min > matrix.matrix[row][col])
                {
                    min = matrix.matrix[row][col];
                }
            }
            pathCost += min;
        }

    }
    return pathCost;
}

void run(Matrix& matrix, vector<size_t>& assignedJobs)
{
    vector<bool> colUsed;
    for (size_t i = 0; i < matrix.size(); i++)
    {
        colUsed.push_back(false);
    }

    for (size_t row = 0; row < matrix.size(); row++)
    {
        size_t col = 0;
        while (colUsed.at(col++)); col--;
        vector<NUM> jobs;
        jobs.push_back(getCost(matrix, col, row, colUsed));
        vector<NUM>::iterator i_min = min_element(jobs.begin(), jobs.end());
        size_t index = (size_t)distance(jobs.begin(), i_min);

        colUsed.at(index) = true;
        assignedJobs.push_back(index);
    }
}
