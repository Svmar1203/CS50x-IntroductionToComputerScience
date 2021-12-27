#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);// count of letters in text
int count_words(string text);// count of words in text
int count_sentences(string text);// count of sentences in text
int readability_index(int letters, int words, int sentences);

int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    int index = readability_index(letters, words, sentences);
    if (index < 1)
    {
        printf("Before Grade 1\n");// output grade level, if index is less then 1
    }
    else if (index >= 16)// if index is more of equal 16
    {
        printf("Grade 16+\n");// output if index is more of equal 16
    }
    else
    {
        printf("Grade %i\n", index);// output grade, if index is more then 1
    }
}

int count_letters(string text)
{
    int letters = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
        if (isalpha(text[i]))// if character is only letters
        {
            letters ++;// number of letters ++
        }
    return letters;
}

int count_words(string text) 
{
    int words = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '-' && isalpha(text[i - 1])) {}
        else if (text[i] == 39 && isalpha(text[i - 1])) {}
        else if (!isalpha(text[i]) && isalpha(text[i - 1]))
        {
            words ++;// number of words ++
        }
    }
    return words;
}

int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        int character = text[i];
        if (character == 46 || character == 33 || character == 63)// if character is period, exclamation point or question mark
        {
            sentences ++;// number of sentences ++
        }

    }
    return sentences;
}

int readability_index(int letters, int words, int sentences)
{
    float words_per_100 = words / 100.0;
    float L = letters / words_per_100;
    float S = sentences / words_per_100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    return index;
}