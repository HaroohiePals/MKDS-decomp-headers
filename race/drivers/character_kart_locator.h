#pragma once
#include "../raceConfig.h"

typedef struct
{
    const char* playerModelName;
    const char* enemyModelName;
    const char* emblemName;
} cklcr_char_def_t;

typedef struct
{
    const char* kartModelName;
    const char* kartShadowName;
} cklcr_kart_def_t;

void cklcr_setLoadFromFolder(BOOL loadFromFolder);
const char* cklcr_getCharacterNsbmdPath(CharacterId character, BOOL isPlayer);
const char* cklcr_getCharacterNsbtxPath(CharacterId character, BOOL isPlayer);
const char* cklcr_getKartNsbmdPath(int kart);
const char* cklcr_getKartNsbtxPath(int kart);
const char* cklcr_getTireNsbmdPath(int a1, const char* tireName);
const char* cklcr_getTireNsbtxPath(int a1, const char* tireName);
const char* cklcr_getKartShadowPath(int kart);
const char* cklcr_getCharacterModelName(CharacterId character, BOOL isPlayer);
const char* cklcr_getCharacterFolderPath(CharacterId character);
const char* cklcr_getFaceAnimPath();
const char* cklcr_getCharacterEmblemPath(CharacterId character);
const char* cklcr_getTeamEmblemPath(int team);
