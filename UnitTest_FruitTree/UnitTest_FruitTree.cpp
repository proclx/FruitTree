#include "pch.h"
#include "CppUnitTest.h"
#include "../FruitTree/FruitTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
namespace UnitTestFruitTree
{
	TEST_CLASS(UnitTestFruitTree)
	{
	public:
		TEST_METHOD(CreateDefaultTree)
		{
			setGlobalYear(0);
			FruitTree Default;
			Assert::IsTrue(Default.getName() == "");
			Assert::IsTrue(Default.getPlantingYear() == 0);
			Assert::IsTrue(Default.getTreeAge() == 0);
			Assert::IsTrue(Default.getTreeProductivity() == 0);
			Assert::IsTrue(Default.getHeigth() == 0);
			Assert::IsTrue(FruitTree::CURRENT_YEAR == 0);
		}
		TEST_METHOD(CreateCustomTree)
		{
			setGlobalYear(0);
			FruitTree Apple = { "apple tree", 0, 10, 100 };
			Assert::IsTrue(Apple.getName() == "apple tree");
			Assert::IsTrue(Apple.getPlantingYear() == 0);
			Assert::IsTrue(Apple.getTreeAge() == 0);
			// дереву менше ніж 3 роки, воно не приносить плоди
			Assert::IsTrue(Apple.getTreeProductivity() == 0);
			Assert::IsTrue(Apple.getHeigth() == 100);
			Assert::IsTrue(FruitTree::CURRENT_YEAR == 0);
		}
		// тест на дерево з віком 1, урожайність повинна бути 0, а ріст повинен змінитися на 25 см
		TEST_METHOD(CreateCustomTree_1year)
		{
			setGlobalYear(2023);
			FruitTree Apple = { "apple tree", 2022, 10, 100 };
			// дереву менше ніж 3 роки, воно не приносить плоди
			Assert::IsTrue(Apple.getTreeProductivity() == 0);
			// ріст повинен змінитися на 25 см
			Assert::IsTrue(Apple.getHeigth() == 125);
			setGlobalYear(0);
		}
		TEST_METHOD(CreateCustomTree_3year)
		{
			setGlobalYear(2023);
			FruitTree Apple = { "apple tree", 2020, 10, 100 };
			// дереву 3 роки, воно приносить 10 кг плодів, бо зараз на найменшому рівні продуктивності
			Assert::IsTrue(Apple.getTreeProductivity() == 10);
			// ріст повинен змінитися на 75 см
			Assert::IsTrue(Apple.getHeigth() == 175);
			setGlobalYear(0);
		}
		TEST_METHOD(CreateCustomTree_4year)
		{
			setGlobalYear(2023);
			FruitTree Apple = { "apple tree", 2019, 10, 100 };
			// дереву 4 роки, воно приносить 11 кг плодів
			Assert::IsTrue(Apple.getTreeProductivity() == 11);
			// ріст повинен змінитися на 100 см
			Assert::IsTrue(Apple.getHeigth() == 200);
			setGlobalYear(0);
		}
		TEST_METHOD(ChangingGlobalYear)
		{
			setGlobalYear(2023);
			FruitTree Default;
			Assert::IsTrue(Default.getTreeAge() == 2023);
			setGlobalYear(0);
		}
		TEST_METHOD(CompareTrees)
		{
			setGlobalYear(2023);
			FruitTree Younger = { "y", 2020, 10, 100 };
			FruitTree Older = { "o", 2012, 10, 100 };
			Assert::IsTrue(Younger < Older);
			Assert::IsTrue(Younger <= Older);
			Assert::IsFalse(Younger > Older);
			Assert::IsFalse(Younger >= Older);
		}
		TEST_METHOD(CompareSameTrees)
		{
			setGlobalYear(2023);
			// порівняння дерев з однаковою продуктивністю + з різним ростом (не повинен впливати)
			FruitTree First = { "y", 2012, 10, 150 };
			FruitTree Second = { "o", 2012, 10, 100 };
			Assert::IsTrue(First >= Second);
			Assert::IsTrue(First <= Second);
			Assert::IsFalse(First > Second);
			Assert::IsFalse(First < Second);
		}
		TEST_METHOD(FindTheMostProductiveTree)
		{
			//                      ці масиви приводяться до типу FruitTrees
			FruitTree Trees[2] = { { "y", 2020, 10, 100 }, { "o", 2012, 10, 100 } };
			Assert::IsTrue(findTheMostProductive(Trees, 2).getTreeProductivity() == Trees[1].getTreeProductivity());
		}
		TEST_METHOD(FindTheHighest)
		{
			FruitTree Trees[2] = { { "y", 2020, 10, 100 }, { "o", 2012, 10, 100 } };
			Assert::IsTrue(findTheHighest(Trees, 2).getHeigth() == Trees[1].getHeigth());
		}
	};
}
