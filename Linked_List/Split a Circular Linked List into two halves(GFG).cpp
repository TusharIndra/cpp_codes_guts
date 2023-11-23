void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    Node *s=head,*f=head;
    while(f->next!=head && f->next->next!=head){
        f=f->next->next;
        s=s->next;
    }
    if(f->next->next==head)f->next->next=s->next;
    else f->next=s->next;
    *head2_ref=s->next;
    s->next=head;
    *head1_ref=head;
  