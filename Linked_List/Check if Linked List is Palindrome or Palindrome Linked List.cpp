class Solution{
  public:
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        Node *s=head, *f=head;
        //traverse 2 pointers s,f. when f==null then s will be at the center of the linked list
        while(f&&f->next){
            f=f->next->next;
            s=s->next;
        }
        //Now we reverse the half of the linked list
        Node *curr=s,*prev=NULL,*next=NULL;
        while(curr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        //now we check one by one 
        while(prev!=NULL && head!=NULL){
            if(prev->data!=head->data)return false;
            head=head->next;
            prev=prev->next;
        }
        return true;
    }
};
