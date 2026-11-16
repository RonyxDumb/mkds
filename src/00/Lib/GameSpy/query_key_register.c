#include "00/Lib/GameSpy/query_key_register.h"

#pragma explicit_zero_data on

char gQr2KeyEmpty[] = "";
char gQr2KeyHostname[] = "hostname";
char gQr2KeyGamename[] = "gamename";
char gQr2KeyMapname[] = "mapname";
char gQr2KeyHostport[] = "hostport";
char gQr2KeyScoreUnderscoreT[] = "score_t";
char gQr2KeyGametype[] = "gametype";
char gQr2KeyGamevariant[] = "gamevariant";
char gQr2KeyNumplayers[] = "numplayers";
char gQr2KeyNumteams[] = "numteams";
char gQr2KeyMaxplayers[] = "maxplayers";
char gQr2KeyGamemode[] = "gamemode";
char gQr2KeyTeamplay[] = "teamplay";
char gQr2KeyTimelimit[] = "timelimit";
char gQr2KeyTeamfraglimit[] = "teamfraglimit";
char gQr2KeyTimeelapsed[] = "timeelapsed";
char gQr2KeyRoundtime[] = "roundtime";
char gQr2KeyFraglimit[] = "fraglimit";
char gQr2KeyRoundelapsed[] = "roundelapsed";
char gQr2KeyPassword[] = "password";
char gQr2KeyDeathsUnderscore[] = "deaths_";
char gQr2KeyGamever[] = "gamever";
char gQr2KeyScoreUnderscore[] = "score_";
char gQr2KeyTeamUnderscoreT[] = "team_t";
char gQr2KeyTeamUnderscore[] = "team_";
char gQr2KeyPingUnderscore[] = "ping_";
char gQr2KeyPlayerUnderscore[] = "player_";
char gQr2KeyPidUnderscore[] = "pid_";
char gQr2KeySkillUnderscore[] = "skill_";
char gQr2KeyGroupid[] = "groupid";

void *gQr2RegisteredKeyList[254] = {
    gQr2KeyEmpty,    gQr2KeyHostname,     gQr2KeyGamename,   gQr2KeyGamever,     gQr2KeyHostport,
    gQr2KeyMapname,     gQr2KeyGametype,     gQr2KeyGamevariant, gQr2KeyNumplayers, gQr2KeyNumteams,
    gQr2KeyMaxplayers,  gQr2KeyGamemode,     gQr2KeyTeamplay,   gQr2KeyFraglimit,   gQr2KeyTeamfraglimit,
    gQr2KeyTimeelapsed, gQr2KeyTimelimit,    gQr2KeyRoundtime,  gQr2KeyRoundelapsed, gQr2KeyPassword,
    gQr2KeyGroupid,     gQr2KeyPlayerUnderscore, gQr2KeyScoreUnderscore, gQr2KeySkillUnderscore, gQr2KeyPingUnderscore,
    gQr2KeyTeamUnderscore,  gQr2KeyDeathsUnderscore, gQr2KeyPidUnderscore,  gQr2KeyTeamUnderscoreT,    gQr2KeyScoreUnderscoreT,
};

void qr2_register_keyA(s32 keyid, void *key) {
    if (keyid >= 0x32 && keyid <= 0xfe) {
        gQr2RegisteredKeyList[keyid] = key;
    }
}
