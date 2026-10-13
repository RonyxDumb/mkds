/* Decompiled C draft; module arm9; ROM address 0204bfac. No matching claim. */
#include "types.h"
#include "deps/0204bfac_func_0204bfac.h"

void func_0204bfac(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  
  uVar2 = Os_DisableIrq();
  if (*(uint *)((uint)puRam0204c080 & 0xfffffffc) >> ((uint)puRam0204c080 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam0204c080 & 0xfffffffc) << ((uint)puRam0204c080 & 3) * -8 + 0x20 == 0) {
    *puRam0204c080 = 1;
    func_0204c28c(param_1,param_2,param_3,param_4);
    Os_RestoreIrq(uVar2);
    uVar2 = uRam0204c088;
    puVar1 = puRam0204c084;
    puVar6 = puRam0204c084 + 0x110;
    *puRam0204c084 = 0;
    Arm_FlushRange(puVar6,uVar2);
    Mem_DcDrainWriteBuffer();
    puVar3 = puVar1 + 0x140;
    iVar4 = 0;
    do {
      puVar6[iVar4] = puVar3;
      puVar6[iVar4 + 0x10] = 0;
      iVar5 = iVar4 + 1;
      puVar6[iVar4 + 0x20] = 0;
      puVar3 = puVar3 + 10;
      iVar4 = iVar5;
    } while (iVar5 < 0x10);
    puVar1[0x3cf] = 0;
    puVar1[0x3d1] = 0;
    uVar2 = uRam0204c088;
    puVar1[0x3d2] = 0;
    Arm_FlushRange(puVar6,uVar2);
    Mem_DcDrainWriteBuffer();
    func_02006a10(uRam0204c08c);
    puVar1[3] = 1;
    return;
  }
  return;
}

