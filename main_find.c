#include "txtfind.h"
#include <stdio.h>
#define LINE 256
#define WORD 30
int main()
{   	
	char first_word[LINE];
	char *pointer_first_word = first_word;
	int length = getword(first_word);
	if(length != 0)
	{
		if(getword(pointer_first_word + length) != 0)
		{
			if(*(pointer_first_word + length) == 'a')
			{
				getword(pointer_first_word+length);
				*(first_word+length)=' ';
				print_lines(first_word);
			}
			else if(*(pointer_first_word + length) == 'b')
			{
				getword(pointer_first_word+length);
				*(first_word+length)=' ';
				print_similar_words(first_word);	
			}
		}
	}	
	return 0;
}
