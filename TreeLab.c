#include <stdio.h>
#include <stdlib.h>
#include<string.h> 
// implement Binary Search Tree
struct Node
{
   int Data;
   struct Node* Left;
   struct Node* Right;
};
struct Node* BST;
 void InOrderTraversal(struct Node* BST);
 void PreOrderTraversal(struct Node* BST);
 void PostOrderTraversal(struct Node* BST);
struct Node* InserNode(struct Node *BST, int item);
void create_BST(struct Node*BST);



int main(){ 
    BST = InserNode(BST, 1);
    BST = InserNode(BST, 10);
    BST = InserNode(BST, 5);
    printf("InOrder Traversal: \n\n");
    InOrderTraversal(BST);
    printf("PreOrder Traversal: \n\n");
    PreOrderTraversal(BST);
    printf("PostOrder Traversal: \n\n");
    PostOrderTraversal(BST);
    return 0;
}




void create_BST(struct Node* BST){ 
    BST = NULL;
}
 void InOrderTraversal(struct Node* BST){
     if(BST!=NULL){
      InOrderTraversal(BST->Left);
     printf("%d\n",BST->Data);
     InOrderTraversal(BST->Right);
     }
 }

  void PreOrderTraversal(struct Node* BST){
     if(BST!=NULL){
      printf("%d\n",BST->Data);
      PreOrderTraversal(BST->Left);
      PreOrderTraversal(BST->Right);
     }
  
 }

   void PostOrderTraversal(struct Node* BST){
     if(BST!=NULL){
    
      PostOrderTraversal(BST->Left);
      PostOrderTraversal(BST->Right);
       printf("%d\n",BST->Data);
     }
  
 }

 
 struct Node *InserNode(struct Node *BST, int item) {

        struct Node *root , *node_root , *parent_root; 
        root=(struct Node*)malloc(sizeof(struct Node)); 
        root->Data=item;
        root->Left=NULL;
        root->Right=NULL;
        if(BST == NULL) { 
            BST = root;
            BST->Left=NULL;
            BST->Right=NULL; 
            }

        else { 
                parent_root = NULL; 
                node_root = BST; 
                while(node_root!=NULL) {
                parent_root= node_root;
                 if(item < (node_root->Data)) 
                 node_root=node_root->Left; 
                 else
                  node_root=parent_root->Right;
                }

                if(item < (parent_root->Data)) 
                     parent_root->Left = root; 
                else 
                parent_root->Right = root;
        }
        return BST;
 }








