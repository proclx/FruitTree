#pragma once
#include <string>
#include <iostream>
// ������� ���� ������ ���� ������������ �� 0.25 �����
const double GROW_CHANGE = 25;
// �� ��������� � ����� ������ ����� ��������� �����
const int START_YEAR = 3;
// ������ ���������� ��������� ������ (3+ ����) ���� ������������ �� 1 ��
const int PRODUCTIVITY_CHANGE = 1;

class FruitTree
{
private:
	std::string tree_name;
	int tree_planting_year;
	double tree_productivity;
	double tree_heigth;
	double update_productivity() const;
	double update_height() const;
public:
	static int CURRENT_YEAR;
	FruitTree();
	FruitTree(const std::string& name, int year, double productivity, double heigth);
	std::string getName() const;
	int getPlantingYear() const;
	double getTreeProductivity() const;
	int getTreeAge() const;
	double getHeigth() const;
	void writeTo(std::ostream& out) const;
	void readFrom(std::istream& in);
	bool operator<(const FruitTree& T) const { return this->getTreeProductivity() < T.getTreeProductivity(); }
	bool operator<=(const FruitTree& T) const { return this->getTreeProductivity() <= T.getTreeProductivity(); }
	bool operator>(const FruitTree& T) const { return this->getTreeProductivity() > T.getTreeProductivity(); }
	bool operator>=(const FruitTree& T) const { return this->getTreeProductivity() >= T.getTreeProductivity(); }
};
std::ostream& operator<<(std::ostream& out, const FruitTree& T);
std::istream& operator>>(std::istream& in, FruitTree& T);
bool setGlobalYear(const int year);
FruitTree findTheMostProductive(const FruitTree* Trees, int length);
FruitTree findTheHighest(const FruitTree* Trees, int length);
FruitTree* onlyProductive(const FruitTree* Trees, int length, int& newLength);