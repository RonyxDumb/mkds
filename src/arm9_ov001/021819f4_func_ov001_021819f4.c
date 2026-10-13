/* Decompiled C draft; module arm9_ov001; ROM address 021819f4. No matching claim. */
#include "types.h"
#include "deps/021819f4_func_ov001_021819f4.h"

void func_ov001_021819f4(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  func_0x020364e8();
  uVar2 = func_0x020364e0();
  iVar3 = func_0x02036bec(uVar2,0x68);
  *piRam02181a5c = iVar3;
  iVar3 = func_0x0207a974((short)*(char *)(*piRam02181a60 + 0x62));
  piVar1 = piRam02181a5c;
  iVar4 = *piRam02181a5c;
  uVar2 = *(undefined4 *)(iVar3 + 0x84);
  *(undefined4 *)(iVar4 + 0x34) = *(undefined4 *)(iVar3 + 0x80);
  *(undefined4 *)(iVar4 + 0x38) = uVar2;
  *(undefined4 *)(iVar4 + 0x3c) = *(undefined4 *)(iVar3 + 0x88);
  *(undefined4 *)(iVar4 + 0x28) = *(undefined4 *)(iVar4 + 0x34);
  *(undefined4 *)(iVar4 + 0x2c) = *(undefined4 *)(iVar4 + 0x38);
  *(undefined4 *)(iVar4 + 0x30) = *(undefined4 *)(iVar4 + 0x3c);
  *(undefined2 *)(iVar4 + 0x42) = *(undefined2 *)(iVar3 + iRam02181a64);
  *(undefined2 *)(*piVar1 + 0x40) = *(undefined2 *)(*piVar1 + 0x42);
  return;
}

