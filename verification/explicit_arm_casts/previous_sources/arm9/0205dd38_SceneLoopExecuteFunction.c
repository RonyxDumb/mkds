/* Decompiled C draft; module arm9; ROM address 0205dd38. No matching claim. */
#include "types.h"
#include "deps/0205dd38_SceneLoopExecuteFunction.h"

undefined4 SceneLoopExecuteFunction(short *param_1)

{
  undefined2 *puVar1;
  bool bVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  undefined1 auStack_38 [20];
  uint uVar6;
  
  func_0205e0b0();
  uVar4 = DAT_0205ded0;
  puVar1 = DAT_0205decc;
switchD_0205ddc4_default:
  uVar7 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  uVar6 = uVar7 + 4 & 3;
  uVar5 = *(uint *)(uVar7 + 4 & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if ((uVar6 == 3) ||
     (uVar6 == (*(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
               *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20))) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (!bVar2) {
    GetActiveExecutionContext();
    uVar3 = ExecutionContext_GetHeapHandle();
    if ((*DAT_0205dedc != 2) &&
       (uVar4 = (*(uint *)(DAT_0205ded0 & 0xfffffffc) >> (DAT_0205ded0 & 3) * 8 |
                *(uint *)(DAT_0205ded0 & 0xfffffffc) << (DAT_0205ded0 & 3) * -8 + 0x20) + 0xc,
       uVar6 = uVar4 & 3, uVar4 = *(uint *)(uVar4 & 0xfffffffc),
       uVar4 >> uVar6 * 8 != 0 || uVar4 << uVar6 * -8 + 0x20 != 0)) {
      DisposeSomeSoundStuff();
      uVar4 = (*(uint *)(DAT_0205ded0 & 0xfffffffc) >> (DAT_0205ded0 & 3) * 8 |
              *(uint *)(DAT_0205ded0 & 0xfffffffc) << (DAT_0205ded0 & 3) * -8 + 0x20) + 0xc;
      uVar6 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      Mem_FreeHeap(uVar3,uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
      *(undefined4 *)
       ((*(uint *)(DAT_0205ded0 & 0xfffffffc) >> (DAT_0205ded0 & 3) * 8 |
        *(uint *)(DAT_0205ded0 & 0xfffffffc) << (DAT_0205ded0 & 3) * -8 + 0x20) + 0xc) = 0;
    }
    uVar6 = *(uint *)(DAT_0205ded0 & 0xfffffffc) >> (DAT_0205ded0 & 3) * 8 |
            *(uint *)(DAT_0205ded0 & 0xfffffffc) << (DAT_0205ded0 & 3) * -8 + 0x20;
    uVar4 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
    if (uVar4 == 0) {
      func_02054330();
    }
    else if (uVar4 == 1) {
      func_02120514();
    }
    return 0;
  }
  *(undefined4 *)(uVar7 + 4) = 3;
  *puVar1 = puVar1[1];
  puVar1[1] = *param_1;
  puVar1[2] = 0xffff;
  uVar6 = DAT_0205ded4 + *param_1 * 4;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  ExecutionContext_Create(auStack_38,uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  ExecutionContext_Execute(auStack_38,puVar1);
  uVar6 = DAT_0205ded8;
  if (puVar1[2] == -1) {
    *param_1 = 9;
  }
  else {
    *param_1 = puVar1[2];
    uVar6 = DAT_0205ded8;
  }
  uVar6 = (*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
          *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) + 0x20;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  switch(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    *(undefined4 *)
     ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
      *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 4) = 1;
    goto switchD_0205ddc4_default;
  case 4:
    LoadExecuteOverlay1();
    *(undefined4 *)
     ((*(uint *)(DAT_0205ded8 & 0xfffffffc) >> (DAT_0205ded8 & 3) * 8 |
      *(uint *)(DAT_0205ded8 & 0xfffffffc) << (DAT_0205ded8 & 3) * -8 + 0x20) + 0x20) = 3;
  default:
    goto switchD_0205ddc4_default;
  }
  *(undefined4 *)
   ((*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
    *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) + 4) = 0;
  goto switchD_0205ddc4_default;
}

