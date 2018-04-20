#include "bstree.h"
#include <iostream>
#include <fstream>

using namespace BSTree;
using namespace std;

Tree::Tree() { root = nullptr; }
void Tree::add_node(int key, Node*& root) {
  if (root == nullptr) {
    root = new Node;
    root->key = key;
    root->left = root->right = nullptr;
  }
  if (key < root->key) {
    if (root->left != nullptr)
      add_node(key, root->left);
    else {
      root->left = new Node;
      root->left->left = root->left->right = nullptr;
      root->left->key = key;
    }
  }
  if (key > root->key) {
    if (root->right != nullptr)
      add_node(key, root->right);
    else {
      root->right = new Node;
      root->right->left = root->right->right = nullptr;
      root->right->key = key;
    }
  }
}

bool Tree::zero() { return (root == nullptr ? true : false); }

void Tree::insert(int key) { add_node(key, root); }

void Tree::showTree(Node* node, int field) {
  if (root != nullptr) {
    cout << "   ";
    if (node->left != nullptr) {
      showTree(node->left, field + 1);
      for (int i = 0; i < field; i++) {
        cout << " ";
      }
    }
    cout << node->key << endl;
    if (node->right != nullptr) {
      showTree(node->right, field + 1);
    }
  }
}

void Tree::PreOrderTree(Node* node) {
  if (root != nullptr) {
    cout << node->key << " ";
    if (node->left != nullptr) {
      PreOrderTree(node->left);
    }
    if (node->right != nullptr) {
      PreOrderTree(node->right);
    }
  }
}

void Tree::InOrderTree(Node* node) {
  if (root != nullptr) {
    if (node->left != nullptr) {
      InOrderTree(node->left);
    }
    cout << node->key << " ";
    if (node->right != nullptr) {
      InOrderTree(node->right);
    }
  }
}

void Tree::PostOrderTree(Node* node) {
  if (root != nullptr) {
    if (node->left != nullptr) {
      PostOrderTree(node->left);
    }
    if (node->right != nullptr) {
      PostOrderTree(node->right);
    }
    cout << node->key << " ";
  }
}
void Tree::InOrder() { InOrderTree(root); }
void Tree::PreOrder() { PreOrderTree(root); }
void Tree::PostOrder() { PostOrderTree(root); }

void Tree::show() {
  if (root != nullptr)
    showTree(root, 0);
  else
    cout << "Дерево пусто!" << endl;
}

void Tree::Deletetree(Node *&node) {
	if(node != nullptr) {
		Deletetree(node->left);
		Deletetree(node->right);
		delete node;
		node = nullptr;
	}
}

void Tree::Deletetr() { Deletetree(root); }

bool Deletenode(Node* root, int value) {
  cout << "Введите значение для нового узла" << endl;
  cin>>value;
  if (root == nullptr)
    return root;
  if  (value < root->key) {
    root->left;
    Deletenode(root->left, value);
  }  
  else if (value > root->key) {
    root->right;
    Deletenode(root->right, value);
  }  
  else if (root->left != nullptr && root->right != nullptr) {
    root->key == root->right->key;
    root->right;
    Deletenode(root->right, root->key);
  }  
  else if (root->left != nullptr)
      root = root->left;
    else 
      root = root->right;
  return root;
}

bool Deleten(){ Deletenode(Node* root, int value); }

/*void Tree::WriteInFile(Node *root, std::string name)  {
    ofstream fout(name, ios::app);
    if (root == nullptr)
        return;
    WriteInFile(root->right, name);
    fout << root->data << endl;
    WriteInFile(root->left, name);
    fout.close();
}

void Tree::Write() {
  string name;
  cout << "Введите название файла:";
  cin >> name;
  ifstream fin(name, ios_base::in);
  string ch_3;
  if (fin.is_open()) {
    cout << "Вы хотите переписать файл? Да/Нет" << endl;
    cin >> ch_3;
  }
  fin.close();
  if ((ch_3 == "y") || (ch_3 == "Да") || (ch_3 == "Нет") || (ch_3 == "да") ||
      (ch_3 == "нет")) {
    WriteInFile(root, name);
  }
} */

bool Tree::LoadfromfileTree(Node* root) {
  cout << "Введите путь к файлу:" << endl;
  string file_name;
  cin >> file_name;
  ifstream fin(file_name);
  if (!fin.is_open()) return false;
  string str;
  getline (fin,str);
  int elements=1;
  for (int i=0; i<str.length(); i++) {
    if (str[i]==' ') elements++;
  }
  fin.close();
  fin.open(file_name);
  for (int i=0; i<elements; i++) {
    fin >> str;
    this->insert (atoi( str.c_str()));
  }
  return true;
}

bool Tree::Loadfromfile() { LoadfromfileTree(root); }

//void Tree::Verification() {
  






#include "bstree.cpp"
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
  Tree *tree = new Tree;
  for (int i = 1; i < argc; i++) {
    tree->insert(atoi(argv[i]));
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
        tree->show();
        break;
      }
      case 2:
        if (!(tree->zero())) {
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
        tree->insert(key);
        break;
      //case 5:
      // tree->Write();
       //break;
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
