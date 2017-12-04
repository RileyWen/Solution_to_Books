#include <iostream>
using namespace std;
class Node{
	public:
		Node *right_sibling,*left_child;
		int LoveValue,index,total_child_best_price,present_total_child_best_price,best_price;
		
		Node(int index,int LoveValue){
			this->index = index;
			this->LoveValue = LoveValue;
			this->right_sibling = this->left_child = NULL;
			this->total_child_best_price = -1;
			this->present_total_child_best_price = -1;
			this->best_price = -1;
		}
		
		void NewChild(Node* Index[],int index,int father_index){
			if (!this->left_child)
				this->left_child = Index[index];
			else{
				Node *current = this->left_child;
				while( current->right_sibling != NULL )
					current = current->right_sibling;
				current->right_sibling = Index[index];
			}
		}
		
		int Total_Child_Best_Price(){
			if (this->total_child_best_price>=0)
				return total_child_best_price;
			if (!this->left_child)
				return this->total_child_best_price=0;
			else{
				Node* current = this->left_child;
				int sum = 0;
				while (current!=NULL){
					sum += current->Best_Price();
					current = current->right_sibling;
				}
				return this->total_child_best_price=sum;
			}
		}
		
		int Present_Total_Child_Best_Price(){
			if (this->present_total_child_best_price>=0)
				return this->present_total_child_best_price;
			if (!this->left_child)
				return present_total_child_best_price=0;
			else{
				Node* current = this->left_child;
				int sum = 0;
				while (current!=NULL){
					sum += current->Total_Child_Best_Price();
					current = current->right_sibling;
				}
				return this->present_total_child_best_price=sum;
			}
		}
		
		int Best_Price(){
			if (this->best_price>=0)
				return this->best_price;
			if (!this->left_child)
				return this->best_price = this->LoveValue;
			else
				return this->best_price=max(this->Present_Total_Child_Best_Price() + this->LoveValue,
				                            this->Total_Child_Best_Price());
		} 	
};

int main(){
	int n,LoveValue,child_Num,current_index; cin>>n;
	Node* Index[n];
	for (int i=0;i<n;i++){
		cin>>LoveValue;
		Index[i] = new Node(i,LoveValue);
	}
	for (int i=0;i<n;i++){
		cin>>current_index>>child_Num;
		for (int j=0,child;j<child_Num;j++){
			cin>>child;
			Index[current_index]->NewChild(Index,child,current_index);
		}
	}
	
	int k=0;
	cout<<"\nTotal_Child_Best_Price:"<<Index[k]->Best_Price();
	cout<<"\nLoveValue"<<Index[k]->LoveValue;
	
	return 0;
}

 

/*---------------------------------------------------------
Sample input:
6
2 3 5 4 4 1
0 3 2 3 5
2 1 1
1 1 4
3 0
4 0
5 0
6
20 3 5 4 5 30
0 2 2 3
2 1 1
3 1 4
1 0
4 1 5
5 0

Sample Output:
13
53
-------------------------------------------------------------*/
