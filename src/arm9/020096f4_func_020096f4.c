/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct Node{unsigned char pad[1212];struct Node *next;} Node;extern Node *data_0216fc4c;
void func_020096f4(Node *n){Node *p=data_0216fc4c;if(!p)data_0216fc4c=n;else{Node *q=p->next;while(q){p=q;q=q->next;}p->next=n;}n->next=0;}