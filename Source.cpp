#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#pragma warning(disable:4996)

struct tag_Attributes
{
	int strength;
	int constitution;
	int dexterity;
	int speed;
	int luck;
	int intelligence;
	int wizardry;
	int charisma;
};
typedef struct tag_Attributes Attributes;

struct tag_Character
{
	char name[21];
	char kindred[21];
	Attributes attributes;
};
typedef struct tag_Character Character;

Character CreateCharacter(char* a, char* b);
void PrintCharacterSheet(const Character* player);
int roll_dice(void);

int main(void)
{
	srand((unsigned int)time(NULL));

	char a[21];
	char b[21];

	scanf("%s", a);
	scanf("%s", b);
	printf("\n");

	Character player = CreateCharacter(a, b);

	PrintCharacterSheet(&player);

	return 0;

}

Character CreateCharacter(char* a, char* b)
{
	Character player;
	strcpy(player.name, a);
	strcpy(player.kindred, b);

	player.attributes.strength = roll_dice();
	player.attributes.constitution = roll_dice();
	player.attributes.dexterity = roll_dice();
	player.attributes.speed = roll_dice();
	player.attributes.luck = roll_dice();
	player.attributes.intelligence = roll_dice();
	player.attributes.wizardry = roll_dice();
	player.attributes.charisma = roll_dice();

	return player;
}

void PrintCharacterSheet(const Character* player)
{

	printf("名前:%s\n", player->name);
	printf("種族:%s\n", player->kindred);
	printf("体力度:%d\n", player->attributes.strength);
	printf("耐久度:%d\n", player->attributes.constitution);
	printf("器用度:%d\n", player->attributes.dexterity);
	printf("速度:%d\n", player->attributes.speed);
	printf("幸運度:%d\n", player->attributes.luck);
	printf("知性度:%d\n", player->attributes.intelligence);
	printf("魔力度:%d\n", player->attributes.wizardry);
	printf("魅力度:%d\n", player->attributes.charisma);

}

int roll_dice(void)
{
	int number, sum, i;
	sum = 0;
	for (i = 0; i < 3; i++)
	{
		number = rand() % 6 + 1;
		sum += number;
	}
	return sum;
}