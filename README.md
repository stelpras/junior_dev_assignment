# junior_dev_assignment
Tennis Game by Coding Dojo

https://codingdojo.org/kata/Tennis/

Stylianos Prasianakis



# Initial thoughts

I was trying to make an implementation plan.

I̶'̶m̶ ̶t̶h̶i̶n̶k̶i̶n̶g̶ ̶o̶f̶ ̶m̶a̶k̶i̶n̶g̶ ̶a̶ ̶g̶e̶n̶e̶r̶i̶c̶ ̶T̶e̶n̶n̶i̶s̶G̶a̶m̶e̶ ̶c̶l̶a̶s̶s̶ ̶(̶a̶n̶d̶ ̶P̶l̶a̶y̶e̶r̶1̶ ̶a̶n̶d̶ ̶P̶l̶a̶y̶e̶r̶2̶ ̶c̶l̶a̶s̶s̶e̶s̶)̶ (initial thought)

Since .NET is OOP  I have to follow those principles in this quiz (I beleive it's more crusial in production haha). I did all lot of those OOP quizes in college. We had this OOP Programming proffessor asking us all the time what are the best classes possible in the certain situations and I remember that it always had to be the most logical in our heads. This professor was teaching us what to keep private and public. The most important think that I remembered is that private are the actions that you don't want everyone to see or use and public are the one open to everybody.

I was thinking a lot that its better to make a generic Player class. 
Ι also don't like the name TennisGame of the class. It doesn't represent an actual person
or a situation that's being handled by someone. So I made the conclusion to make 2 classes,
Player and Umpire .

Let's make the public - private parts.

Player 
public: name , score_point (here is pointless since umpire decides so I think I will delete it in the implementation)

Umpire
public: announcePoint (), endGame() (those are needed in our programm so they remain public, I do think that's correct but the programm can't function otherwise)
private: rememberScore()

There are 4 differt scores. (0 , 15 , 30 ,40).

There are also 9 outcomes to check in the tests to check.
(0, 0)
(1, 0)
(1, 1)
(2, 1)
(3, 0)
(3, 3)
(4, 3)
(3, 4)
(5, 3)
(3, 5)

# Implementation

Two classes: Player and Umpire.

Player only has a name. It doesn't keep its own score. score_point was never added, exactly as I guessed above.

Umpire owns both players and keeps the actual point counts. rememberScore() is private and just adds a point to the right player. announcePoint() is public - it's the only way to report a point, and it returns the score after. endGame() checks if the game is over.

The deuce/advantage/win rules are in a separate function, formatScore. It just takes two numbers and two names and returns the score string. It doesn't need to be part of the Umpire class since it doesn't use any of its internal state.

Files:

Tennis.h has the declarations for Player and Umpire.

Tennis.cpp has the scoring logic.

tests.cpp is the test runner, checks every score from 0-0 to 3-3, plus advantage/win both ways.

main.cpp is the live simulation - random points, printed one at a time.

Makefile has build/test/run/clean.

To build and run:

```
make test    # build and run the tests
make run     # build and run the live simulation
make clean   # delete compiled binaries
```