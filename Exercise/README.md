# <u>This exercise of CPP is one exercise of <font color=red>***<<C++ Primer Plus>>***</font></u>.
## This is the exercise that is the most representative I think.
## It includes <font color=red>virtual funcion, multiple inheritance, abstract base class and file I\O</font>.
## I highly recommend this exercise for any CPP beginner.
\
<u><font size = 5>**Requirements of the code**</font></u>\
<font size = 4>There are employee class, manager class, fink class,highfink class.\
The employee class is inherited from ABC(abstract base class).\
The members of ABC includes firstname, lastname and job.\
The methods of ABC contains constructor, destructor, a function that displays all members, a function that outputs all member into a file, a funcion that inputs all information from a file, a function that inputs all member via keyboard, and overloading `<<` and `>>`.\
The members of manager and fink are increased by one each, representing the number of people managed by manager and the people reported by the fink respectively.\
The highfink class is multiple inherited from manage and fink.\
And the main function of this exercise should create a file and receive information from keyboard at the first time the program running. After the first time the program running, the program should display all information in the file. Then save information from the keyboard, and display all information after input.\
So, there are some points coder should pay attention to:
1. The virtual methods inherited from ABC.
2. The initialization of ABC in every derived class.
3. The file operations.

## This exercise can help you master most concepts of CPP.