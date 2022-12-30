#include <iostream>
using namespace std;
//Node representation of a BST
class Node
{
    public:
        int data;                              ///MOHAMMAD NAIMUL HAQUE
        Node *left=NULL;                      ///PROJECT: BINARY SEARCH TREE BASICS
        Node *right=NULL;
};

class BST
{
    public:
        Node* createNode(int value)
        {
            Node *ptr=new Node();
            ptr->data=value;
            ptr->left=NULL;
            ptr->right=NULL;
            return ptr;
        }

        Node* insertNode(Node *ptr,int value)

        {
            if (ptr==NULL)
            {
               ptr= createNode(value);
            }
            else if(value<ptr->data)
            {
               ptr->left = insertNode(ptr->left,value);
            }
            else if(value>ptr->data)
            {
                ptr->right=insertNode(ptr->right,value);
            }
            return ptr;
        }
        void inorder(Node *ptr)
        {
            if(ptr!=NULL)
            {
                inorder(ptr->left);
                cout<<ptr->data<<" ";
                inorder(ptr->right);
            }
        }
        void preorder(Node *ptr)
        {
            if(ptr!=NULL)
            {
                cout<<ptr->data<<" ";
                preorder(ptr->left);
                preorder(ptr->right);
            }
        }
        void postorder(Node *ptr)
        {
            if(ptr!=NULL)
            {
                postorder(ptr->left);
                postorder(ptr->right);
                cout<<ptr->data<<" ";
            }
        }
        Node* searchNode(Node *ptr,int value)
        {
            if(ptr==NULL)
            {

                return ptr;
            }
            else if(value<ptr->data)
            {
                ptr=searchNode(ptr->left,value);
            }
            else if(value>ptr->data)
            {
                 ptr=searchNode(ptr->right,value);
            }
            return ptr;
        }
        Node* findMin(Node *ptr)
        {
            while(ptr->left!=NULL)
            {
                ptr=ptr->left;
            }
            return ptr;
        }
        Node* findMax(Node *ptr)
        {
            while(ptr->right!=NULL)
            {
                ptr=ptr->right;
            }
            return ptr;
        }
        Node* deleteNode(Node *ptr,int value)
        {
            ptr=searchNode(ptr,value);
            if(ptr==NULL)
            {
                return ptr;
            }
            else
            {
                //Node->leaf node
                if(ptr->left==NULL && ptr->right==NULL)
                {
                    delete ptr;
                    ptr=NULL;
                }
                //Node->left child
                else if(ptr->right==NULL)
                {
                    Node *temp=ptr;
                    ptr=ptr->left;
                    delete temp;
                }
                //Node->right child
                else if(ptr->left==NULL)
                {
                    Node *temp=ptr;
                    ptr=ptr->right;
                    delete temp;
                }

            }
        }

};

int main()
{
    BST a1,a2,a3;
    Node *root=NULL;
//    cout<<"INORDER: ";
//    root = a1.insertNode(root,4);
//    a1.insertNode(root,5);
//    a1.insertNode(root,7);
//    a1.insertNode(root,6);
//    a1.insertNode(root,9);
//    a1.insertNode(root,11);
//    a1.insertNode(root,15);
//    a1.insertNode(root,10);
//    a1.insertNode(root,2);
//    //a1.insertNode(root,13);
//    a1.inorder(root);
//    //root=deleteNode(root,27);
//    cout<<endl;
//    cout<<"MINIMUM NODE: "<<a1.findMin(root)->data<<endl;
//    cout<<"MIXIMUM NODE: "<<a1.findMax(root)->data<<endl;
//    if(a1.searchNode(root,9)==NULL)
//    {
//        cout<<"NODE NOT FOUND"<<endl;
//    }
//    else
//    {
//        cout<<"NODE FOUND"<<endl;
//    }
//    cout<<endl;
//
//    cout<<"PREORDER: : ";
//    root = a2.insertNode(root,4);
//    a2.insertNode(root,5);
//    a2.insertNode(root,7);
//    a2.insertNode(root,6);
//    a2.insertNode(root,9);
//    a2.insertNode(root,11);
//    a2.insertNode(root,15);
//    a2.insertNode(root,10);
//    a2.insertNode(root,2);
//    //a2.insertNode(root,13);
//    a2.preorder(root);
//    cout<<endl;

    //if(a2.searchNode(root,25)==NULL)
    //{
    //    cout<<"NODE NOT FOUND"<<endl;
    //}
    //else
    //{//
        cout<<"NODE FOUND"<<endl;
    //}
    //cout<<"MINIMUM NODE: "<<a2.findMin(root)->data<<endl;
   // cout<<"MIXIMUM NODE: "<<a2.findMax(root)->data<<endl;
    cout<<endl;
    cout<<"POST_ORDER: ";
    root = a3.insertNode(root,7);
    a3.insertNode(root,5);
    a3.insertNode(root,9);
    a3.insertNode(root,15);
    a3.insertNode(root,22);
    a3.insertNode(root,69);
    a3.postorder(root);
   a3.deleteNode(root,15);
   a3.postorder(root);
    //a1.insertNode(root,8);
    //a1.insertNode(root,6);
    //a1.insertNode(root,4);
    //a1.insertNode(root,13);
    //a1.postorder(root);



    return 0;
}
