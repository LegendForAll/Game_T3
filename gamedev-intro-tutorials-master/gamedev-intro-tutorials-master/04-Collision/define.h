#pragma once
#define FULLSCREEN	false
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define WINDOW_CLASS_NAME L"SampleWindow"
#define MAIN_WINDOW_TITLE L"Castlevania"
#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 0, 255)
#define MAX_FRAME_RATE 90

#define SAFE_DELETE(p) \
if(p) \
{\
	delete (p); \
	p = nullptr; \
} \

//Flight equation
#define EQUATION_NORMAL		1
#define EQUATION_SIN		2
#define EQUATION_PARAPOL	3

enum eSoundID
{
	USING_WHIP,
	SLASH_WATER,
	SELECT,
	PAUSE,
	OPEN_DOOR,
	HOLY_WATER,
	HOLY_CROSS,
	HIT_CANNON,
	HIT_SOUND,
	FALLING_DOWN_WATER_SUFACE,
	FALLING,
	DECREASE_WEAPON_USE_POINT,
	COLLECT_WEAPON,
	COLLECT_ITEM,
	BOSS_BATTLE_POISON_MIND,
	GAME_OVER,
	GAME_START_PROLOGUE,
	LIFE_LOST,
	STAGE_01_VAMPIRE_KILLER,
	STAGE_04_STALKER,
	STAGE_CLEAR,
	TITLE_THEME_PRELUDE,
	GO_INTO_CASTLE,
	SIMON_HURTED,
	EAT_CHANGE_STATE_BALL,
	MONEY
};


//Texture
#define ID_TEX_BBOX			-100
#define ID_TEX_MISC			10
#define ID_LEVEL_ONE_BG		20
#define ID_TEX_SIMON		30
#define ID_TEX_WHIP			40
#define ID_TEX_CANDLE		50
#define ID_TEX_DEAD			60

#define ID_ITEM_HEART_BIG		61
#define ID_ITEM_MORNING_STAR	62
#define ID_ITEM_MONEY_BLUE		63
#define ID_ITEM_ROSARY			64
#define ID_ITEM_ROSACT			65
#define ID_ITEM_STOPWATCH		66
#define ID_ITEM_DOUBLE_SHOT		67
#define ID_ITEM_BALL			68
#define ID_STATE_1				69


//Status SIMON
#define SM_STAND_STATIC			0
#define SM_MOVE_LEFT			1
#define SM_SIT					2
#define SM_JUMP					3
#define SM_STAND_ATTACK			4
#define SM_SIT_ATTACK			5
#define SM_STAND_UP_STAIR		6
#define SM_STAND_DOWN_STAIR		7
#define SM_MOVE_UP_STAIR		8
#define SM_MOVE_DOWN_STAIR		9
#define SM_ATTACK_UP_STAIR		10
#define SM_ATTACK_DOWN_STAIR	11
#define SM_HURTED				12
#define SM_INVISIBLE			13
#define SM_EAT_ITEM				14
#define SM_FALL_DOWN			15
#define SM_THROW_WEAPON			16
#define SM_DEAD					17
#define SM_STAND_BACK			18
#define SM_FLY_ATTACK			19
#define SM_AFTER_FLY			20

//Weapons
#define WP_WHIP_STAND_LEFT		0
#define WP_WHIP_SIT_LEFT		1
#define WP_WHIP_FLY				2

#define WP_LV_0					0
#define WP_LV_1					1
#define WP_LV_2					2

//Items

#define I_HEART_BIG				0
#define I_MORNING_STAR			1
#define I_MONEY_BLUE			2
#define I_ROSARY				3
#define I_ROSACT				4
#define I_STOPWATCH				5
#define I_DOUBLE_SHOT			6
#define I_BOSS_BAT				7

//map lv1
#define LM_LEFT_1				0
#define LM_RIGHT_1				1

//ALL BOX
#define PROP_BBOX_WIDTH			35
#define PROP_BBOX_HEIGHT		35
#define PROP_BBOX_CHANGE		100

#define ITEM_BBOX_WIDTH			32
#define ITEM_BBOX_HEIGHT		32

#define GROUND_BBOX_WIDTH		768
#define GROUND_BBOX_HEIGHT		32

//Status candle
#define CANDLE_STATE_NO			100
#define CANDLE_STATE_DIE		200