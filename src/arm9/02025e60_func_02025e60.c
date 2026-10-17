/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern int GetGlobalCA_from_thumb(void);
extern int data_02153274[],data_02153240[];
int func_02025e60(int character){int result=-1;int mode=*(int *)(GetGlobalCA_from_thumb()+200);
switch(mode){case 0:case 1:case 3:case 5:{int *table=data_02153274;result=table[character];}break;
case 2:{int *table=data_02153240;result=table[character];}break;}return result;}
