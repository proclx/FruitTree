#include <iostream>
#include "FruitTree.h"
#include <fstream>

using std::cout;
using std::cin;

int main()
{
    std::ifstream fin("trees.txt");
    int year;
    fin >> year;
    setGlobalYear(year);
    unsigned length;
    fin >> length;
    FruitTree* fruitTrees = new FruitTree[length];
    for (int i = 0; i < length; ++i)
    {
        fin >> fruitTrees[i];
    }
    fin.close();
    for (int i = 0; i < length; ++i)
    {
        cout << fruitTrees[i];
    }
    std::ofstream fout("output.txt");
    int newSize = 0;
    FruitTree* onlyProdTrees = onlyProductive(fruitTrees, length, newSize);
    for (int i = 0; i < newSize; ++i)
    {
        fout << onlyProdTrees[i];
    }
    fout.close();
    delete[] fruitTrees;
    fruitTrees = nullptr;
    delete[] onlyProdTrees;
    onlyProdTrees = nullptr;
    system("pause");
    return 0;
}