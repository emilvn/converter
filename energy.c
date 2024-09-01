#include<stdio.h>

float hartree_to_ev(float hartree)
{
    return hartree * 27.2107;
}

float hartree_to_kcalmol(float hartree)
{
    return hartree * 627.503;
}

float ev_to_hartree(float ev)
{
    return ev / 27.2107;
}

float ev_to_kcalmol(float ev)
{
    return ev * 23.0609;
}

float kcalmol_to_hartree(float kcalmol)
{
    return kcalmol / 627.503;
}

float kcalmol_to_ev(float kcalmol)
{
    return kcalmol / 23.0609;
}

float get_energy_conversion(char from, char to, float value)
{
    switch (from)
    {
    case 'h':
        if(to == 'e'){
            return hartree_to_ev(value);
        } else if(to == 'k'){
            return hartree_to_kcalmol(value);
        }
        break;
    case 'e':
        if(to == 'h'){
            return ev_to_hartree(value);
        } else if(to == 'k'){
            return ev_to_kcalmol(value);
        }
        break;
    case 'k':
        if(to == 'e'){
            return kcalmol_to_ev(value);
        } else if(to == 'h'){
            return kcalmol_to_hartree(value);
        }
        break;
    default:
        break;
    }
}