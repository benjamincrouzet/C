#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum Nombredefoisoujaieulaflemme {
	javier = 30,
	fevrier = 34,
	mars = 10,
	avril = 60,
	mai = 50,
	juin = 15,
	juillet = 70,
	aout = 40,
	septembre = 5,
	octobre = 17,
	novembre = 9,
	decembre = 4,


};
int main(void) {
	char choix[50];
	enum Nombredefoisoujaieulaflemme Benjamin;
	Benjamin = 1;
	printf("choisir un mois pour savoir si j'ai ete flemmard \n");
	scanf(" %s", Benjamin);

		switch (Benjamin)
		{
		case javier:
			printf("ca peut aller");
			break;
		case fevrier:
			printf("un peu abusé alors qui il y a le bac");
			break;
		case mars:
			printf("normal meme si il y a le bac parce qu'il ne faut pas abuse non plus");
			break;
		case avril:
			printf("j'ai abuse du fait que le bac venait de passer");
			break;
		case mai:
			printf("pareil que pour le mois d'avril");
			break;
		case juin:
			printf("tres raisonnable");
			break;
		case juillet:
			printf("normal c'est les vacances");
			break;
		case aout:
			printf("ca va c'est toujours les vacances");
			break;
		case septembre:
			printf("j'ai eu mon entreprise donc normal");
			break;
		case octobre:
			printf("normal");
			break;
		case novembre:
			printf("j'ai travailler");
			break;
		case decembre:
			printf("j'ai menti");
			break;

		}

	return 0;
}