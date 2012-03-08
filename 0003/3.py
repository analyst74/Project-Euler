#!/usr/bin/python


def main():
    the_number = 600851475143
    # loop through to find next prime
    i = 2
    while i <= the_number / 2:
        # try to divide the number
        while the_number % i == 0:
            the_number = the_number / i
        i += 1

    print the_number

# unused function
def is_prime(n):
    for i in range(n/2)[2::]:
        if n % i == 0:
            return False
    return True

if __name__ == '__main__':
    main()
