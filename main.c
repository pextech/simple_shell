#include "shell.h"
/**
* main - carries out the read, execute then print output loop
* @ac: argument count
* @av: argument vector
* Return: 0
*/
int main(int ac, char **av)
{
char *command, **tokens;
unsigned int i;
(void)ac;
(void)av;

while (1)
{

prompt1();

command = read_command();

if (!command)
exit(EXIT_SUCCESS);

if (command[0] == '\0' || strcmp(command, "\n") == 0)
{
free(command);
continue;
}

if (strcmp(command, "exit\n") == 0)
{
free(command);
break;
}

tokens = tokenizer(command);

for (i = 0; tokens && tokens[i]; i++)
printf("%s\n", tokens[i]);

free(command);
free(tokens);
}
return (0);
}
