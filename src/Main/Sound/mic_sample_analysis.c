#include "Main/Sound/mic_sample_analysis.h"
#include "arena_cache_init.h"
#include "linked_palette_vram_alloc.h"
#include "microphone_sampling.h"
#include "linked_texture_vram_alloc.h"
#include "thread_scheduler.h"

u32 ClampMicSample(u32 rawSample) {
    u32 sample = rawSample;
    u32 compareLeft0;
    u32 compareRight0;
    compareLeft0 = sample;
    compareRight0 = 0xffu;
    if (compareLeft0 == compareRight0) {
        sample = 0xfeu;
    }
    return sample;
}

u8 gMicSampleAnalysisMode = MICROPHONE_ANALYSIS_MODE_MIDDLE;

u8 gMicSampleAnalysisValue;
s32 gMicMaxCrossingInterval;
s32 gMicMaxAmplitude;
s32 gMicNearMaxSampleCount;
MICAutoParam *gMicSampleAnalysisParam;
s32 gMicSampleAnalysisRunning;
s32 gMicSampleAnalysisMatchCount;
u8 gMicIntervalHistogram[4];
s32 gMicCrossingLevel;

s32 GetMicSampleAmplitude(s32 sample) {
    if (sample > 0x7f && sample <= 0xfe) {
        return sample - 0x7f;
    }
    return 0x7f - sample;
}

void InitMicSampleAnalysis(MICAutoParam *autoParam) {
    s32 bucketIndex;

    gMicSampleAnalysisParam = autoParam;
    gMicSampleAnalysisRunning = 1;
    gMicSampleAnalysisValue = 0;
    gMicSampleAnalysisMatchCount = 0;
    for (bucketIndex = 0; bucketIndex < 4; bucketIndex++) {
        gMicIntervalHistogram[bucketIndex] = 0;
    }
}

void StartMicSampleAnalysis(void) {
    gMicSampleAnalysisRunning = 1;
}

void StopMicSampleAnalysis(void) {
    if (gMicSampleAnalysisRunning == 0) {
        return;
    }
    gMicSampleAnalysisRunning = 0;
    gMicSampleAnalysisValue = 0;
    gMicSampleAnalysisMatchCount = 0;
}

void SetMicSampleAnalysisMode(u32 mode) {
    gMicSampleAnalysisMode = mode;
}

