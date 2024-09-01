#include<stdio.h>

float parsec_to_au(float parsec)
{
    return parsec * 206264.806;
}

float parsec_to_ly(float parsec)
{
    return parsec * 3.26;
}

float au_to_parsec(float au)
{
    return au / 206264.806;
}

float au_to_ly(float au)
{
    return au / 63239.7263;
}

float ly_to_parsec(float ly)
{
    return ly / 3.26;
}

float ly_to_au(float ly)
{
    return ly * 63239.7263;
}

float get_distance_conversion(char from, char to, float value)
{
    switch (from)
    {
    case 'a':
        if(to == 'l'){
            return au_to_ly(value);
        } else if(to == 'p'){
            return au_to_parsec(value);
        }
        break;
    case 'l':
        if(to == 'a'){
            return ly_to_au(value);
        } else if(to == 'p'){
            return ly_to_parsec(value);
        }
        break;
    case 'p':
        if(to == 'l'){
            return parsec_to_ly(value);
        } else if(to == 'a'){
            return parsec_to_au(value);
        }
        break;
    default:
        break;
    }
    return 0.0;
}