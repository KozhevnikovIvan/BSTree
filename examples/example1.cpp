#include "bstree.cpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  Tree *tree = new Tree;
  for (int i = 1; i < argc; i++) {
    tree->Insert(atoi(argv[i]));
  };
  int ch;
  char ch_2;
  string s;
  do {
    cout << " " << endl;
    cout << "1. Вывести дерево на экран" << endl;
    cout << "2. Вывести список узлов дерева" << endl;
    cout << "3. Добавить узел в дерево" << endl;
    cout << "4. Удалить узел из дерева" << endl;
    cout << "5. Сохранить дерево в файл" << endl;
    cout << "6. Загрузить дерево из файла" << endl;
    cout << "7. Проверить наличие узла" << endl;
    cout << "8. Завершить работу программы" << endl;
    cin >> ch;
    switch (ch) {
      case 1: {
        tree->Show();
        break;
      }
      case 2:
        if (!(tree->Zero())) {
          cout << "a. Прямой обход" << endl;
          cout << "b. Поперечный обход" << endl;
          cout << "c. Обратный обход" << endl;
          cin >> ch_2;
          switch (ch_2) {
            case 'a':
              tree->PreOrder();
              cout << endl;
              break;
            case 'b':
              tree->InOrder();
              cout << endl;
              break;
            case 'c':
              tree->PostOrder();
              cout << endl;
              break;
          }
          break;
        } else
          cout << "Дерево пусто" << endl;
        break;
      case 3:
        cout << "Введите значение для нового узла:"<<endl;
        int key;
        cin >> key;
        tree->Insert(key);
        break;
      case 4:
        cout << "Введите значение для нового узла" << endl;
        int value;
        cin>>value;
        tree->Deleten(value);
        break;
      case 5:
        tree->Write();
        break;
      case 6:
        tree->Deletetr();
        tree->Loadfromfile();
        break;
      case 8: {
        cout << "Вы уверенны, что хотите выйти из программы?" << endl;
        cin >> s;
        if (s == "yes" || s == "YES" || s == "Yes" || s == "Y" || s == "y")
          cout << "До свидания!" << endl;
        break;
      }
    }
  } while (s != "yes" && s != "YES" && s != "Yes" && s != "Y" && s != "y");
  delete tree;
}
