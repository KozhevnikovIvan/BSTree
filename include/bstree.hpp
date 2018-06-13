namespace BSTree {
struct Node {
  int key;
  int value;
  Node* left;
  Node* right;
};  
class Tree {
  Node* root;
  void Add_node(int key, Node*& root);
  void ShowTree(Node* node, int field);
  void PreOrderTree(Node* node);
  void InOrderTree(Node* node);
  void PostOrderTree(Node* node);
  void Deletenode(Node*& root, int value);
  void Deletetree(Node *&node);
  void Writeinfile(Node *root, std::string name);
  bool LoadfromfileTree(Node* root);
  bool Compare(Node *&root, int value) const;

public:
  Tree();
  bool Zero();
  void Show();
  void Insert(int key);
  void PreOrder();
  void InOrder();
  void PostOrder();
  void Deleten(int value);
  void Deletetr();
  void Write();
  bool Loadfromfile();
  bool Check() const;
  bool Compare(int value);
};
}
