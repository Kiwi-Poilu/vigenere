#include <stdio.h>
#include <unistd.h>

char	ft_decrypt(char msg, char key)
{
	char ret;
	
	msg -= 97;
	key -= 97;
	if (msg - key < 0)
		ret = msg - key + 26;
	else
		ret = msg - key;
	return (ret + 97);

}

int	ft_vigenere(char *msg, char *key)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (msg[i])
	{
		if (key[j] == '\0')
			j = 0;
		printf("%c", ft_decrypt(msg[i], key[j]));
		i++;
		j++;
	}
	printf("\n");
	return (0);
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		printf("Invalid number of arguments\n");
		return (0);
	}
	ft_vigenere(av[1], av[2]);
	return (0);
}
