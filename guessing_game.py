import random;
import sys;

def main():
    answer = random.randint(1,100);
    n_guesses = 0
    print("Jag tänker på ett tal mellan 1 och 100")
    while True:
        n_guesses += 1
        guess = input("Gissa talet: ")
        while not guess.isdigit():
            guess = input("Jag vill ha ett tal: ")
        guess = int(guess)
        if answer == guess:
            print("Grattis! Rätt efter", n_guesses, "gissningar!")
            sys.exit(0)
        elif answer > guess:
            print("Mitt tal är större")
        else:
            print("Mitt tal är mindre")


main()
