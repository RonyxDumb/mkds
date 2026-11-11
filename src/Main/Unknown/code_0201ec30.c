#include "Main/Unknown/code_0201ec30.h"

#include "code_0200eddc.h"
#include "Main/Unknown/unk_02173000.h"
#include "Main/Unknown/unk_02161000.h"
#include "Main/Unknown/code_0200e000.h"
#include "Main/Unknown/code_020204b4.h"
#include "mic.h"

u8 data_02161ad8 = 1;

u8 data_02173288;
s32 data_021732a8;
s32 data_0217328c;
s32 data_021732a4;
MICAutoParam *data_02173290;
s32 data_02173294;
s32 data_02173298;
u8 gMicIntervalHistogram[4];
s32 data_0217329c;

s32 GetMicSampleAmplitude(s32 a) {
    if (a > 0x7f && a <= 0xfe) {
        return a - 0x7f;
    }
    return 0x7f - a;
}

void InitMicSampleAnalysis(MICAutoParam *a) {
    s32 i;

    data_02173290 = a;
    data_02173294 = 1;
    data_02173288 = 0;
    data_02173298 = 0;
    for (i = 0; i < 4; i++) {
        gMicIntervalHistogram[i] = 0;
    }
}

void StartMicSampleAnalysis(void) {
    data_02173294 = 1;
}

void StopMicSampleAnalysis(void) {
    if (data_02173294 == 0) {
        return;
    }
    data_02173294 = 0;
    data_02173288 = 0;
    data_02173298 = 0;
}

void SetMicSampleAnalysisMode(u32 arg0) {
    data_02161ad8 = arg0;
}

