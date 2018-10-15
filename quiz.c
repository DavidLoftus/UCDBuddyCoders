#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct question
{
    const char* question;
    const char* answers[4];
    int correctAnswer;
} question_t;

question_t questions[] = {
    {"What is 1+1?", {"1","2","3","4"}, 3},
    {"What is 1+1?", {"1","2","3","4"}, 3},
    {"What is 1+1?", {"1","2","3","4"}, 3}
};

int run_quiz(question_t* questions, int numquestions, int freepasses)
{
    int score = 0;

    for(int i = 0; i < numquestions; i++)
    {
        question_t* question = &questions[i];
        printf("%s\nA: %s\nB: %s\nC: %s\nD: %d",);

        while(1)
        {
            char c;
            scanf("%c", &c);
            c = tolower(c);
            if(c == 'a' || c == 'b' || c == 'c' || c == 'd')
        }

        if(strcmp(str,question->answer)==0)
        {
            printf("Correct!\n");

            if(question->reward != 0)
            {
                score += question->reward;
                printf("Your score is now %d.", score);
            }
        }
        else
        {
            printf("Incorrect! The answer was \"%s\" you said \"%s\"\n", question->answer, str);
            freepasses--;

            if(freepasses < 0)
            {
                return 0;
            }
            else if(freepasses == 0)
            {
                printf("You have no free passes left.\n");
            }
            else
            {
                printf("You have %d free passes left.\n", freepasses);
            }
        }
    }

    return score;
}

int main(void)
{
    run_quiz(questions,3,1);
}
