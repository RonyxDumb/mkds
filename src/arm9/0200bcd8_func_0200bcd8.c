/* Batch reconstruction: complete local bytes verified; full-ROM linking and caller ABI remain unverified. */
typedef struct Context{void (*callback)(int,void *);} Context;extern Context *data_0216fdec;
void func_0200bcd8(unsigned short *p){if(p[1]==0){if(p[2]!=7 && p[2]!=9 && p[2]==21){if(data_0216fdec->callback)data_0216fdec->callback(9,p);}}}