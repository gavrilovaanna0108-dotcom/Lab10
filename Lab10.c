#include <stdio.h>
#include <locale.h>
#include <math.h>

double fa(double x);
double fb(double x);
double ln_n(double x, int N);
double ln_eps(double x, double eps);
float area_triangle(float a, float b);
int draw_triangle(char sym, int size);

int main(void)
{
    setlocale(LC_CTYPE, "RUS");

    int choice;
    char replay;

    printf("Задание 1:\n");
    double x;
    printf("Введите значение x: ");
    if (scanf("%lf", &x) == 1)
    {
        printf("Меню расчета:\n1 - Функция A\n2 - Функция B\n3 - Произведение, разность квадратов и удвоенная сумма\nВыбор: ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("fa(x) = %lf\n", fa(x));
        }
        else if (choice == 2)
        {
            printf("fb(x) = %lf\n", fb(x));
        }
        else if (choice == 3)
        {
            double a_val = fa(x);
            double b_val = fb(x);
            printf("Произведение: %lf\n", a_val * b_val);
            printf("Разность квадратов: %lf\n", (a_val * a_val) - (b_val * b_val));
            printf("Удвоенная сумма: %lf\n", 2 * (a_val + b_val));
        }
    }
    printf("\n");

    printf("Задание 2:\n");
    do
    {
        double x_val;
        int N;
        double eps;
        printf("Введите x (x > 0): ");
        if (scanf("%lf", &x_val) == 1 && x_val > 0)
        {
            printf("Введите число членов ряда N: ");
            scanf("%d", &N);
            printf("Введите точность eps: ");
            scanf("%lf", &eps);

            printf("Стандартный ln(x): %lf\n", log(x_val));
            printf("Через число членов ряда N: %lf\n", ln_n(x_val, N));
            printf("С заданной точностью eps: %lf\n", ln_eps(x_val, eps));
        }
        printf("Продолжить? (Да - y, нет - n): ");
        scanf(" %c", &replay);
    } while (replay == 'y' || replay == 'Y');
    printf("\n");

    printf("Задание 3:\n");
    printf("Меню операции для прямоугольного треугольника:\n1 - Рассчитать площадь\n2 - Вывести определение\n3 - Нарисовать контур\nВыбор: ");
    scanf("%d", &choice);
    if (choice == 1)
    {
        float katet;
        printf("Введите длину катета: ");
        if (scanf("%f", &katet) == 1)
        {
            printf("Площадь: %f\n", area_triangle(katet, katet));
        }
    }
    else if (choice == 2)
    {
        printf("Прямоугольный равнобедренный треугольник — треугольник, у которого один угол прямой, а два катета равны.\n");
    }
    else if (choice == 3)
    {
        char sym;
        int size;
        printf("Введите символ: ");
        scanf(" %c", &sym);
        printf("Введите размер: ");
        if (scanf("%d", &size) == 1 && size >= 2)
        {
            draw_triangle(sym, size);
        }
    }

    return 0;
}

double fa(double x)
{
    if (x <= 3.0)
    {
        return x * x - 3.0 * x + 9.0;
    }
    else
    {
        return 1.0 / (x * x * x + 3.0);
    }
}

double fb(double x)
{
    return x * exp(sin(x * x));
}

double ln_n(double x, int N)
{
    double base = (x - 1.0) / (x + 1.0);
    double base_sq = base * base;
    double sum = 0.0;
    double term = base;
    for (int n = 0; n < N; n++)
    {
        sum += term / (2 * n + 1);
        term *= base_sq;
    }
    return 2.0 * sum;
}

double ln_eps(double x, double eps)
{
    double base = (x - 1.0) / (x + 1.0);
    double base_sq = base * base;
    double sum = 0.0;
    double term = base;
    int n = 0;
    while (fabs(2.0 * term / (2 * n + 1)) > eps)
    {
        sum += term / (2 * n + 1);
        term *= base_sq;
        n++;
    }
    return 2.0 * sum;
}

float area_triangle(float a, float b)
{
    return 0.5f * a * b;
}

int draw_triangle(char sym, int size)
{
    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i == size || j == 1 || j == i)
            {
                printf("%c", sym);
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}