#include <iostream>

using namespace std;
class Node
{
public:
    int data;
    Node *left,*right;
};
class BinaryTree:public Node
{
public:
    Node *root;
    int level;
    BinaryTree()
    {
        root=NULL;
        level=-1;
    }void create();
    void insert();
    void preorder(Node*);
    void inorder(Node*);
    void postorder(Node*);
};
void BinaryTree::create()
{
    if(root==NULL)
    {
        Node *temp=new Node;
        int value;
        cout<<"enter a value:";
        cin>>value;
        temp->data=value;
        temp->left=NULL;
        temp->right=NULL;
        root=temp;
        level=0;
    }else
    cout<<"root already exists"<<endl;
}
void BinaryTree::insert()
{
    if(root==NULL)
    {
        cout<<"root is NULL"<<endl;
        cout<<"create the tree to insert elements"<<endl;
        create();
    }
    else
    {
        Node *temp=new Node;
        int value;
        cout<<"enter any value:";
        cin>>value;
        temp->data=value;
        temp->left=NULL;
        temp->right=NULL;
        if(root->left==NULL||root->right==NULL)
        {
            if(root->left==NULL)
                root->left=temp;
            else if(root->right==NULL)
                root->right=temp;
            level=1;
        }else if(level==1||level==2)
        {
            if((root->left)->left==NULL)
                (root->left)->left=temp;
            else if((root->left)->right==NULL)
                (root->left)->right=temp;
            else if((root->right)->left==NULL)
                (root->right)->left=temp;
            else
                (root->right)->right=temp;
            level=2;
        }
    }
}
void BinaryTree::preorder(Node *temp)
{
    if(temp!=NULL)
    {
        cout<<temp->data<<" ";
        if(temp->left)
            preorder(temp->left);
        if(temp->right)
            preorder(temp->right);
    }else{
    cout<<"cannot display";
    return;
    }
}
void BinaryTree::inorder(Node *temp)
{
    if(temp!=NULL)
    {
        if(temp->left)
            inorder(temp->left);
        cout<<temp->data<<" ";
        if(temp->right)
            inorder(temp->right);
    }else
    {
        cout<<"cannot display"<<endl;
        return ;
    }
}
void BinaryTree::postorder(Node *temp)
{
    if(temp!=NULL)
    {
        if(temp->left)
            postorder(temp->left);
        if(temp->right)
            postorder(temp->right);
        cout<<temp->data<<" ";
    }else{
    cout<<"cannot display"<<endl;
    return ;
    }
}
int main()
{
    BinaryTree b;
    int ch,dis;
    while(true)
    {
        cout<<"\n 1.create\n 2.insert\n 3.display\n 0.exit\n";
        cout<<"enter your choice:";
        cin>>ch;
        switch(ch)
        {
            case 1:b.create();break;
            case 2:b.insert();break;
            case 3:cout<<"\n 1:preorder\n 2:inorder\n 3:postorder\n";
            cout<<"enter your choice:";
            cin>>dis;
            switch(dis)
            {
                case 1:b.preorder(b.root);break;
                case 2:b.inorder(b.root);break;
                case 3:b.postorder(b.root);break;
                default:cout<<"choose correct option"<<endl;
                break;
            }break;
            case 0:return 0;
            default:cout<<"choose the correct option"<<endl;
            break;
        }
    }
    return 0;
}
