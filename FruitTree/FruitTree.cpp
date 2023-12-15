#include "FruitTree.h"
#include <iostream>
#include <queue>
int FruitTree::CURRENT_YEAR = 0;

std::ostream& operator<<(std::ostream& out, const FruitTree& T)
{
	T.writeTo(out);
	return out;
}

std::istream& operator>>(std::istream& in, FruitTree& T)
{
	T.readFrom(in);
	return in;
}

// ������ ��
bool setGlobalYear(const int year)
{
	// year != 0 ��� ��������� �����, �� ������ �� ���� ��������� �������� ����� year
	if (year < FruitTree::CURRENT_YEAR and year != 0)
	{
		return false;
	}
	else
	{
		FruitTree::CURRENT_YEAR = year;
		return true;
	}
}

FruitTree findTheMostProductive(const FruitTree* Trees, int length)
{
	int maxIndex = 0;
	for (int i = 1; i < length; ++i)
	{
		if (Trees[maxIndex] < Trees[i]) maxIndex = i;
	}
	return Trees[maxIndex];
}

FruitTree findTheHighest(const FruitTree* Trees, int length)
{
	int maxIndex = 0;
	for (int i = 1; i < length; ++i)
	{
		if (Trees[maxIndex].getHeigth() < Trees[i].getHeigth()) maxIndex = i;
	}
	return Trees[maxIndex];
}

FruitTree* onlyProductive(const FruitTree* Trees, int length, int& newLength)
{
	std::queue <FruitTree> T;
	for (int i = 0; i < length; ++i)
		if (Trees[i].getTreeProductivity() != 0) T.push(Trees[i]), ++newLength;
	FruitTree* res = new FruitTree[newLength];
	for (int i = 0; i < newLength; ++i)
		res[i] = T.front(), T.pop();
	return res;
}

double FruitTree::update_productivity() const
{
	if (getTreeAge() < START_YEAR) return 0.0;
	else return (getTreeAge() - START_YEAR) * PRODUCTIVITY_CHANGE + tree_productivity;
}

double FruitTree::update_height() const
{
	return tree_heigth + getTreeAge() * GROW_CHANGE;
}

FruitTree::FruitTree() : tree_name(""), tree_planting_year(0), tree_productivity(0), tree_heigth(0) {}

FruitTree::FruitTree(const std::string& name, int year, double productivity, double heigth) : tree_name(name),
tree_planting_year(year), tree_productivity(productivity), tree_heigth(heigth) {}


// ��� ����� �� ���������, �� ������� �� ��� ������
std::string FruitTree::getName() const
{
	return tree_name;
}

// �� ������� ����� �� ���������
int FruitTree::getPlantingYear() const
{
	return tree_planting_year;
}

// this->update(); ������� ���������� ��� ������, ���� �� const 
double FruitTree::getTreeProductivity() const
{
	return update_productivity();
}

// �� ������ ������������ ��������
int FruitTree::getTreeAge() const
{
	return (CURRENT_YEAR - tree_planting_year);
}

// ��� ������ ��������
double FruitTree::getHeigth() const
{
	return update_height();
}

void FruitTree::writeTo(std::ostream& out) const
{
	out << "Tree: " << tree_name << '\n';
	out << "Heigth: " << update_height() << '\n';
	out << "Productivity: " << update_productivity() << '\n';
	out << "Age: " << getTreeAge() << '\n';
}

void FruitTree::readFrom(std::istream& in)
{
	in >> tree_name >> tree_heigth >> tree_productivity >> tree_planting_year;
}
