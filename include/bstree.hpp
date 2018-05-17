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
  bool Deletenode(Node*& root, int value);
  void Deletetree(Node *&node);
  void WriteInFile(Node *root, std::string name);
  bool LoadfromfileTree(Node* root);
  bool Verification(Node*& root, int value);

public:
  Tree();
  bool Zero();
  void Show();
  void Insert(int key);
  void PreOrder();
  void InOrder();
  void PostOrder();
  bool Deleten(int value);
  void Deletetr();
  void Write();
  bool Loadfromfile();
  bool VerificationNode(int value);
};
}
