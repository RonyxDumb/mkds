/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct Node{int id; char pad[36];struct Node *next;} Node;extern Node *GetGlobalGO_from_thumb(void);
Node *FindGlobalGOBy_from_thumb(int id){Node *p=GetGlobalGO_from_thumb();while(p){if(p->id==id)return p;p=p->next;}return 0;}