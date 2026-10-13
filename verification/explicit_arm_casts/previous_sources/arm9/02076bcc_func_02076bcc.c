/* Decompiled C draft; module arm9; ROM address 02076bcc. No matching claim. */
#include "types.h"
#include "deps/02076bcc_func_02076bcc.h"

void func_02076bcc(undefined4 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  puVar2 = puRam02076c3c;
  uVar3 = param_1[0x28];
  uVar5 = param_1[0x29];
  *puRam02076c3c = param_1[0x27];
  puVar2[1] = uVar3;
  puVar2[2] = uVar5;
  puVar2 = puRam02076c40;
  uVar3 = param_1[1];
  uVar5 = param_1[2];
  *puRam02076c40 = *param_1;
  puVar2[1] = uVar3;
  puVar2[2] = uVar5;
  puVar2 = puRam02076c44;
  uVar3 = param_1[0x25];
  uVar5 = param_1[0x26];
  *puRam02076c44 = param_1[0x24];
  puVar2[1] = uVar3;
  puVar2[2] = uVar5;
  G3i_LookAt_(param_1 + 0x27,param_1,param_1 + 0x24,0,uRam02076c48);
  uVar1 = iRam02076c4c + 0xfcU & 3;
  uVar4 = *(uint *)(iRam02076c4c + 0xfcU & 0xfffffffc);
  *(uint *)(iRam02076c4c + 0xfc) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) & 0xffffff17;
  return;
}

