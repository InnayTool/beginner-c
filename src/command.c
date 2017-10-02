#include "command.h"
#include "heap.h"
#include "console.h"


commandset* commandcreateset(commandset * cmdset, size_t size)
{
	if(size)
		cmdset->cmds = (command*) heapalloc(sizeof(command), size, true);
	cmdset->size = size;
	cmdset->n = 0;
	return cmdset;
}
size_t commandadd(commandset * cmdset, const char* str, commandfunction func)
{
	if(cmdset->n == cmdset->size)
	{
		if(cmdset->size)
			cmdset->cmds = (command*) heaprealloc(cmdset->cmds, sizeof(command), cmdset->size+1);
		else
			cmdset->cmds = (command*) heapalloc(sizeof(command), 1, false);
		++cmdset->size;
	}
	cmdset->cmds[cmdset->n].str = str;
	cmdset->cmds[cmdset->n].func = func;
	++cmdset->n;
	return cmdset->n;
}
int commandselect(commandset* cmdset, size_t argc, char* argv[], uintptr_t commandindex)
{
	size_t i;
	for(i = 0; i < cmdset->n; ++i)
		if(!strcmp(cmdset->cmds[i].str, argv[commandindex]))
			return cmdset->cmds[i].func(argc, argv);
}
int commandmainloop(commandset* cmdset, const char* text)
{
	char* str[1024];
	size_t i;
	while(true)
	{
		conwriteint64_t(hex, (uint64_t)text);
		conwrite(text);
		str[0] = (char*) heapalloc(1, 1024, false);
		conreadtok(str[0],1024," ");
		for(i = 1; congetlastdelim() != '\n' && i < 1024; ++i)
		{
			str[i] = (char*) heapalloc(1, 1024, false);
			conreadtok(str[i], 1024, " ");
		}
		switch(commandselect(cmdset, i, str, 0))
		{
			case 0:
				return 0;
				break;
		}
	}
}


