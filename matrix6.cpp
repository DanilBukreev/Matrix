#include <iostream>
#include <string>
#include <cstdio>
#include <fstream>
using namespace std;
void writeFile(int **&arr,int &rows, int &cols){
   ofstream fout ("matrix.txt", ios :: app);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      fout << arr[i][j] << " ";
    }
    fout << endl;
  }
}
void readFile( int **&arr, int &rows, int &cols) {
 cout << "Матрицу какого размера вывести?" << endl;
    cin >> rows >> cols;
     for (int i = 0; i < rows; i++) {
    arr[i] = new int[cols];
  }

    ifstream fin("input.txt");
    if (!fin.is_open()) // если файл не открыт
        cout << "Файл не может быть открыт!\n"; // сообщить об этом
    else
    {
        cout<<"матрица:"<<endl;
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                fin>>arr[i][j];
                cout<<arr[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    cout<<endl;
    fin.close();

}

void sum(int rows, int cols, int **arr, int **arr2) {
  cout << "Введите  матрицy " << rows << "x" << cols << endl;
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
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}
void print(int &rows, int &cols, int **&arr) {
  if (rows == 0) {
    cout << "Матрица пуста" << endl;
    exit(1);
  }
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      cout << arr[i][j] << " ";
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
  int rows2, cols2;
  cout << "Введите размер матрицы: " << endl;
  cin >> rows >> cols;
  cout << endl;
  int **arr = new int *[rows];
  int **arr2 = new int *[rows];
  int **arr3 = new int *[rows2];
  int **arr_umnoj = new int *[rows];

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
        exit(1);
        break;
      }
        case 5:{
         writeFile(arr, rows, cols);
        break;
      }
      case 6:{
        readFile(  arr,rows,  cols);
       break;
       }

         case 4: {
         for (int i=0; i < rows; i++){
             for (int j=0; j < cols; j++)
                  cout << arr[i][j] << "\t";
               cout << endl;
           }
          cout << endl;
          for (int i=0 ; i < cols; i++){
               for (int j=0; j < rows;j++)
               cout << arr[j][i] << "\t";
               cout << endl;
          }
         break;
         }
      case 3: {
        cout << "Введите размер матрицы:" << endl;
        cin >> rows2 >> cols2;
        if (rows2 == 0) {
          cout << "Матрица пуста" << endl;
          exit(1);
        }
        for (int i = 0; i < cols; i++) {
          arr3[i] = new int[cols2];
        }
        for (int i = 0; i < rows; i++) {
          arr_umnoj[i] = new int[cols2];
        }
        for (int i = 0; i < rows2; i++) {
          for (int j = 0; j < cols2; j++) {
            cin >> arr3[i][j];
          }
        }
        if (cols == rows2) {
          for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols2; j++) {
              arr_umnoj[i][j] = 0;
              for (int w = 0; w < cols; w++)
                arr_umnoj[i][j] = arr_umnoj[i][j] + arr[i][w] * arr3[w][j];
            }
          }
          cout << "result:" << endl;
          for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols2; j++) {
              cout << arr_umnoj[i][j] << " ";
            }
            cout << endl;
          }
        } else
          cout << " error";

        break;
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
  for (int i = 0; i < cols; i++) {
    arr3[i] = new int[cols2];
  }
  for (int i = 0; i < rows; i++) {
    arr_umnoj[i] = new int[cols2];
  }
  delete[] arr3;
  delete[] arr_umnoj;
  delete[] arr;
  delete[] arr2;
}
