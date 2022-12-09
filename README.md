# Inventory
1. При запуске приложения первым открывается виджет "Main Menu". В 

нём две кнопки: "New Game" и "Quit". 

2. Нажатие на кнопку "Quit" приводит к закрытию программы. 

3. Нажатие на кнопку "New Game" инициирует начало новой игры. 

4. После нажатия на кнопку новая игра открывается доступ к виджету 

"Game Board". 

6. На игровом поле слева расположен виджет QTableWidget - "Inventory", 

размерностью 3х3, все ячейки таблицы инвентаря квадратной формы. 

7. На игровом поле справа расположен виджет предмета, содержащий предмет 

"Apple", являющийся источником для Drag'n'Drop'a в ячейки Инвентаря. 

Яблоки в этом виджете бесконечные, можно брать из источника и 

перетаскивать в инвентарь неограниченное количество раз. 

8. При перетаскивании яблока из источника в инвентарь оно появляется в 

той ячейке инвентаря, в которую осуществлено перетаскивание. 

Так же возможно перетаскивание предмета внутри ячеек инвентаря. Внутри 

инвентаря предметы перетаскиваются всей пачкой, 

т.е. к примеру, если в ячейке было 3 яблока, перетаскиваются все три. 

9. При повторном перетаскивании яблока из источника в инвентарь в ту 

ячейку, где уже есть яблоко, количество яблок в этой ячейке 

увеличивается на 1. 

Справа снизу от яблока в ячейке инвентаря находится цифра, указывающая 

на количество яблок в ячейке. К примеру, было одно яблоко, цифра 1, 

после перетаскивания стало два яблока, стала цифра два. 

10. При клике правой кнопкой мыши по ячейке инвентаря с яблоком 

происходит уменьшение количества яблок в ячейке. Если там было одно 

яблоко, то картинка яблока 

исчезает. Если яблок больше одного, цифра должна уменьшится на единицу. 

11. Над виджетами "Inventory" и "Object" находится кнопка "Main 

Menu". При нажатии на кнопку игровое поле блокируется и отображается 

виджет, описаный в п. 1. 
