#include <stdio.h>

int main()
{
    int res_x = 2000; // разрешение текстуры по горизонтали
    int map_scale = 64; // масштаб карты
    float txt_scale = (float)res_x / map_scale; // коэфицент для масштабированния текстуры (лучше расчитать один раз и сохранить)
    printf("txt_scale = %f\n", txt_scale); // печать коэфицента для масштабирования

    float cross[3];
    cross[0] = (map_scale * 10) + 0.1; // координата пересечения со стеной с дробной частью (очень маленькое значение)
    cross[1] = (map_scale * 10) + map_scale/2; // 2-ая случайная координата пересечения со стеной с дробной частью (среднее значение)
    cross[2] = (map_scale * 10) + map_scale - 0.1; // 3-ая случайная координата пересечения со стеной с дробной частью (близкое к максимальному)
    int i = 0;

    while (i < 3)
    {
        printf("_________\n\n");
        printf("cross[%d] = %f\n", i, cross[i]); // печать остатка
        float rem_cross = cross[i] - ((int)cross[i] / map_scale * map_scale); // операция нахождения остатка от деления на масштаб карты с дробной частью
        printf("rem_cross = %f\n", rem_cross); // печать остатка
        int txt_index = rem_cross * txt_scale; // поиск индекса столбца текстуры
        printf("txt_index = %d\n", txt_index); // печать индекса
        i++;
    }
    return(0);
}
