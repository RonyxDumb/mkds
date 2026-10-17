/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern void func_02124ed0(int,int,int,int *);
extern void AllocateReserveTEQSub(int,int,int,int);
void func_02025a50(int sub,int heap,int *graphics){int reserve;
func_02124ed0(heap,graphics[3],graphics[5],graphics+6);
if(sub==0){reserve=19;AllocateReserveTEQSub(14,0,((int *)graphics[1])[3],416);
AllocateReserveTEQSub(14,448,((int *)graphics[1])[3]+448,64);}
else{reserve=35;AllocateReserveTEQSub(30,0,((int *)graphics[1])[3],((int *)graphics[1])[2]);}
AllocateReserveTEQSub(reserve,0,((int *)graphics[0])[5],((int *)graphics[0])[4]);}
