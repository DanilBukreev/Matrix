#include <iostream>
#include <cstdlib>
using namespace std;

void print (int rows, int cols , int ** arr){
if (rows == 0) {
      cout << "Матрица пуста" << endl;
      exit(1);
    }
 for (int i =0;i < rows; i++){
       for (int j=0;j < cols; j++){
             cout <<   arr[i][j];
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
  int rows,cols;
   cout << "Введите размер матрицы: " << endl;
  cin >> rows >> cols;
  cout << endl;
  int **arr = new int*[rows];
  for (int i =0;i < rows; i++){
       arr [i] = new int [cols];
  }
 // Заполнение матрицы
   for (int i =0;i < rows; i++){
       for (int j=0;j < cols; j++){
         cin >> arr[i][j];
       }

   }
   while(1) {
   int c,s;
   menu ();
   cin >> c;
   switch (c){
     case 1: {
            print (rows,cols, arr);
            break;
            }
      case 8:{
           return 0;
          }
    }

  }
 // Освобождение памяти
  for (int i=0;i < rows; i++){
      delete[] arr[i];
  }
  delete[] arr;
}
