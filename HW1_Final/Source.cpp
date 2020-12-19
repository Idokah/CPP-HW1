#include <iostream>
#include "Citizen.h"
#include "District.h"
#include "ElectionRound.h"
#include "Party.h"

void addDistrict(ElectionRound& electionRound);
void addCitizen(ElectionRound& electionRound);
void addParty(ElectionRound& electionRound);
void setCitizenAsPartyRepresentive(ElectionRound& electionRound);
void printAllDistricts(ElectionRound& electionRound);
void printAllCitizens(ElectionRound& electionRound);
void printAllParties(ElectionRound& electionRound);
void vote(ElectionRound& electionRound);
void showElectionResults(ElectionRound& electionRound);
bool isValidCitizen(const char *action, Citizen* citizen);
bool isValidParty(const char *action, Party* party);

using namespace std;

const int MAX_STRING_LEN = 100;

int main()
{
    int option = 0;
    int day , month, year;
	cout << "enter elections date DD MM YYYY ";
	cin >> day >> month >> year;
    ElectionRound electionRound(day, month, year);

    //addCitizenMOCK()
    while (option != 10) {
        cout << "enter one of the options-" << endl
             << "1 - add district" << endl
             << "2- add citizen" << endl
             << "3- add party" << endl
             << "4- add citizen as party representive" << endl
             << "5- show all districts" << endl
             << "6- show all citizens" << endl
             << "7- show all parties" << endl
             << "8- vote" << endl
             << "9- show election results" << endl
             << "10- exit the program" << endl;
        cin >> option;
        switch (option)
        {
            case 1:
                addDistrict(electionRound);
                break;
            case 2:
                addCitizen(electionRound);
                break;
            case 3:
                addParty(electionRound);
                break;
            case 4:
                setCitizenAsPartyRepresentive(electionRound);
                break;
            case 5:
                printAllDistricts(electionRound);
                break;
            case 6:
                printAllCitizens(electionRound);
                break;
            case 7:
                printAllParties(electionRound);
                break;
            case 8:
                vote(electionRound);
            case 9:
                showElectionResults(electionRound);
            case 10:
                cout << "See you later :(" << endl;
                break;
        }

    }
}

void addDistrictMOCK(ElectionRound &electionRound, char *name, int representativeNum) {
    District *district = new District(name, representativeNum);
    electionRound.addDistrict(district);
}

void addDistrict(ElectionRound &electionRound) {
    char name[MAX_STRING_LEN];
    int representativeNum;
    cout << "enter name and number of representative ";
    cin >> name >> representativeNum;
    District *district = new District(name, representativeNum);
    electionRound.addDistrict(district);
}

void addCitizenMOCK(ElectionRound& electionRound, char *name, char* id, int districtNum) {
    int birthYear = 1992;
    District* district = electionRound.getDistrictByID(districtNum);
    Citizen* citizen = new Citizen(name, id, birthYear, district);
    electionRound.addCitizen(citizen);
}

void addCitizen(ElectionRound& electionRound) {
    char name[MAX_STRING_LEN];
    char id[MAX_STRING_LEN];
    int birthYear, districtNum;
    cout << "enter name, id, birth year and district number ";
    cin >> name >> id >> birthYear >> districtNum;
    District* district = electionRound.getDistrictByID(districtNum);
    Citizen* citizen = new Citizen(name, id, birthYear, district);
    electionRound.addCitizen(citizen);
}

void addPartyMOCK(ElectionRound& electionRound, char*name, char* id) {

    Citizen* head = electionRound.getCitizenByID(id);
    if (! isValidCitizen("addParty", head)) return;
    Party* party = new Party(name, head);
    electionRound.addParty(party);
    head->setIsPartyMember();
}

void addParty(ElectionRound& electionRound) {
    char name[MAX_STRING_LEN];
    char id[MAX_STRING_LEN];
    cout << "enter name and the party head's id ";
    cin >> name >> id;
    Citizen* head = electionRound.getCitizenByID(id);
    if (! isValidCitizen("addParty", head)) return;
    Party* party = new Party(name, head);
    electionRound.addParty(party);
    head->setIsPartyMember();
}

