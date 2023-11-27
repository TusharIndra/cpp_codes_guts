/*Approach: 1 using maps.
  TC: O(N)
  SC: O(N)
*/

class Solution
{
    void insertTail(Node *&head,Node *&tail, int d){
        Node *temp=new Node(d);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        Node *cloneHead=NULL,*cloneTail=NULL,*oghead=head;
        while(oghead!=NULL){
            insertTail(cloneHead,cloneTail, oghead->data);
            oghead=oghead->next;
        }
        oghead=head;
        Node *clh=cloneHead;
        unordered_map<Node*,Node*>ump;
        while(oghead!=NULL){
            ump[oghead]=clh;
            oghead=oghead->next;
            clh=clh->next;
        }
        oghead=head;
        clh=cloneHead;
        while(oghead!=NULL){
            clh->arb=ump[oghead->arb];
            oghead=oghead->next;
            clh=clh->next;
        }
        return cloneHead;
    }
    

};





/*Approach: 2.
  TC: O(N)
  SC: O(1)
*/


class Solution
{
    void insertTail(Node *&head,Node *&tail, int d){
        Node *temp=new Node(d);
        if(head==NULL){
            head=temp;
            tail=temp;
            return;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }
    public:
    Node *copyList(Node *head)
    {
        Node *cloneHead=NULL,*cloneTail=NULL,*oghead=head;
        //step1: Make a clone of orignal LL
        while(oghead!=NULL){
            insertTail(cloneHead,cloneTail, oghead->data);
            oghead=oghead->next;
        }
        oghead=head;
        Node *clh=cloneHead;
        Node *tempHead=head;
        //merge the Clone LL nodes in between the orignal LL nodes
        while(clh!=NULL && tempHead!=NULL){
            Node *nextt = tempHead->next;
            tempHead->next=clh;
            tempHead=nextt;
            
            nextt=clh->next;
            clh->next=tempHead;
            clh=nextt;
        }
        //step3: now set the random pointers of each Nodes
        tempHead=head;
        while(tempHead!=NULL){
            if(tempHead->next!=NULL)tempHead->next->arb=tempHead->arb?tempHead->arb->next:tempHead->arb; 
            tempHead=tempHead->next->next;
        }
        //step4: now again split the Orignal ll and clone ll that was merged in step2. 
        clh=cloneHead;
        while(clh && oghead){
            oghead->next=clh->next;
            oghead=oghead->next;
            if(oghead!=NULL)clh->next=oghead->next;
            
            clh=clh->next;
        }
        return cloneHead;
        
    }
    

};