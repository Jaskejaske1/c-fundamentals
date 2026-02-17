#define _CRT_SECURE_NO_WARNINGS
#define LEN 64
#define N 2

#include <stdio.h>
#include <string.h>

typedef struct
{
	char streetAndNr[LEN];
	int postalCode;
	char town[LEN];
	char phoneNr[LEN];
} Address;

typedef struct
{
	char name[LEN];
	Address homeAddress;
	Address schoolAddress;
} Student;

void readStudent(Student* s);
void printStudent(Student s);
void readAddress(Address* p);
void printAddress(Address p);

int main(void)
{
	Student students[N];

	printf("Enter data for %d student(s):\n", N);
	for (int i = 0; i < N; i++)
	{
		printf("\n--- Student %d ---\n", i + 1);
		readStudent(&students[i]);
	}

	printf("\nData entered:\n");
	for (int i = 0; i < N; i++)
	{
		printf("Student %d:\n", i + 1);
		printStudent(students[i]);
		printf("\n");
	}

	return 0;
}

void readStudent(Student* s)
{
	printf("Name: ");
	fgets(s->name, LEN, stdin);
	s->name[strcspn(s->name, "\n")] = '\0';

	printf("\n-- Home Address --\n");
	readAddress(&s->homeAddress);

	printf("\n-- School Address --\n");
	readAddress(&s->schoolAddress);
}

void printStudent(Student s)
{
	printf("Name: %s\n", s.name);

	printf("Home Address: ");
	printAddress(s.homeAddress);

	printf("School Address: ");
	printAddress(s.schoolAddress);
}

void readAddress(Address* p)
{
	printf("  Street and Nr: ");
	fgets(p->streetAndNr, LEN, stdin);
	p->streetAndNr[strcspn(p->streetAndNr, "\n")] = '\0';

	printf("  Postal Code: ");
	scanf("%d%*c", &p->postalCode);

	printf("  Town: ");
	fgets(p->town, LEN, stdin);
	p->town[strcspn(p->town, "\n")] = '\0';

	printf("  Phone Nr: ");
	fgets(p->phoneNr, LEN, stdin);
	p->phoneNr[strcspn(p->phoneNr, "\n")] = '\0';
}

void printAddress(Address p)
{
	printf("%s, %d %s (Tel: %s)\n", p.streetAndNr, p.postalCode, p.town, p.phoneNr);
}