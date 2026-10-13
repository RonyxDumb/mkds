/* Decompiled C draft; module arm9; ROM address 020872a4. No matching claim. */
#include "types.h"
#include "deps/020872a4_func_020872a4.h"

void func_020872a4(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_20;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  SetupDriverEmblems_from_thumb();
  *puRam020873c0 = 0;
  uVar3 = Mem_AllocateHeapAligned(uVar2,0x20,0xfffffffc);
  *puRam020873c4 = uVar3;
  uVar3 = Mem_AllocateHeapAligned(uVar2,uRam020873c8,0xfffffffc);
  *puRam020873cc = uVar3;
  uVar3 = Mem_AllocateHeapAligned(uVar2,8,0xfffffffc);
  *puRam020873d0 = uVar3;
  uVar3 = Mem_AllocateHeapAligned(uVar2,uRam020873d4,0xfffffffc);
  *puRam020873d8 = uVar3;
  local_20 = 0;
  iVar4 = *piRam020873dc;
  if (0 < *(int *)(iVar4 + 0x20)) {
    do {
      iVar5 = *(int *)(iVar4 + local_20 * 4 + 0xc4);
      iVar4 = *(int *)(iVar5 + 0x1c);
      *(undefined4 *)(iVar4 + 4) = uRam020873d4;
      *(undefined2 *)(iVar4 + 8) = 0x20;
      *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(*piRam020873dc + iRam020873e0);
      uVar1 = GetVsRacerIndicatorColor_from_thumb(*(undefined2 *)(iVar5 + 0xc));
      *(undefined2 *)(iVar5 + 0x26) = uVar1;
      StructAERSubSub_Fn1_Sub1_from_thumb(iVar4,*(undefined2 *)(iVar5 + 0xc));
      StructAERSubSub_Fn1_Sub2_from_thumb(iVar4 + 0x24,*(undefined2 *)(iVar5 + 0xc));
      StructAERSubSub_Fn1_Sub3_from_thumb(iVar4 + 0x48,*(undefined2 *)(iVar5 + 0xc));
      StructAERSubSub_Fn1_Sub4_from_thumb(iVar4 + 0x6c,*(undefined2 *)(iVar5 + 0xc));
      StructAERSubSub_SomeFn_from_thumb((uint *)(uintptr_t)(iVar4));
      StructAERSubSub_SomeFn_from_thumb((uint *)(uintptr_t)(iVar4 + 0x24));
      StructAERSubSub_SomeFn_from_thumb((uint *)(uintptr_t)(*(int *)(iVar5 + 0x1c) + 0x48));
      if (*(int *)(iVar4 + 0x78) != 0) {
        StructAERSubSub_SomeFn_from_thumb((uint *)(uintptr_t)(iVar4 + 0x6c));
      }
      local_20 = local_20 + 1 & 0xffff;
      iVar4 = *piRam020873dc;
    } while ((int)local_20 < *(int *)(iVar4 + 0x20));
  }
  Mem_FreeHeap(uVar2,*puRam020873d8);
  Mem_FreeHeap(uVar2,*puRam020873d0);
  Mem_FreeHeap(uVar2,*puRam020873cc);
  Mem_FreeHeap(uVar2,*puRam020873c4);
  return;
}

