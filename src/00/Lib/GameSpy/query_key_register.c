#include "00/Lib/GameSpy/query_key_register.h"

#pragma explicit_zero_data on

char gQr2KeyReserved[] = "";
char gQr2KeyHostname[] = "hostname";
char gQr2KeyGamename[] = "gamename";
char gQr2KeyMapname[] = "mapname";
char gQr2KeyHostport[] = "hostport";
char gQr2KeyScoreTeam[] = "score_t";
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
char gQr2KeyDeathsPrefix[] = "deaths_";
char gQr2KeyGamever[] = "gamever";
char gQr2KeyScorePrefix[] = "score_";
char gQr2KeyTeamTeam[] = "team_t";
char gQr2KeyTeamPrefix[] = "team_";
char gQr2KeyPingPrefix[] = "ping_";
char gQr2KeyPlayerPrefix[] = "player_";
char gQr2KeyPidPrefix[] = "pid_";
char gQr2KeySkillPrefix[] = "skill_";
char gQr2KeyGroupid[] = "groupid";

void *gQr2RegisteredKeyList[254] = {
    gQr2KeyReserved,    gQr2KeyHostname,     gQr2KeyGamename,   gQr2KeyGamever,     gQr2KeyHostport,
    gQr2KeyMapname,     gQr2KeyGametype,     gQr2KeyGamevariant, gQr2KeyNumplayers, gQr2KeyNumteams,
    gQr2KeyMaxplayers,  gQr2KeyGamemode,     gQr2KeyTeamplay,   gQr2KeyFraglimit,   gQr2KeyTeamfraglimit,
    gQr2KeyTimeelapsed, gQr2KeyTimelimit,    gQr2KeyRoundtime,  gQr2KeyRoundelapsed, gQr2KeyPassword,
    gQr2KeyGroupid,     gQr2KeyPlayerPrefix, gQr2KeyScorePrefix, gQr2KeySkillPrefix, gQr2KeyPingPrefix,
    gQr2KeyTeamPrefix,  gQr2KeyDeathsPrefix, gQr2KeyPidPrefix,  gQr2KeyTeamTeam,    gQr2KeyScoreTeam,
};

void qr2_register_keyA(s32 keyid, void *key) {
    if (keyid >= 0x32 && keyid <= 0xfe) {
        gQr2RegisteredKeyList[keyid] = key;
    }
}
