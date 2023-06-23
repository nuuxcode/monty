Readme
You allowed to use a maximum of one global variable
 -Wall -Werror -Wextra -pedantic -std=c89
gcc -Wall -Werror -Wextra -pedantic -std=c89 -Wno-unused-variable -Wno-unused-parameter -g *.c -o monty
./monty ./bytecodes/000.m
The prototypes of all your functions should be included in your header file called monty.h
Don’t forget to push your header file
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account

General:
get argument check if there 1 argument (if (argc != 2))
    if no file/more than 1 arg:
        USAGE: monty file
        EXIT_FAILURE
    get file
        loop through each line
            remove spaces at start until reach charachter
            stop reading line imediatly after command and it argument if it have
                first space or end of line
            skip empty line
            in invalid instruction: (start of line must be valid command)
                L<line_number>: unknown instruction <opcode>
                EXIT_FAILURE
    cat open file:
        Error: Can't open file <file>
        EXIT_FAILURE

malloc error:
    Error: malloc failed
    EXIT_FAILURE
You have to use malloc and free
Task0:
push:
    push int
        if int is not an integer or no argument given
            L<line_number>: usage: push integer
    You won’t have to deal with overflows:
        no need to treat the case where is stack is full (also we dont have limit)
    Use the atoi function
pall:
    print all value of the stack if not empty
        starting from the top
    dont print anything if empty

task10:
skip line if it start with hashtag : #
1
list of commandes:
push 1
pall
pint
pop
swap
add
nop

sub
div
mul
mod
pchar
pstr
rotl
rotr
stack
queue


flag char 1 if u pass char,
2 if u pass char and then spac then argument and then space

loop through each chatercter
    skip if it space and flag0
when reach to alpha
    put flag1
if reach space again && space behind it alpha && flag1
    put flag0
    print the space
skip until its digit, or end of line

    when reach alpha flag1 when reach another space and


---------------


General:
get argument check if there 1 argument (if (argc != 2))
    if no file/more than 1 arg:
        USAGE: monty file
        EXIT_FAILURE
    get file
        if cant open file:
        Error: Can't open file <file>
        EXIT_FAILURE

        else loop through each line fgets
            if line is less than 3 charachter skip it (opcode small one have 3 charachter) this will skip empty line
                */* CHECK LONG SPACES LINE */*
            start counting loop (line number)
            token each line
                get the first command part
                    if its push
                        get argument
                check if opcode is valid
                    exec command
                is not valid
                    L<line_number>: unknown instruction <opcode>
                    EXIT_FAILURE

malloc error:
    Error: malloc failed
    EXIT_FAILURE
You have to use malloc and free
Task0:
push:
    push int
        if int is not an integer or no argument given
            L<line_number>: usage: push integer
    You won’t have to deal with overflows:
        no need to treat the case where is stack is full (also we dont have limit)
    Use the atoi function
pall:
    print all value of the stack if not empty
        starting from the top
    dont print anything if empty
