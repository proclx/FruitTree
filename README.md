# FruitTree
Статична змінна CURRENT_YEAR контролює рік, який потім впливає на обчислення висоти та плодовитості дерев, для зміни CURRENT_YEAR, використовується функція setGlobalYear, яка в якості аргумету приймає рік на який потрібно перейти (аргумент має бути більшим за рік у якому зараз ми знаходиомся)

getName() - отримати імя дерева

getPlantingYear() - рік коли дерево висаджено

getTreeProductivity() - отримати урожайність дерева, метод викликає інший приватний метод (я розумію що це не обовязково, але вирішив показати як це зробити) update_productivity(), який повертає продуктивність розраховану по формулі: якщо вік дерева менший за значення START_YEAR (вік з якого дерево починає плодоносити), тоді метод поверне нуль, якщо більше ніж START_YEAR, тоді метод повернет продуктивність дерева(в полі tree_productivity записано значення яке буде плодовитістю дерева як тільки воно досягне віку START_YEAR) + PRODUCTIVITY_CHANGE * (вік дерева - START_YEAR). Приклад: дерево 2020 року, плодовитість - 10кг, рік(CURRENT_YEAR) - 2023, тоді метод getTreeProductivity() поверне 10, бо цьому дереву 3 роки, воно щойно досягло віку START_YEAR і його плодовитість = 10 (плодовитість не збільшується в такому віці), якщо поставити setGlobalYear(2024), тоді getTreeProductivity() поверне 11, бо продуктивність вже почала зростати

update_height() - ріст дерева, розрахований по формулі початковий ріст + GROW_CHANGE(те на скільки змінюється ріст щороку) * вік дерева

getTreeAge() - вік дерева

writeTo(), readFrom() - методи виведення

Перезагружені оператори < <= > >=

Перезагружені оператори << >>

функція findTheMostProductive() - повертає значення найплодовитішого дерева

findTheHighest() - повертає найвище дерево

onlyProductive() - повертає масив типу FruitTree дерев, які досягли плодовитого віку

До всі функцій та методів, окрім останньої функці написані модульні тести
