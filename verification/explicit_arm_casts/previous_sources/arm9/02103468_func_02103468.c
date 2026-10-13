/* Decompiled C draft; module arm9; ROM address 02103468. No matching claim. */
#include "types.h"
#include "deps/02103468_func_02103468.h"

void func_02103468(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  uVar2 = Mem_AllocateHeap(uVar2,0xd0);
  *puRam021034f8 = uVar2;
  *puRam02103500 = (short)uRam021034fc;
  *puRam02103504 = 0;
  *puRam02103508 = 0;
  uVar2 = func_02108e6c(6);
  func_0212c6f0(uVar2,1);
  uVar2 = CreateBillboardModel_from_thumb(uRam0210350c,0,uRam02103510);
  func_0210340c(uRam02103514,uVar2);
  uVar1 = GetIncrementSomeItemCounter();
  *puRam02103518 = uVar1;
  iVar3 = 0;
  do {
    GetIncrementSomeItemCounter();
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  *puRam0210351c = 0;
  *puRam02103520 = 0;
  G3i_OrthoW_(uRam02103530,uRam02103534,uRam02103538,uRam0210353c,0,uRam02103524,uRam02103528,1,
              uRam0210352c);
  *puRam02103540 = 1;
  return;
}

