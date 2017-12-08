#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;
void sum(int rows, int cols, int **arr, int **arr2) {
  cout << "Введите  матрицy: " << endl;
  for (int i = 0; i < rows; i++) {
    arr2[i] = new int[cols];
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cin >> arr2[i][j];
    }
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr[i][j] = arr[i][j] + arr2[i][j];
      cout << arr[i][j];
    }
    cout << endl;
  }
}
void print(int rows, int cols, int **arr) {
  if (rows == 0) {
    cout << "Матрица пуста" << endl;
    exit(1);
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
}
void menu() {
  cout << " " << endl;
  cout << "1. Вывести матрицу" << endl;
  cout << "2. Сложить матрицу" << endl;
  cout << "3. Умножить матрицу" << endl;
  cout << "4. Транспонировать матрицу" << endl;
  cout << "5. Сохранить в файл" << endl;
  cout << "6. Загрузить из файла" << endl;
  cout << "7. Сортировать матрицу" << endl;
  cout << "8. Завершение работы " << endl;
}

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "Russian");
  int rows, cols;
  cout << "Введите размер матрицы: " << endl;
  cin >> rows >> cols;
  cout << endl;
  int **arr = new int *[rows];
  int **arr2 = new int *[rows];
  for (int i = 0; i < rows; i++) {
    arr[i] = new int[cols];
  }
  // Заполнение матрицы
  /*   for (int i =0;i < rows; i++){
         for (int j=0;j < cols; j++){
           cin >> arr[i][j];
         }

     }*/
  string array_str;
  cin.ignore(1024, '\n');
  getline(cin, array_str);  // reading before enter
  int k, i = 0;
  string number_str;  // element in string array_str
  int *arr_odnom = new int[rows * cols];
  for (int i = 0; i < (rows * cols); i++) arr_odnom[i] = 0;
  while ((k <= array_str.length()) && (i < (rows * cols))) {
    if ((k % 2) == 0) {
      number_str = number_str + array_str[k];
      arr_odnom[i] = atoi(number_str.c_str());
      number_str = "";
      i++;
      k++;
    } else
      k++;
  }
  k = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      arr[i][j] = arr_odnom[k];
      k++;
    }
  }
  delete[] arr_odnom;
  while (1) {
    int c, s;
    menu();
    cin >> c;
    switch (c) {
      case 1: {
        print(rows, cols, arr);
        break;
      }
      case 2: {
        sum(rows, cols, arr, arr2);
        break;
      }
      case 8: {
        return 0;
      }
    }
  }
  // Освобождение памяти
  for (int i = 0; i < rows; i++) {
    delete[] arr[i];
  }
  for (int i = 0; i < rows; i++) {
    delete[] arr2[i];
  }
  delete[] arr;
  delete[] arr2;
}
