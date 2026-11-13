#include "00/Lib/CPS/code_021abd68.h"
#include "00/Lib/CPS/code_021abca0.h"
#include "00/Lib/CPS/code_021ac3a8.h"

void long_from_char(u32 *words, const u8 *bytes, u32 byteCount) {
    u32 byteIndex;
    for (byteIndex = 0; byteIndex < byteCount; byteIndex += 4) {
        *words++ = (bytes[byteIndex] << 24) | (bytes[byteIndex + 1] << 16) | (bytes[byteIndex + 2] << 8) |
                   bytes[byteIndex + 3];
    }
}

void CPSi_sha1_block(Hash20Context *context, const u8 *block) {
    u32 words[16];
    u32 stateA;
    u32 stateB;
    u32 stateC;
    u32 stateD;
    u32 stateE;
    u32 wordIndex;
    s32 groupIndex;
    stateA = context->mStateA;
    stateB = context->mStateB;
    stateC = context->mStateC;
    stateD = context->mStateD;
    stateE = context->mStateE;
    long_from_char(words, block, 0x40);
    wordIndex = 0;
    for (groupIndex = 0; groupIndex < 3; groupIndex++) {
        stateE +=
            ((stateA << 5) | (stateA >> 27)) + (stateD ^ (stateB & (stateC ^ stateD))) + words[wordIndex] + 0x5a827999;
        stateB = (stateB << 30) | (stateB >> 2);
        stateD += ((stateE << 5) | (stateE >> 27)) + (stateC ^ (stateA & (stateB ^ stateC))) + words[wordIndex + 1] +
                  0x5a827999;
        stateA = (stateA << 30) | (stateA >> 2);
        stateC += ((stateD << 5) | (stateD >> 27)) + (stateB ^ (stateE & (stateA ^ stateB))) + words[wordIndex + 2] +
                  0x5a827999;
        stateE = (stateE << 30) | (stateE >> 2);
        stateB += ((stateC << 5) | (stateC >> 27)) + (stateA ^ (stateD & (stateE ^ stateA))) + words[wordIndex + 3] +
                  0x5a827999;
        stateD = (stateD << 30) | (stateD >> 2);
        stateA += ((stateB << 5) | (stateB >> 27)) + (stateE ^ (stateC & (stateD ^ stateE))) + words[wordIndex + 4] +
                  0x5a827999;
        stateC = (stateC << 30) | (stateC >> 2);
        wordIndex += 5;
    }
    stateE += ((stateA << 5) | (stateA >> 27)) + (stateD ^ (stateB & (stateC ^ stateD))) + words[15] + 0x5a827999;
    stateB = (stateB << 30) | (stateB >> 2);
    stateD += ((stateE << 5) | (stateE >> 27)) + (stateC ^ (stateA & (stateB ^ stateC))) +
              ComputeSha1ScheduleWord(0, words) + 0x5a827999;
    stateA = (stateA << 30) | (stateA >> 2);
    stateC += ((stateD << 5) | (stateD >> 27)) + (stateB ^ (stateE & (stateA ^ stateB))) +
              ComputeSha1ScheduleWord(1, words) + 0x5a827999;
    stateE = (stateE << 30) | (stateE >> 2);
    stateB += ((stateC << 5) | (stateC >> 27)) + (stateA ^ (stateD & (stateE ^ stateA))) +
              ComputeSha1ScheduleWord(2, words) + 0x5a827999;
    stateD = (stateD << 30) | (stateD >> 2);
    stateA += ((stateB << 5) | (stateB >> 27)) + (stateE ^ (stateC & (stateD ^ stateE))) +
              ComputeSha1ScheduleWord(3, words) + 0x5a827999;
    stateC = (stateC << 30) | (stateC >> 2);
    wordIndex = 4;
    for (groupIndex = 0; groupIndex < 4; groupIndex++) {
        stateE += ((stateA << 5) | (stateA >> 27)) + (stateD ^ (stateB ^ stateC)) +
                  ComputeSha1ScheduleWord(wordIndex, words) + 0x6ed9eba1;
        stateB = (stateB << 30) | (stateB >> 2);
        stateD += ((stateE << 5) | (stateE >> 27)) + (stateC ^ (stateA ^ stateB)) +
                  ComputeSha1ScheduleWord(wordIndex + 1, words) + 0x6ed9eba1;
        stateA = (stateA << 30) | (stateA >> 2);
        wordIndex += 2;
        wordIndex &= 0xf;
        stateC += ((stateD << 5) | (stateD >> 27)) + (stateB ^ (stateE ^ stateA)) +
                  ComputeSha1ScheduleWord(wordIndex, words) + 0x6ed9eba1;
        stateE = (stateE << 30) | (stateE >> 2);
        stateB += ((stateC << 5) | (stateC >> 27)) + (stateA ^ (stateD ^ stateE)) +
                  ComputeSha1ScheduleWord(wordIndex + 1, words) + 0x6ed9eba1;
        stateD = (stateD << 30) | (stateD >> 2);
        stateA += ((stateB << 5) | (stateB >> 27)) + (stateE ^ (stateC ^ stateD)) +
                  ComputeSha1ScheduleWord(wordIndex + 2, words) + 0x6ed9eba1;
        stateC = (stateC << 30) | (stateC >> 2);
        wordIndex += 3;
    }
    for (groupIndex = 0; groupIndex < 4; groupIndex++) {
        stateE += ((stateA << 5) | (stateA >> 27)) + ((stateB & (stateC | stateD)) | (stateC & stateD)) +
                  ComputeSha1ScheduleWord(wordIndex, words) + 0x8f1bbcdc;
        stateB = (stateB << 30) | (stateB >> 2);
        stateD += ((stateE << 5) | (stateE >> 27)) + ((stateA & (stateB | stateC)) | (stateB & stateC)) +
                  ComputeSha1ScheduleWord(wordIndex + 1, words) + 0x8f1bbcdc;
        stateA = (stateA << 30) | (stateA >> 2);
        stateC += ((stateD << 5) | (stateD >> 27)) + ((stateE & (stateA | stateB)) | (stateA & stateB)) +
                  ComputeSha1ScheduleWord(wordIndex + 2, words) + 0x8f1bbcdc;
        stateE = (stateE << 30) | (stateE >> 2);
        wordIndex += 3;
        wordIndex &= 0xf;
        stateB += ((stateC << 5) | (stateC >> 27)) + ((stateD & (stateE | stateA)) | (stateE & stateA)) +
                  ComputeSha1ScheduleWord(wordIndex, words) + 0x8f1bbcdc;
        stateD = (stateD << 30) | (stateD >> 2);
        stateA += ((stateB << 5) | (stateB >> 27)) + ((stateC & (stateD | stateE)) | (stateD & stateE)) +
                  ComputeSha1ScheduleWord(wordIndex + 1, words) + 0x8f1bbcdc;
        stateC = (stateC << 30) | (stateC >> 2);
        wordIndex += 2;
    }
    for (groupIndex = 0; groupIndex < 4; groupIndex++) {
        stateE += ((stateA << 5) | (stateA >> 27)) + (stateD ^ (stateB ^ stateC)) +
                  ComputeSha1ScheduleWord(wordIndex, words) + 0xca62c1d6;
        stateB = (stateB << 30) | (stateB >> 2);
        stateD += ((stateE << 5) | (stateE >> 27)) + (stateC ^ (stateA ^ stateB)) +
                  ComputeSha1ScheduleWord(wordIndex + 1, words) + 0xca62c1d6;
        stateA = (stateA << 30) | (stateA >> 2);
        stateC += ((stateD << 5) | (stateD >> 27)) + (stateB ^ (stateE ^ stateA)) +
                  ComputeSha1ScheduleWord(wordIndex + 2, words) + 0xca62c1d6;
        stateE = (stateE << 30) | (stateE >> 2);
        stateB += ((stateC << 5) | (stateC >> 27)) + (stateA ^ (stateD ^ stateE)) +
                  ComputeSha1ScheduleWord(wordIndex + 3, words) + 0xca62c1d6;
        stateD = (stateD << 30) | (stateD >> 2);
        wordIndex += 4;
        wordIndex &= 0xf;
        stateA += ((stateB << 5) | (stateB >> 27)) + (stateE ^ (stateC ^ stateD)) +
                  ComputeSha1ScheduleWord(wordIndex, words) + 0xca62c1d6;
        stateC = (stateC << 30) | (stateC >> 2);
        wordIndex += 1;
    }
    context->mStateA += stateA;
    context->mStateB += stateB;
    context->mStateC += stateC;
    context->mStateD += stateD;
    context->mStateE += stateE;
}
