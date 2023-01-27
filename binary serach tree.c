#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    struct TreeNode *lchild;
    int data;
    struct TreeNode *rchild;
};

struct TreeNode *root = NULL;

void insert(int item) {

    struct TreeNode* cur = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    cur->data=item;
    cur->lchild=cur->rchild=NULL;

    if (root==NULL) {
        root=cur;
        return;
    }

    struct TreeNode *temp=root, *parent;
    while(temp!=NULL) {
        parent=temp;
        if(item<temp->data) 
            temp=temp->lchild;
        else 
            temp=temp->rchild;
    }
    if (item<parent->data) 
        parent->lchild=cur;
    else if(item>parent->data) 
        parent->rchild=cur;
}

void inOrder(struct TreeNode *r) {
    if (r==NULL) return;
    else {
        inOrder(r->lchild);
        printf("%-3d",r->data);
        inOrder(r->rchild);
    }
}

void preOrder(struct TreeNode *r) {
    if (r==NULL) return;
    else {
        printf("%-3d",r->data);
        preOrder(r->lchild);
        preOrder(r->rchild);
    }
}

void postOrder(struct TreeNode *r) {
    if (r==NULL) return;
    else {
        postOrder(r->lchild);
        postOrder(r->rchild);
        printf("%-3d",r->data);
    }
}

int search(int key) {
    if(root==NULL) {
        printf("No nodes present in tree\n");
        return 0;
    }
    struct TreeNode *temp=root;
    while(temp!=NULL) {
        if(key==temp->data) {
            printf("Item found\n");
            return 1;
        }
        else if(key<temp->data) {
            temp=temp->lchild;
        }
        else {
            temp=temp->rchild;
        }
    }
   printf("Item not found\n");
    return 0;
}

int countNodes(struct TreeNode *r) {
    if(r==NULL) return 0;
    else return(countNodes(r->lchild)+countNodes(r->rchild)+1);
}

int countIntNodes(struct TreeNode *r) {
    if(r==NULL) return 0;
    else if(r->lchild==NULL && r->rchild==NULL) return 0;
    else return(countIntNodes(r->lchild) + countIntNodes(r->rchild) + 1);
}

int countExtNodes(struct TreeNode *r) {
    if(r==NULL) return 0;
    else if(r->lchild==NULL && r->rchild==NULL) return 1;
    else return(countExtNodes(r->lchild) + countExtNodes(r->rchild));
}

int height(struct TreeNode *r) {
    int lh,rh;
    if (r==NULL) return 0;
    else {
        lh=height(r->lchild);
        rh=height(r->rchild);
        if(lh>rh)   return (lh+1);
        else return(rh+1);
    }
}

struct TreeNode* minimumNode(struct TreeNode *r) {
    while(r!=NULL && r->lchild!=NULL)  r=r->lchild;
    return(r);
}

struct TreeNode* maximumNode(struct TreeNode *r) {
    while(r!=NULL && r->rchild!=NULL)  r=r->rchild;
    return(r);
}

void del(int key) {
    if(root==NULL) return;
    struct TreeNode *parent=NULL, *temp=root;
    while(temp!=NULL && temp->data!=key) {
        parent=temp;
        if (key>temp->data) temp=temp->rchild;
        else temp=temp->lchild;
    }
    if(temp==NULL) {
        printf("Item not found\n");
        return;
    }
    if(temp->lchild==NULL) {
        struct TreeNode *ptr=temp->rchild;
        if (key>parent->data) parent->rchild=ptr;
        else parent->lchild=ptr;
        return;
    }
    if(temp->rchild==NULL) {
        struct TreeNode *ptr=temp->lchild;
        if (key>parent->data) parent->rchild=ptr;
        else parent->lchild=ptr;
        return;
    }
    struct TreeNode *ptr1=minimumNode(temp->rchild);
    del(ptr1->data);
    ptr1->lchild=temp->lchild;
    ptr1->rchild=temp->rchild;
    if(key>parent->data) {
        parent->rchild=ptr1;
        
    }
    else parent->lchild=ptr1;
}

int main() {
    int option;
    int item,val;
    struct TreeNode *temp;
    while(1) {
        printf("\n ***** BST*******\n");
		printf("\n  1. Insert\n");
		printf("\n  2. Inorder\n");
		printf("\n  3. Preorder\n");
		printf("\n  4. Postorder\n");
		printf("\n  5. Search\n");
		printf("\n  6. smallest\n");
		printf("\n  7. largest\n");
		printf("\n  8. delete\n");
		printf("\n  9. total number of nodes\n");
		printf("\n 10. external node\n");
		printf("\n 11. internal node\n");
		printf("\n 12. height\n");
		printf("\n Any other key. exit\n");
		printf("\n Enter your option:\n ");
		scanf("%d",&option);
		switch(option) {
		    case 1:
		        printf("Enter a value to insert = ");
		        scanf("%d",&item);
		        insert(item);
		        break;
		    case 2:
		        printf("Inorder = ");
		        inOrder(root);
		        printf("\n");
		        break;
		    case 3:
		        printf("Preorder = ");
		        preOrder(root);
		        printf("\n");
		        break;
		    case 4:
		        printf("Postorder = ");
		        postOrder(root);
		        printf("\n");
		        break;
		    case 5:
		        printf("Enter a value to search = ");
		        scanf("%d",&item);
		        search(item);
		        break;
		    case 6:
		        temp=minimumNode(root);
		        printf("smallest value = %d\n",temp->data);
		        break;
		    case 7:
		        temp=maximumNode(root);
		        printf("largest value = %d\n",temp->data);
		        break;
		    case 8:
		        printf("Enter a value to delete = ");
		        scanf("%d",&item);
		        del(item);
		        break;
		    case 9:
		        val=countNodes(root);
		        printf("Total Nodes = %d\n",val);
		        break;
		    case 10:
		        val=countExtNodes(root);
		        printf("Number of External Nodes = %d\n",val);
		        break;
		    case 11:
		        val=countIntNodes(root);
		        printf("Number of Internal Nodes = %d\n",val);
		        break;
		    case 12:
		        val=height(root);
		        printf("Height of BST = %d\n",val);
		        break;
		    default:
		        return 0;
		}
    }
}


