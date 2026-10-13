/* Decompiled C draft; module arm9; ROM address 0213368c. No matching claim. */
#include "types.h"
#include "deps/0213368c_func_0213368c.h"

/* WARNING: Control flow encountered bad instruction data */

void func_0213368c(void)

{
  undefined4 in_pc;
  undefined4 in_cr0;
  undefined4 in_cr15;
  
  coprocessor_moveto(0,7,7,in_pc,in_cr15,in_cr0);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

