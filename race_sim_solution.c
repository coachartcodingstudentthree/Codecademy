 contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
	int numberOfLaps;
	int currentLap;
	char* firstPlaceDriverName;
	char* firstPlaceRaceCarColor;
};

struct RaceCar {
	char* driverName;
	char* raceCarColor;
	int totalLapTime;
};

// Print functions section
void printIntro() {
	printf("Welcome to our main event digital race fans!\n"\
	       "I hope everybody has their snacks because we are about to begin!\n\n");
}

void printCountdown() {
	printf("Racers Ready! In...\n5\n4\n3\n2\n1\nRace!\n\n");
}

void printFirstPlaceAfterLap(struct Race race) {
	printf("After lap number %d - First Place Is : %s in the %s race car!\n",
		race.currentLap, race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

void printCongratulation(struct Race race) {
	printf("\nLet's all congratulate %s in the %s race car for an amazing performance.\n"\
           "It truly was a great race and everybody have a goodnight!\n",
		race.firstPlaceDriverName, race.firstPlaceRaceCarColor);
}

// Logic functions section
int calculateTimeToCompleteLap() {
	int speed = rand() % 3 + 1;
	int acceleration = rand() % 3 + 1;
	int nerves = rand() % 3 + 1;

	return speed + acceleration + nerves;
}

void  updateRaceCar(struct RaceCar* raceCar) {
	raceCar->totalLapTime += calculateTimeToCompleteLap();
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
	if (raceCar1->totalLapTime < raceCar2->totalLapTime) {
		race->firstPlaceDriverName = raceCar1->driverName;
		race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
	}
	else {
		race->firstPlaceDriverName = raceCar2->driverName;
		race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
	}
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
	struct Race race = {5, 1};

	for (int i = 0; i < race.numberOfLaps; i++) {
		updateRaceCar(raceCar1);
		updateRaceCar(raceCar2);
		updateFirstPlace(&race, raceCar1, raceCar2);
		printFirstPlaceAfterLap(race);
		++race.currentLap;
	}

	printCongratulation(race);
}

int main() {
	srand(time(0));

	printIntro();
	printCountdown();

	char driver1[] = "David";
	char driver2[] = "Fred";
	char color1[] = "Blue";
	char color2[] = "Yellow";

	struct RaceCar raceCar1 = { (char*) &driver1, (char*) &color1, 0};
	struct RaceCar raceCar2 = { (char*) &driver2, (char*) &color2, 0};

	startRace(&raceCar1, &raceCar2);

};
