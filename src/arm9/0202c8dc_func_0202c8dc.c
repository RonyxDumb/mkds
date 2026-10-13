/* Decompiled C draft; module arm9; ROM address 0202c8dc. No matching claim. */
#include "types.h"
#include "deps/0202c8dc_func_0202c8dc.h"

void func_0202c8dc(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  short local_1e [5];
  
  uVar2 = func_020b47cc(uRam0202c958);
  uVar2 = Bmg_GetRawStringPointer_from_thumb(uVar2,0x72);
  piVar1 = piRam0202c95c;
  local_1e[0] = 0;
  local_1e[1] = 0;
  iVar4 = *(int *)(*piRam0202c95c + 0x48);
  if (iVar4 < 8) {
    iVar3 = iVar4 * 0x2c;
    do {
      Mem_CpuFill16(0,*piVar1 + 0x60 + iVar3,0x16);
      CopyMemory16(uVar2,*piVar1 + 0x60 + iVar3,0x14);
      local_1e[0] = ((short)iVar4 + 0x31) - (short)*(undefined4 *)(*piVar1 + 0x48);
      SomeStrcat16((short *)(uintptr_t)(*piVar1 + 0x60 + iVar3),local_1e,1);
      iVar3 = iVar3 + 0x2c;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
  }
  return;
}

