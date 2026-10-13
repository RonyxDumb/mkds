/* Decompiled C draft; module arm9_ov000; ROM address 02186bd4. No matching claim. */
#include "types.h"
#include "deps/02186bd4_FUN_02186bd4.h"

undefined4 FUN_02186bd4(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)(param_1 + DAT_02186c68);
  iVar2 = func_0x0213a434(param_3);
  iVar3 = func_0x0213a434(DAT_02186c6c);
  iVar4 = func_0x0213a434(param_2);
  iVar2 = iVar2 + iVar3 + -4 + iVar4;
  if (((int)(puVar5[2] - puVar5[1]) < iVar2 + 1) &&
     (iVar3 = FUN_02186998(param_1,puVar5,(iVar2 - (puVar5[2] - puVar5[1])) + 1), iVar3 == 0)) {
    return 1;
  }
  iVar3 = func_0x02139f70(*puVar5,DAT_02186c70);
  iVar4 = iVar3 + 2;
  uVar1 = *(undefined1 *)(iVar3 + 2);
  iVar3 = func_0x0213a434(iVar4);
  func_0x02134df8((uint *)(uintptr_t)(iVar4 + iVar2),(uint *)(uintptr_t)(iVar4),iVar3 + 1);
  iVar3 = func_0x0200d9e0(iVar4,iVar2 + 1,DAT_02186c6c,param_2,param_3);
  *(undefined1 *)(iVar4 + iVar3) = uVar1;
  puVar5[1] = puVar5[1] + iVar2;
  return 0;
}

