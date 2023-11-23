//Approach : Brute Force (Data replacement approach)
// tc: O(N)
// Sc: O(1)
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node *curr=head;
        int cnt0=0,cnt1=0,cnt2=0;
        while(curr){
            if(curr->data==0)cnt0++;
            if(curr->data==1)cnt1++;
            if(curr->data==2)cnt2++;
            curr=curr->next;
        }
        curr=head;
        while(curr){
            if(cnt0!=0){
                curr->data=0;
                cnt0--;
            }
            else if(cnt1!=0){
                curr->data=1;
                cnt1--;
            }
            else if(cnt2!=0){
                curr->data=2;
                cnt2--;
            }
            curr=curr->next;
        }
        return head;
    }
};



//Approach: Brute Force (Node change approach)
// Tc: O(N)
// Sc: O(1)

