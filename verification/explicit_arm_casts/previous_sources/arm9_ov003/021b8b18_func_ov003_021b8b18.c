/* Decompiled C draft; module arm9_ov003; ROM address 021b8b18. No matching claim. */
#include "types.h"
#include "deps/021b8b18_func_ov003_021b8b18.h"

undefined4 func_ov003_021b8b18(undefined1 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  
  func_ov003_021b7d84(param_2,0,DAT_021b8be4);
  iVar1 = DAT_021b8be8;
  puVar4 = param_1;
  while( true ) {
    iVar2 = func_ov003_021b7c44(*(undefined2 *)(puVar4 + 2));
    if (iVar2 < 1) {
      return 0xffffffff;
    }
    switch(*puVar4) {
    case 0:
      func_ov003_021b7d90(param_2,puVar4 + 6);
      break;
    case 1:
      func_ov003_021b7d90(param_2 + 0x80,puVar4 + 6);
      break;
    case 2:
      func_ov003_021b7d90(param_2 + DAT_021b8bec,puVar4 + 6);
      break;
    case 3:
    case 4:
      iVar2 = func_ov003_021b7c44(puVar4[6]);
      if (iVar2 < 1) {
        return 0xfffffffe;
      }
      break;
    case 5:
      func_ov003_021b8af4(puVar4 + 6,iVar2);
      uVar3 = func_ov003_021b7c5c();
      *(undefined4 *)(iVar1 + 0x10) = uVar3;
      break;
    case 6:
      func_ov003_021b8af4(puVar4 + 6,iVar2);
      uVar3 = func_ov003_021b7c5c();
      *(undefined4 *)(iVar1 + 0x14) = uVar3;
      break;
    default:
      return 0xffffffff;
    }
    if (*(short *)(puVar4 + 4) == 0) break;
    iVar2 = func_ov003_021b7c44();
    puVar4 = param_1 + iVar2;
  }
  return 0;
}

