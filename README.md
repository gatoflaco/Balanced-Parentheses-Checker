# Balanced-Parentheses-Checker
A simple implementation of a Turing Machine solution to the balanced parentheses problem.

## Author: Isaac Jung

There's really nothing special to see here. In CSE 355 (Theoretical Computer Science) at ASU we had a problem where we drew a TM to accept strings containing balanced parentheses. I felt like translating it to actual code.

### Some things to note:
- unlike the basic TM from class, this one can work with any strings (as in, it may consist of more than just parentheses)
- it handles brackets, curly braces, and angle braces, too
- it does some stupid ascii trickery to cut down on code slightly, because all of the characters except parentheses happen to be 2 values away from each other like this:

![image showing that angle braces, curly braces, and brackets follow the same pattern in ascii](https://cdn.discordapp.com/attachments/930183886435135573/974010082444607498/unknown.png "ascii-table-screenshot")
- it expects user input on loop, you must type "done" to finish

### Here is the example input I used, for easy copy-pasting:
()
(){}
(hello_world())[5];
This string has no parentheses, curly braces, or brackets.
<haha <(owo)> funny face> [({  })]
(
]
}{
[({])}
<(uwu<) this won't work
done

![image showing the output of the program given the inputs](https://cdn.discordapp.com/attachments/930183886435135573/974012856506929203/unknown.png "output")
