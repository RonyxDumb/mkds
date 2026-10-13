/* Decompiled C draft; module arm9; ROM address 02005bec. No matching claim. */
#include "types.h"
#include "deps/02005bec_func_02005bec.h"

undefined4 func_02005bec(int param_1,int param_2,undefined4 param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 local_24;
  undefined4 local_20;
  
  local_20 = 0;
  iVar7 = param_1 + iRam02005cbc;
  puVar6 = (undefined1 *)(param_1 + iRam02005cc0 + param_2 * 0x68);
  if (*(char *)(param_1 + iRam02005cc0 + param_2 * 0x68) == '\x02') {
    iVar2 = func_02006ffc();
    if (iVar2 == 0) {
      local_24 = uRam02005cc4;
    }
    else {
      local_24 = 1;
    }
    if (puVar6[1] == '\x04') {
      iVar2 = FindGlobalGOBy_from_thumb(*(undefined4 *)(puVar6 + 0x10));
      if ((iVar2 != 0) &&
         (iVar3 = func_02006458(*(undefined4 *)(puVar6 + 0x10),*(undefined4 *)(puVar6 + 0x14)),
         iVar3 != -1)) {
        if (*(short *)(iVar2 + 0x32) == 0) {
          uVar4 = func_020063f4(*(undefined4 *)(puVar6 + 0x10),iVar3);
          uVar5 = func_020070d8();
          local_20 = func_0200671c(param_3,local_24,puVar6[2],*(undefined4 *)(puVar6 + 0x10),iVar3,
                                   uVar4,uVar5);
        }
        else if (*(short *)(iVar2 + 0x32) == 1) {
          *(undefined4 *)(iVar7 + 0x14) = *(undefined4 *)(puVar6 + 0x10);
          *(int *)(iVar7 + 0x18) = iVar3;
          uVar1 = func_020070d8();
          *(undefined2 *)(iVar7 + 0x20) = uVar1;
          *(undefined4 *)(iVar7 + 0x1c) = 0;
          func_020061d8(param_1,0xd,param_2);
          if (*(int *)(iVar7 + 0x1c) != 0) {
            local_20 = func_0200671c(param_3,local_24,puVar6[2],*(undefined4 *)(iVar7 + 0x14),
                                     *(undefined4 *)(iVar7 + 0x18),*(int *)(iVar7 + 0x1c),
                                     (int)*(short *)(iVar7 + 0x20));
          }
        }
      }
      *puVar6 = 1;
    }
  }
  return local_20;
}