void setCitizenAsPartyRepresentiveMOCK(ElectionRound& electionRound, char* representiveId, int partyId, int districtId) {
    Citizen *citizen = electionRound.getCitizenByID(representiveId);
    if (! isValidCitizen("setCitizenAsPartyRepresentive", citizen)) return;
    citizen->setIsPartyMember();
    Party *party = electionRound.getPartyByID(partyId);
    if (! isValidParty("setCitizenAsPartyRepresentive", party)) return;
    party->addRepresentive(districtId, citizen);
}

void setCitizenAsPartyRepresentive(ElectionRound& electionRound) {
    char representiveId[MAX_STRING_LEN];
    int partyId;
    int districtId;
    cout << "enter representive ID, party ID, district ID ";
    cin >> representiveId >> partyId >> districtId;
    Citizen *citizen = electionRound.getCitizenByID(representiveId);
    if (! isValidCitizen("setCitizenAsPartyRepresentive", citizen)) return;
    citizen->setIsPartyMember();
    Party *party = electionRound.getPartyByID(partyId);
    if (! isValidParty("setCitizenAsPartyRepresentive", party)) return;
    party->addRepresentive(districtId, citizen);
}


void printAllDistricts(ElectionRound& electionRound) {
    electionRound.printAllDistricts();
}

void printAllCitizens(ElectionRound& electionRound) {
    electionRound.printAllCitizens();
}

void printAllParties(ElectionRound& electionRound) {
    electionRound.printAllParties();
}

void voteMOCK(ElectionRound& electionRound, char *citizenId, int partyId){
    Citizen* voter = electionRound.getCitizenByID(citizenId);
    District* district=voter->getDistrict();
    district->addVote(voter, partyId);
    Party* party = electionRound.getPartyByID(partyId);
    if (! isValidParty("vote", party)) return;
    party->increaseNumberOfVotes();
}

void vote(ElectionRound& electionRound){
    char citizenId[MAX_STRING_LEN];
    int partyId;
    cout << "enter citizen ID, party ID";
    cin >> citizenId >> partyId;
    Citizen* voter = electionRound.getCitizenByID(citizenId);
    District* district=voter->getDistrict();
    district->addVote(voter, partyId);
    Party* party = electionRound.getPartyByID(partyId);
    if (! isValidParty("vote", party)) return;
    party->increaseNumberOfVotes();
}


void showElectionResults(ElectionRound& electionRound) {
    District* district;
    Party* party, * winningParty;
    char* headName;
    int numOfExistsPartiesInDistrict, * numOfRepresantivesPerParty = nullptr, * electionResults;
    float* percentagePerParty = nullptr;
    for (int i = 0; i < electionRound.getDistrictLogSize(); ++i) {

        district = electionRound.getDistricts()[i];
        winningParty = electionRound.getPartyByID(district->getWinningParty());
        headName = winningParty->getPartyHead()->getName();
        cout << *district << endl
            << "    head of the winning party- " << headName << endl
            << "    vote percentage- " << district->getVotePercentage() << "%" << endl;
        electionResults = district->getElectionResults();
        percentagePerParty = district->getPercentagePerParty();
        numOfRepresantivesPerParty = district->getNumOfRepresantivesPerParty(numOfExistsPartiesInDistrict);
        winningParty->increaseNumberOfWinningRepresentives(district->getRepresentativeNum());
        for (int j = 0; j < electionRound.getPartiesLogSize(); ++j) {
            cout << "    " << *(electionRound.getPartyByID(j + 1)) << endl;
            if (j < numOfExistsPartiesInDistrict)
            {
                cout << "        number of voters -" << electionResults[j] << endl
                    << "        percentage of all votes - " << percentagePerParty[j] << "%" << endl;
                if (numOfRepresantivesPerParty[j] > 0) {
                    cout << "        represantives - " << endl;
                    party = electionRound.getPartyByID(j + 1);
                    party->printNRepresantive(i, numOfRepresantivesPerParty[j]);
                }
            }
            else {
                cout << "        number of voters" << " - 0" << endl
                    << "        percentage of all votes - 0%" << endl;
            }
        }
    }


bool isValidCitizen(const char *action, Citizen* citizen){
    if (citizen == NULL) {
        cout << action << " -there is no such citizen." << endl;
        return false;
    }
    if (citizen->getIsPartyMember()){
        cout << action << " -already set as represantive or head." << endl;
        return false;
    }
    return true;
}

bool isValidParty(const char *action, Party* party){
    if (party == NULL) {
        cout << action << " -there is no such party." << endl;
        return false;
    }
    return true;
}