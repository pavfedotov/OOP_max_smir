#include <iostream>

#include <string>
#define SIZE 5

class VECTOR {
private:
    double data[SIZE];
public:

    double& operator[](int index) {
        return data[index];
    }


    // Функция заполнения вектора с помощью клавиатуры
    void  key_completion() {
        for (int i = 0; i < SIZE; i++) {

            std::cout << i + 1 << "й эл-т: ";
            std::cin >> data[i];

        }
        std::cout << std::endl;
    };
    // Функция заполнения вектора
    void completion(double mas[SIZE]) {

        for (int i = 0; i < SIZE; i++) {
            data[i] = mas[i];
        }

    };
    // Функция обнуления
    void vec_null() {
        for (int i = 0; i < SIZE; i++) {
            data[i] = 0;
        }
    }
    //Функция суммы эл-ов вектора
    double summ() {
        double summ = 0.0;
        for (int i = 0; i < SIZE; i++) {
            summ += data[i];
        }
        return summ;
    }
    //Функция сравнения
    bool compare(VECTOR vec) {
        int count = 0;
        for (int i = 0; i < SIZE; i++) {
            if (data[i] == vec[i]) {
                count++;
            }
        }
        if (count == 5) {
            return true;
        }
        return false;
    }
    void operator*=(int n) {
        for (int i = 0; i < SIZE; i++) {
            data[i] *= n;
        }
    }
    VECTOR operator+(VECTOR vec) {
        VECTOR result;
        for (int i = 0; i < SIZE; i++) {
            result[i] = vec[i] + data[i];
        }
        return result;
    }
    //Функция печати
    void print(std::string str) {
        std::cout << str << std::endl;
        for (int i = 0; i < SIZE; i++) {
            std::cout << i + 1 << "й эл-т: " << data[i] << std::endl;
        }
        std::cout << std::endl;
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    VECTOR vec1, vec2, vec3;
    double mass[5] = { 1.2,4.3,5.0,0.9,7.6 };
    vec1.completion(mass);
    vec1.print("Вектор 1");
    vec2.key_completion();
    double summ = vec1.summ();
    std::cout << std::endl << "Сумма эл-ов вектора 1: " << summ << std::endl << std::endl;
    vec2 *= 5;
    vec2.print("Вектор 2 умноженный на 5");
    vec3 = vec1 + vec2;
    vec3.print("Вектор 3, сумма вектора 1 и 2");
    vec1.vec_null();
    vec2.vec_null();
    vec2.print("Вектор 2 обнулен");

    if (vec1.compare(vec2)) {
        std::cout << std::endl << "Векторы равны!";
    }
}

