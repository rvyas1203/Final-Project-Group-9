#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure definitions

// User structure
typedef struct {
    char username[50];
    char email[100];
    char password[50];
    float weight;
    float height;
    int age;
} User;

// Fitness goal structure
typedef struct {
    char type[20]; // e.g., weight loss, muscle gain, overall fitness improvement
    float target; // e.g., target weight or target BMI
    char deadline[20]; // e.g., end of the month, 3 months from now
} Goal;

// Workout structure
typedef struct {
    char type[20]; // e.g., cardio, strength training, yoga
    int duration; // in minutes
    float intensity; // on a scale of 1 to 10
} Workout;

// Nutrition structure
typedef struct {
    char food[50];
    float calories;
    float protein;
    float carbs;
    float fat;
} Nutrition;

// Social post structure
typedef struct {
    char username[50];
    char content[200];
} SocialPost;

// Recommendation structure
typedef struct {
    char username[50];
    char workoutSuggestion[200];
    char nutritionSuggestion[200];
} Recommendation;

// Function prototypes

// User management functions
User* createUser(const char username[], const char email[], const char password[], float weight, float height, int age);
void updateUser(User* user, float weight, float height, int age);
void displayUser(User* user);

// Goal management functions
Goal* createGoal(const char type[], float target, const char deadline[]);
void displayGoal(Goal* goal);

// Workout tracking functions
Workout* createWorkout(const char type[], int duration, float intensity);
void displayWorkout(Workout* workout);

// Nutrition tracking functions
Nutrition* createNutrition(const char food[], float calories, float protein, float carbs, float fat);
void displayNutrition(Nutrition* nutrition);

// Social features functions
SocialPost* createSocialPost(const char username[], const char content[]);
void displaySocialPost(SocialPost* post);

// Recommendation functions
Recommendation* createRecommendation(const char username[], const char workoutSuggestion[], const char nutritionSuggestion[]);
void displayRecommendation(Recommendation* recommendation);
Recommendation* generateRecommendation(User* user, Goal* goal);

int main() {
    // Sample user data and goal
    User* user = createUser("JohnDoe", "john.doe@example.com", "password123", 70.5, 175.0, 30);
    Goal* goal = createGoal("Weight Loss", 65.0, "End of the month");

    // Generate personalized recommendation
    Recommendation* recommendation = generateRecommendation(user, goal);

    // Display recommendation information
    printf("Personalized Recommendation:\n");
    displayRecommendation(recommendation);

    // Free allocated memory
    free(user);
    free(goal);
    free(recommendation);

    return 0;
}

// Function implementations

// User management functions
User* createUser(const char username[], const char email[], const char password[], float weight, float height, int age) {
    User* user = (User*)malloc(sizeof(User));
    if (user == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(user->username, username);
    strcpy_s(user->email, email);
    strcpy_s(user->password, password);
    user->weight = weight;
    user->height = height;
    user->age = age;
    return user;
}

void updateUser(User* user, float weight, float height, int age) {
    user->weight = weight;
    user->height = height;
    user->age = age;
}

void displayUser(User* user) {
    printf("Username: %s\n", user->username);
    printf("Email: %s\n", user->email);
    printf("Weight: %.2f kg\n", user->weight);
    printf("Height: %.2f cm\n", user->height);
    printf("Age: %d\n", user->age);
}

// Goal management functions
Goal* createGoal(const char type[], float target, const char deadline[]) {
    Goal* goal = (Goal*)malloc(sizeof(Goal));
    if (goal == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(goal->type, type);
    goal->target = target;
    strcpy_s(goal->deadline, deadline);
    return goal;
}

void displayGoal(Goal* goal) {
    printf("Type: %s\n", goal->type);
    printf("Target: %.2f\n", goal->target);
    printf("Deadline: %s\n", goal->deadline);
}

// Workout tracking functions
Workout* createWorkout(const char type[], int duration, float intensity) {
    Workout* workout = (Workout*)malloc(sizeof(Workout));
    if (workout == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(workout->type, type);
    workout->duration = duration;
    workout->intensity = intensity;
    return workout;
}

void displayWorkout(Workout* workout) {
    printf("Type: %s\n", workout->type);
    printf("Duration: %d minutes\n", workout->duration);
    printf("Intensity: %.2f/10\n", workout->intensity);
}

// Nutrition tracking functions
Nutrition* createNutrition(const char food[], float calories, float protein, float carbs, float fat) {
    Nutrition* nutrition = (Nutrition*)malloc(sizeof(Nutrition));
    if (nutrition == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(nutrition->food, food);
    nutrition->calories = calories;
    nutrition->protein = protein;
    nutrition->carbs = carbs;
    nutrition->fat = fat;
    return nutrition;
}

void displayNutrition(Nutrition* nutrition) {
    printf("Food: %s\n", nutrition->food);
    printf("Calories: %.2f\n", nutrition->calories);
    printf("Protein: %.2f\n", nutrition->protein);
    printf("Carbs: %.2f\n", nutrition->carbs);
    printf("Fat: %.2f\n", nutrition->fat);
}

// Social features functions
SocialPost* createSocialPost(const char username[], const char content[]) {
    SocialPost* post = (SocialPost*)malloc(sizeof(SocialPost));
    if (post == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(post->username, username);
    strcpy_s(post->content, content);
    return post;
}

void displaySocialPost(SocialPost* post) {
    printf("Username: %s\n", post->username);
    printf("Content: %s\n", post->content);
}

// Recommendation functions
Recommendation* createRecommendation(const char username[], const char workoutSuggestion[], const char nutritionSuggestion[]) {
    Recommendation* recommendation = (Recommendation*)malloc(sizeof(Recommendation));
    if (recommendation == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    strcpy_s(recommendation->username, username);
    strcpy_s(recommendation->workoutSuggestion, workoutSuggestion);
    strcpy_s(recommendation->nutritionSuggestion, nutritionSuggestion);
    return recommendation;
}

void displayRecommendation(Recommendation* recommendation) {
    printf("Username: %s\n", recommendation->username);
    printf("Workout Suggestion: %s\n", recommendation->workoutSuggestion);
    printf("Nutrition Suggestion: %s\n", recommendation->nutritionSuggestion);
}

// Function to generate a personalized recommendation based on user data and goals
Recommendation* generateRecommendation(User* user, Goal* goal) {
    // This is a sample implementation, actual recommendation generation may involve more complex logic
    char workoutSuggestion[200];
    char nutritionSuggestion[200];
    sprintf_s(workoutSuggestion, "Start with 30 minutes of cardio exercise 3 times a week.");
    sprintf_s(nutritionSuggestion, "Include more vegetables and lean protein in your diet.");
    return createRecommendation(user->username, workoutSuggestion, nutritionSuggestion);
}
