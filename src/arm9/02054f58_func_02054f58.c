/* Decompiled C draft; module arm9; ROM address 02054f58. No matching claim. */
#include "types.h"
#include "deps/02054f58_func_02054f58.h"

int func_02054f58(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_02055030();
  if (iVar2 != 3) {
    return iVar2;
  }
  uVar3 = (*(uint *)(DAT_0205502c & 0xfffffffc) >> (DAT_0205502c & 3) * 8 |
          *(uint *)(DAT_0205502c & 0xfffffffc) << (DAT_0205502c & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  switch(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) {
  case 0x16:
    goto LAB_02054fec;
  case 0x17:
    goto LAB_02054fec;
  case 0x18:
    goto LAB_02054fec;
  case 0x19:
LAB_02054fec:
    StructZE_StateFn22_23_24_25_from_thumb();
    goto LAB_02055008;
  case 0x1a:
    break;
  case 0x1b:
    break;
  case 0x1c:
    goto LAB_02054ffc;
  case 0x1d:
    goto LAB_02054ffc;
  case 0x1e:
    goto LAB_02054ffc;
  case 0x1f:
    break;
  case 0x20:
    break;
  case 0x21:
    goto LAB_02054ffc;
  case 0x22:
    goto LAB_02054ffc;
  case 0x23:
LAB_02054ffc:
    StructZE_StateFn_28_29_30_33_34_35_from_thumb();
    goto LAB_02055008;
  case 0x24:
    break;
  case 0x25:
    break;
  case 0x26:
    break;
  case 0x27:
    goto LAB_02054ff4;
  case 0x28:
    goto LAB_02054ff4;
  case 0x29:
    goto LAB_02054ff4;
  case 0x2a:
    goto LAB_02054ff4;
  case 0x2b:
    goto LAB_02054ff4;
  case 0x2c:
    goto LAB_02054ff4;
  case 0x2d:
    break;
  case 0x2e:
LAB_02054ff4:
    func_0204eca0();
    goto LAB_02055008;
  }
  func_020533a0();
LAB_02055008:
  *(undefined4 *)
   ((*(uint *)(DAT_0205502c & 0xfffffffc) >> (DAT_0205502c & 3) * 8 |
    *(uint *)(DAT_0205502c & 0xfffffffc) << (DAT_0205502c & 3) * -8 + 0x20) + 8) = 9;
  return 0;
}

