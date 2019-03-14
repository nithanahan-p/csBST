#include<iostream>
using namespace std;

class node{
   public:
   int data;
   node*left;
   node*right;
   node(int value){
     data=value;
     left=NULL;
     right=NULL;
   }
};
class BST{
  public:
  node*root;
  BST(){
  root=NULL;}

void insert(int value){
   inserthelper(root,value);
}
void inserthelper(node*curr,int value){
   //base case if curr is null
   if(curr==NULL){
   curr=new node(value);
       if(root==NULL)
       root=curr;
       return;
   }

   //else compare the data with value and move to left or right
   else if(value<curr->data){
   //move left and insert
   if(curr->left==NULL)curr->left=new node(value);
   else inserthelper(curr->left,value);}
      else{
      //move right and insert
       if(curr->right==NULL)curr->right=new node(value);
       else inserthelper(curr->right,value);
      }
}

   
void display(){
   display2(root);
   cout<<endl;}
void display2(node*curr){
    //base condition
   if(curr==NULL) return;
   //display left
   
  else{
   display2(curr->left);
   //display curr
   cout<<curr->data<<",";
   //display right
   display2(curr->right);}
}

node*search1(node*curr,int value){
	//if value found or reach the end of the tree
	if(curr==NULL||curr->data==value)return curr;
	else if(value<curr->data) search1(curr->left,value);
	else search1(curr->right,value);}
bool search(int value){
	if(search1(root,value)!=NULL){
	cout<<"found"<<endl;}
	else{
		cout<<"not found"<<endl;}
	}
};
int main(){
    BST b1;
    b1.insert(10);
    b1.insert(4);
    b1.insert(6);
    b1.insert(1);
    b1.insert(5);
    b1.display();
    b1.search(8);
    b1.insert(8);
    b1.display();
    b1.search(8);
}
