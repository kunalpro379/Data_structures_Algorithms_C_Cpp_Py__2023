
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


    Node* mergeLL(Node* a,Node* b ){
           if(!b){
               return a;
           }
           if(!a){
               return b;
           }
    Node* ans=0;
    if((a->data)<(b->data)){
       ans=a;
       a->bottom=mergeLL(a->bottom,b);

    }
    else {
       ans=b;
       b->bottom=mergeLL(a,b->bottom);

    }
    return ans;


    }
Node *flatten(Node *root)
{
    if(!root){
        return 0;
    }
    Node* mergedRev=mergeLL(root,flatten(root->next));
   // Yorettur code here
   return mergedRev;
}