u8 UpdateMicSampleAnalysis(void) {
    u8 *p;
    s32 n;
    s32 prev;
    s32 mind;
    s32 last;
    s32 cnt3;
    s32 lim;
    s32 len;
    u16 pos;
    u8 *buf;
    s32 cnt;
    s32 maxv;
    s32 maxd;
    s32 cnt2;
    s32 i;
    s32 d;
    s32 v;
    s32 j;
    s32 k;
    s32 q;
    s32 ok;
    s32 m;

    cnt = 0;
    n = 0;
    len = data_02173290->mSize;
    last = 9999;
    maxv = 0;
    lim = 2;
    prev = 0;
    cnt3 = 0;
    maxd = 0;
    cnt2 = 0;
    if (data_02173294 == 0) {
        return 0;
    }
    mind = len;
    p = MIC_GetLastSamplingAddress();
    buf = data_02173290->mBuffer;
    pos = p - buf;
    if (pos >= len / 8) {
        i = pos - len / 8;
        DC_InvalidateRange(buf + i, pos);
        for (; i < pos; i++) {
            if (data_02173290->mType == 0) {
                v = GetMicSampleAmplitude(ClampMicSample(buf[i]));
            } else {
                v = (s8) buf[i];
                if (v < 0) {
                    v = -v;
                }
            }
            if (v >= 125) {
                cnt2++;
            }
            if (v > maxv) {
                maxv = v;
            }
        }
    } else {
        i = len - (len / 8 - pos);
        DC_InvalidateRange(buf + i, (u16) len);
        for (; i < len; i++) {
            if (data_02173290->mType == 0) {
                v = GetMicSampleAmplitude(ClampMicSample(buf[i]));
            } else {
                v = (s8) buf[i];
                if (v < 0) {
                    v = -v;
                }
            }
            if (v >= 125) {
                cnt2++;
            }
            if (v > maxv) {
                maxv = v;
            }
        }
        DC_InvalidateRange(buf, pos);
        for (i = 0; i < pos; i++) {
            if (data_02173290->mType == 0) {
                v = GetMicSampleAmplitude(ClampMicSample(buf[i]));
            } else {
                v = (s8) buf[i];
                if (v < 0) {
                    v = -v;
                }
            }
            if (v >= 125) {
                cnt2++;
            }
            if (v > maxv) {
                maxv = v;
            }
        }
    }
    for (j = 0; j < 4; j++) {
        gMicIntervalHistogram[j] = 0;
    }
    for (i = pos; i < len; i++) {
        if (data_02173290->mType != 0) {
            v = (s8) buf[i] + 127;
        } else {
            v = ClampMicSample(buf[i]);
        }
        if (maxv > 30) {
            if (v > 127 && prev <= 127) {
                cnt3++;
                if (last == 9999 || cnt3 < 3) {
                    cnt++;
                    last = i;
                } else {
                    d = i - last;
                    if (d > maxd) {
                        maxd = d;
                    }
                    if (d < mind) {
                        mind = d;
                    }
                    cnt++;
                    last = i;
                    for (j = 0; j < 4; j++) {
                        if (j == 4) {
                            if (d > j * 25) {
                                gMicIntervalHistogram[j]++;
                                j = 4;
                            }
                        } else if (d > j * 25 && d <= (j + 1) * 25) {
                            gMicIntervalHistogram[j]++;
                            j = 4;
                        }
                    }
                }
            }
            prev = v;
        }
    }
    cnt3 = last - len;
    for (i = 0; i < pos; i++) {
        if (data_02173290->mType != 0) {
            v = (s8) buf[i] + 127;
        } else {
            v = ClampMicSample(buf[i]);
        }
        if (maxv > 30) {
            if (v > 127 && prev <= 127) {
                d = i - cnt3;
                if (d > maxd) {
                    maxd = d;
                }
                if (d < mind) {
                    mind = d;
                }
                cnt++;
                cnt3 = i;
                for (k = 0; k < 4; k++) {
                    if (k == 4) {
                        if (d > k * 25) {
                            gMicIntervalHistogram[k]++;
                            k = 4;
                        }
                    } else if (d > k * 25 && d <= (k + 1) * 25) {
                        gMicIntervalHistogram[k]++;
                        k = 4;
                    }
                }
            }
            prev = v;
        }
    }
    q = 0x400 / (len / 10);
    cnt2 = cnt2 * q / 10;
    m = (cnt << 3) * q / 10;
    for (i = 0; i < 4; i++) {
        gMicIntervalHistogram[i] = gMicIntervalHistogram[i] * q / 10;
    }
    data_0217328c = maxv;
    data_0217329c = m;
    data_021732a4 = cnt2;
    data_021732a8 = maxd;
    ok = 0;
    data_02173288 = 0;
    if (m > 99) {
        if (data_02173290->mType == 0) {
            GetMicSampleAmplitude(ClampMicSample(*p));
        }
        n = m;
        if (m > 1883) {
            n = 1883;
        }
        switch (data_02161ad8) {
            case 2:
                if (m >= 100 && m < 200) {
                    if (maxv >= 70 && gMicIntervalHistogram[0] <= 9 && gMicIntervalHistogram[0] >= 5 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 3 &&
                        gMicIntervalHistogram[2] <= 7 && gMicIntervalHistogram[2] >= 1 &&
                        gMicIntervalHistogram[3] <= 7 && gMicIntervalHistogram[3] >= 1 && maxd <= 600 && maxd >= 80) {
                        ok = 1;
                    }
                } else if (m >= 200 && m < 300) {
                    if (maxv >= 90 && gMicIntervalHistogram[0] <= 32 && gMicIntervalHistogram[0] >= 14 &&
                        gMicIntervalHistogram[1] <= 6 && gMicIntervalHistogram[1] >= 2 &&
                        gMicIntervalHistogram[2] <= 5 && gMicIntervalHistogram[2] >= 1 &&
                        gMicIntervalHistogram[3] <= 4 && maxd <= 500 && maxd >= 79) {
                        ok = 1;
                    }
                } else if (m >= 300 && m < 400) {
                    if (maxv >= 100 && gMicIntervalHistogram[0] <= 40 && gMicIntervalHistogram[0] >= 24 &&
                        gMicIntervalHistogram[1] <= 19 && gMicIntervalHistogram[1] >= 2 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[2] >= 1 &&
                        gMicIntervalHistogram[3] <= 2 && maxd <= 400 && maxd >= 65) {
                        ok = 1;
                    }
                } else if (m >= 400 && m < 500) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 89 && gMicIntervalHistogram[0] >= 31 &&
                        gMicIntervalHistogram[1] <= 18 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[3] <= 1 && maxd <= 400 && maxd >= 35 &&
                        cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 500 && m < 600) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 109 && gMicIntervalHistogram[0] >= 41 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 1 && gMicIntervalHistogram[3] <= 1 && maxd <= 400 && maxd >= 30 &&
                        cnt2 >= 5) {
                        ok = 1;
                    }
                } else if (m >= 600 && m < 700) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 130 && gMicIntervalHistogram[0] >= 66 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxd <= 400 && maxd >= 30 &&
                        cnt2 >= 6) {
                        ok = 1;
                    }
                } else if (m >= 700 && m < 800) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 142 && gMicIntervalHistogram[0] >= 66 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxd <= 200 && maxd >= 15 &&
                        cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 800 && m < 900) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 150 && gMicIntervalHistogram[0] >= 76 &&
                        gMicIntervalHistogram[1] <= 9 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 15 &&
                        cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 900 && m < 1100) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 160 && gMicIntervalHistogram[0] >= 90 &&
                        gMicIntervalHistogram[1] <= 7 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 15 && cnt2 >= 8) {
                        ok = 1;
                    }
                } else if (m >= 1100 && m < 1300) {
                    if (maxv == 127 && gMicIntervalHistogram[0] < 170 && gMicIntervalHistogram[0] >= 120 &&
                        gMicIntervalHistogram[1] <= 4 && gMicIntervalHistogram[2] < 2 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 13 && cnt2 >= 9) {
                        ok = 1;
                    }
                } else if (m >= 1300 && m < 1500) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 190 && gMicIntervalHistogram[0] >= 150 &&
                        gMicIntervalHistogram[1] <= 2 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 13 && cnt2 >= 15) {
                        ok = 1;
                    }
                } else if (m >= 1500 && m < 1883) {
                    if (maxv == 127 && gMicIntervalHistogram[0] >= 180 && gMicIntervalHistogram[1] <= 2 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 9 &&
                        cnt2 >= 28) {
                        ok = 1;
                    }
                } else {
                    if (maxv == 127 && gMicIntervalHistogram[1] == 0 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 5 && cnt2 >= 28) {
                        ok = 1;
                    }
                }
                break;
            case 1:
                if (m >= 100 && m < 200) {
                    if (maxv >= 70 && gMicIntervalHistogram[0] <= 9 && gMicIntervalHistogram[0] >= 1 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 7 && gMicIntervalHistogram[3] <= 7 && maxd <= 600 && maxd >= 80) {
                        ok = 1;
                    }
                } else if (m >= 200 && m < 300) {
                    if (maxv >= 90 && gMicIntervalHistogram[0] <= 32 && gMicIntervalHistogram[0] >= 9 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 2 &&
                        gMicIntervalHistogram[2] <= 6 && gMicIntervalHistogram[2] >= 1 &&
                        gMicIntervalHistogram[3] <= 4 && maxd <= 500 && maxd >= 79) {
                        ok = 1;
                    }
                } else if (m >= 300 && m < 400) {
                    if (maxv >= 100 && gMicIntervalHistogram[0] <= 40 && gMicIntervalHistogram[0] >= 20 &&
                        gMicIntervalHistogram[1] <= 19 && gMicIntervalHistogram[1] >= 2 &&
                        gMicIntervalHistogram[2] <= 5 && gMicIntervalHistogram[2] >= 1 &&
                        gMicIntervalHistogram[3] <= 3 && maxd <= 400 && maxd >= 61) {
                        ok = 1;
                    }
                } else if (m >= 400 && m < 500) {
                    if (maxv >= 115 && gMicIntervalHistogram[0] <= 89 && gMicIntervalHistogram[0] >= 22 &&
                        gMicIntervalHistogram[1] <= 18 && gMicIntervalHistogram[1] >= 6 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[3] <= 3 && maxd <= 400 && maxd >= 35) {
                        ok = 1;
                    }
                } else if (m >= 500 && m < 600) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 109 && gMicIntervalHistogram[0] >= 41 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[3] <= 1 && maxd <= 400 && maxd >= 30 &&
                        cnt2 >= 1) {
                        ok = 1;
                    }
                } else if (m >= 600 && m < 700) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 130 && gMicIntervalHistogram[0] >= 61 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 3 && gMicIntervalHistogram[3] == 0 && maxd <= 400 && maxd >= 30 &&
                        cnt2 >= 6) {
                        ok = 1;
                    }
                } else if (m >= 700 && m < 800) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 142 && gMicIntervalHistogram[0] >= 66 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 1 && gMicIntervalHistogram[3] == 0 && maxd <= 200 && maxd >= 15 &&
                        cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 800 && m < 900) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 150 && gMicIntervalHistogram[0] >= 76 &&
                        gMicIntervalHistogram[1] <= 9 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 1 && gMicIntervalHistogram[3] == 0 && maxd <= 125 && maxd >= 15 &&
                        cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 900 && m < 1100) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 160 && gMicIntervalHistogram[0] >= 90 &&
                        gMicIntervalHistogram[1] <= 7 && gMicIntervalHistogram[2] <= 1 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 115 && maxd >= 20 && cnt2 >= 8) {
                        ok = 1;
                    }
                } else if (m >= 1100 && m < 1300) {
                    if (maxv == 127 && gMicIntervalHistogram[0] < 170 && gMicIntervalHistogram[0] >= 120 &&
                        gMicIntervalHistogram[1] <= 4 && gMicIntervalHistogram[2] <= 1 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 32 && cnt2 >= 9) {
                        ok = 1;
                    }
                } else if (m >= 1300 && m < 1500) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 190 && gMicIntervalHistogram[0] >= 150 &&
                        gMicIntervalHistogram[1] <= 2 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 32 && cnt2 >= 15) {
                        ok = 1;
                    }
                } else if (m >= 1500 && m < 1883) {
                    if (maxv == 127 && gMicIntervalHistogram[0] >= 180 && gMicIntervalHistogram[1] <= 2 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 28 &&
                        cnt2 >= 28) {
                        ok = 1;
                    }
                } else {
                    if (maxv == 127 && gMicIntervalHistogram[1] == 0 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 29 && cnt2 >= 28) {
                        ok = 1;
                    }
                }
                break;
            case 0:
                lim = 1;
                if (m >= 100 && m < 200) {
                    if (maxv >= 30 && gMicIntervalHistogram[0] <= 13 && gMicIntervalHistogram[0] >= 1 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 7 && gMicIntervalHistogram[3] <= 7 && maxd <= 600 && maxd >= 80) {
                        ok = 1;
                    }
                } else if (m >= 200 && m < 300) {
                    if (maxv >= 40 && gMicIntervalHistogram[0] <= 20 && gMicIntervalHistogram[0] >= 6 &&
                        gMicIntervalHistogram[1] <= 17 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 6 && gMicIntervalHistogram[3] <= 4 && maxd <= 500 && maxd >= 79) {
                        ok = 1;
                    }
                } else if (m >= 300 && m < 400) {
                    if (maxv >= 50 && gMicIntervalHistogram[0] <= 40 && gMicIntervalHistogram[0] >= 20 &&
                        gMicIntervalHistogram[1] <= 19 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 5 && gMicIntervalHistogram[3] <= 3 && maxd <= 400 && maxd >= 61) {
                        ok = 1;
                    }
                } else if (m >= 400 && m < 500) {
                    if (maxv >= 80 && gMicIntervalHistogram[0] <= 89 && gMicIntervalHistogram[0] >= 22 &&
                        gMicIntervalHistogram[1] <= 18 && gMicIntervalHistogram[1] >= 6 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[3] <= 3 && maxd <= 400 && maxd >= 35) {
                        ok = 1;
                    }
                } else if (m >= 500 && m < 600) {
                    if (maxv == 100 && gMicIntervalHistogram[0] <= 109 && gMicIntervalHistogram[0] >= 41 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 4 && gMicIntervalHistogram[3] <= 1 && maxd <= 400 && maxd >= 30 &&
                        cnt2 >= 1) {
                        ok = 1;
                    }
                } else if (m >= 600 && m < 700) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 130 && gMicIntervalHistogram[0] >= 61 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 3 && gMicIntervalHistogram[3] == 0 && maxd <= 400 && maxd >= 30 &&
                        cnt2 >= 6) {
                        ok = 1;
                    }
                } else if (m >= 700 && m < 800) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 142 && gMicIntervalHistogram[0] >= 66 &&
                        gMicIntervalHistogram[1] <= 14 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 1 && gMicIntervalHistogram[3] == 0 && maxd <= 200 && maxd >= 15 &&
                        cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 800 && m < 900) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 150 && gMicIntervalHistogram[0] >= 76 &&
                        gMicIntervalHistogram[1] <= 9 && gMicIntervalHistogram[1] >= 1 &&
                        gMicIntervalHistogram[2] <= 1 && gMicIntervalHistogram[3] == 0 && maxd <= 125 && maxd >= 15 &&
                        cnt2 >= 7) {
                        ok = 1;
                    }
                } else if (m >= 900 && m < 1100) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 160 && gMicIntervalHistogram[0] >= 90 &&
                        gMicIntervalHistogram[1] <= 7 && gMicIntervalHistogram[2] <= 1 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 115 && maxd >= 20 && cnt2 >= 8) {
                        ok = 1;
                    }
                } else if (m >= 1100 && m < 1300) {
                    if (maxv == 127 && gMicIntervalHistogram[0] < 170 && gMicIntervalHistogram[0] >= 120 &&
                        gMicIntervalHistogram[1] <= 4 && gMicIntervalHistogram[2] <= 1 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 32 && cnt2 >= 9) {
                        ok = 1;
                    }
                } else if (m >= 1300 && m < 1500) {
                    if (maxv == 127 && gMicIntervalHistogram[0] <= 190 && gMicIntervalHistogram[0] >= 150 &&
                        gMicIntervalHistogram[1] <= 2 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 32 && cnt2 >= 15) {
                        ok = 1;
                    }
                } else if (m >= 1500 && m < 1883) {
                    if (maxv == 127 && gMicIntervalHistogram[0] >= 180 && gMicIntervalHistogram[1] <= 2 &&
                        gMicIntervalHistogram[2] == 0 && gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 28 &&
                        cnt2 >= 28) {
                        ok = 1;
                    }
                } else {
                    if (maxv == 127 && gMicIntervalHistogram[1] == 0 && gMicIntervalHistogram[2] == 0 &&
                        gMicIntervalHistogram[3] == 0 && maxd <= 100 && maxd >= 29 && cnt2 >= 28) {
                        ok = 1;
                    }
                }
                break;
        }
    }
    if (ok == 1) {
        if (data_02173298 >= lim) {
            if (n >= 1883) {
                data_02173288 = 255;
            } else {
                data_02173288 = n / 7 - 13;
            }
        } else {
            data_02173298++;
        }
    } else {
        data_02173298 = 0;
    }
    return data_02173288;
}
