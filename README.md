# Inventory 

1. When starting the application, the "Main Menu" widget opens first. It has two buttons: "New Game" and "Quit". 

 2. Pressing the "Quit" button closes the program. 

 3. Pressing the "New Game" button initiates the start of a new game. 

 4. After clicking on the new game button, access the "Game Board" widget is opened. 

 5. On the playing field on the left is the widget QTableWidget - "Inventory", 3x3 in size, all cells of the inventory table are square. 

6. On the playing field on the right is an item widget containing an item called "Object", which is the source for Drag'n'Drop'a to the Inventory cells. The apples in this widget are infinite, can be taken from the source and dragged into the inventory an unlimited number of times. 

7. When dragging an apple from the source to the inventory, it appears in the inventory cell into which the drag was made. It is also possible to drag an item inside inventory cells. Inside the inventory, items are dragged by the whole pack,  for example, if there were 3 apples in the cell, all three are dragged. 

8. When you re-drag an apple from the source to the inventory to the cell where there is already an apple, the number of apples in this cell is increased by 1. 

To the right below the apple in the inventory cell is a number indicating the number of apples in the cell. For example, there was one apple, the number 1, after dragging there were two apples, the number two became. 

9. When you right-click on an inventory cell with an apple, the number of apples in the cell decreases. If there was one apple, then the picture of the apple disappears. If there are more than one apples, the number should decrease by one. 

10. Above the "Inventory" and "Object" widgets is the "Main Menu" button. When the button is pressed, the playing field is blocked and the widget described in paragraph 1 is displayed.
