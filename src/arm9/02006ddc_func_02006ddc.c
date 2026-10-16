/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
extern void func_0200704c(void *);
void func_02006ddc(unsigned short id,unsigned int arg){unsigned char cmd[156];*(unsigned int *)cmd=2;*(unsigned short *)(cmd+8)=id;*(unsigned int *)(cmd+16)=arg;func_0200704c(cmd);}