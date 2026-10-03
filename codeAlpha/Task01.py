import random

def play_hangman():
    # 1. Use a small list of 5 predefined words
    word_list = ["python", "script", "module", "syntax", "object"]
    target_word = random.choice(word_list)
    
    guessed_letters = []
    incorrect_guesses = 0
    # 2. Limit incorrect guesses to 6
    max_incorrect_guesses = 6 
    
    print("Welcome to Text-Based Hangman!")
    print(f"You have {max_incorrect_guesses} incorrect guesses allowed.")
    
    # Main game loop
    while incorrect_guesses < max_incorrect_guesses:
        # Build the current state of the word to display
        display_word = ""
        for letter in target_word:
            if letter in guessed_letters:
                display_word += letter + " "
            else:
                display_word += "_ "
                
        print("\nWord:", display_word.strip())
        
        # Check for win condition
        if "_" not in display_word:
            print(f"\nCongratulations! You guessed the word: '{target_word}'")
            return

        # 3. Basic console input/output
        guess = input(f"Guess a letter (incorrect guesses left - {max_incorrect_guesses - incorrect_guesses}): ").lower()
        
        # Input validation
        if len(guess) != 1 or not guess.isalpha():
            print("Invalid input. Please enter a single letter.")
            continue
            
        if guess in guessed_letters:
            print("You already guessed that letter. Try again.")
            continue
            
        guessed_letters.append(guess)
        
        # Check if the guess is correct or incorrect
        if guess in target_word:
            print("Correct!")
        else:
            print("Incorrect guess.")
            incorrect_guesses += 1
            
    # Loss condition
    print(f"\nGame Over! You've reached {max_incorrect_guesses} incorrect guesses.")
    print(f"The word was: '{target_word}'")

if __name__ == "__main__":
    play_hangman()