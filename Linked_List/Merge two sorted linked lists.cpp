Node* sortedMerge(Node* head1, Node* head2)  
{  
    Node *curr,*head;
    if(head1==NULL)return head2;
    if(head2==NULL)return head1;
    if(head1->data>head2->data){
        head=head2;
        head2=head->next;
    }
    else{
        head=head1;
        head1=head1->next;
    }
    curr=head;
    while(head1!=NULL&&head2!=NULL){
        if(head1->data>head2->data){
            curr->next=head2;
            curr=head2;
            head2=head2->next;
            curr->next=NULL;
        }
        else{
            curr->next=head1;
            curr=head1;
            head1=head1->next;
            curr->next=NULL;
        }
    }
    if(head1==NULL)curr->next=head2;
    if(head2==NULL)curr->next=head1;
    return head;
    // code here
}  