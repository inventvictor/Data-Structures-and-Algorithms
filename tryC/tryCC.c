#include <stdio.h>

void hist(char hist_input[], int len)
{
	int line[128];
	int i = 0, j = 0, k = 0;
	int num = 0;
	int c;
	for (i=0; i<=128; i++)
	{
		line[i] = 0;
	}
	for (k=0; k<len; k++)
	{
		c = hist_input[k];
		if ('a'<=c && c<='z')
		{
			line[c] += 1;
			++num;
		}
	}
	for (j=0; j<=128; j++)
	{
		if (line[j] != 0)
		{
			printf("%d - %d - %d\n", num, j, line[j]);
		}
	}

}

int length_(char _word[])
{
	int i = 0;
	int num = 0;
	for (i=0; _word[i]!='\0'; i++)
	{
		if (_word[i] != ' ')
		{
			num++;
		}
	}
	//printf("length of the word is %d\n", num);
	return num;
}

int length(char _word[])
{
	int i = 0;
	int num = 0;
	for (i=0; _word[i]!='\0'; i++)
	{
		num++;
	}
	//printf("length of the word is %d\n", num);
	return num;
}

void isPalindrome(char wordy[])
{
	int len = length(wordy), rem = len%2;
	int div = 0, i = 0, num = 0, i_ = 0, num_ = 0, j = 0, k = 0, m = 0;
	char n_wordy[len];
	if (rem != 0)
	{
		div = (len - 1)/2;
		while (i<len)
		{
			if ('a'<=wordy[i] && wordy[i]<='z')
			{
				n_wordy[k] = wordy[i];
				k++;
			}
			i++;
		}
		for (m = 0; m<((length_(n_wordy)-1)/2); m++)
		{
			if (n_wordy[m] == n_wordy[(length_(n_wordy)-1) - (m+1)])
			{
				num++;
			}
			i++;
		}
		printf("%d - %d", num, (length_(n_wordy)-1)/2);
		if (num == ((length_(n_wordy)-1)/2))
		{
			printf("True");
		}
		else
		{
			printf("False");
		}
	}

	else
	{
		div = len/2;
		while (i_<div)
		{
			if (wordy[i_] == wordy[len - (i_+1)])
			{
				num_++;
			}
			i_++;
		}
		if (num_ == div)
		{
			printf("True");
		}
		else
		{
			printf("False");
		}
	}
	}

void func_(int n)
{
	int i = 0;
	float ni = 0, no = 2;
	for(i=0; i<(n+1); i++)
	{
		ni = ((3-(no*no))/2);
		no = ni;
		printf("%f\n ", no);
	}
	}
int main()
{
	char *name;
	char x[200] = "I am a boy";
	int len = 0;
	name = &x;
	//length(name);
	//isPalindrome(name);
	//hist(name, length(name));
	func_(100000);
	return 0;
	}

