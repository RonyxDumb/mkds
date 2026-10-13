/* Decompiled C draft; module arm9; ROM address 02000a5c. No matching claim. */
#include "types.h"
#include "deps/02000a5c_Crt0_InitializePU.h"

uint Crt0_InitializePU(void)

{
  uint uVar1;
  undefined4 in_cr0;
  undefined4 in_cr1;
  undefined4 in_cr2;
  undefined4 in_cr3;
  undefined4 in_cr4;
  undefined4 in_cr5;
  undefined4 in_cr6;
  undefined4 in_cr7;
  undefined4 in_cr9;
  
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & ~uRam02000b14);
  coproc_moveto_Invalidate_Entire_Instruction(0);
  coproc_moveto_Invalidate_Entire_Data_cache(0);
  coproc_moveto_Data_Synchronization(0);
  coprocessor_moveto(0xf,0,0,uRam02000b18,in_cr6,in_cr0);
  coprocessor_moveto(0xf,0,0,uRam02000b1c,in_cr6,in_cr1);
  coprocessor_moveto(0xf,0,0,uRam02000b20,in_cr6,in_cr2);
  coprocessor_moveto(0xf,0,0,uRam02000b24,in_cr6,in_cr3);
  coprocessor_moveto(0xf,0,0,uRam02000b28 | 0x1b,in_cr6,in_cr4);
  coprocessor_moveto(0xf,0,0,uRam02000b2c,in_cr6,in_cr5);
  coprocessor_moveto(0xf,0,0,uRam02000b30,in_cr6,in_cr6);
  coprocessor_moveto(0xf,0,0,uRam02000b34,in_cr6,in_cr7);
  coprocessor_moveto(0xf,0,1,0x20,in_cr9,in_cr1);
  coprocessor_moveto(0xf,0,0,uRam02000b28 | 10,in_cr9,in_cr1);
  coproc_moveto_Translation_table_base_1(0x42);
  coproc_moveto_Translation_table_base_0(0x42);
  coproc_moveto_Domain_Access_Control(2);
  coprocessor_moveto(0xf,0,3,uRam02000b38,in_cr5,in_cr0);
  coprocessor_moveto(0xf,0,2,uRam02000b3c,in_cr5,in_cr0);
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 | uRam02000b40);
  return uVar1 | uRam02000b40;
}

