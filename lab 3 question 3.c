#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_TEAMS 10
#define SQUAD_SIZE 15

// Struct to store player's date of birth
typedef struct {
    int day;
    int month;
    int year;
} age_t;

// Struct to store each player's details
typedef struct {
    char name[25];
    int kit_number;
    char club[30];
    age_t dob;
    char position[20];
} player_t;

// Struct to store each team's details
typedef struct {
    char name[20];
    player_t players[SQUAD_SIZE];
    int active_size;
} team_t;

team_t league_teams[NUM_TEAMS];
int current_team_count = 0;

// Function Prototypes
void display_menu();
void enroll_club();
void add_player();
void search_update();
void display_club_statistics();
void handle_error(char *message);

// Main Function
int main() {
    int choice;
    while (1) {
        display_menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1: enroll_club(); break;
            case 2: add_player(); break;
            case 3: search_update(); break;
            case 4: display_club_statistics(); break;
            case 5: printf("Exiting the program.\n"); return 0;
            default: handle_error("Invalid choice. Exiting the program."); return 0;
        }
    }
}

// Displays the main menu
void display_menu() {
    printf("\n--- League Team Application ---\n");
    printf("1. Enroll Club\n");
    printf("2. Add Player\n");
    printf("3. Search and Update Player\n");
    printf("4. Display Club Statistics\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Enroll a new club
void enroll_club() {
    if (current_team_count >= NUM_TEAMS) {
        handle_error("Maximum number of teams reached.");
        return;
    }
    printf("Enter the club name: ");
    scanf(" %[^\n]", league_teams[current_team_count].name);
    league_teams[current_team_count].active_size = 0; // Initialize active size
    current_team_count++;
    printf("Club enrolled successfully.\n");
}

// Add a new player to an enrolled club
void add_player() {
    int club_index, i;
    player_t new_player;

    printf("Choose a club to add the player to:\n");
    for (i = 0; i < current_team_count; i++) {
        printf("%d. %s\n", i + 1, league_teams[i].name);
    }
    scanf("%d", &club_index);
    club_index--;

    if (club_index < 0 || club_index >= current_team_count) {
        handle_error("Invalid club selection.");
        return;
    }

    if (league_teams[club_index].active_size >= SQUAD_SIZE) {
        handle_error("This team has reached the maximum number of players.");
        return;
    }

    printf("Enter player name: ");
    scanf(" %[^\n]", new_player.name);
    printf("Enter kit number: ");
    scanf("%d", &new_player.kit_number);
    printf("Enter position: ");
    scanf(" %[^\n]", new_player.position);
    printf("Enter date of birth (dd mm yyyy): ");
    scanf("%d %d %d", &new_player.dob.day, &new_player.dob.month, &new_player.dob.year);

    // Check for duplicate player names and kit numbers
    for (i = 0; i < league_teams[club_index].active_size; i++) {
        if (strcmp(league_teams[club_index].players[i].name, new_player.name) == 0 ||
            league_teams[club_index].players[i].kit_number == new_player.kit_number) {
            handle_error("Duplicate player name or kit number detected.");
            return;
        }
    }

    league_teams[club_index].players[league_teams[club_index].active_size++] = new_player;
    printf("Player added successfully.\n");
}

// Search for a player by name or kit number and update details if found
void search_update() {
    char search_name[25];
    int kit_number, i, j;
    printf("Search by:\n1. Name\n2. Kit number\n");
    int option;
    scanf("%d", &option);

    if (option == 1) {
        printf("Enter player name to search: ");
        scanf(" %[^\n]", search_name);
        for (i = 0; i < current_team_count; i++) {
            for (j = 0; j < league_teams[i].active_size; j++) {
                if (strcasecmp(league_teams[i].players[j].name, search_name) == 0) {
                    printf("Player found: %s, Kit Number: %d, Position: %s\n", league_teams[i].players[j].name, league_teams[i].players[j].kit_number, league_teams[i].players[j].position);
                    printf("Enter new details:\n");
                    printf("Enter new position: ");
                    scanf(" %[^\n]", league_teams[i].players[j].position);
                    printf("Player details updated successfully.\n");
                    return;
                }
                else
                printf("Player not found");
            }
        }
    } else if (option == 2) {
        printf("Enter kit number to search: ");
        scanf("%d", &kit_number);
        for (i = 0; i < current_team_count; i++) {
            for (j = 0; j < league_teams[i].active_size; j++) {
                if (league_teams[i].players[j].kit_number == kit_number) {
                    printf("Player found: %s, Kit Number: %d, Position: %s\n", league_teams[i].players[j].name, league_teams[i].players[j].kit_number, league_teams[i].players[j].position);
                    printf("Enter new details:\n");
                    printf("Enter new position: ");
                    scanf(" %[^\n]", league_teams[i].players[j].position);
                    printf("Player details updated successfully.\n");
                    return;
                }
            }
        }
    } else {
        handle_error("Invalid search option.");
    }
}

// Display statistics for all clubs, including average age
void display_club_statistics() {
    int i, j, age_sum, count;
    for (i = 0; i < current_team_count; i++) {
        printf("Club: %s\n", league_teams[i].name);
        printf("Number of players: %d\n", league_teams[i].active_size);
        age_sum = 0;
        count = league_teams[i].active_size;
        for (j = 0; j < count; j++) {
            int age = 2024 - league_teams[i].players[j].dob.year;
            age_sum += age;
            printf("Player: %s, Kit Number: %d, Age: %d, Position: %s\n",
                league_teams[i].players[j].name, league_teams[i].players[j].kit_number,
                age, league_teams[i].players[j].position);
        }
        if (count > 0) {
            printf("Average Age: %.2f\n", (float) age_sum / count);
        }
    }
}

// Display an error message
void handle_error(char *message) {
    printf("Error: %s\n", message);
}