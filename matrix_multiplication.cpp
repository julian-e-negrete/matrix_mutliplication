#include <iostream>

#include <vector>

std::vector<std::vector<int>>  EnterMatrix();
void printMatrix(std::vector<std::vector<int>>& par_matrix);
void invertMatrix(std::vector<std::vector<int>>& par_matrix);
std::vector<std::vector<int>> multiply_matrix(std::vector<std::vector<int>>& par_matrix1, std::vector<std::vector<int>>& par_matrix2);



int main()
{
    using namespace std;

    int rows = 2 , cols= 2;

    std::vector<std::vector<int>> matrix1(rows, std::vector<int>(cols, 0));
    std::vector<std::vector<int>> matrix2(rows, std::vector<int>(cols, 0));

    matrix1 = EnterMatrix();

    matrix2 = EnterMatrix();

    /*
    matrix1 =   {{1, 2},
                 {3, 4}};

    matrix2 =   {{5, 6},
                 {7, 8}};
    */
   
    if(matrix1[0].size() != matrix2.size())
    {
        std::cout << "the columns of the matrix1 is diferent from the rows of the matrix2 therefore the multiplication is imposible ";
        return 1;
    }    
   
    std::vector<std::vector<int>> result_matrix(matrix1.size(), std::vector<int>(matrix2[0].size(), 0));
    result_matrix = multiply_matrix(matrix1, matrix2);
    printMatrix(result_matrix);
    return 0;
}


std::vector<std::vector<int>>  EnterMatrix()
{
    using namespace std;

    system("cls");
    
    int rows, cols;

    cout << "Enter the number of rows of the matrix : ";
    cin >> rows;
    cout << "Enter the number of columns of the matrix : ";
    cin >> cols;


    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols, 0));

    system("cls");

    for(int i = 0; i < rows; i++)
    {
        cout << "row : " << i << endl;
        for (int j = 0; j < cols; j++)
        {
            cout << "col : " << j << endl;
            cout << "Enter the value: ";
            cin >> matrix[i][j];
        }
    }


    return matrix;
}

void printMatrix(std::vector<std::vector<int>>& par_matrix)
{
    system("cls");
    using namespace std;

    for(int i = 0; i < par_matrix.size(); i++)
    {   
        cout << "[ ";
        for(int j = 0; j < par_matrix[0].size(); j++)
        {
            cout << par_matrix[i][j] << " ";
        }
        cout << "]" << endl;
    }
}

void invertMatrix(std::vector<std::vector<int>>& par_matrix)
{
    std::vector<std::vector<int>> inv_matrix(par_matrix[0].size(), std::vector<int>(par_matrix.size()));
    
    for(int i = 0; i < par_matrix.size(); i++)
    {      
        for(int j = 0; j < par_matrix[0].size(); j++)
        {
            inv_matrix[j][i] = par_matrix[i][j];
        }
    }
    

    par_matrix = inv_matrix;
}

std::vector<std::vector<int>> multiply_matrix(std::vector<std::vector<int>>& par_matrix1, std::vector<std::vector<int>>& par_matrix2)
{

    std::vector<std::vector<int>> result_matrix(par_matrix1.size(), std::vector<int>(par_matrix2[0].size()));

    for(int i = 0; i < par_matrix1.size();i++)
    {
        for (int j = 0; j < par_matrix2[0].size();j++)
        {
            result_matrix[i][j] = 0;
            for(int k = 0; k < par_matrix1[0].size();k++)
            {
                result_matrix[i][j] += par_matrix1[i][k] * par_matrix2[k][j];
                //std::cout << par_matrix1[i][k] << " x  " << par_matrix2[k][j] << std::endl;
            }
            //std::cout << par_matrix1[i][i] << " x  " << par_matrix2[j][i] << std::endl;
        }
    }

    
    /* 
    // rows
    for(int i = 0; i < par_matrix1.size(); i++)
    {
        for(int j = 0; j < par_matrix2[0].size();j++)
        {
            std::cout << par_matrix1[i][j] << " x " << par_matrix2[j][i] << std::endl;
        }
    }
    */

    return result_matrix;
}