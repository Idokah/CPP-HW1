#include "Citizen.h"
#include "District.h"

int MAX_STRING_LEN = 100;

char* getString(char* input) {
	int inputLen = strlen(input);
	char* str = new char[inputLen + 1];
	memcpy(str, input, inputLen);
	str[inputLen] = '\0';
	return str;
}

Citizen::Citizen() {}

Citizen::Citizen(char* name, char* id, unsigned int birthYear, District* district) : isPartyMember(false), isAlreadyVote(false) {
    this->name = getString(name);
    this->id = getString(id);
    this->birthYear = birthYear;
    this->district = district;
}

Citizen::Citizen(const Citizen& other) {
    *this = other;
}

Citizen::~Citizen() {
    delete[] name;
    delete[] id;
}

char* Citizen::getName() { return this->name; }

bool Citizen::setIsPartyMember() {
    this->isPartyMember = true;
    return true;
}

bool Citizen::setIsAlreadyVote() {
    this->isAlreadyVote = true;
    return true;
}

bool Citizen::getIsPartyMember() const { return this->isPartyMember;}

bool Citizen::getIsAlreadyVote() const { return this->isAlreadyVote;}


Citizen& Citizen::operator=(const Citizen& other){
    this->name = getString(other.name);
    this->id = getString(other.id);
    this->birthYear = other.birthYear;
    *(this->district) = *(other.district);
    this->isPartyMember = other.isPartyMember;
    this->isAlreadyVote = other.isAlreadyVote;
    return *this;
}

char* Citizen::getID() const { return this->id; }

District* Citizen::getDistrict(){ return this->district;};