#include <stdio.h>
#include <string.h>

typedef struct {
    char name[20];
    char address[20];
    char species[20];
} pet;

typedef struct{
    pet petArray[10];
    char councilName[20];
} petDatabase;
void printNamesOfLocalDogs(petDatabase inputDb);
void printNamesOfLocalDogsByRef(petDatabase *inputDbPointer);



void printNamesOfLocalDogsByVal(petDatabase inputDb){
    for (int i = 0; i<10; i++){
        if (strcmp(inputDb.petArray[i].species, "Dog") == 0){
            printf("%s lives at %s. \n",inputDb.petArray[i].name, inputDb.petArray[i].address);
        }
    }
}
void printNamesOfLocalDogsByRef(petDatabase *inputDbPointer){
    for (int i = 0; i<10; i++){
        if (strcmp(inputDbPointer->petArray[i].species, "Dog") == 0){
            printf("%s lives at %s. \n",inputDbPointer->petArray[i].name, inputDbPointer->petArray[i].address);
        }
    }
}
int main(){
    pet pet1;
    strcpy(pet1.name, "Charlie");
    strcpy(pet1.address,"32 Ecclesall Rd");
    strcpy(pet1.species,"Dog");

    pet pet2;
    strcpy(pet2.name, "David");
    strcpy(pet2.address, "33 Ecclesall Rd");
    strcpy(pet2.species, "Cat");

    pet pet3;
    strcpy(pet3.name, "Boo");
    strcpy(pet3.address,"34 Ecclesall Rd");
    strcpy(pet3.species, "Cat");

    pet pet4;
    strcpy(pet4.name, "Spock");
    strcpy(pet4.address, "35 Ecclesall Rd");
    strcpy(pet4.species, "Cat");

    pet pet5;
    strcpy(pet5.name, "Tweety");
    strcpy(pet5.address, "36 Ecclesall Rd");
    strcpy(pet5.species, "Bird");

    pet pet6;
    strcpy(pet6.name, "Snapper");
    strcpy(pet6.address, "37 Ecclesall Rd");
    strcpy(pet6.species, "Dog");

    pet pet7;
    strcpy(pet7.name, "Bella");
    strcpy(pet7.address, "38 Ecclesall Rd");
    strcpy(pet7.species, "Dog");

    pet pet8;
    strcpy(pet8.name, "Nibbles");
    strcpy(pet8.address, "39 Ecclesall Rd");
    strcpy(pet8.species, "Mouse");

    pet pet9;
    strcpy(pet9.name, "Whiskers");
    strcpy(pet9.address, "40 Ecclesall Rd");
    strcpy(pet9.species, "Mouse");

    pet pet10;
    strcpy(pet10.name, "Sprinkles");
    strcpy(pet10.address, "41 Ecclesall Rd");
    strcpy(pet10.species, "Cat");

    petDatabase councilPetDatabase;
    councilPetDatabase.petArray[0] = pet1;
    councilPetDatabase.petArray[1] = pet2;
    councilPetDatabase.petArray[2] = pet3;
    councilPetDatabase.petArray[3] = pet4;
    councilPetDatabase.petArray[4] = pet5;
    councilPetDatabase.petArray[5] = pet6;
    councilPetDatabase.petArray[6] = pet7;
    councilPetDatabase.petArray[7] = pet8;
    councilPetDatabase.petArray[8] = pet9;
    councilPetDatabase.petArray[9] = pet10;

    strcpy(councilPetDatabase.councilName,"Sheffield Council");

    printf("Council: %s\n", councilPetDatabase.councilName);

    printNamesOfLocalDogsByRef(&councilPetDatabase);

    return 0;
}


