#include <stdio.h>

int main()
{
    enum Company { GOOGLE, FACEBOOK, XEROX, YAHOO, EBAY, MICROSOFT };

    enum Company company1 = XEROX;
    enum Company company2 = GOOGLE;
    enum Company company3 = EBAY;

    printf("First value is %i\n Second Value is %i\n Third Value is %i\n", company1, company2, company3);

    return 0;
}