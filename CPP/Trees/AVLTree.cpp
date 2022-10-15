#include <iostream>

using namespace std;
class Node
{
public:
    int key;
    Node *left,*right;
    int height;
};
int max(int a,int b);
int height(Node *N)
{
    if(N==NULL)
        return 0;
    return N->height;
}
int max(int a,int b)
 {
     return (a>b) ? a : b ;
 }
Node *newNode(int key)
{
    Node *node=new Node;
    node->key=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;//initially new node is added at leaf
    return(node);
}
Node *rightRotate(Node *y)
{
    Node *x=y->left;
    Node *t2=x->right;
    //perform rotation
    x->right=y;
    y->left=t2;
    y->height=max(height(y->left),height(y-> right))+1;
    x->height=max(height(x->left),height(x->right))+1;
    return x; //return new root
}
Node *leftRotate(Node *x)
{
    Node *y=x->right;
    Node *t2 = y->left;
    y->left=x;
    x->right=t2;
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y-> right))+1;
    return y;
}
int getBalance(Node *N)
{
    if(N==NULL)
        return 0;
    return height(N->left)-height(N->right);
}
Node *insert(Node *node,int key)
{
if(node==NULL)
    return newNode(key);
else if(key<node->key)
    node->left=insert(node->left,key);
else if(key>node->key)
    node->right=insert(node->right,key);
else
    return node;
node->height=1+max(height(node->left),height(node->right));
int balance=getBalance(node);
//left left case
if(balance>1 && key<node->left->key)
    return rightRotate(node);
 //right right case
if(balance<-1 && key>node->right->key)
    return leftRotate(node);
 //left right case
if(balance>1 && key<node->left->key)
 {   node->left=leftRotate(node->left);
     return rightRotate(node);
     }
 //right left case
if(balance<-1 && key<node->right->key)
   {node->right=rightRotate(node->right);
    return leftRotate(node);
}
 return node;
 }
 void preorder(Node *root)
 {
     if(root!=NULL)
     {
         cout<<root->key<<" ";
         preorder(root->left);
         preorder(root->right);
     }
 }
int main()
{
    Node *root=NULL;
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,30);
    root=insert(root,40);
    root=insert(root,50);
    root=insert(root,25);
    cout<<"PreOrder traversal of the constructed AVL tree \n";
    preorder(root);
    return 0;
}
