#include <stdio.h>
#include "Header.h"
int main() 
	{
        FILE* c_file = fopen("C:\\Users\\alex_\\OneDrive\\Рабочий стол\\Задания\\Информатика\\семак 2\\Лаба 10\\my_program.txt", "r");
        if ((c_file = fopen("C:\\Users\\alex_\\OneDrive\\Рабочий стол\\Задания\\Информатика\\семак 2\\Лаба 10\\my_program.txt", "r")) == 0) {
            return -1;
        }
        FILE* f = fopen("C:\\Users\\alex_\\OneDrive\\Рабочий стол\\Задания\\Информатика\\семак 2\\Лаба 10\\my_header.txt", "w");
        if ((f = fopen("C:\\Users\\alex_\\OneDrive\\Рабочий стол\\Задания\\Информатика\\семак 2\\Лаба 10\\my_header.txt", "w")) == 0) {
            return -1;
        }

        header_func(c_file, f);
            fclose(c_file);
            fclose(f);
        return 0;
	}
        
   /* 
     
(



) {} .. 

   */