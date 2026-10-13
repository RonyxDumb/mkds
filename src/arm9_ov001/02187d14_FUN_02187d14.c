/* Decompiled C draft; module arm9_ov001; ROM address 02187d14. No matching claim. */
#include "types.h"
#include "deps/02187d14_FUN_02187d14.h"

void FUN_02187d14(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined1 auStack_78 [12];
  undefined1 auStack_6c [12];
  undefined1 auStack_60 [12];
  int local_54;
  int local_50;
  int local_4c;
  undefined1 auStack_48 [48];
  int local_18;
  int iStack_14;
  int local_10;
  
  iVar3 = *(int *)(param_1[1] + 0x2c);
  if ((uint)*(byte *)(*param_1 + 1) == *(uint *)(iVar3 + DAT_02187db4)) {
    iVar1 = func_0x02061808();
    func_0x02012f58((int)(uintptr_t)(auStack_78),0);
    func_0x0214755c((uint *)(uintptr_t)(iVar1 + 0x30),(uint *)(void *)(auStack_48));
    func_0x0214733c((uint)(uintptr_t)(auStack_78),(uint *)(void *)(auStack_48),(uint *)(void *)(auStack_78));
    piVar2 = (int *)(iVar3 + DAT_02187db8);
    *piVar2 = local_54 << 4;
    *(int *)(iVar3 + DAT_02187dbc) = local_50 << 4;
    *(int *)(iVar3 + DAT_02187dc0) = local_4c << 4;
    if (*(int *)(iVar3 + DAT_02187dc4) != 0) {
      local_18 = *piVar2;
      iStack_14 = piVar2[1];
      local_10 = piVar2[2];
      func_0x02147fd8(*(undefined4 *)(iVar3 + DAT_02187dc8),(uint)(uintptr_t)(auStack_78),(uint)(uintptr_t)(&local_18),&local_18);
      func_0x02147fd8(*(undefined4 *)(iVar3 + DAT_02187dcc),(uint)(uintptr_t)(auStack_6c),(uint)(uintptr_t)(&local_18),&local_18);
      func_0x02147fd8(*(undefined4 *)(iVar3 + DAT_02187dd0),(uint)(uintptr_t)(auStack_60),(uint)(uintptr_t)(&local_18),&local_18);
      func_0x020fd684(*(undefined4 *)(iVar3 + DAT_02187dc4),(undefined4 *)(void *)(auStack_78),&local_18);
    }
  }
  return;
}

