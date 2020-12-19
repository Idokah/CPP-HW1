#pragma once
#include <iostream>

class Citizen;

class District
{
	public:
		District();
		District(char* name, int representativeNum);
		District(const District& other);
		void operator=(const District& other);
		void increaseCitizenNum();
		~District();
        void addVote(Citizen* voter, const int partyNum);
        int getID();
        char* getName();
        int getRepresentativeNum();
        int getWinningParty();
        int* getNumOfRepresantivesPerParty(int& numOfExistsPartiesInDistrict);
        float* getPercentagePerParty();
        float getVotePercentage();
        int* getElectionResults();
private:
		char *name;
		int id;
		int citizenNum;
		float votersPercentage;
		int representativeNum;
		int generateID();
        int voteCount;
        //// ---- election results functionality ----
        int* electionResults;  // the index represent the (party ID - 1) and the value the number of citizens that vote for it.
        int electionResultsSize;
        void increaseArrSize(int*& arr,int &currSize, const int newSize);
        void addToElectionResult(const int partyNum);
};