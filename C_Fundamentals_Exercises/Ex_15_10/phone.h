#pragma once
#ifndef _PHONE_H
#define _PHONE_H

#define FILENAME "phone.dat"
#define NLEN 25
#define PLEN 20
#define MENU_SIZE 5

typedef struct
{
	char name[NLEN];
	char phoneNr[PLEN];
} Phone;
char* menutext[][2] = { {"a","add"}, {"l","list"}, {"s","search"}, {"r","remove"}, {"e","end"} };
#endif