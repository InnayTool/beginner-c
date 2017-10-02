#include "types.h"
// int func(int argc, char* argv[])
typedef int (*commandfunction)(int argc, char* argv[]);

typedef struct _command
{
	const char* str;
	commandfunction func;
} command;
typedef struct _commandset
{
	command* cmds;
	size_t size;
	size_t n;
} commandset;


commandset* commandcreateset(commandset * cmdset, size_t size		);
size_t		commandadd		(commandset * cmdset, const char* str	, commandfunction func);
int			commandselect	(commandset * cmdset, size_t argc		, char* argv[] );
int			commandmainloop	(commandset * cmdset, const char* text	);
