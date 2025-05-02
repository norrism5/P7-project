#include <iostream>
#include <string>
#include <list>
#include <random>
using namespace std;




class Encryption {
private:
	static const int hashSize = 201;
	list <pair  <string, pair< string, int>>> listing[hashSize];
	string password;
	string encryptPassword(string password, int shift, int salt );
	int hashFunction(string username);
public:
	void addUser(string username, string password);
	bool authenticateUser(string username, string password);
	int generateSalt();
	void displayUsers();
};
string Encryption::encryptPassword(string password, int shift,  int salt) {
	string encrypted = password;
	int effectiveShift = (shift + salt) % 26;  

	for (char& c : encrypted) {
		if (isalpha(c)) { 
			char base = islower(c) ? 'a' : 'A';
			c = (c - base + effectiveShift) % 26 + base;
		}
	}
	return encrypted;

}

void Encryption::addUser(string username, string password) {
	int salt = generateSalt();
	int shift = 3;
	string hashedPwd = encryptPassword(password, shift, salt);
	int index = hashFunction(username);

	for (auto it : listing[index]) {
		if (it.first == username) {
			cout << "[ERROR] User already exists!" << endl;
			return;
		}
	}
	listing[index].emplace_back(username, make_pair(password, salt));
}

int Encryption::generateSalt() {
	random_device r;
	return r() % 1000000;
}

bool Encryption::authenticateUser( string username, string password) {
	int index = hashFunction(username);
	for (auto it : listing[index]) {
		if (it.first == username) {
			string storedHash = it.second.first;
			int salt = it.second.second;
			int shift = 3;
			string newHash = encryptPassword(password, shift, salt);
			return newHash == storedHash;
		}
	}
	return false;
}

int Encryption::hashFunction(string username) {
	int asciiSum = 0;
	for (int i = 0; i < username.size(); i++) {
		asciiSum += username[i];
	}
	return asciiSum % hashSize;
}

void Encryption::displayUsers()
{
	for (int i = 0; i < hashSize; ++i) {
		if (!listing[i].empty()) {
			cout << "Hash Index [" << i << "]:" << endl;
			for (auto it : listing[i]) {
				cout << "  Username: " << it.first << ", Hashed Password: " << it.second.first << ", Salt: " << it.second.second << endl;
			}
		}
	}

}



int main() {

	int shift = 3;
	Encryption enc;

	enc.addUser("Test", "123");
	string user;
	string pass;
	do {
		cout << "LOGIN:" << endl;
		cout << "Enter Username - ";
		cin >> user;
		cout << endl << "Enter Password - ";
		cin >> pass;

		if (enc.authenticateUser(user, pass)) {
			cout << "Thank you! You are a valid user." << endl;
			break;
		}

		cout << "Invalid username or password! Please try again: " << endl;

	} while (!enc.authenticateUser(user, pass));

	//adding users
	enc.addUser("alice_wonderland", "Wonderland2023!");
	enc.addUser("bob_smith_84", "MySecret!2022");
	enc.addUser("charlie_brown42", "PeanutButter@23");
	enc.addUser("diana_ross_77", "DancingQueen@1");
	enc.addUser("edward_norton93", "FightClub#2022");
	enc.addUser("fiona_glenn21", "ShrekLover_2021");
	enc.addUser("george_harrison", "Beatlemania@2023");
	enc.addUser("harry_potter88", "MagicWand#007");
	enc.addUser("isabella_lee99", "StarryNight!2022");
	enc.addUser("jack_sparrow_12", "PirateKing#2021");
	enc.addUser("karen_rose23", "FlowerPower!2023");
	enc.addUser("louis_armstrong", "JazzMaster@2021");
	enc.addUser("mary_jane_parker", "SpiderSense_23");
	enc.addUser("nancy_drew_22", "MysterySolver@2022");
	enc.addUser("oscar_wilde98", "WildeHeart#2023");
	enc.addUser("peter_pan_27", "Neverland2023!");
	enc.addUser("quincy_jones_14", "MusicMan#2023");
	enc.addUser("rachel_green98", "F.R.I.E.N.D.S#2022");
	enc.addUser("sam_smith_99", "StayWithMe@2021");
	enc.addUser("tony_stark_42", "IronMan#2023");
	enc.addUser("ursula_jeffries", "SeaWitch!2023");
	enc.addUser("victor_franklin", "Frankenstein@2022");
	enc.addUser("wendy_park_01", "AdventureTime@2021");
	enc.addUser("xander_cage_77", "TripleX@2023");
	enc.addUser("yvonne_smith_88", "Y2KForever_2023");
	enc.addUser("zane_kaplan_23", "SuperZane!2022");
	enc.addUser("adam_smith_101", "CodeBreaker@2022");
	enc.addUser("betty_white_30", "GoldenGirl@2023");
	enc.addUser("chris_johnson_09", "RocketMan!2021");
	enc.addUser("daniel_williams_88", "FastTrack2023!");
	enc.addUser("emma_watson_99", "HermioneMagic@2022");
	enc.addUser("frank_sinatra_77", "FlyMeToTheMoon#2021");
	enc.addUser("gloria_stewart_01", "BroadwayQueen!2022");
	enc.addUser("harold_james_55", "MountainClimber@2023");
	enc.addUser("iris_chavez_24", "SkyDiver!2023");
	enc.addUser("jessica_taylor_99", "Fashionista@2022");
	enc.addUser("kevin_durant_34", "BasketballKing@2021");
	enc.addUser("linda_carson_66", "BeachBum_2023");
	enc.addUser("michael_jackson_45", "Thriller2022!");
	enc.addUser("nina_brown_22", "SmoothOperator@2023");
	enc.addUser("oliver_queen_23", "GreenArrow#2023");
	enc.addUser("patrick_stewart_32", "ShakespearFan_22");
	enc.addUser("quinn_martin_66", "RockStar@2021");
	enc.addUser("rick_grimes_44", "WalkingDead#2023");
	enc.addUser("sarah_jones_12", "WinterWonderland@2022");
	enc.addUser("thomas_jefferson_99", "Declaration!2021");
	enc.addUser("ursula_kleinsmith_20", "SeaQueen@2023");
	enc.addUser("vince_vaughn_11", "WeddingCrashers@2022");
	enc.addUser("wanda_maximoff_01", "ScarletWitch@2023");
	enc.addUser("xena_warrior_15", "StrongHeart!2022");
	//display users
	cout << "Displaying Users: " << endl;
	enc.displayUsers();


	
	
	

	return 0;
}