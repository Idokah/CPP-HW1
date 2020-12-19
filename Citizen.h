#pragma once
#include <iostream>

class District;

class Citizen
{
    public:
		Citizen();
        Citizen(char* name, char* id, unsigned int birthYear, District* district);
		Citizen(const Citizen& other);
		~Citizen();
		char* getID() const;
		Citizen& operator=(const Citizen& other);
        District* getDistrict();
		char* getName();
		bool setIsPartyMember();
		bool getIsPartyMember() const;
        bool setIsAlreadyVote();
        bool getIsAlreadyVote() const;

    private:
		char* name;
		char* id;
		int birthYear;
		District* district;
		bool isPartyMember; ////head or represantive
        bool isAlreadyVote;
};