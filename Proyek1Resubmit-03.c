/*	Program : Among Us 
	Nama : Brian Samuel Matthew (1906381640) & Lazaruslie Karsono (1906300782) */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>


void isiArray();
void Array();
void Value();
void Random();
void help();
void Jumlahpemain();

int pemain;
int i;
int j;
int k;
int ans;
int randomIndex;
int randomValue;
int random;
int randomBot;
int operasi;
int number[20] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

int main(){
	MAINMENU:
		
	printf("==================================================\n");
	printf(" ---Among Us---");
	printf("\n    _____");
	printf("\n  _|    _|");
	printf("\n | |   |__| ");
	printf("\n |_|  _  |");
	printf("\n   |_| |_|\n");
	printf("\nMenu:\n");
	printf("1. Play Game\n");
	printf("2. Help\n");
	printf("3. Keluar\n");
	printf("Input : ");
	scanf("%d", &operasi);
	
	switch (operasi) {
	case 1:
		
	Jumlahpemain();
		
	j=pemain;
	isiArray();
	Value();
	
	Loop:
	if(j==0){
	goto End;
	}
	Random();
	number[randomBot-1] = 0;
	Ulang:
	sleep(2);
	system("cls");
	printf("==================================================\n");
	printf("Pemain: ");
	Array();
	printf("\nAda satu Impostor di antara pemain ini\n");
	
	
	
	printf("\nAnda harus menebak yang mana Impostornya");
	printf("\nAnda menebak pemain ke : "); scanf("%d", &ans);
	
	if(ans > number[20]) {
		printf("\nMaaf, jumlah pemain melebihi batas");
		sleep(2);
		printf("\nSilahkan pilih pemain sesuai batasannya\n");
		sleep(2);
		system("cls");
		goto Ulang;
		break;
	}
	
	if(number[ans-1] == 0){
		printf("\nPemain tersebut sudah mati");
		sleep(2);	
		printf("\nSilahkan pilih pemain lain\n");
		sleep(2);
		system("cls");
		goto Ulang;
		break;
	}
	
	if(ans == randomValue){
		sleep(2);
		printf("\nSelamat! Pemain ke-%d merupakan Impostor, Crewmate Menang!\n", randomValue);
		goto End;
	}

	else
		j--;
		number[ans-1] = 0;
		sleep(2);
		printf("\nPemain ke-%d bukan Impostor\n", ans);
		sleep(2);
		
		if(j==0){
			printf("\nAnda kalah! Impostor Menang");
			printf("\nPemain ke-%d Merupakan Impostor\n", randomValue);
			printf("\nPermainan berakhir");
			goto End;
		}
		
		else
		goto Loop;
		break;
	
	case 2:
		system("cls");
		help();
		goto MAINMENU;
		
		break;
		
	case 3:
		system("cls");
		goto Exit;
		
	default:
		printf("\nInput hanya menerima pilihan 1 sampai 3");
		printf("\nSilahkan masukkan input kembali");
		break;
}
	End:
		printf("\n==================================================\n");
		printf("Tekan apa saja untuk kembali ke Menu\n");
		getch();
		system("cls");
		goto MAINMENU;
		
	Exit:
		printf ("\nTerima Kasih. :)");
	return 0;
}

void Jumlahpemain() {
	pilih:
	system("cls");
	printf ("Jumlah Pemain minimal 6 dan maksimal 20 pemain\n");
	printf ("Silahkan Input Jumlah Pemain : "); scanf ("%d", &number[20]);
	
	if ( number[20] == 6) {
		pemain = 2;
	}
	if (number[20] == 7) {
		pemain = 3;	
	}
	if (number[20] == 8) {
		pemain = 3;
	}
	if (number[20] == 9) {
		pemain = 4;	
	}
	if (number[20] == 10) {
		pemain = 4;	
	}
	if (number[20] == 11) {
		pemain = 5;
	}
	if (number[20] == 12) {
		pemain = 5;	
	}
	if (number[20] == 13) {
		pemain = 6;
	}
	if (number[20] == 14) {
		pemain = 6;	
	}
	if (number[20] == 15) {
		pemain = 7;
	}
	if (number[20] == 16) {
		pemain = 7;	
	}
	if (number[20] == 17) {
		pemain = 8;
	}
	if (number[20] == 18) {
		pemain = 8;	
	}
	if (number[20] == 19) {
		pemain = 9;
	}
	if (number[20] == 20) {
		pemain = 9;	
	}
	if (number[20] < 6 || number[20] > 20) {
		printf ("\nMaaf Jumlah pemain diluar batasan\n");
		printf ("Silahkan input pemain sesuai batas.\n");
		printf("\n==================================================\n");
		printf("Tekan apa saja untuk kembali\n");
	getch();
	goto pilih;	
	}
}

/* Program untuk mengisi Array */
void isiArray() {
	for(k=0; k<number[20]; k++){
		number[k] = k+1;
	}
}

/* Program untuk menampilkan pemain */
void Array() {
	for(i=0; i<number[20]; i++){
		printf("%d ", number[i]);
	}
}

/* Program untuk menentukan Impostor */
void Value() {
	srand(time(NULL));
	randomIndex = rand() % number[20];
	randomValue = number[randomIndex];
}

/* Program untuk menentukan target Impostor */
void Random() {
	Bot:
	srand(time(NULL));
	random = rand() % number[20];
	randomBot = number[random];
	
	if(randomBot == 0){
		goto Bot;
	}
	
	if(randomBot == ans){
		goto Bot;
	}
	if(randomBot == randomValue){
		goto Bot;
	}
	
	else
	system("cls");
	printf("==================================================\n");
	printf("Pemain: ");
	Array();
	printf("\n.");
	sleep(1);
	printf(".");
	sleep(1);
	printf(".");
	sleep(1);
	printf("\nImpostor membunuh pemain ke %d", randomBot);
	printf("\n    _____");
	printf("\n  _|    _|");
	printf("\n | |   |__| ");
	printf("\n |_|  _  |");
	printf("\n   |_| |_|\n");
}

/* Program Help */
void help() {
	printf("Help\n");
	sleep(1);
	printf("==================================================\n");
	sleep(2);
	printf("Pada permainan ini, terdapat 6-20 pemain \n");
	sleep(2);
	printf("Salah satu pemain merupakan Impostor\n");
	sleep(2);
	printf("Anda harus menebak siapa Impostornya\n");
	sleep(2);
	printf("Jika tebakan Anda benar, maka Crewmate dinyatakan menang\n");
	sleep(2);
	printf("Jika tebakan Anda salah, maka pemain yang Anda tebak dinyatakan mati\n");
	sleep(2);
	printf("Impostor akan membunuh 1 pemain di awal setiap giliran\n");
	sleep(2);
	printf("Jika tersisa 2 pemain, maka Impostor dinyatakan menang\n");
	sleep(2);
	printf("Semoga Berhasil :)\n");
	sleep(2);
	printf("==================================================\n");
	sleep(2);
	printf("Tekan apa saja untuk kembali ke Menu\n");
	getch();
	system("cls");
	
}