u8 UpdateMicSampleAnalysis(void) {
    u8 *samplePtr;
    s32 cappedLevel;
    s32 prev;
    s32 minInterval;
    s32 lastCrossing;
    s32 cnt3;
    s32 requiredMatches;
    s32 len;
    u16 pos;
    u8 *buf;
    s32 crossingCount;
    s32 maxAmplitude;
    s32 maxInterval;
    s32 nearMaxCount;
    s32 sampleIndex;
    s32 interval;
    s32 sample;
    s32 bucketIndex;
    s32 secondBucketIndex;
    s32 scale;
    s32 ok;
    s32 level;

    crossingCount = 0;
    cappedLevel = 0;
    len = gMicSampleAnalysisParam->mSize;
    lastCrossing = 9999;
    maxAmplitude = 0;
    requiredMatches = 2;
    prev = 0;
    cnt3 = 0;
    maxInterval = 0;
    nearMaxCount = 0;
    if (gMicSampleAnalysisRunning == 0) {
        return 0;
    }
    minInterval = len;
    samplePtr = MIC_GetLastSamplingAddress();
    buf = gMicSampleAnalysisParam->mBuffer;
    pos = samplePtr - buf;
    if (pos >= len / 8) {
        sampleIndex = pos - len / 8;
        DC_InvalidateRange(buf + sampleIndex, pos);
        for (; sampleIndex < pos; sampleIndex++) {
            if (gMicSampleAnalysisParam->mType == 0) {
                sample = GetMicSampleAmplitude(ClampMicSample(buf[sampleIndex]));
            } else {
                sample = (s8) buf[sampleIndex];
                if (sample < 0) {
                    sample = -sample;
                }
            }
            if (sample >= 125) {
                nearMaxCount++;
            }
            if (sample > maxAmplitude) {
                maxAmplitude = sample;
            }
        }
    } else {
        sampleIndex = len - (len / 8 - pos);
        DC_InvalidateRange(buf + sampleIndex, (u16) len);
        for (; sampleIndex < len; sampleIndex++) {
            if (gMicSampleAnalysisParam->mType == 0) {
                sample = GetMicSampleAmplitude(ClampMicSample(buf[sampleIndex]));
            } else {
                sample = (s8) buf[sampleIndex];
                if (sample < 0) {
                    sample = -sample;
                }
            }
            if (sample >= 125) {
                nearMaxCount++;
            }
            if (sample > maxAmplitude) {
                maxAmplitude = sample;
            }
        }
        DC_InvalidateRange(buf, pos);
        for (sampleIndex = 0; sampleIndex < pos; sampleIndex++) {
            if (gMicSampleAnalysisParam->mType == 0) {
                sample = GetMicSampleAmplitude(ClampMicSample(buf[sampleIndex]));
            } else {
                sample = (s8) buf[sampleIndex];
                if (sample < 0) {
                    sample = -sample;
                }
            }
            if (sample >= 125) {
                nearMaxCount++;
            }
            if (sample > maxAmplitude) {
                maxAmplitude = sample;
            }
        }
    }
    for (bucketIndex = 0; bucketIndex < 4; bucketIndex++) {
        gMicIntervalHistogram[bucketIndex] = 0;
    }
    for (sampleIndex = pos; sampleIndex < len; sampleIndex++) {
        if (gMicSampleAnalysisParam->mType != 0) {
            sample = (s8) buf[sampleIndex] + 127;
        } else {
            sample = ClampMicSample(buf[sampleIndex]);
        }
        if (maxAmplitude > 30) {
            if (sample > 127 && prev <= 127) {
                cnt3++;
                if (lastCrossing == 9999 || cnt3 < 3) {
                    crossingCount++;
                    lastCrossing = sampleIndex;
                } else {
                    interval = sampleIndex - lastCrossing;
                    if (interval > maxInterval) {
                        maxInterval = interval;
                    }
                    if (interval < minInterval) {
                        minInterval = interval;
                    }
                    crossingCount++;
                    lastCrossing = sampleIndex;
                    for (bucketIndex = 0; bucketIndex < 4; bucketIndex++) {
                        if (bucketIndex == 4) {
                            if (interval > bucketIndex * 25) {
                                gMicIntervalHistogram[bucketIndex]++;
                                bucketIndex = 4;
                            }
                        } else if (interval > bucketIndex * 25 && interval <= (bucketIndex + 1) * 25) {
                            gMicIntervalHistogram[bucketIndex]++;
                            bucketIndex = 4;
                        }
                    }
                }
            }
            prev = sample;
        }
    }
    cnt3 = lastCrossing - len;
    for (sampleIndex = 0; sampleIndex < pos; sampleIndex++) {
        if (gMicSampleAnalysisParam->mType != 0) {
            sample = (s8) buf[sampleIndex] + 127;
        } else {
            sample = ClampMicSample(buf[sampleIndex]);
        }
        if (maxAmplitude > 30) {
            if (sample > 127 && prev <= 127) {
                interval = sampleIndex - cnt3;
                if (interval > maxInterval) {
                    maxInterval = interval;
                }
                if (interval < minInterval) {
                    minInterval = interval;
                }
                crossingCount++;
                cnt3 = sampleIndex;
                for (secondBucketIndex = 0; secondBucketIndex < 4; secondBucketIndex++) {
                    if (secondBucketIndex == 4) {
                        if (interval > secondBucketIndex * 25) {
                            gMicIntervalHistogram[secondBucketIndex]++;
                            secondBucketIndex = 4;
                        }
                    } else if (interval > secondBucketIndex * 25 && interval <= (secondBucketIndex + 1) * 25) {
                        gMicIntervalHistogram[secondBucketIndex]++;
                        secondBucketIndex = 4;
                    }
                }
            }
            prev = sample;
        }
    }
    scale = 0x400 / (len / 10);
    nearMaxCount = nearMaxCount * scale / 10;
    level = (crossingCount << 3) * scale / 10;
    for (sampleIndex = 0; sampleIndex < 4; sampleIndex++) {
        gMicIntervalHistogram[sampleIndex] = gMicIntervalHistogram[sampleIndex] * scale / 10;
    }
    gMicMaxAmplitude = maxAmplitude;
    gMicCrossingLevel = level;
    gMicNearMaxSampleCount = nearMaxCount;
    gMicMaxCrossingInterval = maxInterval;
    ok = 0;
    gMicSampleAnalysisValue = 0;
    if (level > 99) {
        if (gMicSampleAnalysisParam->mType == 0) {
            GetMicSampleAmplitude(ClampMicSample(*samplePtr));
        }
        cappedLevel = level;
        if (level > 1883) {
            cappedLevel = 1883;
        }
        switch (gMicSampleAnalysisMode) {
            case MICROPHONE_ANALYSIS_MODE_STRICT:
                if (level >= 100 && level < 200) {
                    if (maxAmplitude >= 70 && gMicIntervalHistogram[0] <= 9 && gMicIntervalHistogram[0] >= 5 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 3 &&
                        gMicIntervalHistogram[2] <= 7 && gMicIntervalHistogram[2] >= 1 &&
                        gMicIntervalHistogram[3] <= 7 && gMicIntervalHistogram[3] >= 1 && maxInterval <= 600 && maxInterval >= 80) {
                        ok = 1;
                    }
                } else if (level >= 200 && level < 300) {
                    if (maxAmplitude >= 90 && gMicIntervalHistogram[0] <= 32 && gMicIntervalHistogram[0] >= 14 &&
                        gMicIntervalHistogram[1] <= 6 && gMicIntervalHistogram[1] >= 2 &&
                        gMicIntervalHistogram[2] <= 5 && gMicIntervalHistogram[2] >= 1 &&
                        gMicIntervalHistogram[3] <= 4 && maxInterval <= 500 && maxInterval >= 79) {
                        ok = 1;
                    }
                } else if (level >= 300 && level < 400) {
                    if (maxAmplitude >= 100 && gMicIntervalHistogram[0] <= 40 && gMicIntervalHistogram[0] >= 24 &&
                        gMicIntervalHistogram[1] <= 19 && gMicIntervalHistogram[1] >= 2 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[2] >= 1 &&
                        gMicIntervalHistogram[3] <= 2 && maxInterval <= 400 && maxInterval >= 65) {
                        ok = 1;
                    }
                } else if (level >= 400 && level < 500) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 89 && gMicIntervalHistogram[0] >= 31 &&
                        gMicIntervalHistogram[1] <= 18 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[3] <= 1 && maxInterval <= 400 && maxInterval >= 35 &&
                        nearMaxCount >= 7) {
                        ok = 1;
                    }
                } else if (level >= 500 && level < 600) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 109 && gMicIntervalHistogram[0] >= 41 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 1 && gMicIntervalHistogram[3] <= 1 && maxInterval <= 400 && maxInterval >= 30 &&
                        nearMaxCount >= 5) {
                        ok = 1;
                    }
                } else if (level >= 600 && level < 700) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 130 && gMicIntervalHistogram[0] >= 66 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxInterval <= 400 && maxInterval >= 30 &&
                        nearMaxCount >= 6) {
                        ok = 1;
                    }
                } else if (level >= 700 && level < 800) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 142 && gMicIntervalHistogram[0] >= 66 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxInterval <= 200 && maxInterval >= 15 &&
                        nearMaxCount >= 7) {
                        ok = 1;
                    }
                } else if (level >= 800 && level < 900) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 150 && gMicIntervalHistogram[0] >= 76 &&
                        gMicIntervalHistogram[1] <= 9 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 15 &&
                        nearMaxCount >= 7) {
                        ok = 1;
                    }
                } else if (level >= 900 && level < 1100) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 160 && gMicIntervalHistogram[0] >= 90 &&
                        gMicIntervalHistogram[1] <= 7 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 15 && nearMaxCount >= 8) {
                        ok = 1;
                    }
                } else if (level >= 1100 && level < 1300) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] < 170 && gMicIntervalHistogram[0] >= 120 &&
                        gMicIntervalHistogram[1] <= 4 && gMicIntervalHistogram[2] < 2 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 13 && nearMaxCount >= 9) {
                        ok = 1;
                    }
                } else if (level >= 1300 && level < 1500) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 190 && gMicIntervalHistogram[0] >= 150 &&
                        gMicIntervalHistogram[1] <= 2 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 13 && nearMaxCount >= 15) {
                        ok = 1;
                    }
                } else if (level >= 1500 && level < 1883) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] >= 180 && gMicIntervalHistogram[1] <= 2 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 9 &&
                        nearMaxCount >= 28) {
                        ok = 1;
                    }
                } else {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[1] == 0 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 5 && nearMaxCount >= 28) {
                        ok = 1;
                    }
                }
                break;
            case MICROPHONE_ANALYSIS_MODE_MIDDLE:
                if (level >= 100 && level < 200) {
                    if (maxAmplitude >= 70 && gMicIntervalHistogram[0] <= 9 && gMicIntervalHistogram[0] >= 1 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 7 && gMicIntervalHistogram[3] <= 7 && maxInterval <= 600 && maxInterval >= 80) {
                        ok = 1;
                    }
                } else if (level >= 200 && level < 300) {
                    if (maxAmplitude >= 90 && gMicIntervalHistogram[0] <= 32 && gMicIntervalHistogram[0] >= 9 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 2 &&
                        gMicIntervalHistogram[2] <= 6 && gMicIntervalHistogram[2] >= 1 &&
                        gMicIntervalHistogram[3] <= 4 && maxInterval <= 500 && maxInterval >= 79) {
                        ok = 1;
                    }
                } else if (level >= 300 && level < 400) {
                    if (maxAmplitude >= 100 && gMicIntervalHistogram[0] <= 40 && gMicIntervalHistogram[0] >= 20 &&
                        gMicIntervalHistogram[1] <= 19 && gMicIntervalHistogram[1] >= 2 &&
                        gMicIntervalHistogram[2] <= 5 && gMicIntervalHistogram[2] >= 1 &&
                        gMicIntervalHistogram[3] <= 3 && maxInterval <= 400 && maxInterval >= 61) {
                        ok = 1;
                    }
                } else if (level >= 400 && level < 500) {
                    if (maxAmplitude >= 115 && gMicIntervalHistogram[0] <= 89 && gMicIntervalHistogram[0] >= 22 &&
                        gMicIntervalHistogram[1] <= 18 && gMicIntervalHistogram[1] >= 6 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[3] <= 3 && maxInterval <= 400 && maxInterval >= 35) {
                        ok = 1;
                    }
                } else if (level >= 500 && level < 600) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 109 && gMicIntervalHistogram[0] >= 41 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[3] <= 1 && maxInterval <= 400 && maxInterval >= 30 &&
                        nearMaxCount >= 1) {
                        ok = 1;
                    }
                } else if (level >= 600 && level < 700) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 130 && gMicIntervalHistogram[0] >= 61 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 3 && gMicIntervalHistogram[3] == 0 && maxInterval <= 400 && maxInterval >= 30 &&
                        nearMaxCount >= 6) {
                        ok = 1;
                    }
                } else if (level >= 700 && level < 800) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 142 && gMicIntervalHistogram[0] >= 66 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 1 && gMicIntervalHistogram[3] == 0 && maxInterval <= 200 && maxInterval >= 15 &&
                        nearMaxCount >= 7) {
                        ok = 1;
                    }
                } else if (level >= 800 && level < 900) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 150 && gMicIntervalHistogram[0] >= 76 &&
                        gMicIntervalHistogram[1] <= 9 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 1 && gMicIntervalHistogram[3] == 0 && maxInterval <= 125 && maxInterval >= 15 &&
                        nearMaxCount >= 7) {
                        ok = 1;
                    }
                } else if (level >= 900 && level < 1100) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 160 && gMicIntervalHistogram[0] >= 90 &&
                        gMicIntervalHistogram[1] <= 7 && gMicIntervalHistogram[2] <= 1 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 115 && maxInterval >= 20 && nearMaxCount >= 8) {
                        ok = 1;
                    }
                } else if (level >= 1100 && level < 1300) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] < 170 && gMicIntervalHistogram[0] >= 120 &&
                        gMicIntervalHistogram[1] <= 4 && gMicIntervalHistogram[2] <= 1 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 32 && nearMaxCount >= 9) {
                        ok = 1;
                    }
                } else if (level >= 1300 && level < 1500) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 190 && gMicIntervalHistogram[0] >= 150 &&
                        gMicIntervalHistogram[1] <= 2 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 32 && nearMaxCount >= 15) {
                        ok = 1;
                    }
                } else if (level >= 1500 && level < 1883) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] >= 180 && gMicIntervalHistogram[1] <= 2 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 28 &&
                        nearMaxCount >= 28) {
                        ok = 1;
                    }
                } else {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[1] == 0 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 29 && nearMaxCount >= 28) {
                        ok = 1;
                    }
                }
                break;
            case MICROPHONE_ANALYSIS_MODE_LOOSE:
                requiredMatches = 1;
                if (level >= 100 && level < 200) {
                    if (maxAmplitude >= 30 && gMicIntervalHistogram[0] <= 13 && gMicIntervalHistogram[0] >= 1 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 7 && gMicIntervalHistogram[3] <= 7 && maxInterval <= 600 && maxInterval >= 80) {
                        ok = 1;
                    }
                } else if (level >= 200 && level < 300) {
                    if (maxAmplitude >= 40 && gMicIntervalHistogram[0] <= 20 && gMicIntervalHistogram[0] >= 6 &&
                        gMicIntervalHistogram[1] <= 17 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 6 && gMicIntervalHistogram[3] <= 4 && maxInterval <= 500 && maxInterval >= 79) {
                        ok = 1;
                    }
                } else if (level >= 300 && level < 400) {
                    if (maxAmplitude >= 50 && gMicIntervalHistogram[0] <= 40 && gMicIntervalHistogram[0] >= 20 &&
                        gMicIntervalHistogram[1] <= 19 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 5 && gMicIntervalHistogram[3] <= 3 && maxInterval <= 400 && maxInterval >= 61) {
                        ok = 1;
                    }
                } else if (level >= 400 && level < 500) {
                    if (maxAmplitude >= 80 && gMicIntervalHistogram[0] <= 89 && gMicIntervalHistogram[0] >= 22 &&
                        gMicIntervalHistogram[1] <= 18 && gMicIntervalHistogram[1] >= 6 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[3] <= 3 && maxInterval <= 400 && maxInterval >= 35) {
                        ok = 1;
                    }
                } else if (level >= 500 && level < 600) {
                    if (maxAmplitude == 100 && gMicIntervalHistogram[0] <= 109 && gMicIntervalHistogram[0] >= 41 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[3] <= 1 && maxInterval <= 400 && maxInterval >= 30 &&
                        nearMaxCount >= 1) {
                        ok = 1;
                    }
                } else if (level >= 600 && level < 700) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 130 && gMicIntervalHistogram[0] >= 61 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 3 && gMicIntervalHistogram[3] == 0 && maxInterval <= 400 && maxInterval >= 30 &&
                        nearMaxCount >= 6) {
                        ok = 1;
                    }
                } else if (level >= 700 && level < 800) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 142 && gMicIntervalHistogram[0] >= 66 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 1 && gMicIntervalHistogram[3] == 0 && maxInterval <= 200 && maxInterval >= 15 &&
                        nearMaxCount >= 7) {
                        ok = 1;
                    }
                } else if (level >= 800 && level < 900) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 150 && gMicIntervalHistogram[0] >= 76 &&
                        gMicIntervalHistogram[1] <= 9 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 1 && gMicIntervalHistogram[3] == 0 && maxInterval <= 125 && maxInterval >= 15 &&
                        nearMaxCount >= 7) {
                        ok = 1;
                    }
                } else if (level >= 900 && level < 1100) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 160 && gMicIntervalHistogram[0] >= 90 &&
                        gMicIntervalHistogram[1] <= 7 && gMicIntervalHistogram[2] <= 1 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 115 && maxInterval >= 20 && nearMaxCount >= 8) {
                        ok = 1;
                    }
                } else if (level >= 1100 && level < 1300) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] < 170 && gMicIntervalHistogram[0] >= 120 &&
                        gMicIntervalHistogram[1] <= 4 && gMicIntervalHistogram[2] <= 1 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 32 && nearMaxCount >= 9) {
                        ok = 1;
                    }
                } else if (level >= 1300 && level < 1500) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] <= 190 && gMicIntervalHistogram[0] >= 150 &&
                        gMicIntervalHistogram[1] <= 2 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 32 && nearMaxCount >= 15) {
                        ok = 1;
                    }
                } else if (level >= 1500 && level < 1883) {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[0] >= 180 && gMicIntervalHistogram[1] <= 2 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 28 &&
                        nearMaxCount >= 28) {
                        ok = 1;
                    }
                } else {
                    if (maxAmplitude == 127 && gMicIntervalHistogram[1] == 0 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxInterval <= 100 && maxInterval >= 29 && nearMaxCount >= 28) {
                        ok = 1;
                    }
                }
                break;
        }
    }
    if (ok == 1) {
        if (gMicSampleAnalysisMatchCount >= requiredMatches) {
            if (cappedLevel >= 1883) {
                gMicSampleAnalysisValue = 255;
            } else {
                gMicSampleAnalysisValue = cappedLevel / 7 - 13;
            }
        } else {
            gMicSampleAnalysisMatchCount++;
        }
    } else {
        gMicSampleAnalysisMatchCount = 0;
    }
    return gMicSampleAnalysisValue;
}
