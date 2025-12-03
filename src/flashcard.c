#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define FILENAME "flashcards.txt"

struct Flashcard {
    char question[200];
    char answer[200];
};

void addFlashcard();
void viewFlashcards();
void quizMode();
void searchFlashcard();
void deleteFlashcard();
void removeNewline(char *str);

int main() {
    int choice;
    srand(time(NULL));

    while (1) {
        printf("\n====== FLASHCARD LEARNING SYSTEM ======\n");
        printf("1. Add Flashcard\n");
        printf("2. View Flashcards\n");
        printf("3. Quiz Mode\n");
        printf("4. Search Flashcard\n");
        printf("5. Delete Flashcard\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        while(getchar()!='\n'); 

        switch(choice) {
            case 1: addFlashcard(); break;
            case 2: viewFlashcards(); break;
            case 3: quizMode(); break;
            case 4: searchFlashcard(); break;
            case 5: deleteFlashcard(); break;
            case 6: printf("\nGoodbye! Keep Learning! 👋\n"); exit(0);
            default: printf("\nInvalid choice, try again.\n");
        }
    }
    return 0;
}


void removeNewline(char *str) {
    str[strcspn(str, "\n")] = '\0';
}



void addFlashcard() {
    FILE *fp = fopen(FILENAME, "a");
    struct Flashcard f;

    if (!fp) {
        printf("Error opening file.\n");
        return;
    }

    printf("\nEnter Question: ");
    fgets(f.question, sizeof(f.question), stdin);

    printf("Enter Answer: ");
    fgets(f.answer, sizeof(f.answer), stdin);

    removeNewline(f.question);
    removeNewline(f.answer);

    fprintf(fp, "%s|%s\n", f.question, f.answer);
    fclose(fp);

    printf("\nFlashcard Added Successfully!\n");
}


void viewFlashcards() {
    FILE *fp = fopen(FILENAME, "r");
    char line[400];
    int count = 1;

    if (!fp) {
        printf("No flashcards available.\n");
        return;
    }

    printf("\n------ FLASHCARD LIST ------\n");
    while (fgets(line, sizeof(line), fp)) {
        char *q = strtok(line, "|");
        char *a = strtok(NULL, "|");

        if(q && a)
            printf("\n%d) Q: %s\n   A: %s", count++, q, a);
    }

    fclose(fp);
}


void quizMode() {
    FILE *fp = fopen(FILENAME, "r");
    struct Flashcard cards[100];
    char line[400], userAnswer[200];
    int count = 0;

    if (!fp) {
        printf("\nNo flashcards available.\n");
        return;
    }

    while (fgets(line, sizeof(line), fp) && count < 100) {
        char *q = strtok(line, "|");
        char *a = strtok(NULL, "|");

        if(q && a) {
            strcpy(cards[count].question, q);
            strcpy(cards[count].answer, a);
            removeNewline(cards[count].answer);
            count++;
        }
    }
    fclose(fp);

    if (count == 0) {
        printf("\nNo flashcards to quiz.\n");
        return;
    }

    int randomIndex = rand() % count;
    printf("\nQUIZ TIME!\n");
    printf("Question: %s\n", cards[randomIndex].question);

    printf("Your Answer: ");
    fgets(userAnswer, sizeof(userAnswer), stdin);
    removeNewline(userAnswer);

    if (strcmp(userAnswer, cards[randomIndex].answer) == 0) {
        printf("\nCorrect! 🎉\n");
    } else {
        printf("\nIncorrect \nCorrect Answer: %s\n", cards[randomIndex].answer);
    }
}


void searchFlashcard() {
    FILE *fp = fopen(FILENAME, "r");
    char keyword[100], line[400];
    int found = 0;

    if (!fp) {
        printf("\nFile not accessible.\n");
        return;
    }

    printf("\nEnter keyword to search: ");
    fgets(keyword, sizeof(keyword), stdin);
    removeNewline(keyword);

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, keyword)) {
            printf("\nMatch Found:\n%s", line);
            found = 1;
        }
    }

    if (!found) printf("\nNo matching flashcard found.\n");

    fclose(fp);
}


void deleteFlashcard() {
    FILE *fp = fopen(FILENAME, "r");
    FILE *temp = fopen("temp.txt", "w");
    char keyword[100], line[400];
    int deleted = 0;

    if (!fp || !temp) {
        printf("\nError accessing files.\n");
        return;
    }

    printf("\nEnter keyword of flashcard to delete: ");
    fgets(keyword, sizeof(keyword), stdin);
    removeNewline(keyword);

    while (fgets(line, sizeof(line), fp)) {
        if (strstr(line, keyword)) {
            deleted = 1;
        } else {
            fputs(line, temp);
        }
    }

    fclose(fp);
    fclose(temp);
    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (deleted)
        printf("\nFlashcard Deleted Successfully.\n");
    else
        printf("\nNo matching flashcard found.\n");
}