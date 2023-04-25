/**
 * *rot13 - encodes a string
 * @s: a string pointer
 * Return: the pointer
 */
char *rot13(char *s)
{
	int i, j;
	char alp[53] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char cod[53] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; alp[i] != '\0'; i++)
	{
		for (j = 0; s[j] != '\0'; j++)
		{
			if (s[j] == alp[i])
			{
				s[j] = cod[i];
			}
		}
	}
	return (s);
}
