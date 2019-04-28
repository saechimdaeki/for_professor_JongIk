#include<iostream>
#include<cstdlib>
int count;
using namespace std;
typedef struct NodeStruct
{
    int value;
    struct NodeStruct* leftChild;
    struct NodeStruct* rightChild;
}Node;
 
Node* root = NULL;
 
Node* BST_insert(Node* root, int value)
{
    if(root == NULL)
    {
        root = (Node*)malloc(sizeof(Node));
        root->leftChild = root->rightChild = NULL;
        root->value = value;
        count++;
        return root;
    }
    else
    {
        if(root->value > value)
        {
            root->leftChild = BST_insert(root->leftChild, value);
            count++;
        }
             
        else
        {
            root->rightChild = BST_insert(root->rightChild, value);
            count++;
        }
             
    }
    return root;
}
Node* findMinNode(Node* root)
{
    Node* tmp = root;
    while(tmp->leftChild != NULL)
        tmp = tmp->leftChild;
    return tmp;
}
Node* BST_delete(Node* root, int value)
{
    Node* tNode = NULL;
    if(root == NULL)
        return NULL;
 
    if(root->value > value)
        root->leftChild = BST_delete(root->leftChild, value);
    else if(root->value < value)
        root->rightChild = BST_delete(root->rightChild, value);
    else
    {
        // 자식 노드가 둘 다 있을 경우
        if(root->rightChild != NULL && root->leftChild != NULL)
        {
            tNode = findMinNode(root->rightChild);
            root->value = tNode->value;
            root->rightChild = BST_delete(root->rightChild, tNode->value);
        }
        else
        {
            tNode = (root->leftChild == NULL) ? root->rightChild : root->leftChild;
            free(root);
            return tNode;
        }
    }
 
    return root;
}
Node* BST_search(Node* root, int value)
{
    if(root == NULL)
        return NULL;
 
    if(root->value == value)
        return root;
    else if(root->value > value)
        return BST_search(root->leftChild, value);
    else
        return BST_search(root->rightChild, value);
}
void BST_print(Node* root)//전위ㅣ순 
{
    if(root == NULL)
        return;
 
    cout<<root->value<<" ";
    BST_print(root->leftChild);
    BST_print(root->rightChild);
}
void BST_print_middle(Node *root)//중위프린트 
{
	if(root==NULL)
	return;
	BST_print_middle(root->leftChild);
	cout<<root->value<<" ";
	BST_print_middle(root->rightChild);
 } 
 void BST_print_after(Node* root)//후위입니다
 {
 	if(root==NULL)
 	return;
 	BST_print_after(root->leftChild);
 	BST_print_after(root->rightChild);
 	cout<<root->value<<" ";
  } 
 
int main()
{
    int n,n2;
    int x;
    int ca;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        root=BST_insert(root,a);
    }
    //BST_print(root);
    cin>>n2;
    for(int i = 0; i<n2; i++){
        cin>>ca>>x;
        switch(ca){
        case 0://전위 
            root=BST_delete(root,x);
            BST_print(root);
            cout<<endl;
            break;
        case 1://중위 
            root=BST_delete(root,x);
            BST_print_middle(root);
            cout<<endl;
            break;
        
        case 2://후위 
        	root=BST_delete(root,x);
			BST_print_after(root);
			cout<<endl;
			break;
    }
    
    
 
}
}
