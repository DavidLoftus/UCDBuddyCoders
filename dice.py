from random import randint


while True:
    print("Rolling the dice...")
    print("Your number is {}".format(randint(1,6)))
    str = input("Would you like to try again? (y*=Yes, otherwise No) ")

    if str[0].lower() != 'y':
        break
