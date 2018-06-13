#include <iostream>
#include "bstree.h"
#include <fstream>
#include <cstring>

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
    cout << "  ";
    if (node->right != nullptr) {
      ShowTree(node->right, field + 1);
      for (int i = 0; i < field; i++) {
        cout << " ";
      }
    }
    cout << node->key << endl;
    if (node->left != nullptr) {
      ShowTree(node->left, field + 1);
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

void Tree::Deletenode(Node*& root, int value) {
  if (value == root->key) {
    Node* tmp;
    if (root->right == nullptr)
      tmp = root->left;
    else {
      Node* ptr = root->right;
      if (ptr->left == nullptr) {
        ptr->left = root->left;
        tmp = ptr;
      } else {
        Node* pmin = ptr->left;
        while (pmin->left != nullptr) {
          ptr = pmin;
          pmin = ptr->left;
        }
        ptr->left = pmin->right;
        pmin->left = root->left;
        pmin->right = root->right;
        tmp = pmin;
      }
    }
    delete root;
    root = tmp;
  } else if (value < root->key)
    Deletenode(root->left, value);
  else
    Deletenode(root->right, value);
}

void Tree::Deleten(int value) { Deletenode(root, value); }

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
    ofstream fout(name, ios_base::out | ios_base::trunc);
    fout.close();
    Writeinfile(root, name);
  }
}

void Tree::Writeinfile(Node* root, std::string name) {
  ofstream fout(name, ios::app);
  if (root == nullptr) return;
  fout << root->key << endl;
  Writeinfile(root->left, name);
  Writeinfile(root->right, name);
  fout.close();
}

bool Tree::LoadfromfileTree(Node* root) {
  cout << "Введите путь к файлу:" << endl;
  string file_name;
  cin >> file_name;
  ifstream fin(file_name);
  if (!fin.is_open()) return false;
  int key;
  while (fin >> key) {
    Insert(key);
  }
  return true;
}

bool Tree::Loadfromfile() { LoadfromfileTree(root); }

bool Tree::Check() const {
  if (root == nullptr)
    return false;
  else
    return true;
}

bool Tree::Compare(Node*& root, int value) const {
  if (value == root->key) return true;
  if (value < root->key) {
    if (root->left != nullptr)
      return Compare(root->left, value);
    else
      return false;
  } else {
    if (root->right != nullptr)
      return Compare(root->right, value);
    else
      return false;
  }
}

bool Tree::Compare(int value) { Compare(root, value); }
