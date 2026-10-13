/* Decompiled C draft; module arm9_ov000; ROM address 0219ac7c. No matching claim. */
#include "types.h"
#include "deps/0219ac7c_FUN_0219ac7c.h"

undefined4 FUN_0219ac7c(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  
  if (*DAT_0219ad1c != 1) {
    return 2;
  }
  iVar1 = FUN_0219ad20();
  if (iVar1 == 0) {
    return 3;
  }
  piVar2 = (int *)FUN_0219b178();
  if (piVar2 == (int *)0x0) {
    return 1;
  }
  piVar2[1] = param_1;
  piVar2[3] = param_3;
  piVar2[2] = param_2;
  piVar2[0xd] = param_4;
  piVar2[0xe] = param_5;
  piVar2[0xf] = param_6;
  iVar1 = FUN_0218e554(2,2,0);
  *piVar2 = iVar1;
  piVar2[8] = 0;
  *(undefined1 *)((int)piVar2 + 0x32) = 0;
  *(undefined1 *)((int)piVar2 + 0x33) = 0;
  piVar2[0xb] = 0;
  *(undefined2 *)(piVar2 + 0xc) = 0;
  piVar2[9] = 0;
  if (*piVar2 == -1) {
    FUN_0219b130(piVar2);
    return 2;
  }
  FUN_0219aeb0(piVar2);
  return 0;
}

