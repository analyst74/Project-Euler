#!/usr/bin/python


def main():
    i = 1
    j = 2
    sum = 0
    while j < 4000000:
        if j % 2 == 0:
            sum = sum + j
            print 'adding %d' % (j)
        next = i + j
        i = j
        j = next 

    print sum

if __name__ == '__main__':
    main()
