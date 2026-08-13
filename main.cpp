//#include <iostream>
//
//using namespace std;
//
//enum class ESkillDamageType
//{
//	Melee,
//	Magic
//};
//
//enum class EElementType
//{
//	None,
//	Normal,
//	Fire,
//	Water,
//	Grass,
//	Electric,
//	Ice,
//	Ground,
//	Flying
//};
//
//class Skill
//{
//public:
//	int Id;
//	ESkillDamageType SkillDamageType;
//	EElementType SkillElementType;
//	float SkillDamageRate;
//	int HitChance;
//};
//
//class Monster
//{
//public:
//	int Id;
//	int Level;
//	float Exp;
//	float MaxExp;
//	string MonsterName;
//
//	EElementType MonsterElementType1;
//	EElementType MonsterElementType2;
//
//	float Hp;
//	float MeleeAtk;
//	float MagicAtk;
//
//	float MeleeDef;
//	float MagicDef;
//
//	Skill HasSkill[4];
//};
//
//class Player
//{
//public:
//	Monster HasMonster[6];
//};
//
//
//// ========================================
//// Type Chart
//// ========================================
//
////                 None   N    F    W    G    E    I    Gr   Fl
//float TypeChart[9][9] =
//{
//	{ 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f }, // None
//
//	{ 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f, 1.f }, // Normal
//
//	{ 1.f, 1.f, 1.f, 0.5f, 2.f, 1.f, 2.f, 1.f, 1.f }, // Fire
//
//	{ 1.f, 1.f, 2.f, 1.f, 0.5f, 1.f, 1.f, 2.f, 1.f }, // Water
//
//	{ 1.f, 1.f, 0.5f, 2.f, 0.5f, 1.f, 1.f, 2.f, 0.5f }, // Grass
//
//	{ 1.f, 1.f, 1.f, 2.f, 0.5f, 0.5f, 1.f, 2.f, 2.f }, // Electric
//
//	{ 1.f, 1.f, 0.5f, 2.f, 2.f, 1.f, 0.5f, 2.f, 2.f }, // Ice
//
//	{ 1.f, 1.f, 2.f, 2.f, 0.5f, 2.f, 2.f, 1.f, 0.f }, // Ground
//
//	{ 1.f, 1.f, 1.f, 1.f, 2.f, 0.5f, 1.f, 1.f, 1.f }  // Flying
//};
//
//
//// ========================================
//// Monster Pool
//// ========================================
//
//Monster MonsterPool[] =
//{
//	// Normal
//	{
//		1,
//		1, 0.f, 100.f,
//		"잠만보",
//		EElementType::Normal,
//		EElementType::None,
//
//		160.0f,
//		110.0f,
//		65.0f,
//		65.0f,
//		65.0f
//	},
//
//	// Fire / Flying
//	{
//		2,
//		1, 0.f, 100.f,
//		"리자몽",
//		EElementType::Fire,
//		EElementType::Flying,
//
//		150.0f,
//		84.0f,
//		109.0f,
//		78.0f,
//		85.0f
//	},
//
//	// Water
//	{
//		3,
//		1, 0.f, 100.f,
//		"거북왕",
//		EElementType::Water,
//		EElementType::None,
//
//		158.0f,
//		83.0f,
//		85.0f,
//		100.0f,
//		105.0f
//	},
//
//	// Grass / Poison
//	// 현재 Enum에 Poison이 없으므로 일단 Grass만 사용
//	{
//		4,
//		1, 0.f, 100.f,
//		"이상해꽃",
//		EElementType::Grass,
//		EElementType::None,
//
//		160.0f,
//		82.0f,
//		100.0f,
//		83.0f,
//		100.0f
//	},
//
//	// Electric
//	{
//		5,
//		1, 0.f, 100.f,
//		"피카츄",
//		EElementType::Electric,
//		EElementType::None,
//
//		110.0f,
//		55.0f,
//		50.0f,
//		40.0f,
//		50.0f
//	},
//
//	// Ice / Psychic
//	// 현재 Enum에 Psychic이 없으므로 일단 Ice만 사용
//	{
//		6,
//		1, 0.f, 100.f,
//		"루주라",
//		EElementType::Ice,
//		EElementType::None,
//
//		140.0f,
//		50.0f,
//		115.0f,
//		35.0f,
//		95.0f
//	},
//
//	// Ground
//	{
//		7,
//		1, 0.f, 100.f,
//		"닥트리오",
//		EElementType::Ground,
//		EElementType::None,
//
//		120.0f,
//		80.0f,
//		50.0f,
//		50.0f,
//		70.0f
//	},
//
//	// Normal / Flying
//	{
//		8,
//		1, 0.f, 100.f,
//		"깨비드릴조",
//		EElementType::Normal,
//		EElementType::Flying,
//
//		120.0f,
//		90.0f,
//		60.0f,
//		65.0f,
//		65.0f
//	}
//};
//
//Player Player0
//{
//	{
//		MonsterPool[4]
//	}
//};
//
//int Map[100][100] = {};
//
//float GetTypeMultiplier(
//	EElementType AttackType,
//	EElementType DefenseType1,
//	EElementType DefenseType2);
//
//Monster GetRandomMonster();
//void InitializeMap();
//
//int main()
//{
//	InitializeMap();
//
//	int PlayerX = 0;
//	int PlayerY = 0;
//
//	while (true)
//	{
//		cout << "현재 위치 : "
//			<< PlayerX << ", "
//			<< PlayerY << endl;
//
//		cout << "이동 (WASD) : ";
//
//		char Input;
//		cin >> Input;
//
//		switch (Input)
//		{
//		case 'w':
//			PlayerY++;
//			break;
//
//		case 's':
//			PlayerY--;
//			break;
//
//		case 'a':
//			PlayerX--;
//			break;
//
//		case 'd':
//			PlayerX++;
//			break;
//
//		default:
//			cout << "잘못된 입력" << endl;
//			continue;
//		}
//
//		// 현재 위치의 맵 확인
//		cout << "현재 타일 : " << Map[PlayerY][PlayerX] << endl;
//	}
//
//	return 0;
//}
//
//void InitializeMap()
//{
//	for (int y = 40; y < 60; ++y)
//	{
//		for (int x = 40; x < 60; ++x)
//		{
//			Map[y][x] = 1;
//		}
//	}
//}
//
//float GetTypeMultiplier(
//	EElementType AttackType,
//	EElementType DefenseType1,
//	EElementType DefenseType2)
//{
//	float Multiplier = 1.0f;
//
//	Multiplier *= TypeChart[
//		static_cast<int>(AttackType)
//	][
//		static_cast<int>(DefenseType1)
//	];
//
//	if (DefenseType2 != EElementType::None)
//	{
//		Multiplier *= TypeChart[
//			static_cast<int>(AttackType)
//		][
//			static_cast<int>(DefenseType2)
//		];
//	}
//
//	return Multiplier;
//}
//
//Monster GetRandomMonster()
//{
//	srand((unsigned int)time(nullptr));
//	int MonsterPoolCount = sizeof(MonsterPool) / sizeof(MonsterPool[0]);
//
//	int RandomMonsterIndex = rand() % MonsterPoolCount;
//
//	Monster RandomMonster = MonsterPool[RandomMonsterIndex];
//
//	int RandomMonsterLevel = rand() % MonsterPoolCount;
//
//	RandomMonster.Level = RandomMonsterLevel;
//
//	return RandomMonster;
//}