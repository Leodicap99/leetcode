   Node* copyRandomList(Node* head) {
        if(head==NULL)return NULL;
        unordered_map<Node*,Node*> map;
        Node* result=new Node(head->val);
        map[head]=result;
        Node* p1=head->next,*p2=result;
        while(p1)
        {
            p2->next=new Node(p1->val);
            p2=p2->next;
            map[p1]=p2;
            p1=p1->next;
        }
        p1=head,p2=result;
        while(p1)
        {
            p2->random=map[p1->random];
            p1=p1->next;
            p2=p2->next;
        }
        return result;
