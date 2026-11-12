#include "Main/Sound/character_seq_pair.h"
#include "Main/Unknown/unk_02153000.h"

#pragma thumb on
u32 GetCharacterSeqPairNo(u32 characterIndex) {
    return gCharacterSeqPairNoTable[characterIndex];
}
#pragma thumb off
