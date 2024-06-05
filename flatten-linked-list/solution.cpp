//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
void *mergeTwoLists(Node *&list1, Node *&list2) {
    Node dummy(0);
    Node *temp = &dummy;

    while (list1 && list2) {
        if (list1->data < list2->data) {
            temp->bottom = list1;
            list1 = list1->bottom;
        } else {
            temp->bottom = list2;
            list2 = list2->bottom;
        }
        temp = temp->bottom;
    }

    if (list1) temp->bottom = list1;
    else temp->bottom = list2;

    list1 =  dummy.bottom;
}

Node *flatten(Node *root)
{
   vector<Node*> list;
   while(root){
       list.push_back(root);
       root = root -> next;
   }
   if(list.size() == 1){
       Node dummy(0);
       Node * temp = &dummy;
       mergeTwoLists(temp,list[0]);
       return temp->bottom;
   }
   for(int i = 1; i<list.size();i++){
       mergeTwoLists(list[0], list[i]);
   }
   return list[0];
}


