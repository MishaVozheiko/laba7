#include <iostream>
#include <math.h>
#include <vector>
#include <locale>

int main()
{
    setlocale(0, " ");
    std::vector<double> values;//создаем вектор, генерим туда рандомные числа
    std::vector<double> results;
    double summ = 0;
    rand();//чтобы при каждой компиляции генерировалось новое число
    std::vector<double>::const_iterator iter, lastPos;
    for (int i = 0; i < 10; i++)//заполняем рандомными числами
        if (i % 5 == 0)
            values.push_back(0);//здесь добавляем 1 нолик чтобы гарантированно было нулевое число
        else
            values.push_back(-3 + rand() % 6 + rand() % 100 / 100.0);
    for (double element : values) // Добавляем в вектор числа,модуль которых меньше 1
        if (fabs(element) <= 1)
            results.push_back(element);
    for (double element : values) // Добавляем в вектор числа,модуль которых больше 1
        if (fabs(element) > 1)
            results.push_back(element);

    std::cout << "Ishodnay posledovatelnost:" << std::endl; //печатаем сначала те которые были  сгенерены рандомно
    for (int i = 0; i < values.size(); i++)
        std::cout << values[i] << " | ";
    std::cout << std::endl;

    std::cout << "Zadanie #1:" << std::endl; //печатаем а теперь те что в нужной последовательности
    for (int i = 0; i < results.size(); i++)
        std::cout << results[i] << " | ";

    lastPos = values.begin();
    for (iter = values.begin(); iter != values.end(); iter++) { // Ищем первое и второе отрицательное значение
        if (*iter >= 0) {
            lastPos = iter;
        }
    }
    for (iter = values.begin(); iter <= lastPos; iter++)
    {
        summ += *iter;
    }
    std::cout << "\nPoslednee polozhitelnoe: " << *lastPos << std::endl;
    std::cout << "\nZadanie #2(Ispolzuetsy ishodnay posledovatelnost). Summa: " << summ << std::endl;
    return 0;
}
