namespace BSTree {
struct Node {
  int key;
  Node* left;
  Node* right;
};
class Tree {
  Node* root;
  void add_node(int key, Node*& root);
  void showTree(Node* node, int field);
  void PreOrderTree(Node* node);
  void InOrderTree(Node* node);
  void PostOrderTree(Node* node);
  bool AddTo(Node*& root, int value);
  bool Deletenode(Node* root, int value);
  void Deletetree(Node *&node);
  //void WriteInFile(Node *root, std::string name);
  bool LoadfromfileTree(Node* root);

public:
  Tree();
  bool zero();
  void show();
  void insert(int key);
  void PreOrder();
  void InOrder();
  void PostOrder();
  bool Add(int value);
  bool Deleten();
  void Deletetr();
  //void Write();
  bool Loadfromfile();
};
}

