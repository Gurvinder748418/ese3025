#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>

void *harman(void *vargp) {
	//int i;
	int guess;
	printf("\nharman started guessing!\n");
	usleep(20000);
	while (1) {
		guess = ((rand() % 1000) + 1);
		if (guess == *((int*) vargp)) {
			//for (i = 1; i <= 1000; i++) {
			//if (i == *((int *) vargp)) {
			printf("harman won the game! He has guessed the number as %i\n",
					guess);
			exit(0);
		}
		usleep(20000);
	}
}

void *harveer(void *vargp) {
	int guess;
	printf("\nharveer started guessing!\n");
	usleep(20000);
	while (1) {
		guess = ((rand() % 1000) + 1);
		if (guess == *((int *) vargp)) {
			printf("harveer won the game! He has guessed the number as %i\n",
					guess);
			exit(0);
		}
		usleep(20000);
	}
}

void *player(void *vargp) {
	usleep(20000);
	while (1) {
		int guess;

		printf("\nType your guess between 1 to 1000:\n");
		scanf("%d", &guess);
		if (guess == *((int *) vargp)) {
			printf("You won! You have guessed the number as %i\n", guess);
			exit(0);
		}
	}
}

int main() {
	int r;
	pthread_t thread_id1, thread_id2, thread_id3;

	//srand(time(0));

	//r=((rand()%1000)+1);
	printf("please Enter the Number between 1 to 1000= ");
	scanf("%d", &r);

	printf("Guess the number between 1 to 1000\n");
	sleep(1);
	printf("3\n");
	sleep(1);
	printf("2\n");
	sleep(1);
	printf("1\n");
	sleep(1);
	printf("GO!\n\n");
	pthread_create(&thread_id1, NULL, harman, (void *) &r);
	pthread_create(&thread_id2, NULL, harveer, (void *) &r);
	pthread_create(&thread_id3, NULL, player, (void *) &r);

	pthread_join(thread_id1, NULL);
	pthread_join(thread_id2, NULL);
	pthread_join(thread_id3, NULL);
	exit(0);
}
