#include <iostream>
#include "bstree.h"
#include <fstream>

using namespace BSTree;
using namespace std;

Tree::Tree() { root = nullptr; }
void Tree::Add_node(int key, Node*& root) {
  if (root == nullptr) {
    root = new Node;
    root->key = key;
    root->left = root->right = nullptr;
  }
  if (key < root->key) {
    if (root->left != nullptr)
      Add_node(key, root->left);
    else {
      root->left = new Node;
      root->left->left = root->left->right = nullptr;
      root->left->key = key;
    }
  }
  if (key > root->key) {
    if (root->right != nullptr)
      Add_node(key, root->right);
    else {
      root->right = new Node;
      root->right->left = root->right->right = nullptr;
      root->right->key = key;
    }
  }
}

bool Tree::Zero() { return (root == nullptr ? true : false); }

void Tree::Insert(int key) { Add_node(key, root); }

void Tree::ShowTree(Node* node, int field) {
  if (root != nullptr) {
    cout << "   ";
    if (node->left != nullptr) {
      ShowTree(node->left, field + 1);
      for (int i = 0; i < field; i++) {
        cout << " ";
      }
    }
    cout << node->key << endl;
    if (node->right != nullptr) {
      ShowTree(node->right, field + 1);
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

void Tree::Show() {
  if (root != nullptr)
    ShowTree(root, 0);
  else
    cout << "Дерево пусто!" << endl;
}

void Tree::Deletetree(Node*& node) {
  if (node != nullptr) {
    Deletetree(node->left);
    Deletetree(node->right);
    delete node;
    node = nullptr;
  }
}

void Tree::Deletetr() { Deletetree(root); }

bool Tree::Deletenode(Node*& root, int value) {
  if (root == nullptr) {
    return root;
  }
  if (value < root->key) {
    root->left;
    Deletenode(root->left, value);
  } else if (value > root->key) {
    root->right;
    Deletenode(root->right, value);
  } else if (root->left != nullptr && root->right != nullptr) {
    root->key == root->right->key;
    root->right;
    Deletenode(root->right, root->key);
  } else if (root->left == nullptr && root->right == nullptr) {
    Deletenode(root, value);
  } else if (root->left != nullptr)
    root = root->left;
  else
    root = root->right;
  return true;
}

bool Tree::Deleten(int value) { Deletenode(root, value); }

void Tree::WriteInFile(Node* root, std::string name) {
  ofstream fout(name, ios::app);
  if (root == nullptr) return;
  WriteInFile(root->left, name);
  fout << root->key << endl;
  WriteInFile(root->right, name);
  fout.close();
}

void Tree::Write() {
  string name;
  cout << "Введите название файла: ";
  cin >> name;
  ifstream fin(name, ios_base::in);
  string ch_3;
  if (fin.is_open()) {
    cout << "Вы хотите переписать файл? Да/Нет" << endl;
    cin >> ch_3;
  }
  fin.close();
  if ((ch_3 == "y") || (ch_3 == "Да") || (ch_3 == "Yes") || (ch_3 == "да") ||
      (ch_3 == "yes")) {
    WriteInFile(root, name);
  }
}

bool Tree::LoadfromfileTree(Node* root) {
  cout << "Введите путь к файлу:" << endl;
  string file_name;
  cin >> file_name;
  ifstream fin(file_name);
  if (!fin.is_open()) return false;
  string str;
  getline(fin, str);
  int elements = 1;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == ' ') elements++;
  }
  fin.close();
  fin.open(file_name);
  for (int i = 0; i < elements; i++) {
    fin >> str;
    this->Insert(atoi(str.c_str()));
  }
  return true;
}

bool Tree::Loadfromfile() { LoadfromfileTree(root); }

bool Tree::Verification(Node*& root, int value) {
  if (root == nullptr) {
    cout << "Дерево пусто" << endl;
    return false;
    Node* val = root;
    while (val != nullptr) {
      if (value < val->key) {
        val = val->right;
      } else if (value > val->key) {
        val = val->left;
      } else if (val->key == value) {
        break;
      }
    }
    if (val != nullptr) {
      cout << "Узел найден" << endl;
      return true;
    } else {
      cout << "Узел не найден" << endl;
      return false;
    }
  }
}
bool Tree::VerificationNode(int value) { Verification(root, value); }
